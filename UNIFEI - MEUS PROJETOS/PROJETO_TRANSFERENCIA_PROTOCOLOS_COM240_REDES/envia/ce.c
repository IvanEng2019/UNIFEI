/*****************************************************************************************************************

Observacoes:
buffer[0] = Para requisicao entre host requisitante e host requisitado - localizado = L e nao encontrado = N
buffer[1] = Numero do pacote
buffer[2] = soma de verificacao
buffer[3] = Soma de verificacao
buffer[4] = controle de fim de arquivo para mais pacotes a serem enviados = C ou para o ultimo = F
buffer_rec[0]  Numero do pacote  - Pacote tera faixa de 01 ate 09
buffer_rec[4] = Confirmacao de recebimento ACK1 = 1 ou negacao de recebimento ACK0 = 0

*********************************************************************************************************************/

///Inclusao de bibliotecas de i/o, windows /sockt
#include <stdio.h>
#include <winsock2.h>
#include <sys/types.h>
#include <string.h>

///definicao da porta e do tamanho do buffer
#define TAM_BUFFER 1024
#define HOST_PORTA_LOCAL 1033

//prototipo
void soma_de_verificacao(char *buffer,int tam_msg);

//funcao principal
int main(){
    int num_bytes_rec; // armazenara o valor retornado por recvfrom (quantidade de bytes)
    char nome_arq[100]; //nome do arquivo buscado
    FILE *arquivo; //definicao do arquivo buscado
    WSADATA info_socket_cli; //A estrutura WSADATA contem informacoes sobre a implementacao do Windows Sockets.
    SOCKET socket_cli; ////variavel socket do cliente requisitado

    //alocacao de memoria para as buffer de envio e de recebimento
    char *buffer=(char*)malloc(TAM_BUFFER);
    char *buffer_rec=(char*)malloc(TAM_BUFFER);

    // Especifica um endereco de transporte e uma porta para a familia de enderecos AF_INET
    struct sockaddr_in end_cli_requisitante;
    struct sockaddr_in end_cli_local;
    int tam= sizeof(SOCKADDR);

    ///Iniciando sokets em windows
    if(WSAStartup(MAKEWORD(2, 2), &info_socket_cli)!=0){
        printf("HOST REQUISITADO: Erro ao iniciar socket.\n");
        exit(1);
    }
    printf ("HOST REQUISITADO: O status da DLL Winsock eh %s. \n", info_socket_cli.szSystemStatus);
    ///criando socket local
    socket_cli=socket(AF_INET,SOCK_DGRAM,0);
    if(socket_cli<0){
        printf("HOST REQUISITADO: Erro ao iniciar socket.\n");
        exit(1);
    }

    memset(&end_cli_local, 0, sizeof(end_cli_local));
    end_cli_local.sin_family = AF_INET;
    end_cli_local.sin_port = htons(HOST_PORTA_LOCAL);
    end_cli_local.sin_addr.s_addr = inet_addr("127.0.0.1");

    //A funcao bind associa o socket criado a porta local do sistema operacional.
    //Nesta associacao eh verificado se a porta ja nao esta sendo utilizada por algum outro processo.
    //Sera atraves desta associacao (porta) que o programa ira receber dados (bytes) de outros programas.
    //A funcao bind retorna 0 (zero) em caso de sucesso e 1 em caso de erro.
    if(bind(socket_cli,(struct sockaddr *)&end_cli_local, sizeof(end_cli_local))<0){
        printf("HOST REQUISITADO: Erro para associar a porta.\n");
        exit(1);
    }
    printf ("HOST REQUISITADO: Socket associado a porta.\n");
    getsockname (socket_cli, (SOCKADDR*) & end_cli_local, (int*) sizeof (end_cli_local));
    printf("HOST REQUISITADO: IPs local utilizado: %s \n", inet_ntoa (end_cli_local.sin_addr));
    printf("HOST REQUISITADO: Porta local Utilizada: %d \n", htons (end_cli_local.sin_port));

    int sair= 0; //Utilizada para deixar o host requisitado na escuta ou sair
    while(1){
        printf("HOST REQUISITADO: Aguardando solicitacao...");
        while(1){
            memset(buffer,'\0', TAM_BUFFER); //escutando a solicitacao do hoste requisitante
            if (recvfrom(socket_cli, buffer, TAM_BUFFER, 0, (struct sockaddr *) &end_cli_requisitante, &tam) == SOCKET_ERROR){
                printf("HOST REQUISITADO: Nao eh possivel atender ao Host Requisitado.\n");
                closesocket(socket_cli);
                WSACleanup();
                exit(1);
            }
            else{
                printf("HOST REQUISITADO: O pedido solicitado esta sendo verificado...\n");
                if(buffer[0]!='\0'){ // buffer[0] diferente de vazio se foi recebido algo
                   strcpy(nome_arq,buffer);
                   arquivo=fopen(nome_arq,"rb");
                   if(arquivo==NULL){//se nao exisitir o arquivo
                        strcpy(buffer,"Not exist file.");// buffer[0] = N
                        if (sendto(socket_cli, buffer, strlen(buffer), 0, (struct sockaddr *) &end_cli_requisitante, sizeof(end_cli_requisitante)) == SOCKET_ERROR){
                            printf("HOST REQUISITADO: Nao e possivel enviar os dados do host requisitante. Erro codigo: %d\n" , WSAGetLastError());
                            closesocket(socket_cli);
                            WSACleanup();
                            exit(1);
                        }
                        else{
                            printf ("HOST REQUISITADO: Arquivo nao encontado e host requisitante avisado.\n");
                        }

                   }
                   else{  //se existir arquivo
                        strcpy(buffer,"Localizado");//buffer[0] = L
                        if (sendto(socket_cli, buffer, strlen(buffer), 0, (struct sockaddr *) &end_cli_requisitante, sizeof(end_cli_requisitante)) == SOCKET_ERROR){
                                printf("HOST REQUISITADO: Nao eh possivel enviar os dados do host requisitante. Erro codigo: %d\n" , WSAGetLastError());
                                closesocket(socket_cli);
                                WSACleanup();
                                exit(1);
                        }
                        else{
                            printf("HOST REQUISITADO: Enviando arquivo %s\n",nome_arq);
                            int pacote = 1; //identifica o pacote
                            char pkt[2]; //auxiliar para identificar  pacote
                            int fim= 0; // idica ultimo pacote a ser enviado
                            int tam_arq; // tamanho do arquivo lido no repositorio
                            int total_enviado= 0; //total de pacotes enviados
                            int total_ACK1_re= 0; //total de confirmacoes recebidas
                            int total_ACK0_re= 0; //total de confirmacoes nao recebidas
                            int total_reenviado= 0; //total de pacotes reenviados
                            while(1){
                                memset(buffer,'\0', TAM_BUFFER);
                                tam_arq = fread(&buffer[5],1,TAM_BUFFER-5,arquivo);
                                itoa(pacote,pkt,10); // indica qual pacote;
                                buffer[1]= pkt[0]; // numero do pacote formato char
                                soma_de_verificacao(buffer,tam_arq); //faz verificacao com checksun
                                if(tam_arq == TAM_BUFFER-5){//se ainda houver mais arquivos a serem lidos e tranferidos
                                    buffer[4]='C';
                                    fim=1; //nao acabou
                                }
                                else{//se o numero de arquivo for menor do que do buffer idica fim do arquivo
                                    buffer[4]='F';
                                    fim=0; // acabou
                                }
                                //faz tranferencia do arquivo por pacote de tamanho ate 1024
                                if (sendto(socket_cli, buffer, tam_arq+5, 0, (struct sockaddr *) &end_cli_requisitante, sizeof(end_cli_requisitante))== SOCKET_ERROR){
                                    printf("HOST REQUISITADO: Nao eh possivel transferir ao host requisitante.\n");
                                    closesocket(socket_cli);
                                    WSACleanup();
                                    exit(1);
                                }
                                else{
                                    total_enviado++;
                                    printf("HOST REQUISITADO: Enviado pacote %c. Total de pacotes enviados: %d\n",buffer[1],total_enviado);
                                    pacote++;
                                    if(pacote==10){// os pacote seram identificados na faixa de 1 a 9
                                       pacote=1;
                                    }
                                    //Confirmacao de recebimento ACK
                                    while(1){
                                        memset(buffer_rec,'\0', TAM_BUFFER);
                                        if (recvfrom(socket_cli, buffer_rec, TAM_BUFFER, 0, (struct sockaddr*) &end_cli_requisitante, &tam) == SOCKET_ERROR){
                                            printf("HOST REQUISITADO: Nao eh possivel receber confirmacao de AKC.\n");
                                            closesocket(socket_cli);
                                            WSACleanup();
                                            exit(1);
                                        }
                                        else{
                                            if(buffer_rec[4]== '1'){// caso tenha recebido confirmacao de recebimento "1AKC1" ate "9AKC1"
                                               total_ACK1_re++;
                                               printf("HOST REQUISITADO: AKC1 do pacote %c recebido. Total de ACK1 recebidos: %d\n",buffer_rec[0],total_ACK1_re);
                                               break;
                                            }
                                            else{ //if(buffer_rec[4] == 0) caso tenha recebido negacao de recebimento "1ACK0" ate "9ACK0"
                                                total_ACK0_re++;
                                                printf("HOST REQUISITADO: ACK0 do pacote %c recebido. Total de ACK0 recebidos: %d. Reenviando pacote...\n",buffer_rec[0],total_ACK0_re);

                                                if (sendto(socket_cli, buffer, tam_arq+5, 0, (struct sockaddr *) &end_cli_requisitante, sizeof(end_cli_requisitante)) == SOCKET_ERROR){
                                                    printf("HOST REQUISITADO: Nao eh possivel transferir ao host requisitado.\n");
                                                    closesocket(socket_cli);
                                                    WSACleanup();
                                                    exit(1);
                                                }
                                                else{
                                                    total_reenviado++;
                                                    printf("HOST REQUISITADO: Pacote %c reenviado. Total de pacotes reenviados: %d\n",buffer[1],total_reenviado);
                                                }
                                            }
                                        }
                                    }
                                }
                                if(fim==0){
                                   printf("HOST REQUISITADO: Envio concluido com sucesso\n");
                                   printf("\nHOST REQUISITADO: Informacoes acerca da transferencia efetuada.\n");
                                   printf("HOST REQUISITADO: Total de pacotes enviados: %d, Total de pacotes reenviados: %d.\n",total_enviado, total_reenviado);
                                   printf("HOST REQUISITADO: Total de pacotes confirmados: %d, Total de pacotes nao confirmados: %d.\n",total_ACK1_re,total_ACK0_re);

                                   break;
                                }
                            }
                        }
                   }
                   break;
               }
            }
        }
        fclose(arquivo);
        printf("HOST REQUISITADO: Para transferir novos arquivos tecle qualquer tecla ou tecle 1 para sair.\n");
        scanf(" %d",&sair);
        if(sair==1){
           closesocket(socket_cli);
           printf("HOST REQUISITADO: Conexao Finalizada.\n");
           break;
        }
        else{
            printf("HOST REQUISITADO: Conexao ainda aberta. Aguardando novos pedidos.\n");
        }
    }
    return 0;
}

//procedimento para checksun
void soma_de_verificacao(char *buffer,int tam_msg){
    unsigned int i;
    unsigned int soma = 0;
    char check[3];
    for(i=5;i<tam_msg+5;i++){
        soma+= buffer[i];
    }
    soma=soma%16;
    if(soma<10){
        soma= soma*10;
    }
    printf("HOST REQUISITADO: Pacote %c tem Checksum de envio = %d \n",buffer[1],soma);
    itoa(soma,check,10); //converte a soma de base 10 em uma string ch
    buffer[2]=check[0];
    buffer[3]=check[1];
}

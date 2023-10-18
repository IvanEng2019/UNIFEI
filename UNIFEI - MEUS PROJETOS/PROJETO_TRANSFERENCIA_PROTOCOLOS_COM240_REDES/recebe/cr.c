/********************************************************************************************************************************************

Observacoes:
buffer[0] = Para requisicao entre host requisitante e host requisitado - localizado = L e nao encontrado = N e,
buffer[0] = Tambem para requisicao entre host requisitante e servidor - Arquivo localizado = S e nao encontrado = N
buffer[1] = Numero do pacote  - Pacote tera faixa de 1 ate 9
buffer[2] = Soma de verificacao parte 1
buffer[3] = Soma de verificacao parte 2
buffer[4] = Controle de fim de arquivo para mais pacotes a serem recebidos = C ou para o ultimo = F
ack[0] = Numero do pacote  - Pacote tera faixa de 01 ate 09
ack[4]= Confirmacao de recebimento ACK1 = 1 ou negacao de recebimento ACK0 = 0

**********************************************************************************************************************************************/

///Inclusao de bibliotecas de i/o, windows /sockt
#include <stdio.h>
#include <winsock2.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

///definicao da porta e do tamanho do buffer
#define SERV_PORTA 1022
#define TAM_BUFFER 1024

//Prototipos
int soma_de_verificacao(char *buffer, int tam_msg);
void recebe_ip_porta(char *buffer, char *ip_host_requisitado, char *porta_host_requisitado);

//Funcao principal
int main(){
    //Declaracao de variaveis
    char nome_arq_desejado[50]; //nome do arquivo para dwonload
    char ip_host_requisitado [13]; // ip a ser buscado
    char porta_host_requisitado [5]; //porta a ser buscada
    int num_bytes_rec; // armazenara o valor retornado por recvfrom em quantidades
    FILE *arquivo; //definicao do arquivo a ser buscado
    WSADATA info_socket_cli_requisitante;//A estrutura WSADATA contem informacoes sobre a implementacao do Windows Sockets.
    SOCKET socket_cli_req;//variavel socket do cliente requisitante

    // Especifica um endereco de transporte e uma porta para a familia de enderecos AF_INET
    struct sockaddr_in end_serv;
    struct sockaddr_in end_cli_requisitado;
    int tam_end=sizeof(SOCKADDR) ;

    //alocacao de memoria para as buffer de envio e de recebimento
    char *buffer=(char*)malloc(TAM_BUFFER); //enviara mensagem/pacote
    char *buffer_rec=(char*)malloc(TAM_BUFFER); // recebera mensagem
    char ack[6];// confirmacao ou negacao de recebimento de um pacote

    //A funcao WSAStartup inicia o uso da DLL do Winsock por um processo.
    if(WSAStartup(MAKEWORD(2, 2), &info_socket_cli_requisitante)!=0){
        printf("HOST REQUISITANTE: Erro ao iniciar socket.\n");
        exit(1);
    }
    printf ("HOST REQUISITANTE: O status da DLL Winsock eh %s.\n", info_socket_cli_requisitante.szSystemStatus);

    //Criando socket local
    socket_cli_req=socket(AF_INET,SOCK_DGRAM,0);
    if(socket_cli_req<0){
        printf("HOST REQUISITANTE: Erro ao iniciar socket.\n");
        exit(1);
    }

    // Para teste vamos supor que o endereco IP do servidor seja 127.0.0.1 ou localhost
    memset(&end_serv, 0, sizeof(end_serv)); //numero de bytes de memoria especificado para tamanho do buffer
    end_serv.sin_family = AF_INET; // Utiliza a familia IPv4
    end_serv.sin_port = htons(SERV_PORTA);// numero da porta do SERVIDOR
    end_serv.sin_addr.s_addr = inet_addr("127.0.0.1"); // // recebera de ip 127.0.0.1

    int sair=0; // variavel utilizada para sair ou permanecer no laco de repetido de solicitacao de download
    while(1){

       int buscar=0;// variavel utilizada para sair ou permanecer no laco de repeticao de busca ao servidor
       int nova_busca=0;
       int continuar=0;
       while(1){
            fflush(stdin);
            printf("HOST REQUISITANTE: Insira o nome do arquivo desejado para fazer o download: ");
            scanf(" %[^\n]",nome_arq_desejado);
            strcpy(buffer,nome_arq_desejado);

            //A funcao sendto eh utilizada para enviar uma mensagem para outro socket.Ela recebe como parametros a mensagem a ser enviada e o endereco do destino.
            if (sendto(socket_cli_req, buffer, strlen(buffer), 0, (struct sockaddr *) &end_serv, sizeof(end_serv)) == SOCKET_ERROR){
                printf("HOST REQUISITANTE: Nao eh possivel solicitar o seu pedido ao servidor.\n");
                closesocket(socket_cli_req);
                WSACleanup();
                exit(1);
            }
            else{
                printf("HOST REQUISITANTE: Aguardando resposta do servidor.\n");
                while(1){
                    memset(buffer,'\0', TAM_BUFFER); //numero de bytes de memoria especificado para tamanho do buffer
                    //A funcao recvfrom recebe um datagrama e armazena o endereco de origem.
                    num_bytes_rec = recvfrom(socket_cli_req, buffer,TAM_BUFFER, 0, (struct sockaddr *) &end_serv, &tam_end);
                    if (num_bytes_rec > 0){
                        //printf ("HOST REQUISITANTE: Total de bytes recebidos do servidor: %d \n", num_bytes_rec);
                        printf ("HOST REQUISITANTE: Mensagem recebida do servidor: %s.\n",buffer);
                        if(buffer[0]=='S'){ // se existir o arquivo no repositorio
                            buscar=1;
                            memset(ip_host_requisitado,'\0', 13);
                            memset(porta_host_requisitado,'\0', 6);
                            recebe_ip_porta(buffer,ip_host_requisitado,porta_host_requisitado);
                            printf("HOST REQUISITANTE: Buscar o arquivo do cliente numero ip: %s e na porta %s\n",ip_host_requisitado,porta_host_requisitado);
                            continuar=0;
                            break;
                        }
                        else if (buffer[0]=='N'){//se o servidor nao encontrar o arquivo no repositorio
                            printf("HOST REQUISITANTE: Arquivo solicitado nao localizado. O Servidor nao possui host que tenha o arquivo para download\n");
                            continuar=1;
                            break;
                        }
                      }
                }//fim do laco de msg enviadas pelo servidor
                if(continuar==1){
                    printf("HOST REQUISITANTE: Para buscar e baixar novo arquivo tecle qualquer tecla ou para sair tecle 1.\n");
                    scanf(" %d",&nova_busca);
                    if(nova_busca==1){
                       closesocket(socket_cli_req);
                       printf("HOST REQUISITANTE: Conexao Finalizada.\n");
                       break;
                    }
                }
                else{
                    break;
                }
            }
       }
       if(buscar==1){//se existir arquivo e host a ser buscado
            //Preciamos agora solicitar arquivo requerido para download ao host passado pelo servidor
            memset(&end_cli_requisitado, 0, sizeof(end_cli_requisitado));
            end_cli_requisitado.sin_family = AF_INET;
            end_cli_requisitado.sin_port = htons(atoi(porta_host_requisitado));
            end_cli_requisitado.sin_addr.s_addr = inet_addr(ip_host_requisitado);

            getsockname (socket_cli_req, (SOCKADDR*) & end_cli_requisitado, (int*) sizeof (end_cli_requisitado));
            printf("HOST REQUISITANTE: IPs de recebimento utilizada: %s \n", inet_ntoa(end_cli_requisitado.sin_addr));
            printf("HOST REQUISITANTE: Porta de recebimento utilizada: %d \n", htons (end_cli_requisitado.sin_port));

            memset(buffer,'\0', TAM_BUFFER);
            strcpy(buffer,nome_arq_desejado);
            while(1){
                //A funcao sendto eh utilizada para enviar uma mensagem para outro socket.
                if (sendto(socket_cli_req, buffer, strlen(buffer), 0, (struct sockaddr *) &end_cli_requisitado, sizeof(end_cli_requisitado)) == SOCKET_ERROR){
                    printf("HOST REQUISITANTE: Nao eh possivel solicitar o seu pedido ao Host Requisitado.\n");
                    closesocket(socket_cli_req);
                    WSACleanup();
                    exit(1);
                }
                else{
                    printf("HOST REQUISITANTE: Realizando busca no host requisitado.\n");
                    while(1){
                        memset(buffer,'\0',TAM_BUFFER);
                        if (recvfrom(socket_cli_req, buffer, TAM_BUFFER, 0, (struct sockaddr *) &end_cli_requisitado, &tam_end) == SOCKET_ERROR){
                            printf("HOST REQUISITANTE: Nao eh possivel receber os dados do host requisitado. Erro codigo: %d\n" , WSAGetLastError());
                            closesocket(socket_cli_req);
                            WSACleanup();
                            exit(1);
                        }
                        else{
                            printf ("HOST REQUISITANTE: Os dados completos recebidos do host requisitado: %s.\n",buffer);
                            if(buffer[0]!='\0'){//se foi recebida alguma mensaem com conteudo
                                if(buffer[0]=='L'){ // se o arquivo solicitado foi localizado
                                    printf("HOST REQUISITANTE: Iniciando transferencia do arquivo %s.\n",&buffer[1]);
                                    arquivo=fopen(nome_arq_desejado,"wb");
                                    break;
                                }
                                else if(buffer[0]=='N'){
                                    printf("HOST REQUISITANTE: Arquivo nao localizado: %s.\n",&buffer[1]);
                                    break;
                                }
                            }//fim do if de analise de bytes recebidos
                        }
                    }
                    break;
                }
            }

            ///Agora eh preciso realizar a transferindo do arquivo
            int pacote_rec= 0; //quantidade de pacotes recebidos
            int total_ACK1_env= 0; //quantidade de pacotes confirmados
            int total_ACK0_env= 0; //quantidade de pacotes n�o confirmados
            while(1){
                memset(buffer,'\0', TAM_BUFFER);
                if ((num_bytes_rec=recvfrom(socket_cli_req, buffer, TAM_BUFFER, 0, (struct sockaddr *) &end_cli_requisitado, &tam_end)) == SOCKET_ERROR){
                    printf("HOST REQUISITANTE: Nao eh possivel receber os dados do host requisitado. Erro codigo: %d\n" , WSAGetLastError());
                    closesocket(socket_cli_req);
                    WSACleanup();
                    exit(1);
                }
                else{
                    pacote_rec++;
                    printf("HOST REQUISITANTE: Pacote %c recebido. Total de pacotes recebidos: %d.\n",buffer[1],pacote_rec);
                    memset(ack,'\0', 5);
                    ack[0]= buffer[1];//recebe o numero do pacote de 1 a 9
                    if(buffer[4]=='C'){ //se houver mais pacotes para serem recebidos
                        if(soma_de_verificacao(buffer,num_bytes_rec) == 1){ //verifico o checksun
                            fwrite(&buffer[5],1,num_bytes_rec-5,arquivo); //Grava o pacote no arquivo
                            strcat(ack,"ACK1"); //envia confirmacao de recebimento
                            if (sendto(socket_cli_req, ack, strlen(ack), 0, (struct sockaddr *) &end_cli_requisitado, sizeof(end_cli_requisitado)) == SOCKET_ERROR){
                                printf("HOST REQUISITANTE: Nao eh possivel receber os dados do host requisitado. Erro codigo: %d.\n", WSAGetLastError());
                                closesocket(socket_cli_req);
                                WSACleanup();
                                exit(1);
                            }
                            else{
                                total_ACK1_env++;
                                printf("HOST REQUISITANTE: AKC1 do pacote %c enviado. Total de ACK1 enviados: %d\n",ack[0],total_ACK1_env);
                            }
                         }
                         else{    //if(soma_de_verificacao(buffer,num_bytes_rec) == 0){
                            strcat(ack,"ACK0"); //envia o nao recebimento do arquivo
                            if (sendto(socket_cli_req, ack, strlen(ack), 0, (struct sockaddr *) &end_cli_requisitado, sizeof(end_cli_requisitado)) == SOCKET_ERROR){
                                printf("HOST REQUISITANTE: Nao eh possivel informar O NAO RECEBIMENTO ao host requisitado.\n");
                                closesocket(socket_cli_req);
                                WSACleanup();
                                exit(1);
                            }
                            else{
                                total_ACK0_env++;
                                printf("HOST REQUISITANTE: AKC0 do pacote %c enviado. Total de ACK0 enviados: %d\n",ack[0],total_ACK0_env);
                            }
                          }
                    }
                    else{ //if(buffer[4]=='F') se for o ultimo pacote
                        if(soma_de_verificacao(buffer,num_bytes_rec) == 1){
                            fwrite(&buffer[5],1,num_bytes_rec-5,arquivo);
                            strcat(ack,"ACK1");
                            if (sendto(socket_cli_req, ack, strlen(ack), 0, (struct sockaddr *) &end_cli_requisitado, sizeof(end_cli_requisitado)) == SOCKET_ERROR){
                                printf("HOST REQUISITANTE: Nao eh possivel receber os dados do host requisitado. Erro codigo: %d\n" , WSAGetLastError());
                                closesocket(socket_cli_req);
                                WSACleanup();
                                exit(EXIT_FAILURE);
                            }
                            else{
                               total_ACK1_env++;
                               printf("HOST REQUISITANTE: AKC1 do pacote %c enviado. Total de ACK1 enviados: %d\n",ack[0],total_ACK1_env);
                               printf("HOST REQUISITANTE: Transferencia concluida com sucesso\n");
                               printf("\nHOST REQUISITANTE: Informacoes acerca da transferencia efetuada.\n");
                               printf("HOST REQUISITANTE: Total de pacotes recebidos: %d.\n",pacote_rec);
                               printf("HOST REQUISITANTE: Total de pacotes ack confirmados enviados: %d\n",total_ACK1_env);
                               printf("HOST REQUISITANTE: Total de pacotes acks nao confirmados enviados: %d.\n",total_ACK0_env);
                               break;//ao receber  a confirmacao do ultimo pacote sai do laco
                            }
                        }
                        else{   //if(soma_de_verificacao(buffer,num_bytes_rec) == 0){
                            strcat(ack,"ACK0");
                            if (sendto(socket_cli_req, ack, strlen(ack), 0, (struct sockaddr *) &end_cli_requisitado, sizeof(end_cli_requisitado)) == SOCKET_ERROR){
                                printf("HOST REQUISITANTE: Nao eh possivel informar O NAO RECEBIMENTO ao host requisitado.\n");
                                closesocket(socket_cli_req);
                                WSACleanup();
                                exit(EXIT_FAILURE);
                            }
                            else{
                                total_ACK0_env++;
                                printf("HOST REQUISITANTE: AKC0 do pacote %c enviado. Total de ACK0 enviados: %d\n",ack[0],total_ACK0_env);
                            }
                        }
                    }
                }
           }
       }
       fclose(arquivo);
       printf("HOST REQUISITANTE: Para buscar e baixar novo arquivo tecle qualquer tecla ou para sair tecle 1.\n");
       scanf(" %d",&sair);
       if(sair==1){
           closesocket(socket_cli_req);
           printf("HOST REQUISITANTE: Conexao Finalizada.\n");
           break;
       }
   }
   return 0;
}

//funcao checksun
int soma_de_verificacao(char *buffer, int tam_msg){
    unsigned int i;
    unsigned int soma = 0;
    char check[3];

    for(i=5; i<tam_msg; i++){
        soma= soma + buffer[i];
    }
    soma=soma%16;// buffer com 1024 entao 16 seria o numero mais ideal para divisao
    if(soma<10){ // faz uso de 2 posices do vetor para o checksun
        soma=soma*10;
    }
    printf("HOST REQUISITANTE: Pacote %c tem Checksum de Recebimento = %d \n",buffer[1],soma);
    itoa(soma,check,10); //converte a soma de base 10 em uma string ch

    if((check[0] == buffer[2]) && (check[1] == buffer[3])){ //valida os dados recebidos
        return 1; //se validado retorna 1
    }
    return 0;//se nao validado retorna 0
}

//procedimento para separar mensagem: identificando o IP e a porta da mensagem recebida
void recebe_ip_porta(char *buffer, char *ip_host_requisitado, char *porta_host_requisitado){
    int i=1;
    do{
        ip_host_requisitado[i-1]=buffer[i];
        i++;
    }while(buffer[i]!= 'm'); //letra m separa o ip da porta
    i++;
    int j=0;
    do{
        porta_host_requisitado[j]=buffer[i];
        i++;
        j++;
    }while(buffer[i]!= 'f');//letra f separa o lixo restante do buffer da identificacao da porta
}

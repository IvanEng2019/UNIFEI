/******************************************************************************************************************

Observacoes:
buffer_serv[0] = Para requisicao entre host requisitante e servidor - Arquivo localizado = S e nao encontrado = N

*******************************************************************************************************************/

///Inclusao de bibliotecas de i/o, windows /sockt
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <sys/types.h>
#include <windows.h>

///definicao do tipo daa estrutura que contera os dados do cliente
typedef struct{
    char nome_arquivo[100];
    char ip_cliente[32];
    char porta_cliente[6];
}info_cli;

///definicao da porta e do tamanho do buffer
#define SERV_PORTA 1022
#define TAM_BUFFER 1024

///prototipos
int menu();
void add_host_repositorio(); // funcao auxiliar 1 que ira adicionar no repositorio
void add_host_repositorio_manual(); // funcao auxiliar 2 que ira adicionar no repositorio
void add_host_repositorio_pelo_serv(info_cli host); // funcao que ira adicionar de fato no repositorio
void le_host_repositorio();// funcao que ira ler todo o repositorio
void servidor_trabalhando(); //funcao que ira desempenhar o papel do servidor operante

//funcao principal do servidor
int main(){
    int escolha;
     do{
         escolha = menu();
         switch(escolha){
             case 0:
                 printf("\n Servidor desligado.\n");
                 break;
             case 1:
                 printf("\n SERVIDOR: A nivel de teste utilizou-se a Porta 1033 e o IP 127.0.0.1\n");
                 add_host_repositorio();
                 break;
             case 2:
                 printf("\n SERVIDOR: A nivel de teste utilizar a Porta 1033 e o IP 127.0.0.1\n");
                 add_host_repositorio_manual();
                 break;
             case 3:
                 //printf("\nRepositorio completo com os enderecos do hosts e seus respectivos arquivos:\n");
                 le_host_repositorio();
                 break;
             case 4:
                 printf("\n Servidor Trabalhando:\n\n");
                 servidor_trabalhando();
                 break;
             default:
                 printf("\n Escolha invalida.\n");
         }
     }while(escolha!=0);
   return 0;
}

void servidor_trabalhando(){

    info_cli host;//utilizada para representar a infomacao gravada no repositorio
    info_cli cli; //utilizada para representar a infomacao do cliente requisitante
    info_cli add_host;//utilizada para representar a infomacao a ser gravada no repositorio

    struct sockaddr_in end_cli; //especifica um endereco de transporte e uma porta para a familia de enderecos AF_INET para o cliente
    struct sockaddr_in end_serv; //especifica um endereco de transporte e uma porta para a familia de enderecos AF_INET para o servidor
    WSADATA info_socket_serv; //A estrutura WSADATA contem informacoes sobre a implementacao do Windows Sockets.
    SOCKET socket_serv; //variavel socket do servidor
    int tam_end=sizeof(SOCKADDR) ;
    char *buffer_serv = (char*)malloc(TAM_BUFFER); // alocando espaco de memoria para o BUFFER do servidor

    //A funcao WSAStartup inicia o uso da DLL do Winsock por um processo.
    if(WSAStartup(MAKEWORD(2, 2), &info_socket_serv)!=0){
        printf("SERVIDOR: Erro ao iniciar socket do servidor.\n");
        exit(1);
    }
    printf ("SERVIDOR: O status da DLL Winsock eh %s.\n", info_socket_serv.szSystemStatus);

    //criando socket do servidor
    socket_serv=socket(AF_INET,SOCK_DGRAM,0);
    if(socket_serv<0){
        printf("SERVIDOR: Erro ao criar socket no servidor\n");
        exit(1);
    }

    //Dados referente ao socket do servidor
    memset(&end_serv, 0, sizeof(end_serv)); ////numero de bytes de memoria especificado para end_serv
    end_serv.sin_family = AF_INET;  // Utiliza a familia IPv4
    end_serv.sin_port = htons(SERV_PORTA); // numero da porta do SERVIDOR
    end_serv.sin_addr.s_addr = htonl(INADDR_ANY); // recebera de toda a interface (0.0.0.0)

    // bind no socket para associar o socket a um numero de porta em particular.
    if((bind(socket_serv,(struct sockaddr *)&end_serv , sizeof(end_serv)))<0){
        printf("SERVIDOR: Erro para associar a porta.\n");
        exit(1);
    }
    printf ("SERVIDOR: Socket associado a porta: %d \n",end_serv.sin_port);

    /*******************************************************************************************************************************************
    Obs.: O servidor com UDP simplesmente cria um socket; nao eh necessario coloca-lo em modo de escuta (listen) nem aguardar conexoes (accept).
    ********************************************************************************************************************************************/

    getsockname (socket_serv, (SOCKADDR*) & end_serv, (int*) sizeof (end_serv));
    printf("SERVIDOR: IPs de recebimento utilizado: %s \n", inet_ntoa (end_serv.sin_addr));
    printf("SERVIDOR: Porta de recebimento utilizada: %d \n", htons (end_serv.sin_port));

    int sair = 0;//variavel de controle da escuta do servidor dada pelo usuario
    int cont = 0; //controle de escuta e execucao do servidor

    while(cont<5){
        printf("SERVIDOR: Aguardando solicitacao... ");
        memset(buffer_serv,'\0', TAM_BUFFER); //numero de bytes de memoria especificado para tamanho do buffer
        ///A funcao recvfrom ira recebe um datagrama contendo o nome do arquivo que o cliente deseja  e tambem armazena o endereco do requisitante
        if(recvfrom(socket_serv, buffer_serv, TAM_BUFFER, 0, (struct sockaddr*) &end_cli, &tam_end) == SOCKET_ERROR){
            printf("SERVIDOR: Nao eh possivel receber solicitacoes do host.\n");
            closesocket(socket_serv);
            WSACleanup();
            exit(1);
        }
        else{
           printf("\n\nSERVIDOR: Pedido %d solicitado. Faltam %d pedidos.\n",cont+1,(5-cont));
           printf ("SERVIDOR: Nome do arquivo recebido: %s\n",buffer_serv);
           cont++;
           // Algumas informacoes no lado do remetente
           getpeername (socket_serv, (SOCKADDR *) &end_cli, &tam_end);
           printf ("SERVIDOR: IP do host remetente: %s \n", inet_ntoa (end_cli.sin_addr));
           printf ("SERVIDOR: Porta do host remetente: %d \n", htons (end_cli.sin_port));

           printf ("SERVIDOR: Buscando arquivo solicitado.\n");
           if(buffer_serv[0]!='\0'){ //se o nome do arquivo buscado pelo cliente estiver no buffer
                strcpy(cli.nome_arquivo,buffer_serv);
                int existe_arq_rep = 0; //variavel semafaro utilizada para represntar se existe (1) o arquivo solicitado ou nao (0) no repositorio
                FILE *repositorio = fopen("repositorio.txt","rb");//abre repositorio para leitura
                if (repositorio == NULL){//se nao existir repositorio
                    printf("SERVIDOR: Problemas na abertura do arquivo.\n");
                    strcpy(buffer_serv,"Not exist base de dados.");
                }
                while(!feof(repositorio)){//busca arquivo no repositorio
                    fread(&host,sizeof(info_cli),1,repositorio);
                    if(strcmp(host.nome_arquivo,cli.nome_arquivo)==0){//se existir o arquivo no repositorio
                        printf("SERVIDOR: Arquivo %s localizado no ip %s e na porta %s. \n",host.nome_arquivo,host.ip_cliente,host.porta_cliente);
                        existe_arq_rep=1;
                        memset(buffer_serv,'\0', TAM_BUFFER); // numero de bytes de memoria reservado novamente para o buffer
                        buffer_serv[0]='S';
                        strcat(buffer_serv, host.ip_cliente);//insere o ip do cliente no buffer
                        strcat(buffer_serv, "m");//insere o caracter m no buffer
                        strcat(buffer_serv, host.porta_cliente);//insere a porta no buffer
                        strcat(buffer_serv, "f");//insere o caracter f no buffer indicando final de caracterers validos

                        //A funcao sendto eh utilizada para enviar uma mensagem para outro socket.
                        if ((sendto(socket_serv, buffer_serv, strlen(buffer_serv), 0 , (struct sockaddr*)&end_cli, sizeof(end_cli)))== SOCKET_ERROR){
                            printf("SERVIDOR: Nao eh possivel responder ao cliente os dados do host do seu pedido.\n");
                            closesocket(socket_serv);
                            WSACleanup();
                            exit(1);
                        }
                        else{
                            printf("SERVIDOR: Pedido atendido. Os Dados solicitados foram enviados ao cliente com sucesso.\n");
                            break;
                        }
                    }
                }//fim do laco de buca no repositorio
                if(existe_arq_rep==1){ //armazena no repositorio os dados da estao requisitante caso o arquivo seja encontrado
                        char p[6];
                        itoa(end_cli.sin_port,p,10);
                        strcpy(add_host.nome_arquivo,host.nome_arquivo);
                        strcpy(add_host.ip_cliente,inet_ntoa(end_cli.sin_addr));
                        strcpy(add_host.porta_cliente,p);
                        add_host_repositorio_pelo_serv(add_host);
                        le_host_repositorio();
               }
                else{//if(existe_arq_rep == 0){ se o arquivo nao for encontrado no repositorio
                   strcpy(buffer_serv,"Not exist file."); //buffer_serv[0]=N
                   if (sendto(socket_serv, buffer_serv, strlen(buffer_serv) , 0 , (struct sockaddr *) &end_cli, sizeof(end_cli)) == SOCKET_ERROR){
                        printf("SERVIDOR: Nao eh possivel responder ao cliente que nao existe o arquivo solicidado em nenhuma estacao no repositorio.");
                        closesocket(socket_serv);
                        WSACleanup();
                        exit(1);
                   }
                   else{
                      printf("SERVIDOR: Arquivo solicitado nao foi localizado no repositorio do servidor...\n");
                   }
               }//fim do if de exitencia do arquivo no repositorio
               fclose(repositorio);//fecha repositorio
            }//fim do if do buffer
        }//fim do if de recebimento do requisitante

        if(cont==5){
            printf("SERVIDOR: Para continuar na escuta por mais 5 solicitacoes tecle qualquer tecla ou para sair tecle 1.\n");
            scanf(" %d",&sair);
            if(sair==1){
               closesocket(socket_serv);
               WSACleanup();
               printf("SERVIDOR: Conexao Finalizada.\n");
           }
            else{
                printf("SERVIDOR: Conexao ainda aberta. Aguardando novos pedidos.\n");
                cont=0;
           }
        }
    }//fim do laco de escuta do servidor
}

//menu inicial do programa
int menu(){
    int op;
    printf("\n Menu de opcoes:\n");
    printf(" Tecle 0 para desligar servidor.\n");
    printf(" Tecle 1 para adicionar automaticamente (Teste na Porta: 1033 - IP: 127.0.0.1 - arquivo: musica.mp3)\n");
    printf(" Tecle 2 para inserir no repositorio manualmente.\n");
    printf(" Tecle 3 para visualizar o repositorio.\n");
    printf(" Tecle 4 para deixar servidor operante.\n Sua escolha: ");
    scanf(" %d",&op);
    return op;
}

//Procedimento para inserir o nome dos arquivos e o dos seus repectivos hosts
void add_host_repositorio(){
    info_cli add_host;
    printf(" SERVIDOR: o nome do arquivo eh musica.mp3\n");
    strcpy(add_host.nome_arquivo,"musica.mp3");
    printf(" SERVIDOR: A porta do cliente eh 1033\n");
    strcpy(add_host.porta_cliente,"1033");
    printf(" SERVIDOR: o IP do cliente e 127.0.0.1\n");
    strcpy(add_host.ip_cliente,"127.0.0.1");
    add_host_repositorio_pelo_serv( add_host);
}

//Procedimento para inserir o nome dos arquivos e o dos seus repectivos hosts de forma manual pelo usuario
void add_host_repositorio_manual(){
    info_cli add_host;
    printf(" SERVIDOR: Inserir nome do arquivo: ");
    scanf(" %[^\n]",add_host.nome_arquivo);
    printf(" SERVIDOR: Informe a porta do cliente: ");
    scanf(" %s",add_host.porta_cliente);
    printf(" SERVIDOR: Informe o IP do cliente:");
    scanf(" %s",add_host.ip_cliente);
    //gravando os dados no repositorio
    add_host_repositorio_pelo_serv(add_host);
}

//procedimento que faz a Gravacao no final do repositorio
void add_host_repositorio_pelo_serv(info_cli host){
    FILE *repositorio = fopen("repositorio.txt","ab");
    if (repositorio == NULL){
        printf(" SERVIDOR: Problemas na abertura do arquivo\n");
        exit(1);
    }
    fwrite(&host,sizeof(info_cli),1,repositorio);
    fclose(repositorio);
    printf("SERVIDOR: Dados do arquivo e da estacao inseridos no repositorio com sucesso!\n\n");
}

 // Procedimento para leitura completa do repositorio
void le_host_repositorio(){
    info_cli host;
    FILE *repositorio = fopen("repositorio.txt","rb");
    if (repositorio == NULL){
        printf("\n SERVIDOR: Repositorio vazio\n");
    }
    else{
        printf("\n Conteudo do Repositorio: \n");
        int i=1;
        while(1){
            fread(&host,sizeof(info_cli),1,repositorio);
            if(feof(repositorio)){
                break;
            }
            printf("  %d - Arquivo: %s na porta %s do host de IP: %s \n",i++,host.nome_arquivo,host.porta_cliente, host.ip_cliente);
        }
        printf("\n");
    }
    fclose(repositorio);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER 256
int main(void)
{
     int fd[4];/* File descriptors para o Pipe*/

     pid_t pid; /* Variável para armazenar o pid*/
     /* Criando nosso Pipe */
     if(pipe(fd)<0) {
         perror("pipe") ;
         return -1 ;
     }
     /* Criando o processo filho*/
     if ((pid = fork()) < 0)
     {
         perror("fork");
         exit(1);
     }
     /* Processo Pai*/
     if (pid > 0)
     {
         /*No pai, vamos ESCREVER, então vamos fechar a LEITURA do Pipe neste lado*/
         close(fd[0]);
         char strP[BUFFER] = "Aprendi a usar Pipes em C!";
         printf("String enviada pelo pai no Pipe: '%s'\n\n", strP);
         write(fd[1], strP, sizeof(strP) + 1);/// Escrevendo a string no pipe

     }
     /* Processo Filho*/
     else
     {
         char str_recebidaFilho[BUFFER];
         /* No filho, vamos ler. Então vamos fechar a entrada de ESCRITA do pipe */
         close(fd[1]);
         /// Lendo o que foi escrito no pipe, e armazenando isso em 'str_recebida'
         read(fd[0], str_recebidaFilho, sizeof(str_recebidaFilho));
         printf("String lida pelo filho no Pipe : '%s'\n\n",str_recebidaFilho);

     }
     if (pid = 0)
     {
         close(fd[2]);
         char strF[BUFFER] = " pai fala para filho ";
         printf("String enviada pelo pai no Pipe: '%s'\n\n", strF);
         write(fd[3], strF, sizeof(strF) + 1);/// Escrevendo a string no pipe
     }
     else
     {
         char str_recebidaPai[BUFFER];
         /* No filho, vamos ler. Então vamos fechar a entrada de ESCRITA do pipe */
         close(fd[3]);
         /// Lendo o que foi escrito no pipe, e armazenando isso em 'str_recebida'
         read(fd[2], str_recebidaPai, sizeof(str_recebidaPai));
         printf("String lida pelo pai no Pipe : '%s'\n\n",str_recebidaPai);
     }

     return(0);
}

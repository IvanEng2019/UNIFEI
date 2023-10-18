//      fork1.c
//      
//      Copyright 2012 Carlos Minoru Tamaki <professorcco@gmail.com>
//      
//		Este e um software livre; voce pode redistribuir e/ou modificar
//		nos termos do GNU General Public License como publicado pelo
//      Free Software Foundation; como na vesao 2 da Licenca ou (na sua
//      opcao) qualquer versao posterior.
//      
//      Exemplo de criação de processos a partir de um processo em
//      execução.
//      

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
 
int main(int argc, char  *argv[])
{
   pid_t iPid;
   int i;
 
   printf("\nDuplicando o processo\n");
 
   iPid = fork();
   if (iPid < 0)
   {
      perror(argv[0]);
      exit(errno);
   }
 
   if(iPid != 0)
   {
      /* este trecho de código será executado apenas no pai */
      printf("\nCodigo executado no processo pai\n");
      printf("\nPAI -Processo pai.  PID:|%d|\n", getpid());
      printf("\nPAI -Processo filho.PID:|%d|\n", iPid);
      sleep( 2 );
      for( i = 0; i < 2100000000; i++ );
   }
   else
   {
      printf("\nCódigo executado pelo filho");
   }
 
   /* este trecho de código será executado apenas no filho, embora o comando if esteja disponível também para o pai */
   if(iPid == 0)
   {
      printf("\nCodigo executado no processo filho\n");
      printf("\nFILHO-Processo pai.  PID:|%d|\n",getppid());
      printf("\nFILHO-Processo filho.PID:|%d|\n",getpid());
      for( i = 0; i < 2100000000; i++ );
   }
   else
   {
      printf("\nCódigo executado pelo pai");
   }
 
   /* este código está disponível no pai e no filho */
   printf("\nEste mensagem será impressa 2 vezes. PID: |%d|\n", iPid);
   return 0;
}

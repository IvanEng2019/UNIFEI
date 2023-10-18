//      forkwait.c
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
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int i;
    pid_t cpid;
    pid_t child_pid;
    cpid = fork();

    switch (cpid) {
        case -1: printf("Falha ao criar processo; cpid == -1\n");
                 break;

        case 0: child_pid = getpid();
                for (i = 0; i < 10; i++) {
                    printf("%d: esse é o processo filho, pid = %d\n", i, child_pid);
                    sleep(1);
                }
                exit(0);

        default: printf("Esse é o processo pai: esperando pelo %d terminar\n", cpid);
                 waitpid(cpid, NULL, 0);
                 printf("Ttttthat's all, folks\n");
    }
    return 0;
}

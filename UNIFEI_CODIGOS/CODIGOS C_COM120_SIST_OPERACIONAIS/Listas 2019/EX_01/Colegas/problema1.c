#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Dupla: João Pedro Josué 2018011044
       Paulo Sergio da Silva Batista 2017018926

COM 120 - Problema 1 - 26/08/2019

*/
int main(int argc, char *argv[])
{
    int pid=0;
    pid = fork();
    int i;
    if (pid != 0)
    {

        int piB = 0 ;
        piB = fork();

        if(piB != 0)
        {
            printf("Iniciando pai\n");
            for (i = 0; i<=999; i++) printf("Contagem do processo pai %d\n", i);
            printf("Finalizando processo pai\n");

        }
        else
        {
            printf("Iniciando filho B\n");
            for (i = 2000; i<= 2999; i++)printf("Contagem do processo pai %d\n", i);
            printf("Finalizando processo filho B\n");

        }
    }
    else
    {
        int pfa = 0;
        pfa = fork();

        if(pfa != 0)
        {

            int pfd = 0;
            pfd = fork();

            if(pfd != 0)
            {
                printf("Iniciando filho A\n");
                for (i = 1000; i<= 1999; i++) printf("Contagem do processo filho A %d\n", i);
                printf("Finalizando processo filho A\n");
            }
            else
            {
                printf("Iniciando filho D\n");
                for (i = 4000; i<= 4999; i++) printf("Contagem do processo filho D %d\n", i);
                printf("Finalizando processo filho D\n");
            }

        }
        else
        {
            printf("Iniciando filho C\n");
            for (i = 3000; i<= 3999; i++)printf("Contagem do processo filho C %d\n", i);
            printf("Finalizando processo filho C\n");
        }
    }
    return 0;
}

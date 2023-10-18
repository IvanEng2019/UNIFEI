#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(void)
{
    pid_t pid;

    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    if(pid == 0)
    {///codigo a ser executado no processo filho
        printf(" Pid do filho: %d\n",getpid());
    }
    else
    {///codigo a ser executado no processo pai
        printf(" Pid do pai: %d\n",getpid());
    }

    printf(" Esta regiao sera executada por ambos processos.\n\n");

    return 0;
}

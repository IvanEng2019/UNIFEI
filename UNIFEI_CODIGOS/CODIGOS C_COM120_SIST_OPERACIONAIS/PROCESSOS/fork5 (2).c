#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(void)
{
    pid_t pid;
    char c='a';

    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    if(pid == 0)
    {///codigo a ser executado no processo filho
        printf("caracter e endereço: %c - %p (filho)\n",c,&c);
    }
    else
    {///codigo a ser executado no processo pai
        c='b';
        printf("caracter e endereço: %c - %p (pai)\n",c,&c);
    }

    return 0;
}

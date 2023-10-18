#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("pid do Pai: %d\n", getpid());
    execv("./teste", NULL );
    printf("EU TENHO UM SEGREDO PRA CONTAR\n");
    return 0;
}

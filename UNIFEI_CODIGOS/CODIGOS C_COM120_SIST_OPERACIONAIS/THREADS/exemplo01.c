#include <stdio.h> /* standard I/O routines */
#include <pthread.h> /* pthread functions and data structures */

/* function to be executed by the new thread */
void *OLA(void *argumentos) {
    printf("\nOla\n");
    pthread_exit(NULL);
}
int main ( ){
    pthread_t thread;
    int flag, i;
    printf("A criar uma nova thread\n");
    flag = pthread_create(&thread, NULL, OLA, NULL);
    if (flag!=0)
        printf("Erro na cria��o duma nova thread\n");
    return 0; /* O programa n�o vai chegar aqui. */
}

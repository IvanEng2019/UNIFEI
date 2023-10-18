#include <stdio.h> /* standard I/O routines */
#include <pthread.h> /* pthread functions and data structures */

#define NUM_THREADS 5
void *funcao(void *argumentos){
    printf("\nOLA\n");
    return (NULL);
}
int main (){
    pthread_t threads[NUM_THREADS];
    int i;
    for(i=0;i<NUM_THREADS;i++)
        pthread_create(&threads[i], NULL, funcao, NULL);
    printf("Thread principal a esperar o termino das threads criadas \n");
    for(i=0;i<NUM_THREADS;i++)
        pthread_join(threads[i],NULL); /* Esperara a jun��o das threads */
    return 0; /* O programa chegar� aqui. */
}

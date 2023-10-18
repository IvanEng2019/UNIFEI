#include <stdio.h> /* standard I/O routines */
#include <pthread.h> /* pthread functions and data structures */

#define NUM_THREADS 5
void *funcao(void *args){
    int id;
    id = *(int *)args;
    printf("Thread %d\n",id);
    return (NULL);
}
int main (){
    pthread_t threads[NUM_THREADS];
    int i;
    for(i=0;i< NUM_THREADS;i++)
        pthread_create(&threads[i], NULL, funcao,&i);
    for(i=0;i< NUM_THREADS;i++)
        pthread_join(threads[i],NULL);
    return 0;
}

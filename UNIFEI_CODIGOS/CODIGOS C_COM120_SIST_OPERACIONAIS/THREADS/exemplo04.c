#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 5
int saldo = 1000;

void *AtualizaSaldo(void *threadid) {
    int meu_saldo = saldo;
    int novo_saldo = meu_saldo +(long)threadid *100;
    printf("Novo saldo = %d\n",novo_saldo);
    saldo = novo_saldo;
}
int main (int argc, char *argv[]){
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t=0; t<NUM_THREADS; t++){
        rc = pthread_create(&threads[t], NULL,AtualizaSaldo, (void*)t);
        if(rc)
           return -1;
    }
    for(t=0; t<NUM_THREADS; t++){
        pthread_join(threads[t], NULL);
    }
    printf("Saldo final = %d\n", saldo);
    return 0;
}

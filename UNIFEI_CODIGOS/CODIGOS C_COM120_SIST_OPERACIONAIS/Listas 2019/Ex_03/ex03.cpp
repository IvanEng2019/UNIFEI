//COM220 - Sistemas Operacionais
//Exercício Prático 02 - 09/09/2019
//PROBLEMA 1
//Nome: Jônatas Mateus da Silva  Matrícula: 2018015750
//Nome: Ivan Leoni Vilas Boas   Matrícula: 2018009073

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#define T 3

int N = 10;
int C = 5;
sem_t passageiro = C ;
sem_t car = 0;
sem_t andando = 0;
sem_t mutex = 1;
int vet[N];
int car[C];

void passageiro(void *vet) {

    while (true) {
        sem_post(&passageiro);
        *car=(int*)vet;

        /* vários passageiros podem entrar “ao mesmo tempo” */
        for (int i=0; i<C; i++){
            printf("Passageiros do carrinho:&d\n",car[i]);
        }
        sem_post(&mutex);
        N++;
        if (N == C) {  /* carrinho lotou */
            sem_wait(&carrinho);  /* autoriza carrinho a andar */
            sem_post(&andando) ;/* espera carrinho parar */
            sem_wait(&mutex);
        }
        else {
            sem_wait(&mutex);
            sem_post(&andando); /* espera carrinho lotar, passear e voltar */
        }
    }
}

void carrinho(void *vet) {
    while (true){

    sem_post(&car);
    sleep(T);    /* espera autorização para andar */
    /* faz o passeio e volta */
    N = 0;     /* esvazia carrinho */
    for (int i=0; i<C; i++){
        sem_wait(&andando); /* libera passageiro que andou de volta à fila */
        sem_wait(&passageiro); /* libera entrada no carrinho */
    }
  }
}

int main() {
     int i;
    pthread_t thread_id1;

    for(i=0;i<N;i++)//gerando num aleatorios
    {
         vet[i]=rand()%n;
         cout<<vet[i]<<" ";
    }
   sem_init(&mutex,0,1);

   for(i=0;i<N;i++){
      pthread_create(&thread_id[i], NULL, carrinho , (void*)vet);
      pthread_create(&thread_id[i], NULL, passageiro, (void*)vet);
   }

   return(0);
}

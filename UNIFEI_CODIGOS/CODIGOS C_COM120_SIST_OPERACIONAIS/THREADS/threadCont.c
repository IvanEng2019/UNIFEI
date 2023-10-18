#include<stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *cont(void *argumentos){

  int thread_identifier = *(int*) argumentos;
  int i;
  int thread_conter[NUM_THREADS];

  thread_conter[0] = 0;
  thread_conter[1] = 1000;
  thread_conter[2] = 2000;
  thread_conter[3] = 3000;
  thread_conter[4] = 4000;

  switch(thread_identifier){
    case 0:
        for(i=0; i<=999; i++){
          thread_conter[0]=i;
        }
        printf(">Sou thread [%d]- cont [%d]\n", thread_identifier, thread_conter[0]);
        break;
    case 1:
        for(i=1000; i<=1999; i++){
          thread_conter[1]=i;
        }
        printf(">Sou thread [%d]- cont [%d]\n", thread_identifier, thread_conter[1]);
        break;
    case 2:
        for(i=2000; i<=2999; i++){
          thread_conter[2]=i;
        }
        printf(">Sou thread [%d]- cont [%d]\n", thread_identifier, thread_conter[2]);
        break;
    case 3:
        for(i=3000; i<=3999; i++){
          thread_conter[3]=i;
        }
        printf(">Sou thread [%d]- cont [%d]\n", thread_identifier, thread_conter[3]);
        break;
    case 4:
        for(i=4000; i<=4999; i++){
          thread_conter[4]=i;
        }
        printf(">Sou thread [%d]- cont [%d]\n", thread_identifier, thread_conter[4]);
        break;
    default:
        printf("NÃO É POSSIVEL FAZER CONTAGEM\n");
  }
  pthread_exit(NULL);
}

int main(){

  pthread_t threads[NUM_THREADS];
  int i;
  int thread_id[NUM_THREADS];

  for(i = 0; i<5; i++)
    thread_id[i] = i;
  printf(" A criar 5 novas threads\n");
  for(i = 0; i<NUM_THREADS; i++){
    pthread_create(&threads[i], NULL, cont, &thread_id[i]);
    printf("*Thread [%d] foi criada\n", thread_id[i]);
  }

  printf("Esperando termino das [%d] threads\n", NUM_THREADS);
  for(i = 0; i<NUM_THREADS;i++){
    pthread_join(threads[i], NULL);
    printf("Threads [%d] finalizadas.\n", i);
  }
  printf(" Término.\n");
  return 0;
}

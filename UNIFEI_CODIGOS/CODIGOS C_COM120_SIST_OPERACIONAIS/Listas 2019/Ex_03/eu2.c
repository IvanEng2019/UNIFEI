#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define C 5 // Informando a quantidade de passageiros
#define P 15

sem_t passageiro; //Setando como semaforo a varivel
sem_t carrinho;
sem_t andando ;
sem_t mutex;
int Npass;
int volta;
int nVolta;

void *Passageiro() {
        while (volta>0) {
            sem_wait(&passageiro);
            printf("\nEntrando no carrinho todos passageiros\n");
            sem_wait(&mutex);
            Npass= C;
            if (Npass == C) { /* carrinho lotou */
                sem_post(&carrinho); /* autoriza carrinho a andar */
                sem_wait(&andando); /* espera carrinho parar */
                sem_post(&mutex);
        }
        else {
            sem_post(&mutex);
            sem_wait(&andando); /* espera carrinho lotar, passear e voltar */
        }
    }
}
void *Carrinho() {
        while(volta>0){
            volta--;
            sem_wait(&carrinho); /* espera autorização para andar */
            printf("Fazendo Passeio...\n"); /* faz o passeio e volta */
            nVolta++;
            printf("Passeio acabou. Deu-se %d volta(s) de %d restante(s) do dia.\nLiberando todos passageiros do carrinho.\nCarrinho liberado para nova lotação e nova volta.\n",nVolta,volta);
            for (int i=0; i<C; i++){
                sem_post(&andando); /* libera passageiro que andou de volta à fila */
                sem_post(&passageiro); /* libera entrada no carrinho */
            }
            Npass = 0; /* esvazia carrinho */
    }
}

int main(int argc, char **argv){
    Npass=0;
    volta= P/C;
    nVolta=0;
    pthread_t pass, carr;

    sem_init(&passageiro,0,P); //Inicializando o semaforo
    sem_init(&carrinho,0,C);  //Inicializando o semaforo
    sem_init(&andando,0,0);//Inicializando o semaforo
    sem_init(&mutex,0,1); //Inicializando o semaforo

    pthread_create(&pass, NULL, Passageiro, NULL); //Criando thread4
    pthread_create(&carr, NULL, Carrinho , NULL);  //Criando thread

    pthread_join(pass, NULL); //Entrando no thread
    pthread_join(carr, NULL); //Entrando no thread

    return 0;
}


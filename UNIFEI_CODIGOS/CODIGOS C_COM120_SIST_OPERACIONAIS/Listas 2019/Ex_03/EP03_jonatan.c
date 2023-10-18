/*
    Exercicio 3

    Nomes: Robert Nicolas Mendes
           Leonardo Rodrigo de Sousa

    Matricula: 2018012810
               2018015965

    Materia: Sistemas Operacionais

    Turma: Turma 02
    
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>



sem_t passageiro; //Setando como semaforo a varivel
sem_t carrinho;
sem_t andando ;
sem_t mutex;
int C = 5; // Informando a quantidade de passageiros
int Npass = 0;
int ent = 0; //informando o passeiro que entra no carrinho

void entra_no_carrinho(){//Função de inclementar os passageiros no carrinho
    ent ++;
    printf("\nEntrando - %d!!!",ent);
    
}

void passeia(){//Imprimindo quando lota o carrinho
    printf("\nCurtindo!!");
}

void *Passageiro() {
        while (1) {
            sem_wait(&passageiro);
            entra_no_carrinho(); /* vários passageiros podem entrar “ao mesmo tempo” */
            sem_wait(&mutex);
            Npass++;
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
        while (1){
            sem_wait(&carrinho); /* espera autorização para andar */
            passeia(); /* faz o passeio e volta */
            Npass = 0; /* esvazia carrinho */
            for (int i=0; i<C; i++){
                sem_post(&andando); /* libera passageiro que andou de volta à fila */
                sem_post(&passageiro); /* libera entrada no carrinho */
        }
        ent=0;
    }
}

int main(int argc, char **argv){
    
    pthread_t pass, carr;
    
    
    sem_init(&passageiro,C,1); //Inicializando o semaforo
    sem_init(&carrinho,0,1);  //Inicializando o semaforo
    sem_init(&andando,0,1);//Inicializando o semaforo
    sem_init(&mutex,1,1); //Inicializando o semaforo
    
    pthread_create(&pass, NULL, Passageiro, NULL); //Criando thread
    pthread_create(&carr, NULL, Carrinho , NULL);  //Criando thread
    pthread_join(pass, NULL); //Entrando no thread
    pthread_join(carr, NULL); //Entrando no thread
    
    
}


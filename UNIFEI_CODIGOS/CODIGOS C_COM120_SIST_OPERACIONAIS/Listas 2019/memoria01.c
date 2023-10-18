// memoria 01

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
#include <pthread.h>

#define QTD_Thread 4//Quantidade de Processos que vao ser criados

int memoria[100];

int geratam(){
    srand(time(NULL));
    return 2 + rand() % ( 35 - 2 ) ;
}

int geratem(){
    srand(time(NULL));
    return 2 + rand() % ( 5 - 2 ) ;
}

//Funcao que roda uma vez, zerando o vetor de 100 posicoes
void zeramemo(){
    int  i = 0;
    for (i = 0; i < 100; i ++) {
        memoria[i] = 0;
    }

}

void mostramemo(){
    int  i = 0;
    for (i = 0; i < 100; i ++) {
        printf(" %d", memoria[i]);
    }
    printf("\n");
}

//funcao que vai rodar paralelamente escolhendo os lugares
void *funcao(void *thread_id){
    int *ident;
    ident = thread_id;

    int tempo = geratem(), tamanho = geratam();
    //Aqui tem que criar o tamanho e o tempo, antes, 
    //acha o primeiro espaco livre, se nao tiver, chama de novo a propria funcao;

    // Tem que achar o primeiro espaco livre que cabe, guarda o indice do primeiro,
    printf("%d %d %d\n",*ident, geratem(), geratam());

    return NULL;//Para evitar bug no XCODE
}

int main(){
    //verifica tambem se os valores estao entre -1 e 10

    zeramemo();
    mostramemo();

    pthread_t threads[QTD_Thread];//criamos um vetor de thread usando o TAD phtread_t
    int i, qtd[QTD_Thread];

    //chamei 27 vezes
    for (i = 0; i < QTD_Thread; i++) {
        qtd[i] = i + 1;// para variar de 1 ate 3
        pthread_create(&threads[i], NULL, funcao, (void *)&qtd[i]);//funcao para criacao das threads
        //Endereco de memoria da thread/ parametro nulo/ funcao que ela vai executar/ e o argumento da funcao
    }

    //laco para esperar as threads retornarem para depois verificar se os blocos, linhas e colunas estão ok
    for (i = 0; i < QTD_Thread; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

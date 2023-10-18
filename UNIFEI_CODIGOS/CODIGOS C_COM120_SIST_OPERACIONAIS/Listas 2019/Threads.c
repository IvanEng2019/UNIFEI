//  Threads

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QTD_Thread 8//Quantidade de threads a ser usada

void tempo(int laco){//so para gastar um pouquinho de tempo tempo
    int a, b, c;
    for (a = 0; a < laco; a++)
        for (b = 0; b < laco; b++)
            for (c = 0; c < laco; c++)
                laco = laco;
}

void *funcao(void *thread_id){
    int *ident;
    ident = thread_id;
    printf("• Thread %i\n", *ident);//alerta inicio
    tempo(1000);
    printf("o Thread %i\n", *ident);//alerta fim
    return NULL;//Para evitar bug no XCODE
}

int main(int argc, const char * argv[]) {
    pthread_t threads[QTD_Thread];//criamos um vetor de thread usando o TAD phtread_t
    int i, qtd[QTD_Thread];

    for (i = 0; i < QTD_Thread; i++) {
        qtd[i] = i + 1;
        pthread_create(&threads[i], NULL, funcao, (void *)&qtd[i]);//funcao para criacao das threads
        //Endereco de memoria da thread/ parametro nulo/ funcao que ela vai executar/ e o argumento da funcao
    }

    //laco para esperar as threads retornarem para depois seguir em frente
    for (i = 0; i < QTD_Thread; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("\n");
    return 0;
}

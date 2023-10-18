// Memoria 02

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>

#define qtd_processos 5//Quantidade de Processos que vao ser criados

int memoria[100];

//Funcao que gera numero entre 2 e 35 mb
int geratam(){
    srand(time(NULL));
    return 2 + rand() % ( 35 - 2 ) ;
}

//Funcao que gera numero entre 2 e 5 segundos
int geratem(){
    srand(time(NULL));
    return 2 + rand() % ( 5 - 2 ) ;
}

//Funcao vai ficar retornando para ela msm, se nao tiver espaco livre, depois de um segundo

int main(int argc, const char * argv[]) {
    // Vetor com quantidade de memória
    int i = 0, w = 0, tamanho, tempo;
    
    //Zerando o vetor de memoria
    for (i = 0; i < 100; i++) {
        memoria[i] = 0;
    }

    for (w = 1; w <= qtd_processos; w++) {
        tamanho = geratam();
        tempo = geratem();
        printf("%d\n",w);
    }

    i = geratam();
    printf("%d\n",i);

    //sleep(5);

    i = geratem();
    printf("%d\n",i);
    return 0;
}

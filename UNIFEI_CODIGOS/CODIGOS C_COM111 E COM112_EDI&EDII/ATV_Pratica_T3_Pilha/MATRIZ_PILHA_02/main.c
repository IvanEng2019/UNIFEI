//  Atividade Prática T3
//  COM111 - Algoritmo e Estrutura de Dados I
//  Prof Elisa de Cássia Silva Rodrigues


#include "com111_pilhade.h"

//Funcao principal
int main(int argc, const char * argv[]) {
    
    elemento *PILHA = (elemento *) malloc(sizeof(elemento));
    if(!PILHA){
        printf("Memoria Insuficiente!\n");
        exit(1);
    }else{ // Inicializa pilha
        inicia(PILHA);
        int opt;
        
        do{
            opt=menu();
            opcao(PILHA,opt);
        }while(opt);
        
        free(PILHA);
        return 0;
    }
}

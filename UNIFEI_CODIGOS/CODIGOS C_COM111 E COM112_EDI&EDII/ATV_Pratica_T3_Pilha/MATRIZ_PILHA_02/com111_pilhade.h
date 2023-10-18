//  com111_pilhade.h
//  Atividade Prática T3
//  COM111 - Algoritmo e Estrutura de Dados I
//  Prof Elisa de Cássia Silva Rodrigues

#ifndef com111_pilhade_h
#define com111_pilhade_h

#include <stdio.h>
#include <stdlib.h>
//Escopos funcoes
int menu(void);

//Estrutura tipo no
struct Elemento{
    double mat[3][3];
    struct Elemento *prox;
};

//Macro nome
typedef struct Elemento elemento;


void inicia(elemento *PILHA);
void opcao(elemento *PILHA, int op);
void exibe(elemento *PILHA);
void libera(elemento *PILHA);
int empilhar(elemento *PILHA);
elemento *desempilhar(elemento *PILHA);

#endif /* com111_pilhade_h */

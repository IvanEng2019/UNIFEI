#ifndef _ARVORE_BIN_H
#define _ARVORE_BIN_H

typedef struct no* arvBin;

arvBin* cria_arvore();
void libera_no(struct no* NO);
void libera_arvore(arvBin *raiz);
int altura(arvBin* raiz);
int inserir(arvBin* raiz, int dado);
int pre_ordem(arvBin* raiz);
int ordem(arvBin* raiz);
int pos_ordem(arvBin* raiz);

#endif
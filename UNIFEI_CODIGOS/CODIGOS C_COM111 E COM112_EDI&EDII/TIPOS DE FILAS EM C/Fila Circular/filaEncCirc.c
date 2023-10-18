
#include <stdio.h>
#include <stdlib.h>
#include "filaEncCirc.h"

struct elemento{
  int dado;
  struct elemento *prox;
};

typedef struct elemento Elemento;

struct descritor{
    Elemento *inicio;
    Elemento *fim;
    int qtd;
};

typedef struct descritor Fila;

Fila* criar_fila_circ(){
  Fila *li = (Fila*) malloc(sizeof(Fila));
  if(li!= NULL){
    li->fim=NULL;
    li->inicio=NULL;
    li->qtd=0;
    return li;
  }
  else
    return NULL;
}

int liberar_fila(Fila *li){
  if(li == NULL)
    return 0;
  Elemento *no;
  while(li->qtd>0){
      no = li->inicio;
      li->inicio= no->prox;
      free(no);
      (li->qtd)--;
  }
  free(li);
  li=NULL;
  return 1;
}

int tamanho_fila(Fila*li){
    if(li==NULL)
        return -1;
    return li->qtd;
}

int fila_vazia(Fila *li){
  if(li->inicio == NULL || li->qtd== 0)
    return 1;
  if(li == NULL)
    return -1;
  return 0;
}

Elemento* criar_elemento(){
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));
  if(no == NULL)
    return 0;
  return no;
}

int enfileirar(Fila *li, int dado){
  if(li == NULL)
    return 0;
  Elemento *no= criar_elemento();
  no->dado = dado;
  if( li->inicio == NULL ){
     li->inicio=no;
     no->prox=no;
  }
  else{
     (li->fim)->prox= no;
      no->prox=li->inicio;
  }
  li->fim=no;
  (li->qtd)++;
  return 1;
}

int desinfileirar (Fila *li){
  if(li == NULL)
    return -1;
  if (li->inicio==NULL)
    return 0;
  Elemento *ini=li->inicio;
  if(ini->prox!=li->inicio){
    li->inicio = ini->prox;
    li->fim->prox=li->inicio;

  }else{
    li->fim=NULL;
    li->inicio=NULL;
  }
  free(ini);
  (li->qtd)--;
  return 1;
}

int imprime_fila(Fila *li){
    if(li==NULL )
        return -1;
    if(li->inicio==NULL)
        return 0;
    Elemento *no= li->inicio;
    while (no->prox!=li->inicio){
        printf("%d\n",no->dado);
        no=no->prox;
    }
    printf("%d\n",no->dado);
    return 1;
}

int pesquisa_fila_primeiro(Fila *li){
    if(li==NULL || li->inicio==NULL)
        return 0;
    else
        return li->inicio->dado;
}


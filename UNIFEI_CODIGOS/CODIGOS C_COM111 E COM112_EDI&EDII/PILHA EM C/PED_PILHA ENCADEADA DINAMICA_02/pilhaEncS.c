
#include <stdio.h>
#include <stdlib.h>
#include "pilhaEncS.h"

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

typedef struct descritor Pilha;

Pilha* criar_pilha(){
  Pilha *li = (Pilha*) malloc(sizeof(Pilha));
  if(li!= NULL){
    li->fim=NULL;
    li->inicio=NULL;
    li->qtd=0;
    return li;
  }
  else
    return NULL;
}

int liberar_pilha(Pilha*li){
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

int tamanho_pilha(Pilha*li){
    if(li==NULL)
        return -1;
    return li->qtd;
}

int pila_vazia(Pilha *li){
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

int enfileirar(Pilha *li, int dado){
  if(li == NULL)
    return 0;
  Elemento *no= criar_elemento();
  no->dado = dado;
  no->prox = NULL;
  if( li->inicio == NULL )
     li->inicio=no;
  else
     (li->fim)->prox= no;
  li->fim=no;
  (li->qtd)++;
  return 1;
}

int desinfileirar (Pilha *li){
  if(li == NULL)//não existe pilha
    return -1;
  Elemento *no=li->inicio;
  if (no==NULL)//existe e esta vazia
    return 0;
  if(no->prox==NULL){//Elimina o unico elemento e fica vazia
     free(no);
     li->fim=NULL;
     li->inicio=NULL;
     li->qtd=0;
     return 1;
  }
  Elemento*ant,*del;
  while(no->prox!=NULL){
        ant=no;
        no=no->prox;
  }
  del=li->fim;
  li->fim = ant;
  ant->prox=NULL;
  free(del);
  (li->qtd)--;
  return 1;
}

int imprime_pilha(Pilha *li){
    if(li==NULL || li->inicio==NULL)
        return 0;
    Elemento *no= li->inicio;
    while (no!=NULL){
        printf("%d\n",no->dado);
        no=no->prox;
    }
    return 1;
}

int pesquisa_pilha_ultimo(Pilha *li){
    if(li==NULL || li->inicio==NULL)
        return 0;
    else
        return li->fim->dado;
}


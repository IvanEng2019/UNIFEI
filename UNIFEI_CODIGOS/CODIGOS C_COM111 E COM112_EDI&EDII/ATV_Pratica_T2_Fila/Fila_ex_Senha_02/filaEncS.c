#include <stdio.h>
#include <stdlib.h>
#include "FILAENCS.h"

// definicao do struct elemento
struct elemento{
  int dado;
  char tipAt;
  char perfCli;
  struct elemento *prox;
};

// definicao de tipos abstratos
typedef struct elemento Elemento;

struct descritor{
    Elemento *inicio;
    Elemento *fim;
    int qtd;
};

typedef struct descritor Fila;

Fila* criar_fila(){
  Fila *li = (Fila*) malloc(sizeof(Fila));
  if(li!= NULL){
    li->fim=NULL;
    li->inicio=NULL;
    li->qtd=0;
  }
  else
    return NULL;
  return li;
}

void liberar_fila(Fila *li){
  if(li != NULL){
    Elemento *no;
    while( li!= NULL ){
      no = li->inicio;
      li->inicio= li->inicio->prox;
      free(no);
    }
    free(li);
    li=NULL;
  }
}

int tamanho_fila(Fila*li){
  return li->qtd;
}

int fila_vazia(Fila *li){
  if(li->inicio == NULL)
    return 1;
  if(li->qtd== 0)
    return 1;
  if(li == NULL)
    return 1;
  return 0;
}

Elemento* criar_elemento(){
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));
  if(no == NULL)
    return 0;
  return no;
}

int preenche_senha(Fila *li,Fila *SE, char ta, char cp){
          if( SE!=NULL){
                if(li->qtd==0 && SE->qtd!=0){
                  li->inicio=SE->inicio;
                  li->fim=SE->inicio;
                  SE->inicio=SE->inicio->prox;
                  li->inicio->prox=NULL;
                }
                else{
                   li->fim->prox=SE->inicio;
                   li->fim=SE->inicio;
                   SE->inicio=SE->inicio->prox;
                }
                li->fim->perfCli=cp;
                li->fim->tipAt=ta;
                SE->qtd--;
                li->qtd++;
                if(SE->qtd==0){
                    free(SE);
                }
                return 1;
          }
          return 0;
}

int enfileirar(Fila *li, int dado){
  if(li == NULL && li->inicio == NULL)
    return 0;
  Elemento *no= criar_elemento();
  no->dado = dado;
  no->prox = NULL;
  if( li->inicio == NULL ){
     li->inicio=no;
     li->fim=no;
     li->qtd=1;
  }
  else
     (li->fim)->prox= no;
  return 1;
}

int desinfileirar (Fila *li){
  if(li == NULL || li->inicio==NULL)
    return 0;
  Elemento *ini=li->inicio;
  li->inicio = (li->inicio)->prox;
  free(ini);
  return 1;
}

int imprime_senha(Fila *li){
    if(li==NULL || li->inicio==NULL)
        return 0;
    printf(" %c %c %d\n",li->inicio->perfCli,li->inicio->tipAt,li->inicio->dado);
    return 1;
}

int imprime_fila(Fila *li){
    if(li==NULL || li->inicio==NULL)
        return 0;
    Elemento *no= li->inicio;
    while (no->prox!=NULL){
        printf(" %c %c %d\n",no->perfCli,no->tipAt,no->dado);
        no=no->prox;
    }
    return 1;
}


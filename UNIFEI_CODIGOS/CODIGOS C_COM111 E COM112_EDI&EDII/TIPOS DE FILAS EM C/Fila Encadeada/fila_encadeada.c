
#include <stdio.h>
#include <stdlib.h>
#include "fila_encadeada.h"


// definição do tipo lista
struct fila{
  int qtd;
  struct elemento *inicio;
  struct elemento *fim;
};//no descreitor

typedef struct elemento{
    int dado;
    struct elemento *prox;
}Elemento;


//**************************************************************************
// função para alocar memória do tipo Lista
Fila* criar_fila()
{
  // 'li' é um ponteiro do tipo Lista
  Fila *fi = (Fila*) malloc(sizeof(Fila));

  // se a alocação estiver correta qtd da lista é zero
  if(fi != NULL){
    fi->inicio = NULL;
    fi->fim = NULL;
    fi->qtd = 0;

  }

  return fi;
}


//**************************************************************************
// função para liberar memória
int liberar_fila(Fila *fi)
{
  // verifica se a lista foi alocada corretamente
  if(fi == NULL){
    return 0;
  }
   Elemento *no, *aux;
   aux = fi->inicio;
   while((aux->prox) != NULL){
    no = aux;
    aux = aux->prox;
    free(no);
   }
  // libera o ponteiro (Lista)
  free(fi);

  return 1;
}

//**************************************************************************
// função para obter o tamanho da lista
int tamanho_fila(Fila *fi)
{
  // verifica se a lista foi alocada corretamente
  if(fi == NULL){
    return -1;
  }else{
      // retorna a quantidade de elementos da lista
      return fi->qtd;
  }
}

//**************************************************************************
// função para verificar se a lista está vazia
int fila_vazia(Fila *fi)
{
  // verifica se houve problema na criação da lista
  // ou seja, 'li' não é uma lista válida
  if(fi == NULL){
    return -1;
  }

  // verifica se a lista esta vazia
  if(fi->qtd == 0){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}

Elemento* alocar_dado(){
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));
  if(no == NULL)
    return 0;
  return no;
}

//**************************************************************************
// função para inserir elemento no final da lista
int inserir_fila(Fila *fi, int dado)
{
  // verifica se a lista foi criada corretamente
  Elemento *no;
  no = alocar_dado();
  no->dado = dado;
  no->prox = NULL;

  if(fi == NULL){
    return 0;
  }

  else if((fila_vazia(fi)) == 1){
    fi->inicio = no;
    fi->fim = no;
    fi->qtd++;
  }

  else{
    Elemento *aux;
    aux = fi->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = no;
    fi->fim = no;
    fi->qtd++;
  }

  return 1;
}

// função para remover o elemento do início da lista
int remover_fila(Fila *fi)
{
  // verifica se a lista foi criada corretamente
  if(fi == NULL){
    return 0;
  }

  // verifica se a lista esta vazia
  if(fila_vazia(fi) == 1){
    return 0;
  }

  Elemento *no, *aux;
  no = fi->inicio;
  aux = no->prox;
  fi->inicio = aux;
  free(no);

  return 1;
}


int buscar_fila(Fila *fi){
    Elemento *no;
    no = fi->inicio;
    if(fi == NULL)
      return 0;
    else
        return no->dado;
}


//**************************************************************************
// função para imprimir a lista estática
int imprimir_fila(Fila *fi)
{
    if(fi == NULL || fi->inicio == NULL){
      return 0;
    }

    Elemento *aux;
    aux = fi->inicio;

    while(aux->prox != NULL){
      printf(" %d ", aux->dado);
      aux = aux->prox;
    }

    printf(" %d ", aux->dado);

    return 1;
}




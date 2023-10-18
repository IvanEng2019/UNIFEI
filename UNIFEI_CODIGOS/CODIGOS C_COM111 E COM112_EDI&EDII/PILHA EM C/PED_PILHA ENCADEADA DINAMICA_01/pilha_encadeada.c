
#include <stdio.h>
#include <stdlib.h>
#include "pilha_encadeada.h"

typedef struct elemento{
    int dado;
    struct elemento *prox;
}Elemento;


//**************************************************************************
// função para alocar memória do tipo Lista
Pilha* criar_pilha()
{
  // 'li' é um ponteiro do tipo Lista
  Pilha *pi = (Pilha*) malloc(sizeof(Pilha));

  // se a alocação estiver correta qtd da lista é zero
  if(pi != NULL){
    (*pi) = NULL;

  }

  return pi;
}


//**************************************************************************
// função para liberar memória
int liberar_pilha(Pilha *pi)
{
  // verifica se a lista foi alocada corretamente
  if(pi == NULL){
    return 0;
  }
   Elemento *no, *aux;
   aux = (*pi);
   while((aux->prox) != NULL){
     no = aux;
     aux = aux->prox;
     free(no);
   }
  // libera o ponteiro (Lista)
  free(pi);

  return 1;
}

//**************************************************************************
// função para obter o tamanho da lista
int tamanho_pilha(Pilha *pi)
{
  Elemento *aux; int i;
  aux = (*pi);
  // verifica se a lista foi alocada corretamente
  if(pi == NULL){
    return -1;
  }else{
    while(aux->prox != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
  }
}

//**************************************************************************
// função para verificar se a lista está vazia
int pilha_vazia(Pilha *pi)
{
  // verifica se houve problema na criação da lista
  // ou seja, 'li' não é uma lista válida
  if(pi == NULL){
    return -1;
  }

  // verifica se a lista esta vazia
  if((*pi) == NULL){
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
int inserir_pilha(Pilha *pi, int dado)
{
  // verifica se a lista foi criada corretamente
  Elemento *no;
  no = alocar_dado();
  no->dado = dado;
  no->prox = NULL;

  if(pi == NULL){
    return 0;
  }

  else if((pilha_vazia(pi)) == 1){
    (*pi) = no;
  }

  else{
    Elemento *aux;
    aux = (*pi);
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = no;
  }

  return 1;
}

// função para remover o elemento do início da lista
int remover_pilha(Pilha *pi)
{
  // verifica se a lista foi criada corretamente
  if(pi == NULL){
    return 0;
  }

  // verifica se a lista esta vazia
  if(pilha_vazia(pi) == 1){
    return 0;
  }

  Elemento *aux;
  aux = (*pi);
  Elemento *ant;
  while(aux->prox != NULL){
    ant = aux;
    aux = aux->prox;
  }
  free(aux);
  ant->prox = NULL;
  return 1;
}


int buscar_pilha(Pilha *pi){
    Elemento *aux;
    aux = (*pi);

    if(pi == NULL)
      return 0;

    else{
        while(aux->prox != NULL)
            aux = aux->prox;
    }
    return aux->dado;

}


//**************************************************************************
// função para imprimir a lista estática
int imprimir_pilha(Pilha *pi)
{
    if(pi == NULL || (*pi) == NULL){
      return 0;
    }

    Elemento *aux;
    aux = (*pi);

    while(aux->prox != NULL){
      printf(" %d ", aux->dado);
      aux = aux->prox;
    }

    printf(" %d ", aux->dado);

    return 1;
}





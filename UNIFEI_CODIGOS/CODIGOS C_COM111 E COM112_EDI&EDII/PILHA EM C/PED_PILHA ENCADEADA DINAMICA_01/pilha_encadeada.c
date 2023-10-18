
#include <stdio.h>
#include <stdlib.h>
#include "pilha_encadeada.h"

typedef struct elemento{
    int dado;
    struct elemento *prox;
}Elemento;


//**************************************************************************
// fun��o para alocar mem�ria do tipo Lista
Pilha* criar_pilha()
{
  // 'li' � um ponteiro do tipo Lista
  Pilha *pi = (Pilha*) malloc(sizeof(Pilha));

  // se a aloca��o estiver correta qtd da lista � zero
  if(pi != NULL){
    (*pi) = NULL;

  }

  return pi;
}


//**************************************************************************
// fun��o para liberar mem�ria
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
// fun��o para obter o tamanho da lista
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
// fun��o para verificar se a lista est� vazia
int pilha_vazia(Pilha *pi)
{
  // verifica se houve problema na cria��o da lista
  // ou seja, 'li' n�o � uma lista v�lida
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
// fun��o para inserir elemento no final da lista
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

// fun��o para remover o elemento do in�cio da lista
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
// fun��o para imprimir a lista est�tica
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






// TAD para Fila Estatica

#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

#define MAX 100

// definição do tipo fila
struct fila{
  int qtd, inicio, fim;
  int dados[MAX];
};


//**************************************************************************
// função para alocar memória do tipo fila
Fila* criar_fila()
{
  Fila *fi = (Fila*) malloc(sizeof(Fila));

  if(fi != NULL){
    fi->qtd = 0;
    fi->inicio = 0;
    fi->fim = 0;
  }

  return fi;
}


//**************************************************************************
// função para liberar memória
int liberar_fila(Fila *fi)
{
  if(fi == NULL){
    return 0;
  }

  free(fi);

  return 1;
}

//**************************************************************************
// função para obter o tamanho da fila
int tamanho_fila(Fila *fi)
{
  if(fi == NULL){
    return -1;
  }else{
      return fi->qtd;
  }
}

//**************************************************************************
// função para verificar se a fila está vazia
int fila_vazia(Fila *fi)
{
  if(fi == NULL){
    return -1;
  }

  if(fi->qtd == 0){
    return 1;
  }

  return 0;
}


//**************************************************************************
// função para verificar se a fila está cheia
int fila_cheia(Fila *fi)
{
  if(fi == NULL){
    return -1;
  }

  if(fi->qtd == MAX){
    return 1;
  }

  return 0;
}




//**************************************************************************
// função para inserir elemento no final da fila
int inserir_fila(Fila *fi, int dado)
{
  if(fi == NULL){
    return 0;
  }

  if(fila_cheia(fi) == 1){
    return 0;
  }

  fi->dados[fi->fim] = dado;

  fi->qtd++;
  fi->fim++;

  return 1;
}

// função para remover o elemento do início da lista
int remover_fila(Fila *fi)
{
  if(fi == NULL){
    return 0;
  }

  if(fila_vazia(fi) == 1){
    return 0;
  }

  fi->inicio++;
  fi->qtd--;

  return 1;
}

//**************************************************************************
// Funcao para mostrar qual o primeiro elemento da fila
int buscar_fila(Fila *fi){
    if(fi == NULL)
      return 0;
    else
        return fi->dados[fi->inicio];
}


//**************************************************************************
// função para imprimir a fila estática
int imprimir_fila(Fila *fi)
{
  // verifica se a lista foi criada corretamente
  if(fi == NULL){
    return 0;
  }

  for(int i=fi->inicio; i<fi->fim; i++){
    printf("%d ", fi->dados[i]);
  }

  return 1;
}



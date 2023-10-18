
// TAD para Fila Estatica

#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

#define MAX 100

// defini��o do tipo fila
struct fila{
  int qtd, inicio, fim;
  int dados[MAX];
};


//**************************************************************************
// fun��o para alocar mem�ria do tipo fila
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
// fun��o para liberar mem�ria
int liberar_fila(Fila *fi)
{
  if(fi == NULL){
    return 0;
  }

  free(fi);

  return 1;
}

//**************************************************************************
// fun��o para obter o tamanho da fila
int tamanho_fila(Fila *fi)
{
  if(fi == NULL){
    return -1;
  }else{
      return fi->qtd;
  }
}

//**************************************************************************
// fun��o para verificar se a fila est� vazia
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
// fun��o para verificar se a fila est� cheia
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
// fun��o para inserir elemento no final da fila
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

// fun��o para remover o elemento do in�cio da lista
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
// fun��o para imprimir a fila est�tica
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



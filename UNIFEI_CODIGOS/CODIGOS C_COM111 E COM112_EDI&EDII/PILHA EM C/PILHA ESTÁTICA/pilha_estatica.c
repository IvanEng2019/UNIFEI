
// TAD para Lista Din�mica Encadeada Circular

#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

#define MAX 100

// defini��o do tipo lista
struct pilha{
  int qtd;
  int dados[MAX];
};


//**************************************************************************
// fun��o para alocar mem�ria do tipo Lista
Pilha* criar_pilha()
{
  // 'li' � um ponteiro do tipo Lista
  Pilha *pi = (Pilha*) malloc(sizeof(Pilha));

  // se a aloca��o estiver correta qtd da lista � zero
  if(pi != NULL){
    pi->qtd = 0;

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

  // libera o ponteiro (Lista)
  free(pi);

  return 1;
}

//**************************************************************************
// fun��o para obter o tamanho da lista
int tamanho_pilha(Pilha *pi)
{
  // verifica se a lista foi alocada corretamente
  if(pi == NULL){
    return -1;
  }else{
      // retorna a quantidade de elementos da lista
      return pi->qtd;
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
  if(pi->qtd == 0){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


//**************************************************************************
// fun��o para verificar se a lista est� cheia
int pilha_cheia(Pilha *pi)
{
  // verifica se houve problema na cria��o da lista
  // ou seja, 'li' n�o � uma lista v�lida
  if(pi == NULL){
    return -1;
  }

  // verifica se a lista esta cheia
  if(pi->qtd == MAX){
    return 1;
  }

  // se n�o estiver cheia, retorna 0
  return 0;
}




//**************************************************************************
// fun��o para inserir elemento no final da lista
int inserir_pilha(Pilha *pi, int dado)
{
  // verifica se a lista foi criada corretamente
  if(pi == NULL){
    return 0;
  }

  // verifica se a lista esta cheia
  if(pilha_cheia(pi) == 1){
    return 0;
  }

  // insere o dado na posi��o logo ap�s o �ltimo elemento do vetor
  pi->dados[pi->qtd] = dado;

  // incrementa quantidade de elementos
  pi->qtd++;

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

  // movimenta uma posi��o para tr�s, todos os elementos depois do primeiro
  pi->qtd--;

  return 1;
}


int buscar_pilha(Pilha *pi){
    if(pi == NULL)
      return 0;
    else
        return pi->dados[pi->qtd-1];
}


//**************************************************************************
// fun��o para imprimir a lista est�tica
int imprimir_pilha(Pilha *pi)
{
  // verifica se a lista foi criada corretamente
  if(pi == NULL){
    return 0;
  }

  for(int i=0; i<pi->qtd; i++){
    printf("%d ", pi->dados[i]);
  }

  return 1;
}





// TAD para Lista Dinâmica Encadeada Circular

#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

#define MAX 100

// definição do tipo lista
struct pilha{
  int qtd;
  int dados[MAX];
};


//**************************************************************************
// função para alocar memória do tipo Lista
Pilha* criar_pilha()
{
  // 'li' é um ponteiro do tipo Lista
  Pilha *pi = (Pilha*) malloc(sizeof(Pilha));

  // se a alocação estiver correta qtd da lista é zero
  if(pi != NULL){
    pi->qtd = 0;

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

  // libera o ponteiro (Lista)
  free(pi);

  return 1;
}

//**************************************************************************
// função para obter o tamanho da lista
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
// função para verificar se a lista está vazia
int pilha_vazia(Pilha *pi)
{
  // verifica se houve problema na criação da lista
  // ou seja, 'li' não é uma lista válida
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
// função para verificar se a lista está cheia
int pilha_cheia(Pilha *pi)
{
  // verifica se houve problema na criação da lista
  // ou seja, 'li' não é uma lista válida
  if(pi == NULL){
    return -1;
  }

  // verifica se a lista esta cheia
  if(pi->qtd == MAX){
    return 1;
  }

  // se não estiver cheia, retorna 0
  return 0;
}




//**************************************************************************
// função para inserir elemento no final da lista
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

  // insere o dado na posição logo após o último elemento do vetor
  pi->dados[pi->qtd] = dado;

  // incrementa quantidade de elementos
  pi->qtd++;

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

  // movimenta uma posição para trás, todos os elementos depois do primeiro
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
// função para imprimir a lista estática
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




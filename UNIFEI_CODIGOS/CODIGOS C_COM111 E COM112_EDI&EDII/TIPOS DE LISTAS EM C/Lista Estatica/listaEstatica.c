
// TAD para Lista Dinâmica Encadeada Circular

#include <stdio.h>
#include <stdlib.h>
#include "listaEstatica.h"

#define MAX 100

// definição do tipo lista
struct lista{
  int qtd;
  int dados[MAX];
};


//**************************************************************************
// função para alocar memória do tipo Lista
Lista* criar_lista()
{
  // 'li' é um ponteiro do tipo Lista
  Lista *li = (Lista*) malloc(sizeof(Lista));

  // se a alocação estiver correta qtd da lista é zero
  if(li != NULL){
    li->qtd = 0;
  }

  return li;
}


//**************************************************************************
// função para liberar memória
int liberar_lista(Lista *li)
{
  // verifica se a lista foi alocada corretamente
  if(li == NULL){
    return 0;
  }

  // libera o ponteiro (Lista)
  free(li);

  return 1;
}

//**************************************************************************
// função para obter o tamanho da lista
int tamanho_lista(Lista *li)
{
  // verifica se a lista foi alocada corretamente
  if(li == NULL){
    return -1;
  }else{
      // retorna a quantidade de elementos da lista
      return li->qtd;
  }
}

//**************************************************************************
// função para verificar se a lista está vazia
int lista_vazia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, 'li' não é uma lista válida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista esta vazia
  if(li->qtd == 0){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


//**************************************************************************
// função para verificar se a lista está cheia
int lista_cheia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, 'li' não é uma lista válida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista esta cheia
  if(li->qtd == MAX){
    return 1;
  }

  // se não estiver cheia, retorna 0
  return 0;
}



//**************************************************************************
// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, int dado)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

   // verifica se a lista esta cheia
  if(lista_cheia(li) == 1){
    return 0;
  }

  // movimenta todos os elementos da lista uma posição para frente
  for(int i=li->qtd-1; i>=0; i--){
    li->dados[i+1] = li->dados[i];
  }

  // insere o dado na primeira posição do vetor
  li->dados[0] = dado;

  // incrementa quantidade de elementos
  li->qtd++;

  return 1;
}


//**************************************************************************
// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, int dado)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista esta cheia
  if(lista_cheia(li) == 1){
    return 0;
  }

  // insere o dado na posição logo após o último elemento do vetor
  li->dados[li->qtd] = dado;

  // incrementa quantidade de elementos
  li->qtd++;

  return 1;
}


//**************************************************************************
// função para inserir elemento no final da lista
int inserir_lista_ordenada(Lista *li, int dado)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista esta cheia
  if(lista_cheia(li) == 1){
    return 0;
  }

  // percorre a lista, enquanto houver elementos, e o dado da lista for menor que o dado a ser inserido
  int k, i = 0;
  while(i < li->qtd && li->dados < dado){
    i++;
  }

  // movimenta uma posição para frente, todos os elementos que estão depois da posição i, onde o novo elemento será inserido
  for(int i=li->qtd-1; i>=i; i--){
    li->dados[i+1] = li->dados[i];
  }

  // insere o dado na posição logo após o último elemento do vetor
  li->dados[i] = dado;

  // incrementa quantidade de elementos
  li->qtd++;

  return 1;
}

int buscar_lista_posicao(Lista *li,int pos){
    if(li == NULL)
      return 0;
    if(li == NULL || pos<=0 || pos > li->qtd)
      return 0;
    pos = li->dados[pos-1];
    return pos;
}

int buscar_lista_dado(Lista *li, dado){
    int i;
    if(li == NULL){
      return 0;
    for(i=0;i<=li->qtd;i++){

    }
}
//**************************************************************************
// função para imprimir a lista estática
int imprimir_lista(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  for(int i=0; i<li->qtd; i++){
    printf("%d ", li->dados[i]);
  }

  return 1;
}


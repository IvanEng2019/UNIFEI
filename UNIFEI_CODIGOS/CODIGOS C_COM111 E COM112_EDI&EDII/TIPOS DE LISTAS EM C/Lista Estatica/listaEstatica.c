
// TAD para Lista Din�mica Encadeada Circular

#include <stdio.h>
#include <stdlib.h>
#include "listaEstatica.h"

#define MAX 100

// defini��o do tipo lista
struct lista{
  int qtd;
  int dados[MAX];
};


//**************************************************************************
// fun��o para alocar mem�ria do tipo Lista
Lista* criar_lista()
{
  // 'li' � um ponteiro do tipo Lista
  Lista *li = (Lista*) malloc(sizeof(Lista));

  // se a aloca��o estiver correta qtd da lista � zero
  if(li != NULL){
    li->qtd = 0;
  }

  return li;
}


//**************************************************************************
// fun��o para liberar mem�ria
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
// fun��o para obter o tamanho da lista
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
// fun��o para verificar se a lista est� vazia
int lista_vazia(Lista *li)
{
  // verifica se houve problema na cria��o da lista
  // ou seja, 'li' n�o � uma lista v�lida
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
// fun��o para verificar se a lista est� cheia
int lista_cheia(Lista *li)
{
  // verifica se houve problema na cria��o da lista
  // ou seja, 'li' n�o � uma lista v�lida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista esta cheia
  if(li->qtd == MAX){
    return 1;
  }

  // se n�o estiver cheia, retorna 0
  return 0;
}



//**************************************************************************
// fun��o para inserir elemento no in�cio da lista
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

  // movimenta todos os elementos da lista uma posi��o para frente
  for(int i=li->qtd-1; i>=0; i--){
    li->dados[i+1] = li->dados[i];
  }

  // insere o dado na primeira posi��o do vetor
  li->dados[0] = dado;

  // incrementa quantidade de elementos
  li->qtd++;

  return 1;
}


//**************************************************************************
// fun��o para inserir elemento no final da lista
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

  // insere o dado na posi��o logo ap�s o �ltimo elemento do vetor
  li->dados[li->qtd] = dado;

  // incrementa quantidade de elementos
  li->qtd++;

  return 1;
}


//**************************************************************************
// fun��o para inserir elemento no final da lista
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

  // movimenta uma posi��o para frente, todos os elementos que est�o depois da posi��o i, onde o novo elemento ser� inserido
  for(int i=li->qtd-1; i>=i; i--){
    li->dados[i+1] = li->dados[i];
  }

  // insere o dado na posi��o logo ap�s o �ltimo elemento do vetor
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
// fun��o para imprimir a lista est�tica
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


// TAD para Lista Din�mica Encadeada Circular

#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"


// defini��o do struct elemento
struct no{
  int valor;
  struct no *esq;
  struct no *dir;
};

// fun��o para alocar mem�ria
ArvoreBin* criar_arvore_binaria()
{
  // 'raiz' � um ponteiro para ponteiro do tipo No
  ArvoreBin *raiz = (ArvoreBin*) malloc(sizeof(ArvoreBin));

  // se a aloca��o estiver correta 'raiz' aponta para NULL (arvore vazia)
  if(raiz != NULL){
    *raiz = NULL;
  }

  return raiz;
}

// funcao para desalocar memoria de um n� da arvore
void liberar_no(No *no)
{
  if(no == NULL)
    return;

  liberar_no(no->esq);
  liberar_no(no->dir);
  free(no);
  no = NULL;
}


// fun��o para desalocar mem�ria da arvore
int liberar_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL)
    return 0;

  liberar_no(*raiz); //libera cada no
  free(raiz); // libera a raiz

  return 1;
}

// fun��o calcula o total de n�s da arvore binaria
int quantidade_nos_arvore_binaria(ArvoreBin *raiz)
{
  // se o ponteiro for nulo ou se a arvore estiver vazio
  if(raiz == NULL || *raiz == NULL)
    return 0;

  // calcula o numero de nos na subarvore esquerda
  int total_esq = quantidade_nos_arvore_binaria(&((*raiz)->esq));

  // calcula o numero de nos na subarvore direita
  int total_dir = quantidade_nos_arvore_binaria(&((*raiz)->dir));

  // total � a quantidade de nos das subarvores mais a raiz
  return (total_esq + total_dir + 1);
}


// funcao que calcula a altura da arvore binaria
int altura_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL || *raiz == NULL)
    return 0;

  // calcula a altura da subarvore esquerda
  int alt_esq = altura_arvore_binaria(&((*raiz)->esq));

  // calcula a altura da subarvore direita
  int alt_dir = altura_arvore_binaria(&((*raiz)->dir));

  // altura da arvore � a altura da maior subarvore mais a raiz
  if(alt_esq > alt_dir)
    return (alt_esq + 1);
  else
    return (alt_dir + 1);
}

// funcao retorna 1 se n�o houver n�s na arvore
int esta_vazia_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL || *raiz == NULL)
    return 1;

  return 0;
}


// fun��o para inser��o de elementos em uma arvore binaria de busca
int inserir_arvore_binaria(ArvoreBin *raiz, int valor)
{
  if(raiz == NULL)
    return 0;

  // cria um n� novo
  No *novo = (No*) malloc(sizeof(No));

  // verifica se a mem�ria foi alocada corretamente
  if(novo == NULL){
    return 0;
  }

  // preenche campos do n� novo criado
  novo->valor = valor;
  novo->esq = NULL;
  novo->dir = NULL;

  // se a arvore estiver vazia, raiz recebe o novo n�
  if(*raiz == NULL){
    *raiz = novo;

  }else{
    No *atual = *raiz;
    No *ant = NULL;

    // percorre a arvore binaria at� encontrar uma posicao nula,
    // de acordo com a ordem desejada
    while(atual != NULL){

      ant = atual;

      // verifica se o valor novo j� existe na �rvore
      if(valor == atual->valor){
        free(novo);
        return 0;
      }

      // identifica a subarvore pela qual ir� percorrer
      if(valor < atual->valor){
        atual = atual->esq;
      }else{
        atual = atual->dir;
      }
    }

    // verifica para qual filho atribu�ra o n� novo
    if(valor < ant->valor){
      ant->esq = novo;
    }else{
      ant->dir = novo;
    }
  }

  return 1;

}

// fun��o para remo��o de um n� da arvore binaria de busca
No* remover_no(No *atual)
{
  No *no1, *no2;

  // verifica se "atual" n�o possui filho da esquerda
  if(atual->esq == NULL){
    no2 = atual->dir;
    free(atual); // libera mem�ria do n� atual

     // retorna "no2", filho da direita, como n� substituto do n� removido
     return no2;
  }

  no1 = atual;
  no2 = atual->esq;

  // busca o n� mais a direita do n� atual, "no2"
  while(no2->dir != NULL){
    no1 = no2;      // armazena o pai do "no2"
    no2 = no2->dir;
  }

  // verifica se o pai do n� mais a direita � diferente do atual, a ser removido
  if(no1 != atual){
    // subarvore da esquerda do "no2" se torna a subarvore da direita do "no1"
    no1->dir = no2->esq;

    // subarvore da esquerda do "atual" se torna a subarvore da esquerda do "no2"
    no2->esq = atual->esq;
  }

  // subarvore da direita do "atual" se torna a subarvore da direita do "no2"
  no2->dir = atual->dir;

  free(atual); // libera mem�ria do n� atual

  // retorna "no2" como n� substituto do n� removido
  return no2;
}

// fun��o para remo��o de elementos de uma arvore binaria de busca
int remover_arvore_binaria(ArvoreBin *raiz, int valor)
{
  if(raiz == NULL)
    return 0;

  No *ant = NULL;    // n� pai do n� atual
  No *atual = *raiz; // n� atual

  // percorre a arvore binaria at� encontrar o n� a ser removido
  while(atual != NULL){

    // verifica se o valor buscado foi encontrado
    if(valor == atual->valor){

      // verifica se o n� a ser removido � a raiz da �rvore
      if(atual == *raiz){
        *raiz = remover_no(atual); // remove o n� e atualiza a arvore

      }else{

        if(ant->dir == atual){
          ant->dir = remover_no(atual); // remove o n� e atualiza a arvore
        }else{
          ant->esq = remover_no(atual); // remove o n� e atualiza a arvore
        }

      }

      // n� a ser removido foi encontrado e removido corretamente
      return 1;
    }

    // se o n� atual n�o � o n� procurado
    // "ant" recebe "atual" e "atual" recebe um de seus filhos
    ant = atual;

    // verifica em qual subarvore o valor procurado pode estar
    // e atualiza o n� atual para o filho da direita ou da esquerda
    if(valor > atual->valor){
      atual = atual->dir;
    }else{
      atual = atual->esq;
    }

  }

  // n� a ser removido n�o existe na �rvore
  return 0;
}

// fun��o para buscar elementos na arvore binaria
int consultar_arvore_binaria(ArvoreBin *raiz, int valor)
{
  if(raiz == NULL)
    return 0;

  No *atual = *raiz;

  // percorre a arvore binaria at� encontrar o valor desejado
  while(atual != NULL){

    // retorna 1 quando encontra o valor
    if(valor == atual->valor){
      return 1;
    }

    // identifica a subarvore pela qual ir� percorrer
    if(valor < atual->valor){
      atual = atual->esq;
    }else{
      atual = atual->dir;
    }
  }

  return 0;
}

// fun��o para percorrer a arvore binaria em ordem
void percorrer_em_ordem_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL)
    return;

  if(*raiz != NULL){
    percorrer_em_ordem_arvore_binaria(&((*raiz)->esq));
    printf("%d\n", (*raiz)->valor);
    percorrer_em_ordem_arvore_binaria(&((*raiz)->dir));
  }
}

// fun��o para percorrer a arvore binaria em pr� ordem
void percorrer_pre_ordem_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL)
    return;

  if(*raiz != NULL){
    printf("%d\n", (*raiz)->valor);
    percorrer_pre_ordem_arvore_binaria(&((*raiz)->esq));
    percorrer_pre_ordem_arvore_binaria(&((*raiz)->dir));
  }
}

// fun��o para percorrer a arvore binaria em p�s ordem
void percorrer_pos_ordem_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL)
    return;

  if(*raiz != NULL){
    percorrer_pos_ordem_arvore_binaria(&((*raiz)->esq));
    percorrer_pos_ordem_arvore_binaria(&((*raiz)->dir));
    printf("%d\n", (*raiz)->valor);
  }
}

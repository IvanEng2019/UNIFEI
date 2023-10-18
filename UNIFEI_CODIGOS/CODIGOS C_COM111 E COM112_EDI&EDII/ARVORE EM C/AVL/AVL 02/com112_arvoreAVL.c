#include <stdio.h>
#include <stdlib.h>
#include "com112_arvoreAVL.h"

// definição do struct elemento
struct no{
  int valor;
  int alt;    //facilita o calcula do fator de balanceamento
  struct no *esq;
  struct no *dir;
};

//alocar memória
ArvoreAVL* criar_arvore_avl()
{
  ArvoreAVL *raiz = (ArvoreAVL*) malloc(sizeof(ArvoreAVL));
  if(raiz != NULL){
    *raiz = NULL;
  }

  return raiz;
}

//desalocar memoria de um nó da arvore
void liberar_no(No *no)
{
  if(no == NULL)
    return;

  liberar_no(no->esq);
  liberar_no(no->dir);
  free(no);
  no = NULL;
}


//desalocar memória da arvore
int liberar_arvore_avl(ArvoreAVL *raiz)
{
  if(raiz == NULL)
    return 0;

  liberar_no(*raiz); //libera cada no
  free(raiz); // libera a raiz

  return 1;
}

//total de nós da arvore
int quantidade_nos_arvore_avl(ArvoreAVL *raiz)
{
  if(raiz == NULL || *raiz == NULL)
    return 0;

  //numero de nos na subarvore esquerda
  int total_esq = quantidade_nos_arvore_avl(&((*raiz)->esq));

  //numero de nos na subarvore direita
  int total_dir = quantidade_nos_arvore_avl(&((*raiz)->dir));

  // total é a quantidade de nos das subarvores mais a raiz
  return (total_esq + total_dir + 1);
}


//calcula a altura da arvore
int altura_arvore_avl(ArvoreAVL *raiz)
{
  if(raiz == NULL || *raiz == NULL)
    return 0;

  // calcula a altura da subarvore esquerda
  int alt_esq = altura_arvore_avl(&((*raiz)->esq));

  // calcula a altura da subarvore direita
  int alt_dir = altura_arvore_avl(&((*raiz)->dir));

  // altura da arvore é a altura da maior subarvore mais a raiz
  if(alt_esq > alt_dir)
    return (alt_esq + 1);
  else
    return (alt_dir + 1);
}

int esta_vazia_arvore_avl(ArvoreAVL *raiz)
{
  if(raiz == NULL || *raiz == NULL)
    return 1;

  return 0;
}


// função para inserção de elementos em uma arvore
int inserir_arvore_avl(ArvoreAVL *raiz, int valor)
{
  if(raiz == NULL)
    return 0;
  
  //resposta da inserção
  int res;
  
  // cria um nó novo
  No *novo = (No*) malloc(sizeof(No));
  // preenche campos do novo nó criado
  novo->valor = valor;
  novo->esq = NULL;
  novo->dir = NULL;
  novo->alt = 0;

  // verifica se a memória foi alocada corretamente
  if(novo == NULL){
    return 0;
  }
  
  // se a arvore estiver vazia, raiz recebe o novo nó
  if(*raiz == NULL){
    *raiz = novo;
  // se a arvore ja tiver elemento(s), faz o calculo da inserção
  }else{
    No *atual = *raiz;
    No *ant = NULL;
	//insere valor a esquerda
    if(valor < atual->valor){
      if((res=inserir_arvore_avl(&(atual->esq), valor))==1){
        if(fatorBalanceamento_no(atual) >=2){
		//faz o balanceamento da arvore
          if(valor < (*raiz)->esq->valor){
            rotacaoLL(raiz);
          }else{
            rotacaoLR(raiz);
          }
        }
      }
    }
	//se o novo valor for maior, insere a direita
    else{
      if(valor > atual->valor){
        if((res=inserir_arvore_avl(&(atual->dir), valor))==1){
          if(fatorBalanceamento_no(atual) >= 2){
			//faz o balanceamento  
            if((*raiz)->dir->valor < valor){
              rotacaoRR(raiz);
            }else{
              rotacaoRL(raiz);
            }
          }
        }
      }else{
        printf("Valor duplicado!\n");
        return 0;
      }
    }
	//recalculo da altura do nó atual
    atual->alt = maior(alt_no(atual->esq),alt_no(atual->dir)) + 1;
    return res;
  }  
  return 1;
}


// função para remoção de elementos de uma arvore binaria de busca
int remover_arvore_avl(ArvoreAVL *raiz, int valor)
{
  if(raiz == NULL)  //arvore nao existe
    return 0;

  //arvore vazia
  if(*raiz == NULL){
    printf("Valor nao existe!");
    return 0;
  }
  
  int res;
  if(valor < (*raiz)->valor){
    if((res=remover_arvore_avl(&(*raiz)->esq,valor)) == 1){
      if(fatorBalanceamento_no(*raiz) >= 2){
        if(alt_no((*raiz)->dir->esq) <= alt_no((*raiz)->dir->dir))
          rotacaoRR(raiz);
        else
          rotacaoRL(raiz);
      }
    }
  }
  if((*raiz)->valor < valor){
    if((res=remover_arvore_avl(&(*raiz)->dir,valor)) == 1){
      if(fatorBalanceamento_no(*raiz) >= 2){
        if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq))
          rotacaoLL(raiz);
        else
          rotacaoLR(raiz);
      }
    }
  }
  
  if((*raiz)->valor == valor){
    if(((*raiz)->esq == NULL) || (*raiz)->dir == NULL){
      No *noAntigo = (*raiz);
      if((*raiz)->esq != NULL)
        *raiz = (*raiz)->esq;
      else
        *raiz = (*raiz)->dir;
      free(noAntigo);
    }else{
      No* temp = procuraMenor((*raiz)->dir);
      (*raiz)->valor = temp->valor;
      remover_arvore_avl(&(*raiz)->dir, (*raiz)->valor);
      if(fatorBalanceamento_no(*raiz) >= 2){
        if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq))
          rotacaoLL(raiz);
        else
          rotacaoLR(raiz);
      }
    }
    return 1;
  }
  return res;
}

//buscar elementos na arvore binaria
int consultar_arvore_avl(ArvoreAVL *raiz, int valor)
{
  if(raiz == NULL)
    return 0;

  No *atual = *raiz;

  // percorre a arvore binaria até encontrar o valor desejado
  while(atual != NULL){

    // retorna 1 quando encontra o valor
    if(valor == atual->valor){
      return 1;
    }

    // identifica a subarvore pela qual irá percorrer
    if(valor < atual->valor){
      atual = atual->esq;
    }else{
      atual = atual->dir;
    }
  }

  return 0;
}

//percorrer a arvore binaria em ordem
void percorrer_em_ordem_arvore_avl(ArvoreAVL *raiz)
{
  if(raiz == NULL)
    return;

  if(*raiz != NULL){
    percorrer_em_ordem_arvore_avl(&((*raiz)->esq));
    printf("%d\n", (*raiz)->valor);
    percorrer_em_ordem_arvore_avl(&((*raiz)->dir));
  }
}

//percorrer a arvore binaria em pré ordem
void percorrer_pre_ordem_arvore_avl(ArvoreAVL *raiz)
{
  if(raiz == NULL)
    return;

  if(*raiz != NULL){
    printf("%d\n", (*raiz)->valor);
    percorrer_pre_ordem_arvore_avl(&((*raiz)->esq));
    percorrer_pre_ordem_arvore_avl(&((*raiz)->dir));
  }
}

//percorrer a arvore binaria em pós ordem
void percorrer_pos_ordem_arvore_avl(ArvoreAVL *raiz)
{
  if(raiz == NULL)
    return;

  if(*raiz != NULL){
    percorrer_pos_ordem_arvore_avl(&((*raiz)->esq));
    percorrer_pos_ordem_arvore_avl(&((*raiz)->dir));
    printf("%d\n", (*raiz)->valor);
  }
}


int alt_no(No *no){
  if(no == NULL)
    return -1;
  else
    return no->alt;
}

int fatorBalanceamento_no(No *no){
  return labs(alt_no(no->esq) - alt_no(no->dir)); //modulo do fator de balanceamento -> altura esq - altura dir
}

int maior(int x, int y){
  if(x > y)
    return x;
  else
    return y;
}


void rotacaoLL(ArvoreAVL *raiz){
  No *no;
  no = (*raiz)->esq;
  (*raiz)->esq = no->dir;
  no->dir = *raiz;
  (*raiz)->alt = maior(alt_no((*raiz)->esq),alt_no((*raiz)->dir)) + 1;	//calculo das alturas
  no->alt = maior(alt_no(no->esq),(*raiz)->alt) + 1;
  *raiz = no;
}


void rotacaoRR(ArvoreAVL *raiz){
  No *no;
  no = (*raiz)->dir;
  (*raiz)->dir = no->esq;
  no->esq = (*raiz);
  (*raiz)->alt = maior(alt_no((*raiz)->esq),alt_no((*raiz)->dir)) + 1;
  no->alt = maior(alt_no(no->dir),(*raiz)->alt) + 1;
  (*raiz) = no;
}


void rotacaoLR(ArvoreAVL *raiz){
  rotacaoRR(&(*raiz)->esq);
  rotacaoLL(raiz);
}


void rotacaoRL(ArvoreAVL *raiz){
  rotacaoLL(&(*raiz)->dir);
  rotacaoRR(raiz);
}


No* procuraMenor(No* atual){
  No *no1 = atual;
  No *no2 = atual->esq;
  while(no2 != NULL){
    no1 = no2;
    no2 = no2->esq;
  }
  return no1;
}
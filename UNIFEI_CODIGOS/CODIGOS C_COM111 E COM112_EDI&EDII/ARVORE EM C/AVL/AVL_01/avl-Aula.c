#include <stdio.h>
#include <stdlib.h>

typedef struct no * pno;

typedef struct no{
  int chave;
  pno esq;
  pno dir;
  int alt;
}no;

pno criar_no(int c){
  pno aux = (pno) malloc(sizeof(no));
  aux->chave = c;
  aux->esq = NULL;
  aux->dir = NULL;
  aux->alt = 0;
  return aux;
}



int altura(pno n){
  if(n == NULL) return -1;
  else return n->alt;
}

int max(int a, int b){
  if(a>b)return a;
  return b;
}

pno rotaciona_direita(pno n){
  pno aux;
  aux = n->esq;
  n->esq = aux->dir;
  aux->dir = n;
  
  n->alt   = max(altura(n->esq), altura(n->dir)) + 1;
  aux->alt = max(altura(aux->esq), altura(aux->dir)) + 1;
  
  return(aux);
}

pno rotaciona_esquerda(pno n){
  pno aux;
  aux = n->dir;
  n->dir = aux->esq;
  aux->esq = n;
  
  n->alt   = max(altura(n->esq), altura(n->dir)) + 1;
  aux->alt = max(altura(aux->esq), altura(aux->dir)) + 1;
  
  return(aux);
}

pno rotaciona_esquerda_direita(pno n){
  n->esq = rotaciona_esquerda(n->esq);
  pno aux = rotaciona_direita(n);
  return aux;
}

pno rotaciona_direita_esquerda(pno n){
  n->dir = rotaciona_direita(n->dir);
  pno aux = rotaciona_esquerda(n);
  return aux;
}

void print_arvore(pno arv){
  if(arv == NULL) return;
  printf("(%d, ", arv->chave);
  print_arvore(arv->esq);
  printf(", ");
  print_arvore(arv->dir);
  printf(")");
  return;
}

int fator_balanceamento(pno n){
  if(n == NULL) return 0;
  return(altura(n->dir) - altura(n->esq));
}

pno insere(pno arvore, int c){
  if(arvore == NULL) return(criar_no(c));
  if(arvore->chave == c){
    printf("Chave existente\n");
    return arvore;
  }
  if(arvore->chave > c){
    //insere na esquerda
    arvore->esq = insere(arvore->esq, c);
    //como eu inseri na esquerda o unico problema que eu posso ter é se a esquerda agora tem 2 vezes mais altura
    if(fator_balanceamento(arvore) == -2){
      if(c < arvore->esq->chave) arvore = rotaciona_direita(arvore);
      else arvore = rotaciona_esquerda_direita(arvore);
    }
  }
  if(arvore->chave < c){
    //insere na direita
    arvore->dir = insere(arvore->dir, c);
    //como eu inseri na esquerda o unico problema que eu posso ter é se a esquerda agora tem 2 vezes mais altura
    if(fator_balanceamento(arvore) == 2){
      if(c > arvore->dir->chave) arvore = rotaciona_esquerda(arvore);
      else arvore = rotaciona_direita_esquerda(arvore);
    }
  }
  arvore->alt   = max(altura(arvore->esq), altura(arvore->dir)) + 1;
  return(arvore);
}


int main(int argc, char*argv){
  pno arvore = NULL;
  
  arvore = insere(arvore, 30);
  print_arvore(arvore);
  printf("\n");
  
  arvore = insere(arvore, 40);
  print_arvore(arvore);
  printf("\n");
  
  arvore = insere(arvore, 50);
  print_arvore(arvore);
  printf("\n");

  arvore = insere(arvore, 25);
  print_arvore(arvore);
  printf("\n");

  arvore = insere(arvore, 27);
  print_arvore(arvore);
  printf("\n");
  
  return 0;
}

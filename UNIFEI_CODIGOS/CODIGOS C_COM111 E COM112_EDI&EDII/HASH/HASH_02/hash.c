#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


Hash* criaHash(int TABLE_SIZE){
  Hash* h1 = (Hash*) malloc(sizeof(Hash)); //aloca hash

  if(h1 != NULL){  //se a alocacao ocorreu corretamente
    int i;

    h1->TABLE_SIZE = TABLE_SIZE;     //aloca os itens com tamanho struct aluno
    h1->itens = (struct aluno**) malloc(TABLE_SIZE * sizeof(struct aluno*));

    if(h1->itens == NULL){      //caso ocorra problema na alocacao
      free(h1);
      return NULL;
    }

    h1->qtd = 0;   //seta qtd inicial
    for(i=0; i<h1->TABLE_SIZE; i++){ //aloca valores NULL para o tamanho da tabela
      h1->itens[i] = NULL;
    }
  }
  return h1;
}



void liberaHash(Hash *h1){
  if(h1 != NULL){        // percore a tabela nao vazia liberando as posicoes de um a um
    for(int i=0; i<h1->TABLE_SIZE; i++){
      if(h1->itens[i] != NULL)
        free(h1->itens[i]);
    }
    free(h1->itens); //libera o vetor
    free(h1);  //libera a tabela (struct)
  }
}


int insereSemColisao(Hash* h1, struct aluno a1){
  if(h1 == NULL || h1->qtd == h1->TABLE_SIZE) //tabela nao criada ou cheia
    return 0;
  int chave = a1.matricula;

  int pos = chaveDivisao(chave,h1->TABLE_SIZE); //calculo da chave
  struct aluno* novo;
  novo = (struct aluno*) malloc(sizeof(struct aluno));
  if(novo == NULL)    //verifica alocacao
    return 0;
  *novo = a1;
  h1->itens[pos] = novo;    //salva o novo aluno
  h1->qtd++;
  return 1;
}


int buscaSemColisao(Hash* h1, int mat, struct aluno* a1){
  if(h1 == NULL)
    return 0;

  int pos = chaveDivisao(mat, h1->TABLE_SIZE);

  if(h1->itens[pos] != NULL){
    *a1 = *(h1->itens[pos]);
    return 1;
  }

  else
    return 0;

}



//funcoes auxiliares Backes

// chave a partir do resto da divisao evitando overflow com & bit-a-bit

int chaveDivisao(int chave, int TABLE_SIZE){
  return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}


/*
int chaveMultiplicacao(int chave, int TABLE_SIZE){
  float A = 0.6180339887;
  float val = chave * A;
  val = val - (int) val;
  return (int) (TABLE_SIZE * val);
}



int chaveDobra(int chave, int TABLE_SIZE){
  int num_bits = 10;
  int parte1 = chave >> num_bits;
  int parte2 = chave & (TABLE_SIZE-1);
  return (parte1 ^ parte2);
}

int valorString(char *str){
  int i, valor = 7;
  int tam = strlen(str);
  for(i=0; i<tam; i++)
    valor = 31 * valor + (int) str[i];
  return valor;
}


*/
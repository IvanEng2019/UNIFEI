/* Alunos: 111111 222222 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int TipoIndice;
typedef int TipoChave;
typedef struct TipoItem{
  TipoChave Chave;
} TipoItem;


void Insere (TipoItem *x , TipoItem *A, TipoIndice *n);
void AumentaChave(TipoIndice i, TipoChave ChaveNova, TipoItem *A);
TipoItem RetiraMax(TipoItem *A, TipoIndice *n);
void Constroi(TipoItem *A, TipoIndice n);
void Refaz(TipoIndice Esq, TipoIndice Dir, TipoItem *A);

void Insere (TipoItem *x , TipoItem *A, TipoIndice *n){
  (*n)++; 
  A[*n] = *x; 
  A[*n].Chave = INT_MIN;
  AumentaChave(*n, x->Chave, A);
}

void AumentaChave(TipoIndice i, TipoChave ChaveNova, TipoItem *A){ 
  TipoItem x;
  if(ChaveNova < A[i].Chave){ 
    printf("ChaveNova menor que atual \n");
    return;
  }
  A[i].Chave = ChaveNova;
  while(i > 1 && A[i/2].Chave < A[i].Chave){ 
    x = A[i/2]; 
    A[i/2] = A[i]; 
    A[i] = x;
    i = i/2;
  }
}

TipoItem RetiraMax(TipoItem *A, TipoIndice *n){ 
  TipoItem Maximo;
  if (*n < 1)
    printf("Erro: heap vazio \n" );
  else{ 
    Maximo = A[1]; 
    A[1] = A[*n]; 
    (*n)--;
    Refaz(1, *n, A);
  }
  return Maximo;
}

void Constroi(TipoItem *A, TipoIndice n){ 
  TipoIndice Esq;
  Esq = n / 2 + 1;
  while (Esq > 1){ 
    Esq--;
    Refaz(Esq, n, A);
  }
}

void Refaz(TipoIndice Esq, TipoIndice Dir, TipoItem *A){ 
  TipoIndice i = Esq;
  int j; TipoItem x;
  j = i * 2;
  x = A[i];
  while (j <= Dir){ 
    if (j < Dir)
      if (A[j].Chave < A[j+1].Chave) j++;
    if (x.Chave >= A[j].Chave) break;
    A[i] = A[j]; i = j; j = i*2;
  }
  A[i] = x;
}

TipoItem Max(TipoItem *A){ 
  return (A[1]); 
}


int main(int argc, char * argv[]){
  ???
  ???
  
  return 0;
}

#include <stdio.h>
#include <stdlib.h>


/************************************************************/
/** Com Aloca��o Din�mica de Mem�ria                        */
/************************************************************/

// ************** Prot�tipos das fun��es auxiliares
void preencherVetor(int n, int *V);
void imprimirVetor(int n, int *V);
void preencherMatriz(int l, int c, int **M, int *V);
void imprimirMatriz(int l, int c, int **M);
int *alocarVetor(int n);
int **alocarMatriz(int l, int c);



// ************** Implementa��o da fun��o principal
int main(void) {

  int l, c;
  int *V, **M;

  printf("\nDigite n�mero de linhas e colunas: \n");
  scanf("%d %d", &l, &c);

  V = alocarVetor(l*c);
  M = alocarMatriz(l, c);

  if(V == NULL || M == NULL){
      return 0;
  }

  printf("\nPreencha o vetor V com %d n�meros inteiros: \n", l*c);
  preencherVetor(l*c, V);

  printf("\nVetor com %d elementos: \n", l*c);
  imprimirVetor(l*c, V);

  preencherMatriz(l, c, M, V);

  printf("\n\nMatriz %d x %d preenchida com elementos do vetor: \n", l, c);
  imprimirMatriz(l, c, M);

  // desaloca ponteiros
  free(V);
  free(*M);

  return 0;
}



// ************** Implementa��o das fun��es auxiliares
void preencherVetor(int n, int *V){
  for(int i=0; i<n; i++){
    scanf("%d", &V[i]);
  }
}

void imprimirVetor(int n, int *V){
  for(int i=0; i<n; i++){
    printf(" %d", V[i]);
  }
}

void preencherMatriz(int l, int c, int **M, int *V){
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){
      M[i][j] = V[i*c+j];
    }
  }
}

void imprimirMatriz(int l, int c, int **M){
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){
      printf(" %d", M[i][j]);
    }
    printf("\n");
  }
}

int *alocarVetor(int n){

  int *V = (int*) malloc(n*sizeof(int));

  if(V == NULL){
    printf("\nMem�ria insuficiente!\n");
    return NULL;
  }

  return V;
}

int **alocarMatriz(int l, int c){

  int **M = (int**) malloc(l*sizeof(int*));

  if(M == NULL){
    printf("\nMem�ria insuficiente!\n");
    return NULL;
  }

  for(int i=0; i<l; i++){
    M[i] = (int*) malloc(c*sizeof(int));

    if(M[i] == NULL){
      printf("\nMem�ria insuficiente!\n");
      return NULL;
    }
  }

  return M;
}

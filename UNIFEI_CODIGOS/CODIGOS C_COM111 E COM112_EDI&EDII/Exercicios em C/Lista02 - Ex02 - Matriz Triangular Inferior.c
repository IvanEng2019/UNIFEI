#include <stdio.h>
#include <stdlib.h>


/*** prot�tipos das fun��es ***/
float **cria(int n);
void atribui(int i, int j, float x, float **mat);
float acessa(int i, int j, float **mat);
void libera(int n, float **m5at);


/*** fun��o principal ***/
int main()
{
  int n;
  float **mat, x;

  printf("\nDigite a dimens�o da matriz quadrada triangular inferior: ");
  scanf("%d", &n);

  // cria matriz
  mat = cria(n);
  printf("\n");

  // atribui valores para a matriz
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i<=j){
        printf("Digite o valor do elemento %d, %d da matriz: ", i, j);
        scanf("%f", &x);
        atribui(i, j, x, mat);
      }
    }
    printf("\n");
  }

  // imprime matriz triangular inferior
  for(int i=0; i<n; i++){
    printf("\n");
    for(int j=0; j<n; j++){
      printf("%.2f ", acessa(i, j, mat));
    }
  }

  // libera mem�ria
  libera(n, mat);

  return 0;
}

/*** fun��o cria uma matriz representada por um vetor de ponteiros e aloca a mem�ria para n posi��es ***/
float** cria(int n)
{
  // aloca vetor de ponteiros
  float **mat = (float**) malloc(n * sizeof(float*));
  if(mat == NULL){
    printf("Mem�ria insuficiente!");
    return NULL;
  }

  // aloca vetores de float (um para cada linha)
  // mat[i] possui n elementos.
  for(int i=0; i<n; i++){

    mat[i] = (float*) malloc((n-i) * sizeof(float));

    if(mat[i] == NULL){
      printf("Mem�ria insuficiente!");
      return NULL;
    }
  }

  // retorna vetor de ponteiros (matriz)
  return mat;
}


/*** fun��o atribui valor x ao elemento i,j da matriz ***/
void atribui(int i, int j, float x, float **mat)
{
  // verifica se o elemento est� na parte n�o nula da matriz triangular superior
  if(i <= j){
    mat[i][j-i] = x;
  }
}

/*** fun��o acessa o valor do elemento i,j da matriz ***/
float acessa(int i, int j, float **mat)
{
  // verifica se o elemento est� na parte n�o nula da matriz triangular superior
  if(i <= j){
    return mat[i][j-i];

  }else{
    return 0;
  }
}

/*** fun��o libera mem�ria ***/
void libera(int n, float **mat)
{
  // libera mem�ria para cada linha da matriz
  for(int i=0; i<n; i++){
    free(mat[i]);
  }

  // libera mem�ria alocada para o ponteiro de ponteiro mat
  free(mat);
}

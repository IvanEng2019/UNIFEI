#include <stdio.h>
#include <stdlib.h>

/*** prot�tipos das fun��es ***/
float *alocaMatrizV(int m, int n);
float **alocaMatrizP(int m, int n);
float **converte_a(int m, int n, float *mat);
float *converte_b(int m, int n, float **mat);


/*** fun��o principal ***/
int main()
{
  int m, n;
  float *matV;
  float **matP;

  printf("\nDigite o n�mero de linhas da matriz: ");
  scanf("%d", &m);

  printf("Digite o n�mero de colunas da matriz: ");
  scanf("%d", &n);

  // aloca matriz representada por vetor
  matV = alocaMatrizV(m, n);
  printf("\n");

  // atribui valores para a matriz matV
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      printf("matV[%d]: ", i);
      scanf("%f", &matV[i*n+j]);
    }
  }

  // imprime vetor original
  printf("\nMatriz original do tipo vetor: ");
  for(int i=0; i<m; i++){
    printf("\n");
    for(int j=0; j<n; j++){
      printf("%.2f ", matV[i*n+j]);
    }
  }

  // converte matriz representada como vetor para vetor de ponteiros
  matP = converte_a(m, n, matV);

  // imprime vetor original
  printf("\n\nMatriz convertida para vetor de ponteiros: ");
  for(int i=0; i<m; i++){
    printf("\n");
    for(int j=0; j<n; j++){
      printf("%.2f ", matP[i][j]);
    }
  }

  // converte matriz representada como vetor de ponteiros para vetor
  matV = converte_b(m, n, matP);

  // imprime vetor original
  printf("\n\nMatriz convertida para vetor: ");
  for(int i=0; i<m; i++){
    printf("\n");
    for(int j=0; j<n; j++){
      printf("%.2f ", matV[i*n+j]);
    }
  }

  // libera mem�ria
  free(matV);

  for(int i=0; i<m; i++){
    free(matP[i]);
  }
  free(*matP);

  return 0;
}



/*** fun��o aloca matriz de decimais representada por vetor com m linhas e n colunas  ***/
float *alocaMatrizV(int m, int n)
{
  // aloca vetor de inteiros
  float *matV = (float*) malloc(m * n * sizeof(float));

  if(matV == NULL){
    printf("Mem�ria insuficiente!");
    return NULL;
  }

  // retorna vetor de inteiros
  return matV;
}


/*** fun��o aloca matriz de decimais representada por vetor de ponteiros com m linhas e n colunas  ***/
float **alocaMatrizP(int m, int n)
{
  // aloca vetor de ponteiros com m posi��es (n� de linhas da matriz)
  float **matP = (float**) malloc(m*sizeof(float*));
  if(matP == NULL){
    printf("\nMem�ria insuficiente!\n");
    return NULL;
  }

  // aloca m vetores de decimais com n posi��es (n� de colunas da matriz)
  for(int i=0; i<m; i++){
    matP[i] = (float*) malloc(n*sizeof(float));

    if(matP[i] == NULL){
      printf("\nMem�ria insuficiente!\n");
      return NULL;
    }
  }

  return matP;
}

/*** fun��o converte uma matriz representada por um vetor em uma matriz representada por um vetor de ponteiros  ***/
float **converte_a(int m, int n, float *mat)
{
  float **matP = alocaMatrizP(m, n);

  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      matP[i][j] = mat[i*n+j];
    }
  }

  return matP;
}


/*** fun��o converte uma matriz representada por um vetor em uma matriz representada por um vetor de ponteiros  ***/
float *converte_b(int m, int n, float **mat)
{
  float *matV = alocaMatrizV(m, n);

  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      matV[i*n+j] = mat[i][j];
    }
  }

  return matV;
}

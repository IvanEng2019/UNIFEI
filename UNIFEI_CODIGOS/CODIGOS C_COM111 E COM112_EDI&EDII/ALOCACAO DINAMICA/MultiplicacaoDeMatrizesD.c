
/********************************************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 19/08/2018
======================================================================================================================
Exercício : matrizes multiplicação A [M][P] x B [P][N]

***********************************************************************************************************************
Inclusao de Bibliotecas
***********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/**********************************************************************************************************************
Protótipos de funções
***********************************************************************************************************************/
float **alocarMatriz(int m, int n);
void cadastroMatriz(int m, int n, float **Mat);
void imprimirMatriz(int m, int n, float **Mat);
void liberaMemoria(int m, int p,float **A,float **B,float **M);
void** MultMatriz(int m, int p, int n, float **A, float **B,float **M);
/*************************************************************************************************************************
Função principal
/*************************************************************************************************************************/
int main(void){
    int m,n,p,p1;
    float **A, **B,**M;
    do{
        printf("Programa realiza Multiplicação de matriz:\n");
        printf("Entre com as dimenssões da matiz A [MxP]:");
        scanf("%d %d",&m,&p);
        printf("Entre com as dimenssões da matiz B [MxP]:");
        scanf("%d %d",&p1,&n);
        if(p!=p1)
            printf("Não existe mutiplicação de matizes nesta dimenssão.\nO numero de colunas de A deve ser igual de linhas de B.\n");
    }while(p!=p1);
    printf("Matriz A:\n");
    A=alocarMatriz(m,p);
    cadastroMatriz(m,p,A);
    printf("Matriz B:\n");
    B=alocarMatriz(p1,n);
    cadastroMatriz(p1,n,B);
    printf("A [M][P] x B [P][N]= Matriz M:");
    M=alocarMatriz(m,n);
    MultMatriz(m,p,n,A,B,M);

    imprimirMatriz(m,n,M);
    liberaMemoria(m,p,A,B,M);

 return 0;
}
/*************************************************************************************************************************
Função aloca a memória para matriz ponteiro [m][p], [p][n] e [m][n]
**************************************************************************************************************************/
float **alocarMatriz(int m, int n){
  float **mP= (float**) malloc(m*sizeof(float*));//aloca vetor
  if(mP == NULL){
    printf("Memória insuficiente! Tente Alocar menos memoria!\n");
   return NULL;
  }
  for(int i=0;i<m;i++){ //aloca vetor do vetor - cria-se matriz de ponteiro
    mP[i] = (float*) malloc(n*sizeof(float));
    if(mP[i] == NULL){
      printf("Memória insuficiente! aloque menos memoria.\n");
      return NULL;
    }
  }
  return mP;
}
/*************************************************************************************************************************
Função que castra a matriz ponteiro [m][n] atraves dos dados do usuario
**************************************************************************************************************************/
void cadastroMatriz(int m, int n, float **mat){
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
           printf("Entre com o valor de [%d][%d]:",i,j);
           scanf("%f",&mat[i][j]);
        }
}
/*************************************************************************************************************************
Função para multiplicar vetor de ponteiro
**************************************************************************************************************************/
void **MultMatriz(int m, int p, int n, float **A, float **B,float **M){
    int i,j,k;
    float t;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++){
            t=0;
            for(k=0;k<p;k++)
                t=t+A[i][k]*B[k][j];
            M[i][j]=t;
        }
}
/*************************************************************************************************************************
Função para imprimir matriz
**************************************************************************************************************************/
void imprimirMatriz(int m, int n, float **mat){
  for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
        printf("\nM[%d][%d]=%.2f",i,j,mat[i][j]); // imprime na tela o valor da posição i,j da matriz
}
/*************************************************************************************************************************
 Função para liberar matriz de ponteiro e matriz de vetor alocados-libera memoria
 *************************************************************************************************************************/
void liberaMemoria(int m, int p, float **A,float **B,float **M){
    for(int i=0; i<m; i++)
            free(A[i]);
    for(int i=0; i<p; i++){
            free(B[i]);
            free(M[i]);
    }
    free(A);
    free(B);
    free(M);
}


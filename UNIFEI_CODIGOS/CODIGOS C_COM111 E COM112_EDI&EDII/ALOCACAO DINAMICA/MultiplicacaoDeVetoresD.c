
/********************************************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 19/08/2018
======================================================================================================================
Exercício : matrizes multiplicação A [MxP] x B [PxN]

***********************************************************************************************************************
Inclusao de Bibliotecas
***********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/**********************************************************************************************************************
Protótipos de funções
***********************************************************************************************************************/
float *alocarVetor(int m, int n);
void cadastroVetor(int m, int n, float *vet);
void* MultMatriz(int m, int p, int n, float *A, float *B,float *M);
void imprimirVetor(int m, int n, float *vet);
void liberaMemoria(float *A,float *B,float *M);
/*************************************************************************************************************************
Função principal
/*************************************************************************************************************************/
int main(void){
    int m,n,p,p1;
    float *A,*B,*M;
    do{
        printf("Programa realiza Multiplicação de matriz de vetor:\n");
        printf("Entre com as dimenssões da matiz A [MxP]:");
        scanf("%d %d",&m,&p);
        printf("Entre com as dimenssões da matiz B [MxP]:");
        scanf("%d %d",&p1,&n);
        if(p!=p1)
            printf("Não existe mutiplicação de matizes nesta dimenssão.\nO numero de colunas de A deve ser igual de linhas de B.\n");
    }while(p!=p1);
    printf("Matriz de vetor A:\n");
    A=alocarVetor(m,p);
    cadastroVetor(m,p,A);
    printf("Matriz de vetor B:\n");
    B=alocarVetor(p1,n);
    cadastroVetor(p1,n,B);
    printf("\nMatriz de vetor M:");
    M=alocarVetor(m,n);
    MultMatriz(m,p,n,A,B,M);
    imprimirVetor(m,n,M);
    liberaMemoria(A,B,M);

 return 0;
}
/*************************************************************************************************************************
Função para multiplicar vetor de ponteiro
**************************************************************************************************************************/
void *MultMatriz(int m, int p, int n, float *A, float *B,float *M){
    int i,j,k;
    float t;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++){
            t=0;
            for(k=0;k<p;k++)
             //   t=t+A[i*n+k]*B[k*n+j];
            M[i*n+j]=t;
        }
}
/*************************************************************************************************************************
Função que aloca memória para matriz de um vetor simples de tamango m*n
**************************************************************************************************************************/
float *alocarVetor(int m, int n){
  float *vP;// declara um ponteiro de ponteiro
  vP = (float*) malloc(m*n*sizeof(float));// aloca memória para um vetor de ponteiro com m*n posições do tipo float
  if(vP == NULL){//Se v==NULL nao conseguiu alocar memoria para o vetor
    printf("Memória insuficiente! Tente Alocar memoria menor!\n");
  }
  return vP;
}
/*************************************************************************************************************************
Função para preencher a matriz de vetor com valores digitados pelo usuário
**************************************************************************************************************************/
void cadastroVetor(int m, int n, float *vet){
  for(int i=0; i<m; i++){
     for(int j=0; j<n; j++){
        printf("Entre com o valor do elemento V[%d]=",i*n+j);
        //scanf("%f",&vet[i*n+j]);// atribui a posição i do vetor valor digitado pelo usuário
        scanf("%f",(vet+(i*n)+ j));
    }
  }
     /*
    for(int i=0; i<n*m; i++){
       printf("Entre com o valor do elemento V[%d]:",i);
       scanf("%f",&vet[i]);// atribui a posição i do vetor valor digitado pelo usuário
    }*/
}
/*************************************************************************************************************************
 Função para imprimir a matriz de vetor
**************************************************************************************************************************/
void imprimirVetor(int m, int n, float *vet){
   /*for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
           printf("\nV[%d]=%2.f",i*n+j,vet[i*n+j]); //imprime na tela o valor do elementoda posição n do vetor
          //matriz[linha][coluna] → *(matriz de vetor + (linha*comprimento_da_linha) + coluna): *(mat+(i*n)+j)
         //printf("\nM[%d][%d]=%.2f\t",i,j,*(vet+i*n+j));
   */
   for(int i=0; i<n*m; i++)
      printf("\nV[%d]=%.2f",i,vet[i]);
}
void liberaMemoria(float *mat, float *vet,float *m){
    free(m);
    free(mat);
    free(vet);
}

/********************************************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa de C�ssia Silva Rodrigues
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 15/08/2018

Exerc�cio 1
Escreva uma fun��o que receba um vetor V de n n�meros inteiros e tenha como valor de retorno
um novo vetor, alocado dinamicamente, com os elementos do vetor original em ordem reversa.
A fun��o deve ter como valor de retorno o ponteiro do vetor alocado, seguindo o prot�tipo:
float *reverso (int n, float *v)
Fa�a uma fun��o main para testar sua fun��o. Na fun��o main, n�o esque�a de liberar a
mem�ria alocada pela fun��o auxiliar.
**************************************************************************************************************************
Inclusao de bibliotecas
**************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/***********************************************************************
Prot�tipos de fun��es
***********************************************************************/
int *alocarVetorVetP(int n);
void cadastroVetP(int n, int *vet);
int *reverso(int *v, int n);
void imprimirVetorVetP(int n, int *vet);
void liberaMemoriaVP(int *rV,int *vet);
/***********************************************************************
  Fun��o principal
/***********************************************************************/
int main(void){
    int n,*vetP,*rVetP;
    printf("Programa que retorna um vetor din�mico reverso.\n\n");
    printf("Entre com o a quantidade de elementos do vetor:");
    scanf("%d",&n);
    vetP=alocarVetorVetP(n);
    cadastroVetP(n,vetP);
    printf("\nImprimindo o vetor cadastrado.");
    imprimirVetorVetP(n,vetP);
    rVetP=reverso(vetP,n);
    printf("\n\nImprimindo o vetor reverso.");
    imprimirVetorVetP(n,rVetP);
    liberaMemoriaVP(rVetP,vetP);
 return 0;
}
/*************************************************************************************************************************
Fun��o que aloca mem�ria para matriz de um vetor simples de tamango m*n
**************************************************************************************************************************/
int *alocarVetorVetP(int n){
  int *vP;// declara um ponteiro de ponteiro
  vP = (int*) malloc(n*sizeof(int));// aloca mem�ria para um vetor de ponteiro com m*n posi��es do tipo float
  if(vP == NULL){//Se v==NULL nao conseguiu alocar memoria para o vetor
    printf("Mem�ria insuficiente! Tente Alocar memoria menor!\n");
  }
  return vP;
}
/*************************************************************************************************************************
Fun��o para preencher a matriz de vetor com valores digitados pelo usu�rio
**************************************************************************************************************************/
void cadastroVetP(int n, int *vet){
  for(int i=0; i<n; i++){
        printf("Entre com o valor do elemento V[%d]:",i);
        scanf("%d",&vet[i]);
    }
}
/*************************************************************************************************************************
 Fun��o para imprimir a matriz de vetor
**************************************************************************************************************************/
void imprimirVetorVetP(int n, int *vet){
     for(int i=0; i<n; i++)
      printf("\nV[%d]=%d",i,vet[i]);
}
int *reverso(int *v, int n){
     int *v2= alocarVetorVetP(n);
     for(int i=0;i<n;i++)
         v2[i]= v[n-1-i];
return v2;
}

/*************************************************************************************************************************
 Fun��o para liberar matriz de ponteiro e matriz de vetor alocados-libera memoria
 *************************************************************************************************************************/
void liberaMemoriaVP(int *rV,int *vet){
    free(rV);
    free(vet);
}

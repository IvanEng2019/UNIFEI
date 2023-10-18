/********************************************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa de Cássia Silva Rodrigues
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 15/08/2018

Exercício 1
Escreva uma função que receba um vetor V de n números inteiros e tenha como valor de retorno
um novo vetor, alocado dinamicamente, com os elementos do vetor original em ordem reversa.
A função deve ter como valor de retorno o ponteiro do vetor alocado, seguindo o protótipo:
float *reverso (int n, float *v)
Faça uma função main para testar sua função. Na função main, não esqueça de liberar a
memória alocada pela função auxiliar.
**************************************************************************************************************************
Inclusao de bibliotecas
**************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/***********************************************************************
Protótipos de funções
***********************************************************************/
int *alocarVetorVetP(int n);
void cadastroVetP(int n, int *vet);
int *reverso(int *v, int n);
void imprimirVetorVetP(int n, int *vet);
void liberaMemoriaVP(int *rV,int *vet);
/***********************************************************************
  Função principal
/***********************************************************************/
int main(void){
    int n,*vetP,*rVetP;
    printf("Programa que retorna um vetor dinâmico reverso.\n\n");
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
Função que aloca memória para matriz de um vetor simples de tamango m*n
**************************************************************************************************************************/
int *alocarVetorVetP(int n){
  int *vP;// declara um ponteiro de ponteiro
  vP = (int*) malloc(n*sizeof(int));// aloca memória para um vetor de ponteiro com m*n posições do tipo float
  if(vP == NULL){//Se v==NULL nao conseguiu alocar memoria para o vetor
    printf("Memória insuficiente! Tente Alocar memoria menor!\n");
  }
  return vP;
}
/*************************************************************************************************************************
Função para preencher a matriz de vetor com valores digitados pelo usuário
**************************************************************************************************************************/
void cadastroVetP(int n, int *vet){
  for(int i=0; i<n; i++){
        printf("Entre com o valor do elemento V[%d]:",i);
        scanf("%d",&vet[i]);
    }
}
/*************************************************************************************************************************
 Função para imprimir a matriz de vetor
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
 Função para liberar matriz de ponteiro e matriz de vetor alocados-libera memoria
 *************************************************************************************************************************/
void liberaMemoriaVP(int *rV,int *vet){
    free(rV);
    free(vet);
}

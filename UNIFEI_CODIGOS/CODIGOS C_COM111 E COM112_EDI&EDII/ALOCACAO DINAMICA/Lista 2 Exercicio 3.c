/********************************************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa de Cássia Silva Rodrigues
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 12/08/2018
======================================================================================================================
Exercício 3:
Escreva:
(a) Uma função para converter uma matriz representada por um vetor (float *mat) numa
matriz representada por um vetor de ponteiros (float **mat):
float **converte_a(int m, int n, float *mat);
(b) Uma função para converter uma matriz representada por um vetor de ponteiros
(float **mat) numa matriz representada por um vetor (float *mat):
float *converte_b(int m, int n, float **mat);
Escreva também as funções para criar as matrizes e implemente uma função main para testar
as conversões.

***********************************************************************************************************************
Inclusao de Bibliotecas
***********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/**********************************************************************************************************************
Protótipos de funções
***********************************************************************************************************************/
float *alocarVetorVet(int m, int n);
void cadastroVetor(int m, int n, float *vet);
void imprimirVetorVet(int m, int n, float *vet);
float **converte_a(int m, int n, float *mat);
float **alocarMatrizM(int m, int n);
void imprimirMatrizMat(int m, int n, float **mat);
void liberaMemoriaVmP(int m,float **mat, float*vet);
void cadastroMatrizM(int m, int n, float **mat);
float *converte_b(int m, int n, float **mat);
/*************************************************************************************************************************
Função principal
/*************************************************************************************************************************/
int main(void){
    int m,n;
    float **matAp,*vetBp,**tMatAp,*tVetBp;
    printf("Digite o tamanho maximo do vetor dado por V[M*N]:");
    scanf("%d %d",&m,&n);
    vetBp=alocarVetorVet(m,n); //alocação de matriz de um vetor simples
    cadastroVetor(m,n,vetBp);//cadastro da matriz de vetor simples
    printf("\nImprimindo A matriz de vetor:");
    imprimirVetorVet(m,n,vetBp);//imprimi vetor cadastrado
    matAp=converte_a(m,n,vetBp); // convete uma matriz de vetor em uma matriz de ponteiro
    printf("\nImprimindo A matriz de ponteiro:");
    imprimirMatrizMat(m,n,matAp);// imprime a matriz de ponteiro
    liberaMemoriaVmP(m,matAp,vetBp);//libera memoria
    printf("\n\nAgorao inverso...\n");
    printf("Digite o tamanho maximo da matriz dada por V[M][N]:");
    scanf("%d %d",&m,&n);
    matAp=alocarMatrizM(m,n);
    cadastroMatrizM(m,n,matAp);
    printf("\nImprimindo A matriz de ponteiro:");
    imprimirMatrizMat(m,n,matAp);
    vetBp=converte_b(m,n,matAp);
    printf("\nImprimindo A matriz de vetor:");
    imprimirVetorVet(m,n,vetBp);
    liberaMemoriaVmP(m,matAp,vetBp);

 return 0;
}
/*************************************************************************************************************************
Função que aloca memória para matriz de um vetor simples de tamango m*n
**************************************************************************************************************************/
float *alocarVetorVet(int m, int n){
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
void imprimirVetorVet(int m, int n, float *vet){
   /*for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
           printf("\nV[%d]=%2.f",i*n+j,vet[i*n+j]); //imprime na tela o valor do elementoda posição n do vetor
          //matriz[linha][coluna] → *(matriz de vetor + (linha*comprimento_da_linha) + coluna): *(mat+(i*n)+j)
         //printf("\nM[%d][%d]=%.2f\t",i,j,*(vet+i*n+j));
   */
   for(int i=0; i<n*m; i++)
      printf("\nV[%d]=%.2f",i,vet[i]);
}
/*************************************************************************************************************************
Função aloca a memória para matriz ponteiro [m][n] atraves de outra chamada de função
e depois atibui os dados de uma matriz vetor [m*n] a matriz ponteiro
**************************************************************************************************************************/
float **converte_a(int m, int n, float *mat){
   float** matP2= alocarMatrizM(m,n);
   for(int i=0;i<m;i++)
       for(int j=0; j<n;j++)
           matP2[i][j] = mat[i*n+j];
  return matP2;
}
/*************************************************************************************************************************
Função aloca a memória para matriz ponteiro [m][n]
**************************************************************************************************************************/
float **alocarMatrizM(int m, int n){
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
Função para imprimir matriz
**************************************************************************************************************************/
void imprimirMatrizMat(int m, int n, float **mat){
  for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
        printf("\nM[%d][%d]=%.2f",i,j,mat[i][j]); // imprime na tela o valor da posição i,j da matriz
}
/*************************************************************************************************************************
 Função para liberar matriz de ponteiro e matriz de vetor alocados-libera memoria
 *************************************************************************************************************************/
void liberaMemoriaVmP(int m, float **mat, float *vet){
    for(int i=0; i<m; i++)
            free(mat[i]);
    free(mat);
    free(vet);
}
/*************************************************************************************************************************
Função que castra a matriz ponteiro [m][n] atraves dos dados do usuario
**************************************************************************************************************************/
void cadastroMatrizM(int m, int n, float **mat){
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
           printf("Entre com o valor de M[%d][%d]:",i,j);
           scanf("%f",&mat[i][j]);
        }
}
/**************************************************************************************************************************
 Função para converter uma matriz de ponteiro em um matriz de vetor
***************************************************************************************************************************/
float *converte_b(int m, int n, float **mat){
      float  *matV= alocarVetorVet(m,n);
      /*
      for(int i=0;i<m;i++)
        for(int j=0; j<n;j++)
             matV[i*n+j]= mat[i][j];
      */
        int pos=0;
        for(int i=0;i<m;i++)
            for(int j=0; j<n;j++)
             matV[pos++]=mat[i][j];
return matV;
}

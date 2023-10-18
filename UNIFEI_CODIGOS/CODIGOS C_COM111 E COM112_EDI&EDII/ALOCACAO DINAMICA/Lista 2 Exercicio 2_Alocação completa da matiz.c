/********************************************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 12/08/2018
======================================================================================================================
Exercício 3:
Escreva:
(a) Uma função para converter uma matriz representada por um vetor numa matriz representada por um vetor de ponteiros:
float **converte_a(int m, int n, float *mat);
(b) Uma função para converter uma matriz representada por um vetor de ponteiros numa matriz representada por um vetor:
float *converte_b(int m, int n, float **mat);
Escreva também as funções para criar as matrizes e implemente uma função main para testar as conversões.

***********************************************************************************************************************
Inclusao de Bibliotecas
***********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/**********************************************************************************************************************
Protótipos de funções
***********************************************************************************************************************/
int menu();
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
  int m,n,resp;
  do{
    resp=menu();
    float **matAp,*vetBp;
    switch (resp){
    case 1:
        printf("Digite o tamanho maximo do vetor dado por V[M*N]:");
        scanf("%d %d",&m,&n);
        vetBp=alocarVetorVet(m,n); //alocação de matriz de um vetor simples
        cadastroVetor(m,n,vetBp);//cadastro da matriz de vetor simples
        imprimirVetorVet(m,n,vetBp);//imprimi vetor cadastrado
        matAp=converte_a(m,n,vetBp); // convete uma matriz de vetor em uma matriz de ponteiro
        imprimirMatrizMat(m,n,matAp);// imprime a matriz de ponteiro
        liberaMemoriaVmP(m,matAp,vetBp);//libera memoria
    break;
    case 2:
        printf("Digite o tamanho maximo da matriz dada por V[M][N]:");
        scanf("%d %d",&m,&n);
        matAp=alocarMatrizM(m,n);
        cadastroMatrizM(m,n,matAp);
        imprimirMatrizMat(m,n,matAp);
        vetBp=converte_b(m,n,matAp);
        imprimirVetorVet(m,n,vetBp);
        liberaMemoriaVmP(m,matAp,vetBp);
    break;
    default:
        printf("Fim Programa.\n");
    }
    }while(resp!=3);
 return 0;
}
/*************************************************************************************************************************
Função que imprime menu na tela
**************************************************************************************************************************/
int menu(){
   int op;
   do{
        printf("*********************************************************************************************");
        printf("\nPrograma q tranforma matriz de vetor em poneito e vice-versa:\n");
        printf("\nTecle 1:\nPara converter uma matriz representada por um vetor numa matriz de um vetor de ponteiros.");
        printf("\n\nTecle 2:\nPara converter uma matriz representada por um vetor de ponteiros numa matriz de um vetor.");
        printf("\n\nTecle 3:\nPara sair.\n");
        printf("*********************************************************************************************\n");
        scanf("%d",&op);
        if(op!=1 && op!=2 && op!=3)
            printf("Opção inavlida!\n");
   }while(op!=1 && op!=2 && op!=3);
   return op;
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
        //scanf("%f",&vet[i*n+j]);// atribui a posição i do vetor o valor digitado pelo usuário
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
  printf("\nImprimindo A matriz de vetor:");
   /*for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
           printf("\nV[%d]=%2.f",i*n+j,vet[i*n+j]); //imprime na tela o valor do elementoda posição n do vetor
          //matriz[linha][coluna] → *(matriz de vetor + (linha*comprimento_da_linha) + coluna): *(mat+(i*n)+j)
         //printf("\nM[%d][%d]=%.2f\t",i,j,*(vet+i*n+j));
   */
   for(int i=0; i<n*m; i++)
      printf("\nV[%d]=%.2f",i,vet[i]);
   printf("\n");
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
      printf("Memória insuficiente! Aloque menos memoria.\n");
      return NULL;
    }
  }
  return mP;
}
/*************************************************************************************************************************
Função para imprimir matriz
**************************************************************************************************************************/
void imprimirMatrizMat(int m, int n, float **mat){
  printf("\nImprimindo A matriz de ponteiro:");
  for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
        printf("\nM[%d][%d]=%.2f",i,j,mat[i][j]); // imprime na tela o valor da posição i,j da matriz
  printf("\n");
}
/*************************************************************************************************************************
 Função para liberar matriz de ponteiro e matriz de vetor alocados-libera memoria
 *************************************************************************************************************************/
void liberaMemoriaVmP(int m, float **mat, float*vet){
    for(int i=0; i<m; i++)
        free(mat[i]);
    free(mat);
    free(vet);
}
/*************************************************************************************************************************
Função que cadastra a matriz ponteiro [m][n] atraves dos dados do usuario
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
      for(int i=0;i<m;i++)
        for(int j=0; j<n;j++)
             matV[i*n+j]= mat[i][j];
return matV;
}

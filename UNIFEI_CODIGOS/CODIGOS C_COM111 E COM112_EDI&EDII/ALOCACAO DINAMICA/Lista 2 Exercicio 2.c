/********************************************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa de Cássia Silva Rodrigues
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 15/08/2018

Exercício 2
Escreva funções para lidar com matrizes triangulares inferiores de dimensão n × n, onde todos
os elementos abaixo da diagonal são iguais a zero e não devem ser alocados.
No entanto, um acesso a um elemento abaixo da diagonal deve retornar o valor zero.
Escreva as seguintes funções, usando a estratégia de vetor de ponteiros para armazenar a matriz.
(a) Função para criar uma matriz, onde n representa a dimensão da matriz, inicialmente com
os valores todos iguais a zero: float **cria(int n);
(b) Função para atribuir o valor de um elemento da matriz, assumindo que i <= j:
void atribui(int i, int j, float x);
(c) Função para acessar o valor de um elemento da matriz, inclusive elementos acima da
diagonal: float acessa(int i, int j, float **mat);
(d) Função para liberar a memória da matriz alocada: void libera(int n, float **mat);
Escreva uma função main para testar as funções implementadas.

**************************************************************************************************************************
Inclusao de bibliotecas
**************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/*************************************************************************************************************************
Prototipos das Funções
**************************************************************************************************************************/
int menu();
float **cria(int n);
void imprimeM(int n, float **mat);
void atribui(int i, int j,float x,float **mat);
float acessa(int i, int j, float **mat);
void libera(int n, float **mat);
/*************************************************************************************************************************
Função Principal
**************************************************************************************************************************/
int main(void){
   int n,i,j,resp;
   float **m,x;
   char r;
   do{
    resp=menu();
    if(resp==1){
       printf("Entre com o tamanho da matriz NxN:");
       scanf("%d",&n);
       m=cria(n);//alocar apenas a parte superior da matriz
       printf("\nMatiz inicial:");
       imprimeM(n,m);
    }
    if(resp==2){
     do{
        printf ("\nDeseja atribuir em qual posição i e j da matriz: ");
        scanf ("%d %d",&i,&j);
        if(i>j)
           printf ("\nPosição da parte inferior da diagonal.Forneça i<=j.\n");
        else
        {
            j=j-i;//arruma o endereço correto da matriz
            printf("Qual valor deseja atribuir: ");
            scanf("%f",&x);
            atribui(i,j,x,m);
        }
     setbuf(stdin, NULL);
     printf ("\nDeseja atribui mais valor para matiz M[%d][%d]?(s/n)\n",n,n);
     scanf(" %c",&r);
     }while(r =='s');
    }
    if(resp==3){
      do{
        printf ("\nDeseja acessar qual endereço i e j da matriz respectivamente: ");
        scanf ("%d %d",&i,&j);
        if(i>j){//se tentara acessar abaixo da matiz nxn obtera zero
          x=0;
          printf ("\nA Matiz[%d][%d] = %2.f.\n",i,j,x);
        }
        else{// como a alocaçao é formou cada coluna 1 a menos
           j=j-i;//atribui o endereço correto da matiz nxn deformada
           x=acessa(i,j,m);
           printf ("\nA Matiz[%d][%d] = %2.f.\n",i,j+i,x);
        }
        setbuf(stdin, NULL);
        printf ("\nDeseja acessar mais alguma posição da matiz M[%d][%d]? (s/n)",n,n);
        scanf("%c",&r);
       }while(r=='s');
    }
    if(resp==4)
       libera(n,m);
    if(resp==5){
       printf("\nImprimindo Matiz completa:");
       imprimeM(n,m);
    }
    if(resp==6)
        printf("Fim Programa.\n");
  }while (resp!=6);
return 0;
}
/*************************************************************************************************************************
Função que imprime menu na tela
**************************************************************************************************************************/
int menu(){
   int op;
   do{
        printf("*********************************************************************************************");
        printf("\nPrograma cria uma matriz triangular inferior de dimensão n x n:\n");
        printf("\nTecle 1:Para criar uma matriz e iniciar os elementos superiores iguais a zero.\n");
        printf("Tecle 2:Para atribuir o valor de um elemento da matriz, assumindo que i <= j\n");
        printf("Tecle 3:Para acessar o valor de um elemento da matriz, inclusive elementos acima da diagonal.\n");
        printf("Tecle 4:Para liberar a memória da matriz alocada.\n");
        printf("Tecle 5:Para imprimir matriz completa.\n");
        printf("Tecle 6:Para sair.\n");
        printf("*********************************************************************************************\n");
        scanf("%d",&op);
        if(op<0 && op>5)
            printf("Opção inavlida!\n");
   }while(op<0 && op>5);
   return op;
}
/*************************************************************************************************************************
Função que cria a matriz de ponteiros
**************************************************************************************************************************/
float **cria(int n){
  float **mat2 = (float**) calloc(n,sizeof(float*));
  if(mat2 == NULL){
    printf("Memória insuficiente! Tente Alocar menos memoria!\n");
   return NULL;
  }
  for(int i=0;i<n;i++){// para cada linha da matriz m[i] aloca um vetor de inteiros com n posições
    mat2[i] = (float*) calloc(n-i,sizeof(float));
    if(mat2[i] == NULL){//se nao conseguir alocar o valor de mat2[i] sera Null
      printf("Memória insuficiente! aloque menos memoria.\n");
      return NULL;
    }
  }
return mat2;
}
/*************************************************************************************************************************
Função que imprime a matriz de ponteiros por completo
**************************************************************************************************************************/
void imprimeM(int n, float **mat){
     for(int i=0; i<n; i++)
        for(int j=0; j<n-i; j++){
            printf("\nM[%d][%d]=%.2f",i,j+i,mat[i][j]);
        }
     printf("\n");
}
/*************************************************************************************************************************
Função que acessa um elemento particular da matriz de ponteiro
**************************************************************************************************************************/
float acessa(int i, int j,float **mat){
     return mat[i][j];
}
/*************************************************************************************************************************
Função que atribui um elemento na posição dada em uma matriz de ponteiros
**************************************************************************************************************************/
void atribui(int i, int j,float x,float **mat){
      mat[i][j]=x;
 }
/*************************************************************************************************************************
Função que libera a matriz de ponteiros
**************************************************************************************************************************/
void libera(int n, float **mat){
    printf("Liberando memoria.\n");
    for(int i=0; i<n; i++)
        free(mat[i]);
    free(mat);
}

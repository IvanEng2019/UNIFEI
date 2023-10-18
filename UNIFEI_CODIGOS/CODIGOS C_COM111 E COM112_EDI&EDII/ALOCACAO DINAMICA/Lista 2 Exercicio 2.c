/********************************************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa de C�ssia Silva Rodrigues
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 15/08/2018

Exerc�cio 2
Escreva fun��es para lidar com matrizes triangulares inferiores de dimens�o n � n, onde todos
os elementos abaixo da diagonal s�o iguais a zero e n�o devem ser alocados.
No entanto, um acesso a um elemento abaixo da diagonal deve retornar o valor zero.
Escreva as seguintes fun��es, usando a estrat�gia de vetor de ponteiros para armazenar a matriz.
(a) Fun��o para criar uma matriz, onde n representa a dimens�o da matriz, inicialmente com
os valores todos iguais a zero: float **cria(int n);
(b) Fun��o para atribuir o valor de um elemento da matriz, assumindo que i <= j:
void atribui(int i, int j, float x);
(c) Fun��o para acessar o valor de um elemento da matriz, inclusive elementos acima da
diagonal: float acessa(int i, int j, float **mat);
(d) Fun��o para liberar a mem�ria da matriz alocada: void libera(int n, float **mat);
Escreva uma fun��o main para testar as fun��es implementadas.

**************************************************************************************************************************
Inclusao de bibliotecas
**************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/*************************************************************************************************************************
Prototipos das Fun��es
**************************************************************************************************************************/
int menu();
float **cria(int n);
void imprimeM(int n, float **mat);
void atribui(int i, int j,float x,float **mat);
float acessa(int i, int j, float **mat);
void libera(int n, float **mat);
/*************************************************************************************************************************
Fun��o Principal
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
        printf ("\nDeseja atribuir em qual posi��o i e j da matriz: ");
        scanf ("%d %d",&i,&j);
        if(i>j)
           printf ("\nPosi��o da parte inferior da diagonal.Forne�a i<=j.\n");
        else
        {
            j=j-i;//arruma o endere�o correto da matriz
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
        printf ("\nDeseja acessar qual endere�o i e j da matriz respectivamente: ");
        scanf ("%d %d",&i,&j);
        if(i>j){//se tentara acessar abaixo da matiz nxn obtera zero
          x=0;
          printf ("\nA Matiz[%d][%d] = %2.f.\n",i,j,x);
        }
        else{// como a aloca�ao � formou cada coluna 1 a menos
           j=j-i;//atribui o endere�o correto da matiz nxn deformada
           x=acessa(i,j,m);
           printf ("\nA Matiz[%d][%d] = %2.f.\n",i,j+i,x);
        }
        setbuf(stdin, NULL);
        printf ("\nDeseja acessar mais alguma posi��o da matiz M[%d][%d]? (s/n)",n,n);
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
Fun��o que imprime menu na tela
**************************************************************************************************************************/
int menu(){
   int op;
   do{
        printf("*********************************************************************************************");
        printf("\nPrograma cria uma matriz triangular inferior de dimens�o n x n:\n");
        printf("\nTecle 1:Para criar uma matriz e iniciar os elementos superiores iguais a zero.\n");
        printf("Tecle 2:Para atribuir o valor de um elemento da matriz, assumindo que i <= j\n");
        printf("Tecle 3:Para acessar o valor de um elemento da matriz, inclusive elementos acima da diagonal.\n");
        printf("Tecle 4:Para liberar a mem�ria da matriz alocada.\n");
        printf("Tecle 5:Para imprimir matriz completa.\n");
        printf("Tecle 6:Para sair.\n");
        printf("*********************************************************************************************\n");
        scanf("%d",&op);
        if(op<0 && op>5)
            printf("Op��o inavlida!\n");
   }while(op<0 && op>5);
   return op;
}
/*************************************************************************************************************************
Fun��o que cria a matriz de ponteiros
**************************************************************************************************************************/
float **cria(int n){
  float **mat2 = (float**) calloc(n,sizeof(float*));
  if(mat2 == NULL){
    printf("Mem�ria insuficiente! Tente Alocar menos memoria!\n");
   return NULL;
  }
  for(int i=0;i<n;i++){// para cada linha da matriz m[i] aloca um vetor de inteiros com n posi��es
    mat2[i] = (float*) calloc(n-i,sizeof(float));
    if(mat2[i] == NULL){//se nao conseguir alocar o valor de mat2[i] sera Null
      printf("Mem�ria insuficiente! aloque menos memoria.\n");
      return NULL;
    }
  }
return mat2;
}
/*************************************************************************************************************************
Fun��o que imprime a matriz de ponteiros por completo
**************************************************************************************************************************/
void imprimeM(int n, float **mat){
     for(int i=0; i<n; i++)
        for(int j=0; j<n-i; j++){
            printf("\nM[%d][%d]=%.2f",i,j+i,mat[i][j]);
        }
     printf("\n");
}
/*************************************************************************************************************************
Fun��o que acessa um elemento particular da matriz de ponteiro
**************************************************************************************************************************/
float acessa(int i, int j,float **mat){
     return mat[i][j];
}
/*************************************************************************************************************************
Fun��o que atribui um elemento na posi��o dada em uma matriz de ponteiros
**************************************************************************************************************************/
void atribui(int i, int j,float x,float **mat){
      mat[i][j]=x;
 }
/*************************************************************************************************************************
Fun��o que libera a matriz de ponteiros
**************************************************************************************************************************/
void libera(int n, float **mat){
    printf("Liberando memoria.\n");
    for(int i=0; i<n; i++)
        free(mat[i]);
    free(mat);
}

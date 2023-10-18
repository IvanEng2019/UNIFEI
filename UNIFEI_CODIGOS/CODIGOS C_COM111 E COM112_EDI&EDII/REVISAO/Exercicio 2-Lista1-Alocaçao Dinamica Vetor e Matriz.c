/***************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 12/08/2018

Exerc�cio 2:
Escreva um programa que leia um n�mero L de linhas e um n�mero C de colunas. Em seguida,
um vetor V de tamanho L * C e uma matriz M com L linhas e C colunas devem ser alocados
dinamicamente. Seu programa deve executar as tarefas abaixo sequencialmente, atrav�s de
chamadas de fun��es:
(a) Preencher o vetor V com valores inteiros digitados pelo usu�rio.
(b) Imprimir o vetor V na tela.
(c) Preencher a matriz M, sequencialmente, com os valores do vetor V .
(d) Imprimir a matriz M na tela.

****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***********************************************************************
Prot�tipos de fun��es
***********************************************************************/
int *alocarVetorIntV(int n);
void preencherVetorV(int n, int *v);
void imprimirVetorV(int n, int *v);
int **alocarMatrizIntM(int l, int c);
void preencherMatrizM(int l, int c, int **m, int *v);
void imprimirMatrizM(int l, int c, int **m);

/***********************************************************************
  Fun��o principal
/***********************************************************************/
int main(void)
{
  printf("Programa le um N de linhas e um N de colunas. Cria um vetor V de tamanho L * C e uma matriz M com L X C alocados dinamicamente.");
  int l,c,*pvetor,**pMatriz;
  do{
     printf("\n\nDigite n�mero de  Linhas e colunas respectivamente:");
     scanf(" %d %d", &l,&c);

     //Aloca��o Dinamica de vetor e matriz
     pvetor = alocarVetorIntV(l*c); // chama fun��o que aloca mem�ria para o vetor com tamanho l*c
     pMatriz = alocarMatrizIntM(l,c); //chama fun��o que aloca mem�ria para a matriz
     if(pvetor== NULL || pMatriz==NULL)
       printf("Memoria da maquina Insuficiente forne�a colunas e memorias menores:\n");
  }while (pvetor== NULL || pMatriz==NULL);

  // Manipulando Vetor

  //cadatar o vetor
  printf("\nCadastro do vetor dinamico de %d posi��es:\n", l*c);
  preencherVetorV(l*c, pvetor);// chamada de fun��o para preencher vetor
  //mostrando os elementos do vetor cadastrado
  printf("\nElementos do Vetor v[0-%d]:", (l*c)-1);
  imprimirVetorV(l*c, pvetor);// chamada de fun��o para imprimir vetor

  // Manipulando matriz dinamica

  //cadatrando o matriz
  printf("\n\nPreenchimento da matriz M[%d][%d]: \n", l, c);
  preencherMatrizM(l, c, pMatriz, pvetor);// chamada de fun��o para preencher matriz
  //mostrando os elementos da matriz
  imprimirMatrizM(l, c, pMatriz);// chamada de fun��o para imprimir matriz

  // Libera a mem�ria alocada
  free(pvetor); // desaloca mem�ria do vetor
  for(int i=0;i<l;i++)
    free(pMatriz[i]);
  free(*pMatriz);// desaloca mem�ria da matriz

  return 0;
}
/********************************************************************
Fun��o para alocar mem�ria para vetor com l*c elementos (t)
********************************************************************/
int *alocarVetorIntV(int t){
  int *v;// declara um ponteiro de ponteiro
  v = (int*) malloc(t * sizeof(int));// aloca mem�ria para um vetor de ponteiro com t posi��es do tipo (int)
  if(v == NULL){//Se v==NULL nao conseguiu alocar memoria para o vetor
    printf("Mem�ria insuficiente! Tente Alocar memoria menor!\n");
  }
  return v;
}
/********************************************************************
Fun��o para alocar mem�ria para matriz com l linhas e c colunas
********************************************************************/
int **alocarMatrizIntM(int l, int c){
  int **m;// declara um ponteiro de ponteiro
  //cria-se a aloca��o de uma coluna. Cada lenha desta coluna ira possuir um ponteiro que apontara para outro vetor(linhas que formaram uma matriz)
  m = (int**) malloc(l * sizeof(int*)); //Aloca mem�ria para um vetor de ponteiro m com l posi��es do tipo (int*)
  if(m == NULL){//se nao conseguir alocar o valor de m sera Null
    printf("Mem�ria insuficiente! Tente Alocar menos memoria!\n");
   return NULL;
  }
 //cria��o da matriz, atravez do apontamento de cada elemento (ponteiro) do vetor m cria-se novos vetores
  for(int i=0;i<l;i++){// para cada linha da matriz m[i] aloca um vetor de inteiros com c posi��es
    m[i] = (int*) malloc(c * sizeof(int));//Aloca mem�ria para um vetor de inteiros m[i] com c posi��es do tipo (int)
    if(m[i] == NULL){//se nao conseguir alocar o valor de m[i] sera Null
      printf("Mem�ria insuficiente! aloque menos memoria.\n");
      return NULL;
    }
  }
  return m;
}
/*******************************************************************
Fun��o para preencher vetor com valores digitados pelo usu�rio
********************************************************************/
void preencherVetorV(int n, int *v){
  for(int i=0; i<n; i++){
     printf("Entre com o valor do elemento V[%d]=",i);
     scanf("%d",&v[i]);// atribui a posi��o i do vetor valor digitado pelo usu�rio
    }
}
/******************************************************************
 Fun��o para imprimir vetor
******************************************************************/
void imprimirVetorV(int n, int *v)
{
  for(int i=0; i<n; i++)
      printf("\nV[%d]=%d", i, v[i]); //imprime na tela o valor do elementoda posi��o n do vetor
}
/********************************************************************
Fun��o para preencher matriz com valores do vetor
********************************************************************/
void preencherMatrizM(int l, int c, int **m, int *v)
{
  int posv=0;
  for(int i=0; i<l; i++)
    for(int j=0; j<c; j++)
       m[i][j]= v[posv++];// atribui os valores de v a m

}
/*****************************************************************
Fun��o para imprimir matriz
******************************************************************/
void imprimirMatrizM(int l, int c, int **m)
{
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++)
        printf("\nM[%d][%d]=%d", i,j,m[i][j]); // imprime na tela o valor da posi��o i,j da matriz
  }
}

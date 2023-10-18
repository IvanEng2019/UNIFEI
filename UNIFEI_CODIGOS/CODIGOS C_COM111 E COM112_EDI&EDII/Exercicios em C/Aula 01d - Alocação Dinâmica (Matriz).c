#include <stdio.h>
#include <stdlib.h>

/***********************************************************************/
/** Prot�tipos de fun��es                                              */
/***********************************************************************/
int **alocarMatrizInt(int l, int c);
void preencherMatriz(int l, int c, int **m);
void imprimirMatriz(int l, int c, int **m);


/***********************************************************************/
/** Fun��o principal                                                   */
/***********************************************************************/
int main(void)
{
  int l, c;
  int **pMatriz;

  printf("\n\nDigite n�mero de linhas e colunas:");
  scanf("%d %d", &l, &c);

  // aloca mem�ria para a matriz
  pMatriz = alocarMatrizInt(l, c);

  printf("Preencha a matriz [%d x %d]: \n", l, c);

  // chamada de fun��o para preencher matriz
  preencherMatriz(l, c, pMatriz);

  printf("Matriz [%d x %d] = \n", l, c);

  // chamada de fun��o para imprimir matriz
  imprimirMatriz(l, c, pMatriz);

  // desaloca mem�ria
  free(*pMatriz);

  return 0;
}


/********************************************************************/
/** Fun��o para alocar mem�ria para matriz com l linhas e c colunas */
/********************************************************************/
int **alocarMatrizInt(int l, int c)
{
  // declara um ponteiro de ponteiro
  int **m;

  // aloca mem�ria para um vetor de ponteiro com l posi��es do tipo (int*)
  m = (int**) malloc(l * sizeof(int*));

  if(m == NULL){
    printf("Mem�ria insuficiente!");
    return NULL;
  }

  // para cada linha da matriz m[i] aloca um vetor de inteiros com c posi��es
  for(int i=0;i<l;i++){

    // aloca mem�ria para um vetor de inteiros com c posi��es do tipo (int)
    m[i] = (int*) malloc(c * sizeof(int));

    if(m[i] == NULL){
      printf("Mem�ria insuficiente!");
    }
  }

  return m;
}

/********************************************************************/
/** Fun��o para preencher matriz com valores digitados pelo usu�rio */
/********************************************************************/
void preencherMatriz(int l, int c, int **m)
{
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){

      // atribui a posi��o i,j da matriz o valor digitado pelo usu�rio
      scanf("%d", &m[i][j]);

    }
    printf("\n");
  }
}

/******************************************************************/
/** Fun��o para imprimir matriz                                   */
/******************************************************************/
void imprimirMatriz(int l, int c, int **m)
{
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){

      // imprime na tela o valor da posi��o i,j da matriz
      printf("%d ", m[i][j]);

    }
    printf("\n");
  }
}

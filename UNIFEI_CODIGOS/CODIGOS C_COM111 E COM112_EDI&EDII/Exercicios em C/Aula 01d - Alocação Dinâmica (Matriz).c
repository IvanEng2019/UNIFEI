#include <stdio.h>
#include <stdlib.h>

/***********************************************************************/
/** Protótipos de funções                                              */
/***********************************************************************/
int **alocarMatrizInt(int l, int c);
void preencherMatriz(int l, int c, int **m);
void imprimirMatriz(int l, int c, int **m);


/***********************************************************************/
/** Função principal                                                   */
/***********************************************************************/
int main(void)
{
  int l, c;
  int **pMatriz;

  printf("\n\nDigite número de linhas e colunas:");
  scanf("%d %d", &l, &c);

  // aloca memória para a matriz
  pMatriz = alocarMatrizInt(l, c);

  printf("Preencha a matriz [%d x %d]: \n", l, c);

  // chamada de função para preencher matriz
  preencherMatriz(l, c, pMatriz);

  printf("Matriz [%d x %d] = \n", l, c);

  // chamada de função para imprimir matriz
  imprimirMatriz(l, c, pMatriz);

  // desaloca memória
  free(*pMatriz);

  return 0;
}


/********************************************************************/
/** Função para alocar memória para matriz com l linhas e c colunas */
/********************************************************************/
int **alocarMatrizInt(int l, int c)
{
  // declara um ponteiro de ponteiro
  int **m;

  // aloca memória para um vetor de ponteiro com l posições do tipo (int*)
  m = (int**) malloc(l * sizeof(int*));

  if(m == NULL){
    printf("Memória insuficiente!");
    return NULL;
  }

  // para cada linha da matriz m[i] aloca um vetor de inteiros com c posições
  for(int i=0;i<l;i++){

    // aloca memória para um vetor de inteiros com c posições do tipo (int)
    m[i] = (int*) malloc(c * sizeof(int));

    if(m[i] == NULL){
      printf("Memória insuficiente!");
    }
  }

  return m;
}

/********************************************************************/
/** Função para preencher matriz com valores digitados pelo usuário */
/********************************************************************/
void preencherMatriz(int l, int c, int **m)
{
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){

      // atribui a posição i,j da matriz o valor digitado pelo usuário
      scanf("%d", &m[i][j]);

    }
    printf("\n");
  }
}

/******************************************************************/
/** Função para imprimir matriz                                   */
/******************************************************************/
void imprimirMatriz(int l, int c, int **m)
{
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){

      // imprime na tela o valor da posição i,j da matriz
      printf("%d ", m[i][j]);

    }
    printf("\n");
  }
}

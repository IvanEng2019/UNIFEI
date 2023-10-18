#include <stdio.h>
#include <stdlib.h>

/***********************************************************************/
/** Prot�tipos de fun��es                                              */
/***********************************************************************/
int *alocarVetorInt(int n);
void preencherVetor(int n, int *v);
void imprimirVetor(int n, int *v);


/***********************************************************************/
/** Fun��o principal                                                   */
/***********************************************************************/
int main(void)
{
  int n;
  int *vetor;

  printf("\nDigite n�mero de alunos a ser cadastrado:");
  scanf("%d", &n);

  // aloca mem�ria para o vetor com tamanho n
  vetor = alocarVetorInt(n);

  printf("\nCadastre o n�mero de matr�cula de %d alunos: \n", n);

  // chamada de fun��o para preencher vetor
  preencherVetor(n, vetor);

  printf("\nAlunos matriculados: \n", n);

  // chamada de fun��o para imprimir vetor
  imprimirVetor(n, vetor);

  // desaloca mem�ria
  free(vetor);

  return 0;
}


/********************************************************************/
/** Fun��o para alocar mem�ria para vetor com n elementos           */
/********************************************************************/
int *alocarVetorInt(int n)
{
  // declara um ponteiro de ponteiro
  int *v;

  // aloca mem�ria para um vetor de ponteiro com n posi��es do tipo (int)
  v = (int*) malloc(n * sizeof(int));

  if(v == NULL){
    printf("Mem�ria insuficiente!");
  }

  return v;
}

/********************************************************************/
/** Fun��o para preencher vetor com valores digitados pelo usu�rio */
/********************************************************************/
void preencherVetor(int n, int *v)
{
  for(int i=0; i<n; i++){

      // atribui a posi��o i da matriz o valor digitado pelo usu�rio
      scanf("%d", &v[i]);

    }
}

/******************************************************************/
/** Fun��o para imprimir vetor                                   */
/******************************************************************/
void imprimirVetor(int n, int *v)
{
  for(int i=0; i<n; i++){

      // imprime na tela o valor da posi��o n do vetor
      printf("%d ", v[i]);

    }
}

#include <stdio.h>
#include <stdlib.h>

/*** prot�tipos das fun��es  ***/
int *reverso(int n, int *v);
int *aloca(int n);


/*** fun��o principal  ***/
int main()
{
  int n;
  int *v, *vn;

  printf("\nDigite a quantidade de elementos do vetor: ");
  scanf("%d", &n);

  // cria matriz
  v = aloca(n);
  printf("\n");

  // atribui valores para o vetor
  for(int i=0; i<n; i++){
    printf("V[%d]: ", i);
    scanf("%d", &v[i]);
  }

  // calcula vetor reverso
  vn = reverso(n, v);

  // imprime vetor original
  printf("\nVetor original: ");
  for(int i=0; i<n; i++){
    printf("%d ", v[i]);
  }

  // imprime vetor reverso
  printf("\nVetor reverso: ");
  for(int i=0; i<n; i++){
    printf("%d ", vn[i]);
  }

  // libera mem�ria
  free(v);
  free(vn);

  return 0;
}



/*** fun��o aloca um vetor de inteiros com n posi��es  ***/
int *aloca(int n)
{
  // aloca vetor de inteiros
  int *v = (int*) malloc(n * sizeof(int));

  if(v == NULL){
    printf("Mem�ria insuficiente!");
    return NULL;
  }

  // retorna vetor de inteiros
  return v;
}



/*** fun��o inverte um vetor de inteiros com n posi��es  ***/
int *reverso(int n, int *v)
{
  int *vn;

  // aloca vetor
  vn = aloca(n);

  // inverte vetor
  for(int i=0; i<n; i++){
    vn[i] = v[n-1-i];
  }

  return vn;
}


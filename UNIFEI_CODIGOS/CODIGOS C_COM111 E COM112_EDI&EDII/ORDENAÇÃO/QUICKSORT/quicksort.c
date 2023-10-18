#include <stdio.h>
#include <stdlib.h>

typedef int TipoIndice;
typedef long TipoChave;
typedef struct Pessoas{
  TipoChave Chave;
  char name[100];
} Pessoas;

/*SUAS FUNCOES AQUI*/

int main(int argc, char * argv[]){
  int n;
  Pessoas * P, * Q;

    
  scanf("%d\n", &n);

  P = calloc(sizeof(Pessoas), n+1); //+1 para a sentinela em P[0]
  Q = calloc(sizeof(Pessoas), n+1); //+1 para a sentinela em P[0]
  if(P==NULL){
    perror("Error while allocating memory.\n");
    exit(EXIT_FAILURE);
  }
 
  for(int i = 1; i <= n; i++){
    scanf("%d ", &(P[i].Chave));
    fgets(P[i].name, 100, stdin);
    P[i].name[strlen(P[i].name) - 1] = '\0';
  }


  QuickSort(P, n);
  

  for(int i = 1; i <= n; i++){
    printf("%d %s\n", P[i].Chave, P[i].name);
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TipoIndice;
typedef long TipoChave;
typedef struct Pessoas{
  TipoChave Chave;
  char name[100];
} Pessoas;

void imprime_chaves(Pessoas * P,int n){
  printf("\nChaves:\n");
  for(int i=1; i<=n; i++)
      printf("%ld - ",P[i].Chave);
}

int ordenaMediana(TipoChave CH1, TipoChave CH2, TipoChave CH3){
    if(CH2>=CH1 && CH1>=CH3)
        return CH1;
    if(CH1>CH2 && CH2>=CH3 )
        return CH2;
    else
        return CH3;
}

//Metodo Quicksort
void particao(int Esq, int Dir, int *i, int *j, Pessoas *A, int total){
 Pessoas x,aux;
 TipoChave mediana;
 *i=Esq;
 *j=Dir;

  mediana=ordenaMediana(A[*i].Chave,A[(*i+*j)/2].Chave,A[*j].Chave);
  if(mediana==A[*i].Chave)
    x=A[*i];///PIVO
  if(mediana==A[*j].Chave)
     x=A[*j];///PIVO
  else
     x=A[(*i+*j)/2];///PIVO

  do{
    while(x.Chave>A[*i].Chave)
        (*i)++;
    while(x.Chave<A[*j].Chave)
        (*j)--;
    if(*i<=*j){
        imprime_chaves(A,total);
        aux=A[*i];
        A[*i]=A[*j];
        A[*j]=aux;
        (*i)++;
        (*j)--;

    }
  }while(*i<=*j);
}

void ordena(int Esq,int Dir, int total, Pessoas *A){
    int i,j;
    particao(Esq,Dir,&i,&j,A,total);
    if(Esq<j)
        ordena(Esq,j,total, A);
    if(i<Dir)
        ordena(i,Dir,total,A);
}

void quicksort(Pessoas *A, int n){
    ordena(1,n,n,A);
}

//impime chave e registro ordenados
void imprime_ordenacao(Pessoas * P, int n){
  for(int i=1; i<=n; i++)
      printf(" Chave:%ld\n Registro:%s\n",P[i].Chave,P[i].name);
}

///Verifica se os dados foram ordenados
void verifica_ordenacao(Pessoas * P, int n){
  for(int i=2; i<n+1; i++){
    if(P[i].Chave < P[i-1].Chave){
      printf("Ordenacao invalida.\n");
      exit(EXIT_FAILURE);
    }
  }
  printf("\n\nDados dos Arquivos ordenados por chave em ordem crescente:\n");
  imprime_ordenacao(P,n);
}

int main(int argc, char * argv[]){
  int n;
  Pessoas * P;
  printf("Entre com o numero de chaves:\n");
  scanf("%d\n",&n);

  P = calloc(sizeof(Pessoas), n+1); //+1 para a sentinela em P[0]
  if(P==NULL){
    perror("Error while allocating memory.\n");
    exit(EXIT_FAILURE);
  }

  printf("Entre com as %d chaves e seus registros respectivamente:\n",n);
  for(int i=1;i<=n;i++){
    fflush(stdin);
    printf("%d Chave:",i);
    scanf(" %ld",&(P[i].Chave));
    fflush(stdin);
    printf("Registro:");
    scanf(" %[^\n]c",&(P[i].name));
    ///scanf(" %ld",&(P[i].Chave));
    ///fgets(P[i].name, 100, stdin);
    ///P[i].name[strlen(P[i].name) - 1] = '\0';
  }
  ///ordena e imprime a cada orndenação
  quicksort(P,n);

  ///verifica se foi ornenado e imprime ordenação final
  verifica_ordenacao(P,n);

  return 0;
}


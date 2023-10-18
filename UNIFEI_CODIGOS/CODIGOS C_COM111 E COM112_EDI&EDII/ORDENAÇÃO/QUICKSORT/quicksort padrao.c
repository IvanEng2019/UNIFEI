/// Aluno: Ivan Leoni Vilas Boas  2018009073

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long contador;

typedef struct Pessoas{
  int Chave;
  char name[100];
} Pessoas;

///Metodo Quicksort
void particao(int Esq, int Dir, int *i, int *j, Pessoas *A){
 Pessoas x, aux;
 *i=Esq;
 *j=Dir;
  x=A[(((*i)+(*j))/2)]; ///PIVO
  do{
    while(x.Chave>A[*i].Chave)
        (*i)++;
    while(x.Chave<A[*j].Chave)
        (*j)--;
    if(*i<=*j){
        aux=A[*i];
        A[*i]=A[*j];
        A[*j]=aux;
        (*i)++;
        (*j)--;
    }
  }while(*i<=*j);
}

void ordena(int Esq,int Dir, Pessoas *A){
    int i,j;
    particao(Esq,Dir,&i,&j,A);
    if(Esq<j)
        ordena(Esq,j,A);
    if(i<Dir)
        ordena(i,Dir,A);
}

void quicksort(Pessoas *A, contador n){
    ordena(1,n,A);
}


///Faz uma copia dos registros dados na entrada
void copia_pessoas(Pessoas * destino, Pessoas * origem, int n){
  for(int i = 1; i <n+1; i++){
    destino[i] = origem[i];
  }
}

//imprime os registros caso suas chaves forem ordenadas
void imprime_ordenacao(Pessoas * P, int n){
  for(int i = 1; i <n+1; i++){
      printf("Chave:%d\n",P[i].Chave);
      printf("Registro:%s\n",P[i].name);
  }
}

//Verifica se os dados foram ordenados
void verifica_ordenacao(Pessoas * P, int n){
  for(int i = 2; i <n+1; i++){
    if(P[i].Chave < P[i-1].Chave){
      printf("Ordenacao invalida.\n");
      exit(EXIT_FAILURE);
    }
  }
  printf("\nDados dos Arquivos ordenados por chave em ordem crescente:\n");
  imprime_ordenacao(P,n);
}

//Função principal
int main(int argc, char * argv[]){
  int n;
  Pessoas *P, *Q;
  contador num_comparacoes, num_movimentos;

  printf("Entre com a quantidade de Registros: ");
  scanf("%d\n",&n);

  ///Aloca a quantidade de memoria necessaria de acordo com o numero de registros dado
  P = calloc(sizeof(Pessoas),n+1); //+1 para a sentinela em P[0]
  Q = calloc(sizeof(Pessoas),n+1); //+1 para a sentinela em P[0]
  if(P==NULL){
    perror("Error while allocating memory.\n");
    exit(EXIT_FAILURE);
  }

  ///Cadastrando os registros no sistema no vetor dinamico P:
  printf("Forneça as %d chaves e seus respctivos registros:\n",n);

  for(int i=1; i<n+1; i++){

  }

  ///Faz uma copia dos registros do vetor P para o vetor Q
  copia_pessoas(Q, P, n);
  ///ordena Utilizando o metodo
fflush(stdin);
    printf("%d Chave:",i);
    scanf(" %d",&(P[i].Chave));
    fflush(stdin);
    printf("Registro:");
    scanf(" %[^\n]c",&(P[i].name));  quicksort(P,n);
  /// verifica se foi de fato ordenado pelo metodo
  verifica_ordenacao(P, n);


  return 0;
}

/// Aluno: Ivan Leoni Vilas Boas  2018009073

/**
Nessa atividade voce devera' implementar 3 algoritmos de ordenacao
o bubble sort, o selection sort e o insertion sort
voce pode e deve usar os codigos das atividades passadas.

- A ordenacao e' so' por chave. Alguns algoritmos podem ser estaveis, outros nao.
- suas funcoes devem receber dois apontadores para o tipo 'contador' que deve ser
atualizado com o numero de comparacoes e com o numero de movimentos de registros de
cada algoritmo
- voce deve submeter sua solucao no run.codes conforme explicado em sala
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long contador;

typedef struct Pessoas{
  int Chave;
  char name[100];
} Pessoas;

/*Metodo de ordenação Bubble - ordena P[1...n]
void bubble(Pessoas *B, int n, contador *Comparacoes, contador *Movimentos){
    int i,j;
    Pessoas x;
    (*Comparacoes)=0;
    (*Movimentos)=0;
    for(i=1;i<n;i++){
     for(j=i+1;j<=n;j++){
        (*Comparacoes)++;
        if (B[i].Chave > B[j].Chave){
          x = B[i];
          B[i] = B[j];
          B[j] = x;
          (*Movimentos)+=3;
      }
     }
    }
}*/

/*Metodo de ordenação Bubble - ordena P[1...n]*/
void bubble(Pessoas *B, int n, contador *Comparacoes, contador *Movimentos){
    int i,j;
    Pessoas x;
    (*Comparacoes)=0;
    (*Movimentos)=0;
    for(i=1;i<n;i++){
     for(j=n;j>i;j--){
        (*Comparacoes)++;
        if (B[i].Chave > B[j].Chave){
          x = B[i];
          B[i] = B[j];
          B[j] = x;
          (*Movimentos)+=3;
      }
     }
    }
}

/*Metodo de ordenação Insertion - ordena P[1...n]*/
void insertion(Pessoas *A, int n, contador *Comparacoes, contador *Movimentos){
    int i, j, Min;
    Pessoas x;
    (*Comparacoes)=0;
    (*Movimentos)=0;
    int melhorcaso=1;
    for(i=2;i<=n;i++)
    {
        x=A[i];
        j=i-1;
        A[0]=x; ///sentinela
        (*Movimentos)+=2;
        (*Comparacoes)++;///melhor caso
        while (x.Chave<A[j].Chave)
        {
            A[j+1]=A[j];
            j=j-1;
            (*Movimentos)++;
            (*Comparacoes)++;
            melhorcaso=0;
        }
        A[j+1]=x;
        (*Movimentos)++;
    }
    if(melhorcaso==0){
        (*Movimentos)-=n;
        (*Comparacoes)-=n;
    }

}

/* Metodo de ordenação Selection - ordena P[1...n]*/
void selection(Pessoas *P, int n, contador *Comparacoes, contador *Movimentos){
  int i, j, Min;
  Pessoas x;
  (*Movimentos)=0;
  (*Comparacoes)=0;
  for (i=1; i<n; i++){
    Min = i;
    for (j=i+1; j<=n; j++){
      if (P[j].Chave < P[Min].Chave){
        Min = j;
      }
      (*Comparacoes)++;
    }
    x = P[Min];
    P[Min] = P[i];
    P[i] = x;
    (*Movimentos)+=3;
  }
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
    fflush(stdin);
    printf("%d Chave:",i);
    scanf(" %d",&(P[i].Chave));
    fflush(stdin);
    printf("Registro:");
    scanf(" %[^\n]c",&(P[i].name));
    //fgets(P[i].name, 100, stdin);
    //P[i].name[strlen(P[i].name) - 1] = '\0';
  }

  ///Faz uma copia dos registros do vetor P para o vetor Q
  copia_pessoas(Q, P, n);

  ///ordena Utilizando o metodo Bubble
  bubble(P, n, &num_comparacoes, &num_movimentos);
  printf("\nMetodo Bubble\n Numero de comparações:%lu Numero de movimentações:%lu\n", num_comparacoes, num_movimentos);
  /// verifica se foi de fato ordenado pelo metodo Bubble
  verifica_ordenacao(P, n);

  ///Faz uma copia dos registros do vetor Q para o vetor P ( Q estava com os dados Originais de entrada )
  copia_pessoas(P, Q, n);

  ///ordena Utilizando o metodo  Selection
  selection(P, n, &num_comparacoes, &num_movimentos);
  printf("\nMetodo  Selection:\n Numero de comparações:%lu Numero de movimentações:%lu\n", num_comparacoes, num_movimentos);
  /// verifica se foi de fato ordenado pelo  metodo  Selection
  verifica_ordenacao(P, n);

  ///Faz uma copia dos registros do vetor Q para o vetor P ( Q estava com os dados Originais de entrada)
  copia_pessoas(P, Q, n);

  ///ordena Utilizando o metodo insertion
  insertion(P, n, &num_comparacoes, &num_movimentos);
  printf("\nMetodo insertion:\n Numero de comparações:%lu Numero de movimentações:%lu\n", num_comparacoes, num_movimentos);
  /// verifica se foi de fato ordenado pelo  metodo insertion
  verifica_ordenacao(P, n);

  return 0;
}

/* Alunos: 2018014331 2018009073 2018012346 */

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

typedef unsigned long contador;

typedef struct Pessoas{
  int Chave;
  char name[100];
} Pessoas;

#include <string.h>

/** EDITAR APENAS AS 3 FUNCOES ABAIXO */
/*ordena P[1...n]*/
void bubble(Pessoas *P, int n, contador *num_comparacoes, contador *num_movimentos){
    int i, j;
    Pessoas aux;
    contador num_com = 0, num_mov = 0;
    for (i = 1; i < n; i++) {
        for (j = n; j > i; j--) {
            num_com++;
            if (P[j].Chave < P[j - 1].Chave) {
                num_mov = num_mov+2;
                aux = P[j];
                P[j] = P[j - 1];
                P[j - 1]= aux;
            }
        }
    }
    *num_comparacoes = num_com;
    *num_movimentos = num_mov;
}

/*ordena P[1...n]*/
void selection(Pessoas *P, int n, contador *num_comparacoes, contador *num_movimentos){
  int i, j, Min;
  contador num_comp = 0, num_mov = 0;
  Pessoas x;
  for (i = 0; i < n - 1; i++){
    Min = i;
    for (j = i + 1; j < n; j++){
      num_comp++;
      if (P[j].Chave < P[Min].Chave){
        Min = j;
      }
    }
    x = P[Min];
    P[Min] = P[i];
    P[i] = x;
    num_mov = num_mov + 3;
  }
  *num_comparacoes = num_comp;
  *num_movimentos = num_mov;
}

/*ordena P[1...n]*/
void insertion(Pessoas *A, int n, contador *num_comparacoes, contador *num_movimentos){
    int i, j;
    Pessoas x;
    contador num_comp = 0, num_mov = 0;
    for(i=2; i<=n; i++){
        x = A[i];
        j = i - 1;
        A[0] = x;
        num_comp++;
        while(x.Chave<A[j].Chave){
            A[j+1] = A[j];
            j--;
            num_mov++;
        }
        num_mov++;
        A[j+1] = x;
    }
    *num_comparacoes = num_comp;
    *num_movimentos = num_mov;
}


void copia_pessoas(Pessoas * destino, Pessoas * origem, int n){
  for(int i = 1; i <= n; i++){
    destino[i] = origem[i];
  }
}


void verifica_ordenacao(Pessoas * P, int n){
  for(int i = 2; i <= n; i++){
    if(P[i].Chave < P[i-1].Chave){
      printf("Ordenacao invalida.\n");
      exit(EXIT_FAILURE);
    }
  }
}


int main(int argc, char * argv[]){
  int n;
  Pessoas * P, * Q;
  contador num_comparacoes, num_movimentos;

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

  copia_pessoas(Q, P, n);


  bubble(P, n, &num_comparacoes, &num_movimentos);
  printf("%lu %lu\n", num_comparacoes, num_movimentos);

  verifica_ordenacao(P, n);
  copia_pessoas(P, Q, n);

  selection(P, n, &num_comparacoes, &num_movimentos);
  printf("%lu %lu\n", num_comparacoes, num_movimentos);

  verifica_ordenacao(P, n);
  copia_pessoas(P, Q, n);

  insertion(P, n, &num_comparacoes, &num_movimentos);
  printf("%lu %lu\n", num_comparacoes, num_movimentos);

  verifica_ordenacao(P, n);

  /*for(int i = 1; i <= n; i++){
    printf("%d %s\n", P[i].Chave, P[i].name);
  }*/
  return 0;
}

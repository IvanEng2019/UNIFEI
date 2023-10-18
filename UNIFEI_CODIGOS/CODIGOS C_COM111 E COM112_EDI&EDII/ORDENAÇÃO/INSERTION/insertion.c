#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoas{
  int Chave;
  char name[100];
} Pessoas;


/*ordena P[1...n]*/
void selection(Pessoas *P, int n){
  int i, j, Min;
  Pessoas x;
  for (i = 1; i <= n - 1; i++){
    Min = i;
    for (j = i + 1; j <= n; j++){
      if (P[j].Chave < P[Min].Chave){
        Min = j;
      }
    }
    x = P[Min];
    P[Min] = P[i];
    P[i] = x;
  }
}

/*ordena P[1...n]*/
void insertion(Pessoas *A, int n){
    int i, j, Min;
    Pessoas x;
    for( i=2; i<n;i++)
    {
        x=A[i];
        j=i-1;
        A[0]=x; ///sentinela
        while (x.Chave<A[j].Chave)
        {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=x;
    }
}

int main(int argc, char * argv[]){
  FILE *fp;
  int n;
  Pessoas * P;
  fp = fopen(argv[1], "r"); // read mode

  if (fp == NULL){
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

  fscanf(fp, "%d\n", &n);
  P = calloc(sizeof(Pessoas), n+1); //+1 para a sentinela em P[0]
  if(P==NULL){
    perror("Error while allocating memory.\n");
    exit(EXIT_FAILURE);
  }

  for(int i = 1; i <= n; i++){
    fscanf(fp, "%d ", &(P[i].Chave));
    fgets(P[i].name, 100, fp);
    P[i].name[strlen(P[i].name) - 1] = '\0';
  }

  //selection(P, n);
  insertion(P, n);

  for(int i = 1; i <= n; i++){
    printf("%d %s\n", P[i].Chave, P[i].name);
  }
}

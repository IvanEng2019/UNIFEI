/*
BRUNO BRANDAO BORGES 2018014331
ADRIEL NOGUEIRA 2018012346
IVAN LEAONI 2018009073
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int TipoIndice;
typedef long TipoChave;
typedef struct Pessoas{
  TipoChave Chave;
  char name[100];
} Pessoas;


void Particao(int Esq, int Dir, int *i, int *j, Pessoas *A){
	Pessoas x, w, orde[3], temp;
	*i = Esq;
	*j = Dir;
	orde[0]=A[*i];
	orde[1]=A[*j];
	orde[2]=A[(*i+*j)/2];
	int min;
	if((orde[0].Chave==orde[1].Chave)||(orde[0].Chave==orde[2].Chave)){
		x = orde[0];
	}else if(orde[1].Chave==orde[2].Chave){
		x = orde[1];
	}else{
		for(int k = 0; k < 2; k++){
			min = k;
			for(int h = k+1; h<3; h++){
				if(orde[h].Chave<orde[min].Chave) min = h;
			}
			temp = orde[min];
    		orde[min]=orde[k];
    		orde[k]=temp;
		}
		//x = A[(*i + *j)/2];
		x = orde[1];
	}
	do{
		while(x.Chave > A[*i].Chave) (*i)++;
		while(x.Chave < A[*j].Chave) (*j)--;
		if(*i<=*j){
			w = A[*i]; A[*i] = A[*j]; A[*j] = w;
			(*i)++; (*j)--;
		}
	}while(*i<=*j);
}

void Ordena(int Esq, int Dir, Pessoas *A, int n){
	TipoIndice i, j;
	Particao (Esq, Dir, &i, &j, A);
	for(int g = 1; g <= n; g++){
				printf ("%ld ", A[g].Chave);
	}
	printf("\n");
	if(Esq < j) Ordena(Esq, j, A, n);
	if(i < Dir) Ordena(i, Dir, A, n);
}

void QuickSort(Pessoas *A, int n){
	Ordena(1, n, A, n);
}

int main(int argc, char * argv[]){
  int n;
  Pessoas * P;


  scanf("%d\n", &n);

  P = calloc(sizeof(Pessoas), n+1); //+1 para a sentinela em P[0]
  if(P==NULL){
    perror("Error while allocating memory.\n");
    exit(EXIT_FAILURE);
  }

  for(int i = 1; i <= n; i++){
    scanf("%ld ", &(P[i].Chave));
    fgets(P[i].name, 100, stdin);
    P[i].name[strlen(P[i].name) - 1] = '\0';
  }


  QuickSort(P, n);
  for(int i = 1; i <= n; i++){
    printf("%ld %s\n", P[i].Chave, P[i].name);
  }
  return 0;
}

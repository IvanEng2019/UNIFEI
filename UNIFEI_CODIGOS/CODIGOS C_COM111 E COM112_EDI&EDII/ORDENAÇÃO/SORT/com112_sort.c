#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "com112_sort.h"

double bubble_sort(int *dados, int qtd, int *mov, int *comp){
	clock_t start = clock();
  int i, j, aux;
	for (i=0; i<qtd; i++){    //percorre a lista qtd vezes
    j = 0;
		for (j=0;j<qtd-1;j++){    //percorre os numeros da lista
      (*comp)++;
			if (dados[j] > dados[j+1]){     //se o elemento for maior que o proximo, troca posicao
				aux = dados[j];
				dados[j] = dados[j+1];
				dados[j+1] = aux;
        (*mov)++;
			}
		}
	}
  clock_t end = clock();
  double tmp = ((double) (end - start)) / CLOCKS_PER_SEC;
	return tmp;
}

double selection_sort(int *dados, int qtd, int *mov, int *comp){
  clock_t start = clock();
  int i, j, min_marc, aux;
  for (i=0; i<qtd-1; i++){
    min_marc = i;
    for (j=i+1; j<qtd; j++){
      (*comp)++;
      if (dados[j] < dados[min_marc]){    //identifica a posicao do menor elemento da lista em relacao a i
        min_marc = j;
      }
    }
    (*mov)++;
    aux = dados[min_marc];        //troca a posicao do primeiro da "nova lista" pelo menor elemento identificado
    dados[min_marc] = dados[i];
    dados[i] = aux;
  }
  clock_t end = clock();
  double tmp = ((double) (end - start)) / CLOCKS_PER_SEC;
  return tmp;
}


double insertion_sort(int *dados, int qtd, int *mov, int *comp){
  clock_t start = clock();
  int j, i, aux;
  for(i=1; i<qtd; i++){
    (*comp)++;
    aux = dados[i];
    j = i - 1;
    while(j >= 0 && (aux < dados[j])){    //percorre o elemento na lista ate que sua posicao seja encontrada
      dados[j+1] = dados[j];
      j = j - 1;
      (*mov)++;
      (*comp)++;
      (*comp)++;
    }
    dados[j+1] = aux;   //avanca de elemento
  }
  clock_t end = clock();
  double tmp = ((double) (end - start)) / CLOCKS_PER_SEC;
  return tmp;
}


void merge_ascencio(int *dados, int ini, int meio, int fim, int *mov, int *comp){
  int poslivre, inicio_vetor1, inicio_vetor2, i, tam;
  int *aux;

  tam = fim - ini + 1;
	aux = (int *) malloc(tam*sizeof(int));
  inicio_vetor1 = ini;
  inicio_vetor2 = meio + 1;
  poslivre = 0;

  while (inicio_vetor1 <= meio && inicio_vetor2 <= fim){
    (*comp)++;
    if (dados[inicio_vetor1] <= dados[inicio_vetor2]){
      aux[poslivre] = dados[inicio_vetor1];
      inicio_vetor1++;
      poslivre++;
      (*mov)++;
    }
    else{
      aux[poslivre] = dados[inicio_vetor2];
      inicio_vetor2++;
      poslivre++;
      (*mov)++;
    }
  }

  for(i=inicio_vetor1; i<=meio; i++){
    aux[poslivre] = dados[i];
    poslivre++;
    (*mov)++;
  }

  for(i=inicio_vetor2; i<=fim; i++){
    aux[poslivre] = dados[i];
    poslivre++;
    (*mov)++;
  }

  int j = 0;
  for(i=ini; i<=fim; i++){
    dados[i] = aux[j];
    j++;
  }

  free(aux);

  return;
}


double merge_sort(int *dados, int qtd, int ini, int fim, int *mov, int *comp){
  clock_t start = clock();

	int meio;
	if(ini < fim){
		meio = floor((ini+fim)/2);
		merge_sort(dados, qtd, ini, meio, mov, comp);
		merge_sort(dados, qtd, meio+1, fim, mov, comp);
		//merge(dados, ini, meio, fim, mov, comp);
    merge_ascencio(dados, ini, meio, fim, mov, comp);
	}

  clock_t end = clock();
  double tmp = ((double) (end - start)) / CLOCKS_PER_SEC;

  return tmp;
}


int particiona(int *dados, int inicio, int fim, int *mov, int *comp){
  int esq, dir, pivo, aux;
  esq = inicio;
  dir = fim;
  pivo = dados[inicio];
  while(esq < dir){
    while(dados[esq] <= pivo){
      (*comp)++;
      esq++;
    }
    while(dados[dir] > pivo){
      (*comp)++;
      dir--;
    }
    if(esq < dir){
      aux = dados[esq];
      dados[esq] = dados[dir];
      dados[dir] = aux;
      (*mov)++;
    }
  }
  (*mov)++;
  dados[inicio] = dados[dir];
  dados[dir] = pivo;
  return dir;
}

double quicksort(int *dados, int inicio, int fim, int *mov, int *comp){
  clock_t start = clock();
  int pivo;
  if(fim > inicio){
    pivo = particiona(dados, inicio, fim, mov, comp);
    quicksort(dados, inicio, pivo-1, mov, comp);
    quicksort(dados, pivo+1,fim, mov, comp);
  }
  clock_t end = clock();
  double tmp = ((double) (end - start)) / CLOCKS_PER_SEC;

  return tmp;
}


/*
void merge(int *dados, int ini, int meio, int fim, int *mov, int *comp){
	int *temp, p1, p2, tam, i, j, k;
	int fim1=0, fim2=0;
	tam = fim - ini + 1;
	p1 = ini;
	p2 = meio + 1;
	temp = (int *) malloc(tam*sizeof(int));
	if(temp != NULL){
		for(i=0; i<tam; i++){

			if(!fim1 && !fim2){
        (*comp)++; // a comparação deve ser incrementada logo antes desse if que compara elementos do vetor

				if(dados[p1] < dados[p2]){
					temp[i] = dados[p1++];
					(*mov)++;
				}
				else
					temp[i] = dados[p2++];
          (*mov)++;
				if(p1>meio) fim1=1;
				if(p2>fim) fim2=1;
			}else{
				if(!fim1){
					temp[i] = dados[p1++];
          (*mov)++;
        }
				else{
					temp[i] = dados[p2++];
          (*mov)++;
        }
			}
		}
		for(j=0, k=ini; j<tam; j++, k++)
			dados[k] = temp[j];
      (*mov)++;
	}
	free(temp);
	return;
}


*/

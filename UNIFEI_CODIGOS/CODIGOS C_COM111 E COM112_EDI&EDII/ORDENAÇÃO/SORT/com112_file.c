#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "com112_file.h"
#include "com112_sort.h"

int* copia_vetor(int *dados, int qtd){      //aloca um novo vetor e clona o vetor principal (*dados) nesse novo vetor alocado
  int *aux;                                 //funcao auxiliar utilizada para comparacao dos Sort's durante o relatorio
  aux = (int *) malloc(qtd * sizeof(int));
  int i;
  for (i=0; i<qtd; i++){
    aux[i] = dados[i];
  }
  return aux;
}


void escreve_dado(int *dados, int qtd, int aux){      //escreve dados gerados em outras funcoes para os arquivos: com112_entrada.txt ou com112_saida.txt
  int i;
  FILE *file;

  if (aux == 0){
    file = fopen("com112_entrada.txt", "w");
    fprintf(file, "%d\n", qtd);
    for(i=0; i<qtd; i++){
      fprintf(file, "%d ", dados[i]);
   }
    fclose(file);
    }

  else if (aux == 1){
    file = fopen("com112_saida.txt", "w");
    fprintf(file, "%d\n", qtd);
    for(i=0; i<qtd; i++){
      fprintf(file, "%d ", dados[i]);
   }
    fclose(file);
    }

  return;
}


void le_dado(int aux){      //le todos os dados dos arquivos: com112_entrada.txt ou com112_saida.txt
  int i;
  int dado;
  FILE *file;
  if (aux == 0){
    file = fopen("com112_entrada.txt", "r");
    while(fscanf(file, "%d", &dado) != EOF)
      printf("%d ", dado);
    fclose(file);
    }

  else if (aux == 1){
    file = fopen("com112_saida.txt", "r");
    while(fscanf(file, "%d", &dado) != EOF)
      printf("%d ", dado);
    fclose(file);
    }
  return;
}


void escreve_relatorio(int *dados_rel, int qtd, int *mov, int *comp, int temp){     //faz um relatorio completo de todos Sort's de um mesmo vetor de dados

  if (temp == 1){
    relatorio_arquivo(dados_rel, qtd, mov, comp, temp, "com112_relatorio_aleatorio.txt");
  }
  else if (temp == 2){
    relatorio_arquivo(dados_rel, qtd, mov, comp, temp, "com112_relatorio_crescente.txt");
  }
  else if (temp == 3){
    relatorio_arquivo(dados_rel, qtd, mov, comp, temp, "com112_relatorio_decrescente.txt");
  }
  return;
}


void relatorio_arquivo(int *dados_rel, int qtd, int *mov, int *comp, int temp, char nome[40]){
    FILE *file;
    float tmp;
    int *aux;

    aux = copia_vetor(dados_rel, qtd);
    *mov = 0; *comp = 0;
    tmp = bubble_sort(aux, qtd, mov, comp);
    file = fopen( nome, "w");
    fprintf(file, "\nMetodo Bubble Sort\n");
    fprintf(file, "\t\tTempo de execução: %f\n\t\tNúmero de comparações: %d\n\t\tNúmero de movimentações: %d", tmp, *comp, *mov);
    fprintf(file, "\n\n");
    fclose(file);
    printf("\nMetodo Bubble Sort\n");
    printf("\t\tTempo de execução: %f\n\t\tNúmero de comparações: %d\n\t\tNúmero de movimentações: %d\n\n", tmp, *comp, *mov);
    free(aux);

    aux = copia_vetor(dados_rel, qtd);
    *mov = 0; *comp = 0;
    tmp = selection_sort(aux, qtd, mov, comp);
    file = fopen( nome, "a");
    fprintf(file, "\nMetodo Selection Sort\n");
    fprintf(file, "\t\tTempo de execução: %f\n\t\tNúmero de comparações: %d\n\t\tNúmero de movimentações: %d", tmp, *comp, *mov);
    fprintf(file, "\n\n");
    fclose(file);
    printf("\nMetodo Selection Sort\n");
    printf("\t\tTempo de execução: %f\n\t\tNúmero de comparações: %d\n\t\tNúmero de movimentações: %d\n\n", tmp, *comp, *mov);
    free(aux);

    aux = copia_vetor(dados_rel, qtd);
    *mov = 0; *comp = 0;
    tmp = insertion_sort(aux, qtd, mov, comp);
    file = fopen( nome, "a");
    fprintf(file, "\nMetodo Insertion Sort\n");
    fprintf(file, "\t\tTempo de execução: %f\n\t\tNúmero de comparações: %d\n\t\tNúmero de movimentações: %d", tmp, *comp, *mov);
    fprintf(file, "\n\n");
    fclose(file);
    printf("\nMetodo Insertion Sort\n");
    printf("\t\tTempo de execução: %f\n\t\tNúmero de comparações: %d\n\t\tNúmero de movimentações: %d\n\n", tmp, *comp, *mov);
    free(aux);

    aux = copia_vetor(dados_rel, qtd);
    *mov = 0; *comp = 0;
    tmp = merge_sort(aux, qtd, 0, qtd-1, mov, comp);
    file = fopen( nome, "a");
    fprintf(file, "\nMetodo Merge Sort\n");
    fprintf(file, "\t\tTempo de execução: %f\n\t\tNúmero de comparações: %d\n\t\tNúmero de movimentações: %d", tmp, *comp, *mov);
    fprintf(file, "\n\n");
    fclose(file);
    printf("\nMetodo Merge Sort\n");
    printf("\t\tTempo de execução: %f\n\t\tNúmero de comparações: %d\n\t\tNúmero de movimentações: %d\n\n", tmp, *comp, *mov);
    free(aux);

    aux = copia_vetor(dados_rel, qtd);
    *mov = 0; *comp = 0;
    tmp = quicksort(aux, 0, qtd-1, mov, comp);
    file = fopen( nome, "a");
    fprintf(file, "\nMetodo Quick Sort\n");
    fprintf(file, "\t\tTempo de execução: %f\n\t\tNúmero de comparações: %d\n\t\tNúmero de movimentações: %d", tmp, *comp, *mov);
    fprintf(file, "\n\n");
    fclose(file);
    printf("\nMetodo Quick Sort\n");
    printf("\t\tTempo de execução: %f\n\t\tNúmero de comparações: %d\n\t\tNúmero de movimentações: %d\n\n", tmp, *comp, *mov);
    printf("______________________________________________________");
    free(aux);

  return;
  }

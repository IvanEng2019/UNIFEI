#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoas{
  int Chave;
  char name[100];
} Pessoas;


void selection(Pessoas *P, int n){ 
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
    P = calloc(sizeof(Pessoas), n);
    if(P==NULL){
        perror("Error while allocating memory.\n");
        exit(EXIT_FAILURE);
    }
 
    for(int i = 0; i < n; i++){
      fscanf(fp, "%d ", &(P[i].Chave));
      fgets(P[i].name, 100, fp);
      P[i].name[strlen(P[i].name) - 1] = '\0';
    }
    
    selection(P, n);
    
    for(int i = 0; i < n; i++){
      printf("%d %s\n", P[i].Chave, P[i].name);
    }
}

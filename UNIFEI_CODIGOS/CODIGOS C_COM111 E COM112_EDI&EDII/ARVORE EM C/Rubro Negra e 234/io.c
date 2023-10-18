#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* getFileValores(char *arq,int tam){
    FILE *file;
    file = fopen(arq,"r");
    int x,i=0;
    int *v = (int*)malloc(sizeof(int)*tam);
     
    if(!file){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        exit(-1);
    }else{
	while(fscanf(file,"%d\n", &x) != EOF ){
            v[i] = x;
            i++;
        }
    }
    //fclose(file); 
    return v;
}

/*void geraElementos(char *c,int n,int t){
    srand(time(NULL));
    int i;

    FILE *fp = fopen("num.txt","w");
    for(i=0;i<n;i++){
	fprintf(fp,"%d\n",rand()%t);
    }

    fclose(fp);
}

void printVetor(int *v,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",v[i]);
    }
}*/
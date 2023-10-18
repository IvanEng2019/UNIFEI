#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *arq;
	char nome[51];
	int idade;
	int cont = 0;
	
	arq = fopen("ARQUIVO.dat", "w+");
	if(arq==NULL){
		printf("Arquivo invalido");
		exit(1);
	}else{
		for(int i = 0; i<3; i++){
			printf("Entre com o nome: ");
			scanf(" %[^\n]", nome);
			printf("Entre com a idade: ");
			scanf("%d", &idade);
			fprintf(arq, "%s %d\n", nome, idade);
		}
		rewind(arq);
		fscanf(arq, "%s %d", nome, &idade);
		while(!(feof(arq))){
			printf("Dado [%d] Nome[%s] Idade[%d]\n", cont, nome, idade);
			fscanf(arq, "%s %d", nome, &idade);
			
			cont++;
		}
		fclose(arq);
	}
}

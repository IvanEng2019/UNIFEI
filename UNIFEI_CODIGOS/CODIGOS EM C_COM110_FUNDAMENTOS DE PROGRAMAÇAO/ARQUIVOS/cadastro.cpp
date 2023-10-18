#include<stdio.h>
#include<stdlib.h>
int main(){
	int cont = 0;
	char nome[21];
	int idade;
	
	FILE *arq;
	arq = fopen("cadastro.dat", "w+");
	
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
	}
	rewind(arq);
	fscanf(arq, "%s %d", nome, &idade);
	while(!feof(arq)){
		printf("Nome [%s] Idade[%d]\n", nome, idade);
		fscanf(arq, "%s %d", nome, &idade);
		system("pause");
	}
	fclose(arq);
}

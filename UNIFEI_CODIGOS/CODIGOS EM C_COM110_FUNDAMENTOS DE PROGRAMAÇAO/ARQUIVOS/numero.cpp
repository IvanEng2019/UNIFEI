#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *arq;
		
	int num1, num2, cont;	
	arq = fopen("rolaozao.dat", "w+");
	
	if(arq==NULL){
		printf("Invalido");
	}else{
		for(int i = 0; i<3; i++){
			printf("Entre com um numero: ");
			scanf("%d", &num1);
			printf("Entre com outro numero: ");
			scanf("%d", &num2);
			fprintf(arq, "%d %d\n", num1, num2);
		}
	}
	rewind(arq);
		fscanf(arq, "%d %d", &num1, &num2);
		while(!feof(arq)){
			printf("[%d] [%d]\n", num1, num2);
			fscanf(arq, "%d %d", &num1, &num2);			
		}
		fclose(arq);
}

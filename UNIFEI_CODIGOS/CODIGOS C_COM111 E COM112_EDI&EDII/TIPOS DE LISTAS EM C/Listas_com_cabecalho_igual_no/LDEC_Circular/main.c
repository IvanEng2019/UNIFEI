/// Inclusao de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "ILVB_List.h"

///Função principal
int main(){
    int escolha;
    //criação do cabeçalho da lista
    celula *lista=alocaMemoriaCelula();
	iniciaNoCabecalho(lista);//função inicicializa lista com cabeçalho
	do{
		escolha=menu();
		opcao(escolha,lista);
	}while(escolha!=0);
	return 0;
}

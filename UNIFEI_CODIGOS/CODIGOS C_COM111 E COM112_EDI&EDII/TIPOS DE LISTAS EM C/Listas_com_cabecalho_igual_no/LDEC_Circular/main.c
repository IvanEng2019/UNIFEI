/// Inclusao de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "ILVB_List.h"

///Fun��o principal
int main(){
    int escolha;
    //cria��o do cabe�alho da lista
    celula *lista=alocaMemoriaCelula();
	iniciaNoCabecalho(lista);//fun��o inicicializa lista com cabe�alho
	do{
		escolha=menu();
		opcao(escolha,lista);
	}while(escolha!=0);
	return 0;
}

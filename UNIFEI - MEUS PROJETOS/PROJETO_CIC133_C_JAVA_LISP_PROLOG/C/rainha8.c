#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
   
int naoEstaAmeacada(int tabuleiro[8][8], int linha, int coluna){
	int i, j, posicaoBoa = TRUE;

    i = linha - 1;
    while (i >= 0 && posicaoBoa){ // verifica coluna
		posicaoBoa= !tabuleiro[i][coluna];
        i = i - 1;
    }

    i = linha - 1;
    j = coluna + 1;
    while (i >= 0 && j < 8 && posicaoBoa){//verifica diagonal secundaria
		posicaoBoa= !tabuleiro[i][j];
        i--;
        j++;
    }

    i = linha - 1;
    j = coluna - 1;
    while (i >= 0 && j >= 0 && posicaoBoa){//Verifica diagonal principal
		posicaoBoa = !tabuleiro[i][j];
        i--;
        j--;
    }
	return posicaoBoa;
}
   
int colocarRainha(int tabuleiro[8][8], int linha){
    int coluna = 0, posicao = FALSE;

    if (linha >= 8){ //Parada da recursividade
        return TRUE;
    }

    else{
        while (coluna < 8 && !posicao){
            tabuleiro[linha][coluna] = TRUE;
            if (naoEstaAmeacada(tabuleiro,linha,coluna)){//Verifica se a posição é apropriada ♕
                posicao = colocarRainha(tabuleiro,linha + 1);
            }
            if (!posicao){//se a posição não for apropriada
                tabuleiro[linha][coluna] = FALSE;
                coluna = coluna + 1;
            }
        }
        return posicao; 
    }
}

void apresentarTabuleiro(int tabuleiro[8][8]){
    int i, j;
	  for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++){
			if (tabuleiro[i][j]){
				printf("  R");
			}
            else{
				printf("  X");
			}
	    }
		printf("\n\n");
	}
}
   
int main(void){
	int i, j,tabuleiro[8][8];

    printf(" Criacao Tabuleiro 8X8\n\n");
    for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++){
			tabuleiro[i][j] = FALSE;
		}
	}
    apresentarTabuleiro(tabuleiro);

    if (colocarRainha(tabuleiro,0)){
        printf("\n Distribuicao da Rainha tabuleiro 8X8\n\n");
		apresentarTabuleiro(tabuleiro);
    }
    else{
         printf("\n Rainha não pode ser colocada  tabuleiro 8X8.\n");
    }
    system("pause");
    return 0;
}
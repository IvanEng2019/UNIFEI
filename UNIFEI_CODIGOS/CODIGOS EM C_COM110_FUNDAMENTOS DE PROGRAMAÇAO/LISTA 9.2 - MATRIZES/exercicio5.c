/***************************************************************************************************
5. Ler uma matriz quadrada A de dimens�o M (M <= 10) de elementos inteiros. Em seguida, obter seu
elemento minimax. O minimax � o menor elemento da linha que cont�m o maior elemento da matriz.
*****************************************************************************************************/

#include<stdio.h>
#define LIN 3
#define COL 3

 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");//i+j=n-1;
}
int main(){
    cabecalho(); //imprime os dados do aluno
    //freopen("l.in","r",stdin); // copia os dados do arquivo txt
    int mA[LIN][COL];
    for(int i=0;i<LIN;i++)
    {
        for(int j=0;j<COL;j++)
        {
            printf("Entre com o valor da matriz [%d][%d] = ",i,j);
            scanf("%d",&mA[i][j]);
        }
    }
    for(int i=0;i<LIN;i++)
    {
        for(int j=0;j<COL;j++)
        {

        }
    }

    return 0;
}

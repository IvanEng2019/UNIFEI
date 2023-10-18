/***************************************************************************************************
4. Escreva um programa que leia uma matriz 5 x 5 e imprima sua diagonal prim�ria e secund�ria.
Na �lgebra linear, os �ndices (i,j) dos elementos da diagonal secund�ria de uma matriz NxN
apresentam o seguinte comportamento: i+j=N+1. Voc� pode usar esta regra para resolver o problema.
Contudo, em C, os �ndices iniciam em 0 e, na �lgebra linear, os �ndices come�am com1. Logo, voc�
dever� fazer as adapta��es necess�rias para adequar os valores dos �ndices em uma matriz em C.
*****************************************************************************************************/

#include<stdio.h>
#define LIN 5
#define COL 5

 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");//i+j=n-1;
}
int main(){
    cabecalho(); //imprime os dados do aluno
    //freopen("l.in","r",stdin); // copia os dados do arquivo txt
    int m[LIN][COL];
    for(int i=0;i<LIN;i++)
    {
        for(int j=0;j<COL;j++)
        {
            printf("Entre com o valor da matriz [%d][%d] = ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    printf("\nDiagonal prim�ria:");
    for(int i=0;i<LIN;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(i==j)
            printf("\nA matriz [%d][%d]=%d",i,j,m[i][j]);
        }
    }
    printf("\nDiagonal secundaria:");
    for(int i=0;i<LIN;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(i+j==LIN-1)
            printf("\nA matriz [%d][%d]=%d ",i,j,m[i][j]);
        }
    }
    return 0;
}

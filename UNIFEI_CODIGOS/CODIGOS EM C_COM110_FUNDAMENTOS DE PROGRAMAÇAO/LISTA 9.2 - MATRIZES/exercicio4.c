/***************************************************************************************************
4. Escreva um programa que leia uma matriz 5 x 5 e imprima sua diagonal primária e secundária.
Na álgebra linear, os índices (i,j) dos elementos da diagonal secundária de uma matriz NxN
apresentam o seguinte comportamento: i+j=N+1. Você pode usar esta regra para resolver o problema.
Contudo, em C, os índices iniciam em 0 e, na álgebra linear, os índices começam com1. Logo, você
deverá fazer as adaptações necessárias para adequar os valores dos índices em uma matriz em C.
*****************************************************************************************************/

#include<stdio.h>
#define LIN 5
#define COL 5

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
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
    printf("\nDiagonal primária:");
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

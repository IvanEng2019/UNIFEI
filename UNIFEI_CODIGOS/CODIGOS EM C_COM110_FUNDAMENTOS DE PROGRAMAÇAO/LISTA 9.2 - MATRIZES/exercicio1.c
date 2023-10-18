/***************************************************************************************************
1. Escrever um programa que leia os dados e preencha uma matriz de dimensão 5 x 8 e imprima os
os dados digitados. O preenchimento e a impressão dos dados devem ser feitos separados.
*****************************************************************************************************/

#include<stdio.h>
#define LIN 2
#define COL 3

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 07/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    //freopen("l.in","r",stdin); // copia os dados do arquivo txt
    int m[LIN][COL];
    for(int i=0;i<LIN;i++)
    {
        for(int j=0;j<COL;j++)
        {
            printf("Entre com o valor[%d][%d] = ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    for(int i=0;i<LIN;i++)
    {
        for(int j=0;j<COL;j++)
            printf("\nA matriz [%d][%d]=%d ",i,j,m[i][j]);
    }
    return 0;
}

/*****************************************************************************************************
6.Ler duas matrizes A e B de dimensão 5 e elaborar uma matriz C resultante da multiplicação de A por B.

*******************************************************************************************************/
#include<stdio.h>
#define MAX 2

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 07/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno

    float a[MAX][MAX],b[MAX][MAX],c[MAX][MAX],soma;

    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            printf("Entre com o valor de A[%d][%d] = ",i,j);
            scanf("%f",&a[i][j]);
        }
    }
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            printf("Entre com o valor de B[%d][%d] = ",i,j);
            scanf("%f",&b[i][j]);
        }
    }
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            soma=0;
            for(int k=0;k<MAX;k++)
            {
                soma=soma+(a[i][k]*b[k][j]);
            }
            c[i][j]= soma;
        }
    }
    printf(" Vetor C resultante da multiplicação de A por B.\n");
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
            printf("C[%d][%d]=%f\n",i,j,c[i][j]);
    }
    return 0;
}

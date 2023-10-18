/***************************************************************************************************
2-Escreva um programa que preencha uma matriz de dimensão N (N <=10 e deve ser digitado pelo usuário)
e retorne a soma dos elementos positivos da matriz. O preenchimento da matriz deve ser feito
separado do cálculo da soma.
*****************************************************************************************************/

#include<stdio.h>
#define LIM 10

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 07/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    //freopen("l.in","r",stdin); // copia os dados do arquivo txt
    int m[LIM][LIM],n,s=0;
    printf("Entre com o tamanho da matriz");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Entre com o valor[%d][%d] = ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           if(m[i][j]>0)
            s=s+m[i][j];
        }
    }
    printf(" \nA soma é : %d.",s);
    return 0;
}

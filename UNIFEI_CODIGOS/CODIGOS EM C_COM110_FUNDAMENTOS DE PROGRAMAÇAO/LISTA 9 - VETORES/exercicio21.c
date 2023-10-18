/*******************************************************************************************************
Faça um programa que leia um vetor com dez posições para números inteiros. Crie um segundo vetor,
substituindo os valores nulos por 1. Mostre os dois vetores.
********************************************************************************************************/
//inclusão da bibliotecas
#include<stdio.h>

#define MAX 10

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    int v1[MAX],v2[MAX];
    for(int i=0;i<MAX;i++)
    {
        printf("Entre com o valor de V1[%d] =",i);
        scanf(" %d",&v1[i]);
    }
    for(int i=0;i<MAX;i++)
    {
        if(v1[i]=0)
            v2[i]=1;
        else
            v2[i]=v1[i];
    }
    for(int i=0;i<MAX;i++)
    {
        printf("V1[%d]=%d\n",i,v1[i]);
    }
    printf("\n");
    for(int i=0;i<MAX;i++)
    {
        printf("V2[%d]=%d\n",i,v2[i]);
    }
    return 0;
}

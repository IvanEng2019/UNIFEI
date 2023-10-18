/*******************************************************************************************************
Faça um programa que leia dois vetores de dez posições e faça a multiplicação dos elementos de mesmo
índice, colocando o resultado em um terceiro vetor. Mostre o vetor resultante.
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
    float v1[MAX],v2[MAX],v3[2*MAX];
    for(int i=0;i<MAX;i++)
    {
        printf("Entre com o valor de V1[%d] =",i);
        scanf(" %f",&v1[i]);
    }
    for(int i=0;i<MAX;i++)
    {
        printf("Entre com o valor de V2[%d] =",i);
        scanf(" %f",&v2[i]);
    }
    for(int i=0;i<MAX;i++)
    {
        v3[i]=v1[i]*v2[i];
    }
     for(int i=0;i<MAX;i++)
    {
        printf("V3[%d]=%.2f\n",i,v3[i]);
    }
    return 0;
}

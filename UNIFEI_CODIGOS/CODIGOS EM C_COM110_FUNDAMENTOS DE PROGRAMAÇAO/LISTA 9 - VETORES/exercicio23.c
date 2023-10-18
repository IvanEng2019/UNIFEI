/*******************************************************************************************************
Faça um programa que leia dois vetores (A e B) com cinco posições para números inteiros. O program a
deve, então, subtrair o primeiro elemento de A do último de B, acumulando o valor, subtrair o segundo
elemento de A do penúltimo de B, acumulando o valor e assim por diante. Ao final, mostre o resultado
de todas as subtrações realizadas.
********************************************************************************************************/
//inclusão da bibliotecas
#include<stdio.h>

#define MAX 5

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    int va[MAX],vb[MAX],j;
    for(int i=0;i<MAX;i++)
    {
        printf("Entre com o valor de VA[%d] =",i);
        scanf(" %d",&va[i]);
    }
    for(int i=0;i<MAX;i++)
    {
        printf("Entre com o valor de VB[%d] =",i);
        scanf(" %d",&vb[i]);
    }
    for(int i=0;i<MAX;i++)
    {
        j=(MAX-1)-i;
        va[i]=vb[j]-va[i];
    }
    printf("\nO vetor A= VBf[]- VAi[]:\n");
    for(int i=0;i<MAX;i++)
    {
        printf("VA[%d]=%d.\n",i,va[i]);
    }
    return 0;
}

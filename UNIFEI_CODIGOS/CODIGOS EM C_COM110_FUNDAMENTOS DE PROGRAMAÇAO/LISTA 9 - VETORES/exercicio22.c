/*******************************************************************************************************
Fa�a um programa que leia um vetor A de dez posi��es. Em seguida, compacte o vetor, retirando os
valores nulos e negativos. Armazene esse resultado no vetor B. Mostre o vetor B. (Lembre-se: o vetor B
pode n�o ser completamente preenchido.)
********************************************************************************************************/
//inclus�o da bibliotecas
#include<stdio.h>

#define MAX 10

 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    int va[MAX],vb[MAX],pb=0;
    for(int i=0;i<MAX;i++)
    {
        printf("Entre com o valor de VA[%d] =",i);
        scanf(" %d",&va[i]);
    }
    for(int i=0;i<MAX;i++)
    {
        if(va[i]>0)
        {
            vb[pb]=va[i];
            pb++;
        }
    }
    for(int i=0;i<pb;i++)
    {
        printf("VB[%d]=%d\n",i,vb[i]);
    }
    return 0;
}

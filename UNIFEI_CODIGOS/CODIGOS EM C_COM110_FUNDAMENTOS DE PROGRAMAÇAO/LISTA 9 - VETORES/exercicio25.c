/*******************************************************************************************************
Fa�a um programa que leia um vetor com quinze posi��es para n�meros inteiros. Depois da leitura, divida
todos os seus elementos pelo maior valor do vetor. Mostre o vetor ap�s os c�lculos.
********************************************************************************************************/
//inclus�o da bibliotecas
#include<stdio.h>

#define MAX 15
 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    int va[MAX],maior=0;
    for(int i=0;i<MAX;i++)
    {
        printf("Entre com o valor de VA[%d] =",i);
        scanf(" %d",&va[i]);
        if(maior<va[i])
            maior=va[i];
    }
    for(int i=0;i<MAX;i++)
    {

        printf("VA[%d]=%.2f.\n",i,(float)va[i]/maior);
    }
    return 0;
}

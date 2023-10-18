/*******************************************************************************************************
Fa�a um programa que leia um vetor com quinze posi��es para n�meros inteiros. Crie, a seguir, um vetor
resultante que contenha todos os n�meros primos do vetor digitado. Escreva o vetor resultante.
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
    int va[MAX],vr[MAX],pvr=0,aux;
    for(int i=0;i<MAX;i++)
    {
        printf("Entre com o valor de VA[%d] =",i);
        scanf(" %d",&va[i]);
    }
    for(int i=0;i<MAX;i++)
    {
        aux=0;
        for(int j=2;j<=va[i];j++)
        {
           if(va[i]%j==0)
              aux++;
        }
        if(aux==1)
        {
            vr[pvr]=va[i];
            pvr++;
        }
    }
    printf("\vO Vetor resultante :\n");
    for(int i=0;i<pvr;i++)
        printf("VR[%d]=%d.\n",i,vr[i]);
    return 0;
}

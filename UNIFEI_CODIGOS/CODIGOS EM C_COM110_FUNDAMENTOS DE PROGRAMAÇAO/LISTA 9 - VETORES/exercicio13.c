/*******************************************************************************************************
Fa�a um programa que receba o nome e a nota de oito alunos e mostre o relat�rio a seguir:
Digite o nome do 1
o
Digite a nota do Car laolsu:n 8o: Carlos
Digite o nome do 2o aluno: Pedro
Digite a nota do Pedro: 5
Relat�rios de notas
Carlos 8.0
Pedro 5.0
..
M�dia da classe = ??
********************************************************************************************************/
//inclus�o da bibliotecas
#include<stdio.h>
#include <stdlib.h>

#define MAX 8

 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 03/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    float n[MAX], soma=0;
    char nom[MAX];

    for(int i=0;i<MAX;i++)
    {
        setbuf(stdin,NULL);
        printf("Entre com a 1�letra do nome do %d� aluno:",i+1);
        scanf(" %c",&nom[i]);
        printf("Entre com o valor da nota de %c:", nom[i]);
        scanf(" %f",&n[i]);
        soma=soma+n[i];
    }
    printf("\nRelatorio de notas:\n");
    for(int i=0;i<MAX;i++)
    {
        printf("%c %.2f\n",nom[i],n[i]);
    }
    printf("\nM�dia da classe = %2.6f\n",soma/MAX);
    return 0;
}

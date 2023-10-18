/*******************************************************************************************************
Faça um programa que receba o nome e a nota de oito alunos e mostre o relatório a seguir:
Digite o nome do 1
o
Digite a nota do Car laolsu:n 8o: Carlos
Digite o nome do 2o aluno: Pedro
Digite a nota do Pedro: 5
Relatórios de notas
Carlos 8.0
Pedro 5.0
..
Média da classe = ??
********************************************************************************************************/
//inclusão da bibliotecas
#include<stdio.h>
#include <stdlib.h>

#define MAX 8

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
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
        printf("Entre com a 1ªletra do nome do %dº aluno:",i+1);
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
    printf("\nMédia da classe = %2.6f\n",soma/MAX);
    return 0;
}

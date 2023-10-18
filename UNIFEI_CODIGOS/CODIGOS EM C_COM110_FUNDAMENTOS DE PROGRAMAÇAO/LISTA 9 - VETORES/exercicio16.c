/*******************************************************************************************************
Faça um programa que receba o nome de cinco produtos e seus respectivos preços. Calcule e mostre:
■ a quantidade de produtos com preço inferior a R$ 50,00;
■ o nome dos produtos com preço entre R$ 50,00 e R$ 100,00;
■ a média dos preços dos produtos com preço superior a R$ 100,00.

********************************************************************************************************/
//inclusão da bibliotecas
#include<stdio.h>
#include <stdlib.h>

#define MAX 5
 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    float p[MAX];
    char nom[MAX];
    int qtd=0,media=0,soma=0;
    for(int i=0;i<MAX;i++)
    {
        setbuf(stdin,NULL);
        printf("Entre com a 1ªletra do nome do %dº produto:",i+1);
        scanf(" %c",&nom[i]);
        printf("Entre com o valor de %c:", nom[i]);
        scanf(" %f",&p[i]);
    }

    for(int i=0;i<MAX;i++)
    {
        if(p[i]<50)
            qtd++;
        else
            if (p[i]>=50 && p[i]<=100) //printf("\nO nome dos produtos com preço entre R$ 50,00 e R$ 100,00:\n");
                printf("O produto %c tem valor de %2.f\n",nom[i],p[i]);
            else
            {
                media++;
                soma+=p[i];
            }
    }
    printf("A quantidade de produtos com preço inferior a R$ 50,00 é igual a %d.\n",qtd);
    printf("A média dos preços dos produtos com preço superior a R$ 100,00 é igual a %.2f.\n",(float)soma/media);
    return 0;
}

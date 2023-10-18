/*******************************************************************************************************
Faça um programa que preencha três vetores com dez posições cada um: o primeiro vetor, com os nomes de
dez produtos; o segundo vetor, com os códigos dos dez produtos; e o terceiro vetor, com os preços dos produtos.
Mostre um relatório apenas com o nome, o código, o preço e o novo preço dos produtos que sofrerão
aumento.
Sabe-se que os produtos que sofrerão aumento são aqueles que possuem código par ou preço superior a
R$ 1.000,00. Sabe-se ainda que, para os produtos que satisfazem as duas condições anteriores, código e
preço, o aumento será de 20%; para aqueles que satisfazem apenas a condição de código, o aumento será
de 15%; e para aqueles que satisfazem apenas a condição de preço, o aumento será de 10%.
********************************************************************************************************/
//inclusão da bibliotecas
#include<stdio.h>
#include <stdlib.h>

#define MAX 4

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 03/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    float p[MAX];
    int cod[MAX];
    char nom[MAX];

    for(int i=0;i<MAX;i++)
    {
        setbuf(stdin,NULL);
        printf("Entre com a primeira letra do nome do produto:");
        scanf(" %c",&nom[i]);
        printf("Entre com o codigo do produto:");
        scanf(" %d",&cod[i]);
        printf("Entre com o valor do produto:");
        scanf(" %f",&p[i]);
        if(cod[i]%2==0 )
        {
            if(p[i]>1000)
              p[i]=p[i]*1.2;
            else
              p[i]=p[i]*1.15;
        }
        else
        {
           if(p[i]>1000)
              p[i]=p[i]*1.1;
        }
    }
    for(int i=0;i<MAX;i++)
    {
        printf("Produto %c de codigo %d vale %.2f.\n",nom[i],cod[i],p[i]);
    }
    return 0;
}

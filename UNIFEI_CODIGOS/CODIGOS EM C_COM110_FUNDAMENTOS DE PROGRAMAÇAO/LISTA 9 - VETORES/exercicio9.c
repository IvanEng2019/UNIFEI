/*******************************************************************************************************
Fa�a um programa que preencha tr�s vetores com dez posi��es cada um: o primeiro vetor, com os nomes de
dez produtos; o segundo vetor, com os c�digos dos dez produtos; e o terceiro vetor, com os pre�os dos produtos.
Mostre um relat�rio apenas com o nome, o c�digo, o pre�o e o novo pre�o dos produtos que sofrer�o
aumento.
Sabe-se que os produtos que sofrer�o aumento s�o aqueles que possuem c�digo par ou pre�o superior a
R$ 1.000,00. Sabe-se ainda que, para os produtos que satisfazem as duas condi��es anteriores, c�digo e
pre�o, o aumento ser� de 20%; para aqueles que satisfazem apenas a condi��o de c�digo, o aumento ser�
de 15%; e para aqueles que satisfazem apenas a condi��o de pre�o, o aumento ser� de 10%.
********************************************************************************************************/
//inclus�o da bibliotecas
#include<stdio.h>
#include <stdlib.h>

#define MAX 4

 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
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

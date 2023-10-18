/*******************************************************************************************************
Faça um programa que receba o nome de oito clientes e armazene-os em um vetor. Em um segundo vetor,
armazene a quantidade de DVDs locados em 2011 por cada um dos oito clientes. Sabe-se que, parac ada
dez locações, o cliente tem direito a uma locação grátis. Faça um programa que mostre o nome de todos
os clientes, com a quantidade de locações grátis a que ele tem direito.
********************************************************************************************************/
//inclusão da bibliotecas
 #include<stdio.h>
 #include <stdlib.h>

#define MAX 8
 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    char nom[MAX];
    int qtd[MAX],gratis;
    for(int i=0;i<MAX;i++)
    {
        setbuf(stdin,NULL);
        printf("Entre com a 1ªletra do nome do %dº cliente:",i+1);
        scanf(" %c",&nom[i]);
        printf("Entre com a quantidade de DVD :", qtd[i]);
        scanf(" %d",&qtd[i]);
    }

    for(int i=0;i<MAX;i++)
    {
        if(qtd[i]/10>0)
        {
            gratis=qtd[i]/10;
            printf("O cliente %c tem %d alocações gratis.\n",nom[i],gratis);
        }
        else
            printf("O cliente %c não tem alocações gratis.\n",nom[i]);
    }
    return 0;
}

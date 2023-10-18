/*******************************************************************************************************
Fa�a um programa que receba o nome de oito clientes e armazene-os em um vetor. Em um segundo vetor,
armazene a quantidade de DVDs locados em 2011 por cada um dos oito clientes. Sabe-se que, parac ada
dez loca��es, o cliente tem direito a uma loca��o gr�tis. Fa�a um programa que mostre o nome de todos
os clientes, com a quantidade de loca��es gr�tis a que ele tem direito.
********************************************************************************************************/
//inclus�o da bibliotecas
 #include<stdio.h>
 #include <stdlib.h>

#define MAX 8
 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
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
        printf("Entre com a 1�letra do nome do %d� cliente:",i+1);
        scanf(" %c",&nom[i]);
        printf("Entre com a quantidade de DVD :", qtd[i]);
        scanf(" %d",&qtd[i]);
    }

    for(int i=0;i<MAX;i++)
    {
        if(qtd[i]/10>0)
        {
            gratis=qtd[i]/10;
            printf("O cliente %c tem %d aloca��es gratis.\n",nom[i],gratis);
        }
        else
            printf("O cliente %c n�o tem aloca��es gratis.\n",nom[i]);
    }
    return 0;
}

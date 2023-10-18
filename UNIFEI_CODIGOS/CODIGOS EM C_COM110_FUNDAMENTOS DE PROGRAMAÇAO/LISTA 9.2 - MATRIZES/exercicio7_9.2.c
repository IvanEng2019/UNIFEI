/********************************************************************************************************************
Uma empresa possui uma rela��o de N funcion�rios (N < 100), cada um contendo: c�digo (valor inteiro), idade e sal�rio.
 Fa�a um programa para:
a. Elabore uma fun��o que leia as informa��es dos N funcion�rios, considerando que o n�mero m�ximo de funcion�rio � 100
   e que o c�digo 0 significa que n�o existem mais dados.
b. Elabore uma fun��o que retorne o c�digo do funcion�rio mais velho.
c. Elabore uma fun��o que imprima o c�digo e a idade dos funcion�rios que ganham mais que a m�dia dos sal�rios.
***********************************************************************************************************************/

#include<stdio.h>
#define MAX 3

int funcaoA(int cod[], int idade[], float sal[])
{
    int cont=0;
    for(int i=0;i<MAX;i++)
    {
        printf("Entre com o codigo do funcionario %d:",i+1);
        scanf("%d",&cod[i]);
        if(cod[i]!=0)
        {
            printf("Entre com a idade do funcionario %d:",i+1);
            scanf("%d",&idade[i]);
            printf("Entre com o salario do funcionario %d:",i+1);
            scanf("%f",&sal[i]);
            cont++;
        }
        else
            break;
    }
    return cont;
}
int funcaoB(int cod[],int idade[],int qtd)
{
    int velho=0, posvelho,codvelho;
    for(int i=0;i<qtd;i++)
    {
        if (velho<idade[i])
        {
            velho=idade[i];
            posvelho=i;
        }
    }
    codvelho=cod[posvelho];
    return codvelho;
}

void funcaoC (int cod[],int idade[], float sal[],int qtd)
{
    float s=0,m;
    for(int i=0;i<qtd;i++)
    {
        s=s+sal[i];
    }
    m=s/qtd;
    for(int i=0;i<qtd;i++)
    {
        if(sal[i]>m)
            printf("Idade:%d e codigo %d\n",idade[i],cod[i]);
    }
    return;
}
 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");//i+j=n-1;
}
int main(){
    cabecalho(); //imprime os dados do aluno
    //freopen("l.in","r",stdin); // copia os dados do arquivo txt
    int cod[MAX],idade[MAX],qtdf;
    float sal[MAX];
    qtdf=funcaoA(cod,idade,sal);
    printf("Codigo do mais velho %d.\n",funcaoB(cod,idade,qtdf));
    funcaoC(cod,idade,sal,qtdf);
    return 0;
}

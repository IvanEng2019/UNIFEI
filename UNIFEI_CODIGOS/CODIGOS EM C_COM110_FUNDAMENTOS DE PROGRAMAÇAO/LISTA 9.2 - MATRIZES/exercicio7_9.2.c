/********************************************************************************************************************
Uma empresa possui uma relação de N funcionários (N < 100), cada um contendo: código (valor inteiro), idade e salário.
 Faça um programa para:
a. Elabore uma função que leia as informações dos N funcionários, considerando que o número máximo de funcionário é 100
   e que o código 0 significa que não existem mais dados.
b. Elabore uma função que retorne o código do funcionário mais velho.
c. Elabore uma função que imprima o código e a idade dos funcionários que ganham mais que a média dos salários.
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
 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
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

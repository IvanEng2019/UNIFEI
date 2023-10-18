/***************************************************************************************************2-
2-Escreva uma função que receba dois vetores A e B de números inteiros de tamanho = 30 e altere os
elementos do segundo vetor somando os elementos correspondentes de A e B. Como exemplo:
A = {10,20,30,40}
B = {1,2,3,4}, depois da chamada função B = {11,22,33,44}
*****************************************************************************************************/

#include<stdio.h>
#define MAX 5

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");//i+j=n-1;
}
int main(){
    cabecalho(); //imprime os dados do aluno
    //freopen("l.in","r",stdin); // copia os dados do arquivo txt
    int a[MAX],b[MAX];
    for(int i=0;i<MAX;i++)
    {
       printf("Entre com A[%d]=",i);
       scanf("%d",&a[i]);
    }
    for(int i=0;i<MAX;i++)
    {
       printf("Entre com B[%d]=",i);
       scanf("%d",&b[i]);
    }
    for(int i=0;i<MAX;i++)
    {
        b[i]+=a[i];
    }
    for(int i=0;i<MAX;i++)
    {
        printf("B[%d]=%d\n",i,b[i]);
    }
    return 0;
}

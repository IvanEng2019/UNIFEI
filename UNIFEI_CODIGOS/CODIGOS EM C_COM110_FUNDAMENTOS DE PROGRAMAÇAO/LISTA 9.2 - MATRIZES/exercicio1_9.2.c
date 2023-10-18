/***************************************************************************************************
1. Elabore uma função que receba um vetor de inteiros e o tamanho do vetor e retorne o vetor com
todos os números negativos substituídos por 0.
*****************************************************************************************************/

#include<stdio.h>
#define MAX 10

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");//i+j=n-1;
}
int main(){
    cabecalho(); //imprime os dados do aluno
    //freopen("l.in","r",stdin); // copia os dados do arquivo txt
    int v[MAX],n;
    printf("Entre com o tamanho do vetor (v<10):");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       printf("Entre com [%d]=",i);
       scanf("%d",&v[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]<0)
            v[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        printf("v[%d]=%d\n",i,v[i]);
    }
    return 0;
}

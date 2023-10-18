/*******************************************************************************************************
Faça um programa que preencha um vetor com quinze números, determine e mostre:
■ o maior número e a posição por ele ocupada no vetor;
■ o menor número e a posição por ele ocupada no vetor.
********************************************************************************************************/
//inclusão da bibliotecas
 #include<stdio.h>
#include <stdlib.h>

#define MAX 15
 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    float v1[MAX], maior,menor;
    int i=0,pmaior,pmenor;
    printf("Entre com o valor de V1[%d]=",i);
    scanf("%f",&v1[i]);
    maior=v1[i];
    menor=v1[i];
    pmaior=i;
    pmenor=i;
    for(i=1;i<MAX;i++)
    {
        printf("Entre com o valor de V1[%d] =",i);
        scanf(" %f",&v1[i]);
        if(v1[i]>maior)
        {
            pmaior=i;
            maior=v1[i];
        }
        if(v1[i]<menor)
        {
            pmenor=i;
            menor=v1[i];
        }
    }
    printf("O maior número %.2f ocupa a posição %d do vetor.\n",maior,pmaior);
    printf("O menor número %.2f ocupa a posição %d do vetor.\n",menor,pmenor);
    return 0;
}

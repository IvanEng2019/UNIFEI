/****************************************************************************************************
5.	Utilize as funções dos exercícios 3 e 4 em um programa para preencher uma lista de nomes de 10
alunos que deverão ser digitados pelo usuário. Em seguida, substituir um nome da lista por um nome
novo também digitado pelo usuário.
*****************************************************************************************************/

#include <stdio.h>
#include <string.h>

void preencha(char cad[10][101], int tam)
{
    for(int i=0;i<tam;i++)
    {
        printf("Entre com o nome:");
        scanf(" %[^\n]",cad[i]);
    }
    return;
}
void trocaigual(char origem[], char destino[], char nome[50][101],int qtd)
{
    for(int i=0;i<qtd;i++)
    {
        if(strcmp(nome[i],origem)==0)
            strcpy(nome[i],destino);
    }
    return;
}
int main(){

    char cadeia [10][101],origem [101],destino[101];
    preencha(cadeia,10);
    printf("Entre com o nome de origem:");
    scanf(" %[^\n]",origem);
    printf("Entre com o nome de destino:");
    scanf(" %[^\n]",destino);
    trocaigual(origem,destino,cadeia,10);
    printf("nova lista de nomes:\n");
    for(int i=0;i<10;i++)
       printf("Nome:%s\n",cadeia[i]);
return 0;
}

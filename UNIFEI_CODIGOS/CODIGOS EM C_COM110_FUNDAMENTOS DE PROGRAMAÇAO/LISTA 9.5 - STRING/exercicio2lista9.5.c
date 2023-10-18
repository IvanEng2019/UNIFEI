/****************************************************************************************************
2. Elabore uma função que receba uma matriz de nome (tamanho máximo de cada nome = 50) e um nome
(tamanho máximo = 50) e retorne 1 se o nome estiver na matriz e 0, caso contrário.
*****************************************************************************************************/

#include <stdio.h>
#include <string.h> // funçoes de strings:
// strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
// strlen - fornece o tamanho da cadeia
// strcmp - compara se são iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 é maior que a segunda em ordem alfabetica

#define MAX 3

int verifica(char cad[MAX][51], char nom[])
{
    int ver;
    for(int i=0;i<MAX;i++)
    {
        ver=strcmp(cad[i],nom);
        if(ver==0)
        {
            ver=1;
            i=MAX;
        }
        else
            ver=0;
    }
    return ver;
}
int main(){

    char cadeia[MAX][51],nome[51];
    int existe;
    for(int i=0;i<MAX;i++)
    {
        printf("Entre com o nome:");
        scanf(" %[^\n]",cadeia[i]);
    }
    printf("Qual o nome deseja verificar se existe:");
    scanf(" %[^\n]",nome);
    existe=verifica(cadeia,nome);
    if(existe==1)
        printf("Existe o nome");
    else
        printf("Nao este o nome");
return 0;
}

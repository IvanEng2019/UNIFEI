/****************************************************************************************************
4.	Elabore uma função que receba dois nomes (origem e destino), uma matriz de nomes (máximo 50 nomes),
 a quantidade de nomes preenchidos na matriz e substitua toda ocorrência do nome origem pelo nome destino.
 O tamanho máximo de cada nome é 100.
*****************************************************************************************************/

#include <stdio.h>
#include <string.h> // funçoes de strings:
// strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
// strlen - fornece o tamanho da cadeia
// strcmp - compara se são iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 é maior que a segunda em ordem alfabetica

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
    int n;
    char cadeia[50][101],origem [101],destino[101];
    printf("Entre com o numero de nomes da lista:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Entre com o nome:");
        scanf(" %[^\n]",cadeia[i]);
    }
    printf("Entre com o nome de origem:");
    scanf(" %[^\n]",origem);
    printf("Entre com o nome de destino:");
    scanf(" %[^\n]",destino);
    trocaigual(origem,destino,cadeia,n);
    printf("nova lista de nomes:\n");
    for(int i=0;i<n;i++)
       printf("Nome:%s\n",cadeia[i]);
return 0;
}

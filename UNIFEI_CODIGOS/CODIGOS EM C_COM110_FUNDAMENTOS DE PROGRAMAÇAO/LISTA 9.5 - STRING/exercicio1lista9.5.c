/****************************************************************************************************
1. Elabore programa que preencha uma matriz de nomes contendo dois nomes com no máximo 50 caracteres.
Imprima os nomes digitados a partir da leitura da matriz.
*****************************************************************************************************/

#include <stdio.h>
#include <string.h> // funçoes de strings:
// strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
// strlen - fornece o tamanho da cadeia
// strcmp - compara se são iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 é maior que a segunda em ordem alfabetica

int main(){
    char cadeia[2][51];
    for(int i=0;i<2;i++)
    {
        printf("Entre com o nome:");
        scanf(" %[^\n]",cadeia[i]);
    }
    for(int i=0;i<2;i++)
        printf("%s\n",cadeia[i]);
return 0;
}

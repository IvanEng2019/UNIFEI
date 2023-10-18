/*****************************************************************************************
3. Elabore uma função que receba uma cadeia de caractere retorne o tamanho da cadeia. Não
podem ser usadas funções da biblioteca string.h.
******************************************************************************************/

#include <stdio.h>
//#incluse <string.h> // funçoes de strings:
// strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
// strlen - fornece o tamanho da cadeia
// strcmp - compara se são iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 é maior que a segunda em ordem alfabetica

int main(){

    int i=0,qtd=0;
    char cadeia[11];
    printf("Entre com a palavra:");
    scanf(" %[^\n]",cadeia);
    while(cadeia[i]!='\0')
    {
        qtd++;
        i++;
    }
    printf ("A cadeia %s tem tamannho %d\n", cadeia,qtd-1);

return 0;
}

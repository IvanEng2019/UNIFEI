/*****************************************************************************************
3. Elabore uma fun��o que receba uma cadeia de caractere retorne o tamanho da cadeia. N�o
podem ser usadas fun��es da biblioteca string.h.
******************************************************************************************/

#include <stdio.h>
//#incluse <string.h> // fun�oes de strings:
// strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
// strlen - fornece o tamanho da cadeia
// strcmp - compara se s�o iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 � maior que a segunda em ordem alfabetica

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

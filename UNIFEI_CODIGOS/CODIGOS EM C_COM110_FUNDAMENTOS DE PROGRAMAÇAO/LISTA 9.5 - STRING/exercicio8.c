/*****************************************************************************************
8. Escreva uma fun��o em C que leia uma lista de cadeias de caractere do teclado at� que a
cadeia �Acabou� seja digitada e retorne a quantidade de cadeias digitadas.
******************************************************************************************/

#include <stdio.h>
#include <string.h> // fun�oes de strings:
// strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
// strlen - fornece o tamanho da cadeia
// strcmp - compara se s�o iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 � maior que a segunda em ordem alfabetica

int main(){
    int i=0,qtd=0,igual=1;
    char cadeia[100][51];
    while(igual!=0)
    {
        printf("Entre com a cadeia:");
        scanf(" %[^\n]",cadeia[i]);
        qtd++;
        igual=strcmp(cadeia[i],"acabou");
    }
    printf ("A quantidade de linhas � %d\n",qtd-1);
return 0;
}

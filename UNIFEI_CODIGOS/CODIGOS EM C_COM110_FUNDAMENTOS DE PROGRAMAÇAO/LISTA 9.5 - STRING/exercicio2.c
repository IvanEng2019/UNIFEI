/*****************************************************************************************
2. Escreva um programa que leia uma cadeia de caractere com espaço e uma letra e imprima a
quantidade de vezes que a letra ocorre na cadeia de caractere.
******************************************************************************************/

#include <stdio.h>

int main(){

    int i=0,qtd=0;
    char letra,cadeia[11];
    printf("Entre com a palavra:");
    scanf(" %[^\n]",cadeia);
    printf("Entre com a letra que deseja verificar a repetição:");
    scanf(" %c",&letra);
    while(cadeia[i]!='\0')
    {
        if(cadeia[i]==letra)
            qtd++;
        i++;
    }
    printf ("A letra '%c' aparece %d vezes na palavra %s.\n", letra,qtd,cadeia);

return 0;
}

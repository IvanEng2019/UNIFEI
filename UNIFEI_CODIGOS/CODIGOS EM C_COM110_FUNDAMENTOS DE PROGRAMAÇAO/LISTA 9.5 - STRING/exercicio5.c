/*****************************************************************************************
5. Escreva um programa em C que recebe uma cadeia de caracteres de tamanho m�ximo 100 e
retorna 1 se esta cadeia � um pal�ndromo e zero caso contr�rio. Uma palavra � dita ser
pal�ndromo se a sequ�ncia de seus caracteres da esquerda para a direita � igual � sequ�ncia
 de seus caracteres da direita para a esquerda. Ex.: arara.

******************************************************************************************/

#include <stdio.h>
#include <string.h> // fun�oes de strings:
// strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
// strlen - fornece o tamanho da cadeia
// strcmp - compara se s�o iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 � maior que a segunda em ordem alfabetica

int main(){

    int tam,semafaro;
    char cadeia[100];
    printf("Entre com a cadeia:");
    scanf(" %[^\n]",cadeia);
    tam=strlen(cadeia);
    for(int i=0;i<tam/2;i++)
    {
        if(cadeia[i]==cadeia[(tam-1)-i])
            semafaro=1;
        else
        {
            semafaro=0;
            i=tam;
        }

    }
    if(semafaro==1)
        printf ("A cadeia %s � um polindromo.\n", cadeia);
    else
        printf ("A cadeia %s n�o � um polindromo.\n", cadeia);
return 0;
}

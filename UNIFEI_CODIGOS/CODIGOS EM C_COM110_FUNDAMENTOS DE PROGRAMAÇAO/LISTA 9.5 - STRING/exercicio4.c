/*****************************************************************************************
4. Escreva um programa em C que leia uma lista de N cadeias de caractere de tamanho
máximo igual a 50 e armazene a quantidade de caractere de cada cadeia em um vetor de
inteiros. A posição i do vetor de inteiros deve armazenar o tamanho da i-ésima cadeia
digitada. N deve ser fornecido pelo usuário (valor máximo = 10).
Imprima o vetor de tamanhos.
Dica: utilize a função strlen da biblioteca string.h que retorna o tamanho de uma cadeia de
caracter. Por exemplo, strlen(“casa”) é igual a 4.

******************************************************************************************/

#include <stdio.h>
#include <string.h> // funçoes de strings:
// strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
// strlen - fornece o tamanho da cadeia
// strcmp - compara se são iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 é maior que a segunda em ordem alfabetica

int main(){
    int qtd[10],n;
    char cadeia[10][51];
    printf("Entre com o numero de cadeia (tamanho da lista de 1 a 10):");
    scanf(" %d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Entre com a cadeia:");
        scanf(" %[^\n]",cadeia[i]);
        qtd[i]=strlen(cadeia[i]);
    }
    for(int i=0;i<n;i++)
        printf ("A cadeia %s tem tamannho %d\n", cadeia[i],qtd[i]);
return 0;
}

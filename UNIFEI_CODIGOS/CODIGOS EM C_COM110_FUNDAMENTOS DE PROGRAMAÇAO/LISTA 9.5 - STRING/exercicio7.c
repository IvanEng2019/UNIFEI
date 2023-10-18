/*****************************************************************************************
7. Escreva um programa que leia uma linha do teclado e imprima todas as vogais encontradas
no texto e o total de vezes que elas aparecem. O tamanho máximo da linha é 40 caracteres
******************************************************************************************/

#include <stdio.h>
#include <string.h> // funçoes de strings:
// strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
// strlen - fornece o tamanho da cadeia
// strcmp - compara se são iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 é maior que a segunda em ordem alfabetica

int main(){

    int cont=0,tam;
    char cadeia[41];
    printf("Entre com a cadeia:");
    scanf(" %[^\n]",cadeia);
    tam=strlen(cadeia);
    for(int i=0;i<tam;i++)
        if(cadeia[i]=='a'||cadeia[i]=='e'||cadeia[i]=='i'||cadeia[i]=='o'||cadeia[i]=='u')
           {
               printf("vagal[%d]= %c\n",i,cadeia[i]);
               cont++;
           }
    printf("Aparecem %d vogais.\n",cont);
  return 0;
}

/*****************************************************************************************
6. Escreva um programa em C que leia 3 cadeias de caracteres de tamanho máximo 50, e as
imprime na tela em ordem alfabética. Voce pode usar a função strcmp da biblioteca string.h

******************************************************************************************/

#include <stdio.h>
#include <string.h> // funçoes de strings:
// strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
// strlen - fornece o tamanho da cadeia
// strcmp - compara se são iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 é maior que a segunda em ordem alfabetica

int main(){

    int ordem,ret,ret1,ret2;
    char cadeia[3][50];
    for(int i=0;i<3;i++)
   {
        printf("Entre com a cadeia:");
        scanf(" %[^\n]",cadeia[i]);
   }
   ret=strcmp(cadeia[0],cadeia[1]);//se retornar >0 signiffica q a segunda vem antes no alfabeto
   ret1=strcmp(cadeia[0],cadeia[2]);
   ret2=strcmp(cadeia[1],cadeia[2]);

   if (ret<0 && ret1<0)
   {
       printf( "%s - ",cadeia[0]);
       if(ret2<0)
        printf("%s - %s",cadeia[1],cadeia[2]);
       else
         printf("%s - %s",cadeia[2],cadeia[1]);
   }
   if(ret>0 && ret2<0)
   {
       printf( "%s - ",cadeia[1]);
       if(ret1<0)
        printf("%s - %s",cadeia[0],cadeia[2]);
       else
         printf("%s - %s",cadeia[1],cadeia[0]);
   }
   if(ret1>0&&ret2>0)
   {
       printf( "%s - ",cadeia[2]);
       if(ret<0)
        printf("%s - %s",cadeia[0],cadeia[1]);
       else
        printf("%s - %s",cadeia[1],cadeia[0]);
   }
return 0;
}

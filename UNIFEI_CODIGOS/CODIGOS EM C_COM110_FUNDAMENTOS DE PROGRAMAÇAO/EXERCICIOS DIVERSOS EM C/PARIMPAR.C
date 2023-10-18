/* Ler um número e verificar se o número é par ou impar. Em C, o operador % retorna o resto da divisão. */

#include <stdio.h>
int main ()
 {
     int num;
     printf ("Entre com o valor do mumero algorismos:");
     scanf("%d",&num);
     if(num%2==0)
        printf ("\nNumero é par.\n");
     else
        printf("\nNumero é impar.");
     return 0;
 }

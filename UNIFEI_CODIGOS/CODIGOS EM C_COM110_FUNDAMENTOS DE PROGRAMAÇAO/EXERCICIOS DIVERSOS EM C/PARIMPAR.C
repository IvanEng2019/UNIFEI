/* Ler um n�mero e verificar se o n�mero � par ou impar. Em C, o operador % retorna o resto da divis�o. */

#include <stdio.h>
int main ()
 {
     int num;
     printf ("Entre com o valor do mumero algorismos:");
     scanf("%d",&num);
     if(num%2==0)
        printf ("\nNumero � par.\n");
     else
        printf("\nNumero � impar.");
     return 0;
 }

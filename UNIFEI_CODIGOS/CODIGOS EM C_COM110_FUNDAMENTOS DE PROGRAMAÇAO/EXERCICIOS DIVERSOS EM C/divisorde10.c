/*Elabore um programa que leia uma lista de n�meros inteiros at� que um n�mero negativo seja digitado.
Para cada n�mero lido, verificar se o n�mero � divisor de 10 ou n�o */

#include <stdio.h>
int main ()
 {
     int n,i;
     printf ("Entre com o valor de  n:");
     scanf("%d",&n);
     while(n>=0)
     {
         if(n%10==0)
            printf ("E divis�vel por 10.\n");
         else
            printf ("N�o � divisivel por 10.\n");

         printf ("Entre com o valor de  n:");
         scanf("%d",&n);
     }
     return 0;
 }

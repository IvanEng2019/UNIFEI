/*Elabore um programa que leia uma lista de números inteiros até que um número negativo seja digitado.
Para cada número lido, verificar se o número é divisor de 10 ou não */

#include <stdio.h>
int main ()
 {
     int n,i;
     printf ("Entre com o valor de  n:");
     scanf("%d",&n);
     while(n>=0)
     {
         if(n%10==0)
            printf ("E divisível por 10.\n");
         else
            printf ("Não é divisivel por 10.\n");

         printf ("Entre com o valor de  n:");
         scanf("%d",&n);
     }
     return 0;
 }

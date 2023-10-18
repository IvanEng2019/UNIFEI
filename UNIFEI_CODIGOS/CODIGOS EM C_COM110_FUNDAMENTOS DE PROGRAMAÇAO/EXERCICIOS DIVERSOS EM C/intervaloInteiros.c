/*Elabore um programa que leia um número inteiro n e escreva todos os números inteiros entre 1 e este número (inclusive).*/

#include <stdio.h>
int main ()
 {
     int n,i;
     printf ("Entre com o valor n:");
     scanf("%d",&n);
     printf("\nO intervalo de 1 ate %d :\n",n);
     for(i=1;i<=n;i++)
        printf("%d,",i);
     return 0;
 }

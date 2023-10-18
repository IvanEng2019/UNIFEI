/*  Escreva um algoritmo para calcular e exibir o comprimento de uma circunferência,
sendo dado o valor de seu raio. Considere que o raio fornecido será sempre maior que 0.
C = 2 (π) R  */

#include <stdio.h>
#include <math.h>
int main ()
 {
     float r;
     printf ("Entre com o valor do raio:");
     scanf("%f",&r);
     printf("\no comprimento da circunferência:%.2f\n",2*M_PI*r);
     return 0;
 }

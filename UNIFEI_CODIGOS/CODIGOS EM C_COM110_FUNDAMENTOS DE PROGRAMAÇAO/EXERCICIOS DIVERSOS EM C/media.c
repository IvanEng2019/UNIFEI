/* Escreva um algoritmo para calcular e exibir a m�dia ponderada de 2 notas dadas.
(nota 1 tem peso 6 e nota 2 tem peso 4)  */

#include <stdio.h>
int main ()
 {
     float n1,n2,m;
     printf ("Entre com os valores da 1� e 2� nota:");
     scanf("%f %f",&n1,&n2);
     m = (n1*6 + n2*4)/10;
     printf("A media ponderada �:%.2f\n",m);
     return 0;
 }

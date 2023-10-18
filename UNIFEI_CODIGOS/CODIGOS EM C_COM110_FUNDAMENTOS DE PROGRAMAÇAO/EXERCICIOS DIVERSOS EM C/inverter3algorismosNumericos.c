/* Dado um número inteiro positivo de 3 algarismos, inverter a ordem de seus algarismos.
Os três algarismos do número dado são diferentes de zero.  */

#include <stdio.h>
int main ()
 {
     int num,c,d,u;
     printf ("Entre com o valor do mumero de 3 algorismos:");
     scanf("%d",&num);
     c=num/100;
     d=(num%100)/10;
     u=(num%100)%10;
     printf("O valor do num invertido é: %d%d%d",u,d,c);
     return 0;
 }

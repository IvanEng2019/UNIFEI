/* Dado um n�mero inteiro positivo de 3 algarismos, inverter a ordem de seus algarismos.
Os tr�s algarismos do n�mero dado s�o diferentes de zero.  */

#include <stdio.h>
int main ()
 {
     int num,c,d,u;
     printf ("Entre com o valor do mumero de 3 algorismos:");
     scanf("%d",&num);
     c=num/100;
     d=(num%100)/10;
     u=(num%100)%10;
     printf("O valor do num invertido �: %d%d%d",u,d,c);
     return 0;
 }

/*Elabore um programa que leia dois n�meros n e m (m>=n) e escreva todos os n�meros pares entre n e m.
 interromper quando n=0 */

#include <stdio.h>
int main ()
 {
     int n,m,i;
     printf ("Entre com o valor de m e n onde (M>=n):");
     scanf("%d %d",&m,&n);
     if(m>=n)
     {
         printf("\nOs numeros pares entre %d e %d :\n",n,m);
         for(i=n+1;i<m;i++)
         {
            if(i%2==0)
              printf("%d,",i);
         }
     }
     else
        printf("M � menor que n!\n");
     return 0;
 }

 /* Escreva um algoritmo para calcular as ra�zes de uma equa��o do segundo grau (Ax2 + Bx + C).
 Considere que o valor de A <> 0 e (B2 � 4AC) > 0. Escreva os valores na tela*/
#include <stdio.h>
#include <math.h>

 int main ()
 {
     float a,b,c,d,r1,r2;
     printf("Entre com os valores de a,b e c:");
     scanf("%f %f %f",&a,&b,&c);
     if (a!=0)
     {
        d=sqrt(b*b-4*a*c);
        if (d>0)
        {
            r1=-b+d/(2*a);
            r2=-b-d/(2*a);
            printf("Os valores das 2 raizes s�o: %f e %f.\n",r1,r2);
        }
        else
        {
            if(d=0)
            {
               r1=-b+d/(2*a);
               r2=r1;
               printf("Os valores da raizes s�o iguais: %f e %f.\n",r1,r2);
            }
            else
               printf("N�o existe raizes reais!\n");
        }
     }
     else
        printf ("N�o � uma equa��o do 2� grau.\n");
     return 0;
 }

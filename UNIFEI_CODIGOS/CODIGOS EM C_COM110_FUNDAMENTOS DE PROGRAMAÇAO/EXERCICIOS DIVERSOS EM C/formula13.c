/*  O cosseno de um ângulo X (em radianos) pode ser calculado utilizando-se a série

COS(X) = 1 – X2/2! + X4/4!- X6/6! + x8/8! - x10/10!...
Escrever um algoritmo que leia um valor para X, calcule e escreva o valor da soma dos 10 primeiros termos da série.
Voce deve usar uma estrutura de repetição.

 */
#include <stdio.h>
#include <math.h>
int main ()
 {
    int i,aux,x,f,fat;
    float cos,p;
    cos=1.0;
    aux=0;
    printf("Entre com x:");
    scanf("%d",&x);
    for(i=2;i<=20;i=i+2)//1,2,4,8,10,12,14,16,18,20 - ate 10 termo
    {
       fat=1;
       p=(float)pow(x,i);
       for(f=1;f<=i;f++)
          fat=fat*f;
       if (aux==0)
       {
          cos=cos - p/(float)fat;
          aux=1;

       }
       else
       {
          cos= cos + p/(float)fat;
          aux=0;

       }
    }
    printf("S=%.3f\n",cos);
    return 0;
 }

/* Elabore um programa em C para calcular e escrever a seguinte soma:
   s=37x38/1 +36x37/2 +35x36/3 +...+1x2/37*/
#include <stdio.h>
int main ()
 {
    int i;
    float aux,s;
    s=0;
    aux=38;
    for(i=1;i<38;i++)
    {
        s=(s+aux*(aux-1))/(float)i;
        aux=aux-1;
    }
    printf("S=%f\n",s);
    return 0;
 }

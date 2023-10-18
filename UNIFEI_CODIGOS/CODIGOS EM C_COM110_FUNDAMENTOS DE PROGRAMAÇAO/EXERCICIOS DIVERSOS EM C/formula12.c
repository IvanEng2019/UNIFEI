/*  Elabore um programa em C que calcule e imprima a seguinte soma:
    s=1/1+3/2+5/3+7/4+..+99/50
 */
#include <stdio.h>
int main ()
 {
    int i;
    float aux,s;
    s=0;
    aux=1;
    for(i=1;i<51;i++)
    {
        s=(s+aux)/(float)i;
        aux=aux+2;
    }
    printf("S=%f\n",s);
    return 0;
 }

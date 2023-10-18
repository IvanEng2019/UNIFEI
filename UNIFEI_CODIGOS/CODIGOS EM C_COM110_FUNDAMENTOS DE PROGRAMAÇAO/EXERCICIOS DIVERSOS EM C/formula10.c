/* . Elabore um programa em C que calcule e imprima o somatório expresso pela seguinte série:
s=500/2 + 480/3 + 460/4+...+ 20/26
 */

#include <stdio.h>
int main ()
 {
    int i;
    float aux,s;
    s=0;
    aux=500;
    for(i=2;i<27;i++)
    {
        s=s+aux/(float)i;
        aux=aux-20;
    }
    printf("S=%.3f\n",s);
    return 0;
 }

/* Elabore um algoritmo para calcular e imprimir o valor de S, sendo S = -1/2 + 2/4 - 3/6 + 4/8 -5/10 +, ..., +10/20.
 */
#include <stdio.h>
int main ()
 {
    int i;
    float s;
    s=0.0;
    for(i=1;i<11;i++)
    {
        if (i%2==0)
            s=s+ (float)(i/(2*i));
        else
            s=s- (float)(i/(2*i));
    }
    printf("\nO valor de s é %.2f.\n",s);
    return 0;
 }

/*  Dados dois números inteiros positivos determinar quantas vezes o primeiro divide exatamente o segundo.
 Se o primeiro não divide o segundo, o número de vezes exibido deve ser zero. */

#include <stdio.h>
int main ()
 {
    int n1,n2,r,cont;
    printf("Entre com dois numeros:");
    scanf ("%d %d",&n1,&n2);
    cont=0;
    if(n1<n2)
    {
        while (n2!=0)
        {
            r=n2-n1; //6-2=4 4-2=2 2-2=0
            n2=r;
            cont++;
        }
        printf("\nO numero de vezes que divide é %d\n",cont);
    }
    else
         printf("\nO numero de vezes que divide é %d\n",cont);
    return 0;
 }

/*  Dados dois n�meros inteiros positivos determinar quantas vezes o primeiro divide exatamente o segundo.
 Se o primeiro n�o divide o segundo, o n�mero de vezes exibido deve ser zero. */

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
        printf("\nO numero de vezes que divide � %d\n",cont);
    }
    else
         printf("\nO numero de vezes que divide � %d\n",cont);
    return 0;
 }

#include <stdio.h>
int main ()
 {
    int a,b,i;
    printf ("Porta logica E:\n A  B  SAIDA\n");//sera 1 (v) quando toDas entradas forem verdade
    for(i=0;i<4;i++) //0,1,2,3
    {
     a=i%2;
     b=(i/2)%2;
     printf (" %d %2d %4d\n",a,b,a&&b);
    }
    printf ("\nPorta logica ou:\n A  B  SAIDA\n");//sera 1 (v) quando apenas uma entrada ou mais for verdade (1)
    for(i=0;i<4;i++)
    {
     a=i%2;
     b=(i/2)%2;
     printf (" %d %2d %4d\n",a,b,a||b);
    }
    printf ("\nPorta logica xor (EOU/xou):\n A  B  SAIDA\n"); //saida sera 1(v) quando o nº de entradas 1 forem impares
    for(i=0;i<4;i++)
    {
     a=i%2;
     b=(i/2)%2;
     printf (" %d %2d %4d\n",a,b,a^b);
    }
    printf ("Porta logica NÃO:\n A  SAIDA\n");
    for(i=0;i<2;i++) //0,1,2,3
    {
     a=i%2;
     printf (" %d %4d\n",a,!a);
    }
    printf ("Porta logica NÃO:\n A   B  NâoA NãoB NãoAeB NãoAouB NãoAXOUB\n");
    for(i=0;i<4;i++) //0,1,2,3
    {
     a=i%2;
     b=(i/2)%2;
     printf (" %d %3d %4d %4d %4d %7d %7d\n",a,b,!a,!b,!(a&&b),!(a||b), !(a^b) );
    }

  return 0;
 }

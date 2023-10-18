#include <stdio.h>
int main ()
 {
    int a,b,c,i;
    printf ("Porta logica E:\n A  B  C  SAIDA\n");
    for(i=0;i<8;i++)
    {
     a=i%2;
     b=(i/2)%2;
     if(i<4)
     c=0;
     else
     c=1;
     printf (" %d %2d %2d %4d\n",a,b,c,a&&b&&c);
    }
    printf ("Porta logica OU:\n A  B  C  SAIDA\n");
    for(i=0;i<8;i++)
    {
     a=i%2;
     b=(i/2)%2;
     if(i<4)
     c=0;
     else
     c=1;
     printf (" %d %2d %2d %4d\n",a,b,c,a||b||c);
    }
    printf ("Porta logica XOU:\n A  B  C  SAIDA\n");
    for(i=0;i<8;i++)
    {
     a=i%2;
     b=(i/2)%2;
     if(i<4)
     c=0;
     else
     c=1;
     printf (" %d %2d %2d %4d\n",a,b,c,a^b^c);
    }
    printf ("Porta logica NÃO:\n A   B   C NâoA NãoB NãoC NãoAeBeC NãoAouBouC NãoAxouBxouC\n");
    for(i=0;i<8;i++) //0,1,2,3
    {
     a=i%2;
     b=(i/2)%2;
     if(i<4)
     c=0;
     else
     c=1;
     printf (" %d %3d %3d %4d %4d %4d %7d %7d %7d\n",a,b,c,!a,!b,!c,!(a&&b&&c),!(a||b||c),!(a^b^c) );
    }
  return 0;
 }

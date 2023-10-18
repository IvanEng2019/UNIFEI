/* Suponha que no ano N a população dos EUA seja maior que a brasileira.
Sabendo-se que os Estados Unidos possuem um crescimento anual de 2% na sua população e que o
Brasil tem crescimento anual de 4%, determine o ano em que as duas populações serão iguais (em quantidade).
dados os numero de ahabitates de ambos os paises no ano n
*/

#include <stdio.h>
int main ()
 {
    float pb,pe;
    int ano;
    printf("Entre com o ano:");
    scanf("%d",&ano);
    printf("Entre com a população do Brasil e do EUA Respectivamente\n Onde pop EUA > pop Brasil:");
    scanf("%f %f",&pb,&pe);
    while(pe!= pb)
    {
        pb=pb*1,04;
        pe=pe*1,02;
        ano=ano+1;
    }
    printf ("O ano será %d\n",ano);
    return 0;
 }

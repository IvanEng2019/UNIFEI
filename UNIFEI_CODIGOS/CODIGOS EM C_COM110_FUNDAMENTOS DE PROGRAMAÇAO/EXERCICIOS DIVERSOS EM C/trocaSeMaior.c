/* Ler dois números, armazenando-os nas variáveis num1 e num2.
Verificar se o valor de num1 é maior que o valor de num2 e, em caso positivo, trocar os conteúdos das variáveis.  */

#include <stdio.h>
int main ()
 {
     int num1,num2,aux;
     printf ("Entre com o valor dos 2 mumeros:");
     scanf("%d %d",&num1,&num2);
     if(num1>num2)
     {
        aux=num1;
        num1=num2;
        num2=aux;
        printf("\n Os numeros foram trocados. num1=%d e num2=%d.\n",num1, num2);
     }
     else
         printf("\n Como num 1 < num2 Os numeros não foram trocados:num1=%d e num2=%d.\n",num1,num2);
     return 0;
 }

/* Ler dois n�meros, armazenando-os nas vari�veis num1 e num2.
Verificar se o valor de num1 � maior que o valor de num2 e, em caso positivo, trocar os conte�dos das vari�veis.  */

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
         printf("\n Como num 1 < num2 Os numeros n�o foram trocados:num1=%d e num2=%d.\n",num1,num2);
     return 0;
 }

/********************************************************************************************************************
Quest�o 2. Elabore uma fun��o que receba um n�mero inteiro e retorne 1 se o n�mero recebido for positivo ou retorne 0,
 se o n�mero for negativo.Elabore um programa que receba um n�mero inteiro (digitado no teclado) e utilize a fun��o
 criada para informar ao usu�rio se o n�mero � positivo ou negativo. Caso o n�mero seja 0, emitir uma mensagem para
 o usu�rio informando que a entrada � inv�lida.
********************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca

int posNeg (int a){//fun��o que retorna 1 se o n�mero recebido for positivo ou 0 se negativo
 if (a>0)
    return 1;
 else
   return 0;
}

int main (){//fun��o principal
    int num,x;//declara��o de variaveis locais
    printf ("Entre com o vlor do numero inteiro:");
    scanf("%d",&num);
    if (num!=0)//caso seja digitado qualquer numero diferente de0
    {
        x=posNeg(num);
        if(x==1)//caso seja retornado o valor 1
            printf("Positivo.\n");
        else //caso seja retornado o valor 0
            printf("Negativo.\n");
    }
    else //caso seja digitado 0
        printf("\nEntrada invalida!\nDigite numero diferente de zero!\n");
return 0;
}



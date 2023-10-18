/********************************************************************************************************************
Questão 2. Elabore uma função que receba um número inteiro e retorne 1 se o número recebido for positivo ou retorne 0,
 se o número for negativo.Elabore um programa que receba um número inteiro (digitado no teclado) e utilize a função
 criada para informar ao usuário se o número é positivo ou negativo. Caso o número seja 0, emitir uma mensagem para
 o usuário informando que a entrada é inválida.
********************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca

int posNeg (int a){//função que retorna 1 se o número recebido for positivo ou 0 se negativo
 if (a>0)
    return 1;
 else
   return 0;
}

int main (){//função principal
    int num,x;//declaração de variaveis locais
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



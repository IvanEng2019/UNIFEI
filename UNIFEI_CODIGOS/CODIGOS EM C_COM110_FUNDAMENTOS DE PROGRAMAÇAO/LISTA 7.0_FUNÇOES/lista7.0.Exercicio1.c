/********************************************************************************************************************
Quest�o 1. Elabore uma fun��o que receba dois n�meros inteiros (a e b) e retorne a soma desses valores.
Elabore uma fun��o para imprimir a seguinte cadeia de caracter na tela: A soma {a,b} =
A cadeia de caracter acima deve obrigatoriamente come�ar em uma nova linha.
Contudo, o cursor n�o deve pular de linha depois de imprimir a cadeia.
Elabore um programa que leia dois valores digitados no teclado e utilize as duas fun��es criadas para
imprimir o valor da soma na tela da seguinte forma:
A soma {a,b} = valor da soma
********************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca

int soma (int a,int b){ // fun�ao que retorna a soma de dois valores inteiros
    return a+b; // a e b variaveis locais, reconhecidas apenas por soma ( da propria fun��o)
}

void imprima(){ //fun��o que imprime na tela: A soma {a,b} =
     printf ("A soma {a,b} = ");
}

int main (){ //fun��o principal
    int a,b,s; // variaveis locais de main()
    printf("Entre com dois numeros:");
    scanf("%d %d",&a,&b);
    s=soma(a,b);//chamada da fun��o soma atribuindo uma copia do valor a e b respetivamente para a e b da fun��o soma
    imprima();
    printf("%d.\n",s);
return 0;
}

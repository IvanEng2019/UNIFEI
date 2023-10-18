/********************************************************************************************************************
Questão 1. Elabore uma função que receba dois números inteiros (a e b) e retorne a soma desses valores.
Elabore uma função para imprimir a seguinte cadeia de caracter na tela: A soma {a,b} =
A cadeia de caracter acima deve obrigatoriamente começar em uma nova linha.
Contudo, o cursor não deve pular de linha depois de imprimir a cadeia.
Elabore um programa que leia dois valores digitados no teclado e utilize as duas funções criadas para
imprimir o valor da soma na tela da seguinte forma:
A soma {a,b} = valor da soma
********************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca

int soma (int a,int b){ // funçao que retorna a soma de dois valores inteiros
    return a+b; // a e b variaveis locais, reconhecidas apenas por soma ( da propria função)
}

void imprima(){ //função que imprime na tela: A soma {a,b} =
     printf ("A soma {a,b} = ");
}

int main (){ //função principal
    int a,b,s; // variaveis locais de main()
    printf("Entre com dois numeros:");
    scanf("%d %d",&a,&b);
    s=soma(a,b);//chamada da função soma atribuindo uma copia do valor a e b respetivamente para a e b da função soma
    imprima();
    printf("%d.\n",s);
return 0;
}

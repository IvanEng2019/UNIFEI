/*
======================================================================================
Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
Professora  : MELISE MARIA VEIGA DE PAULA
Autores :     Ivan Leoni Vilas Boas - RU: 2018009073

Data atual  : 15/04/2018
======================================================================================
Exercício 11: while
Elabore um programa que leia uma lista de números inteiros até que um número negativo
seja digitado. Para cada número lido, verificar se o número é divisor de 10 ou não.

======================================================================================
*/

#include <stdio.h> // inclusão de biblioteca com funçoes de entrada e saida

//inicio do programa principal
int main()
{
    int n;
    printf("Entre com o numero:");
        scanf("%d",&n);
    while (n>=0)
    {
        if(n%10==0)
           printf("É divisivel por 10.\n");
        printf("Entre com o numero:");
        scanf("%d",&n);
    }
return 0;
}

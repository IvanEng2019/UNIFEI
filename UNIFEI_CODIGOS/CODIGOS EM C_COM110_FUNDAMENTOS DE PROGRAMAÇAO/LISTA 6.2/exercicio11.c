/*
======================================================================================
Disciplina  : FUNDAMENTOS DE PROGRAMA��O
Professora  : MELISE MARIA VEIGA DE PAULA
Autores :     Ivan Leoni Vilas Boas - RU: 2018009073

Data atual  : 15/04/2018
======================================================================================
Exerc�cio 11: while
Elabore um programa que leia uma lista de n�meros inteiros at� que um n�mero negativo
seja digitado. Para cada n�mero lido, verificar se o n�mero � divisor de 10 ou n�o.

======================================================================================
*/

#include <stdio.h> // inclus�o de biblioteca com fun�oes de entrada e saida

//inicio do programa principal
int main()
{
    int n;
    printf("Entre com o numero:");
        scanf("%d",&n);
    while (n>=0)
    {
        if(n%10==0)
           printf("� divisivel por 10.\n");
        printf("Entre com o numero:");
        scanf("%d",&n);
    }
return 0;
}

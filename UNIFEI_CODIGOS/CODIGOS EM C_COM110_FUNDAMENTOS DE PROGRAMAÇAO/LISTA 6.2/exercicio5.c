/*
======================================================================================
Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
Professora  : MELISE MARIA VEIGA DE PAULA
Autores :     Ivan Leoni Vilas Boas - RU: 2018009073

Data atual  : 12/04/2018
======================================================================================
Exercício 5:
Calcular o valor da sequência abaixo definida por recorrência:
S(i) = i2*S(i-1), para i=1, S=1, n deve ser fornecido pelo usuário.
A função pow(x,y) da biblioteca math.h devolve x elevado a y (o resultado da função é
sempre um valor do tipo double)
======================================================================================
*/

#include <stdio.h> // inclusão de biblioteca com funçoes de entrada e saida
#include <math.h> // inclusão de biblioteca com funçoes matematicas

//inicio do programa principal
int main()
{
    int i;
    int s=1;
    int n;
    printf("Entre com o valor de n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        s=(int)pow(i,2)*s;
    }
    printf("O valor de s é %d.\n",s);
return 0;
}

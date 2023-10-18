/*
======================================================================================
Disciplina  : FUNDAMENTOS DE PROGRAMA��O
Professora  : MELISE MARIA VEIGA DE PAULA
Autores :     Ivan Leoni Vilas Boas - RU: 2018009073

Data atual  : 12/04/2018
======================================================================================
Exerc�cio 5:
Calcular o valor da sequ�ncia abaixo definida por recorr�ncia:
S(i) = i2*S(i-1), para i=1, S=1, n deve ser fornecido pelo usu�rio.
A fun��o pow(x,y) da biblioteca math.h devolve x elevado a y (o resultado da fun��o �
sempre um valor do tipo double)
======================================================================================
*/

#include <stdio.h> // inclus�o de biblioteca com fun�oes de entrada e saida
#include <math.h> // inclus�o de biblioteca com fun�oes matematicas

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
    printf("O valor de s � %d.\n",s);
return 0;
}

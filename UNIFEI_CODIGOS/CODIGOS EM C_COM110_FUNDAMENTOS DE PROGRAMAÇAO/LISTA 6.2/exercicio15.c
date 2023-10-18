/*
======================================================================================
Disciplina  : FUNDAMENTOS DE PROGRAMA��O
Professora  : MELISE MARIA VEIGA DE PAULA
Autores :     Ivan Leoni Vilas Boas - RU: 2018009073

Data atual  : 15/04/2018
======================================================================================
Exerc�cio 15: while
O departamento de marketing de uma editora est� com o problema de calcular o
ponto de equil�brio para qualquer livro que se prop�e publicar. O ponto de equil�brio
representa o valor do pre�o de venda que cobre os custos de produ��o. J� os custos
de produ��o consistem em um custo fixo mais um custo de c�pia que � igual ao
n�mero estimado de c�pias multiplicado pelo n�mero de p�ginas. Logo:
custo de produ��o = custo fixo + (num estimado de c�pias x num de p�ginas)
Leia uma lista contendo, para cada livro, o identificador do livro (valor inteiro), o
custo fixo, o n�mero estimado de c�pias e o n�mero de p�ginas e imprima:
� o custo de produ��o de cada livro,
� o c�digo identificador e o custo do livro com o maior custo de produ��o.
Considere que o custo de produ��o ser� sempre diferente. Al�m disso, o programa
deve ser encerrado quando for digitado um identificador negativo.
======================================================================================
*/

#include <stdio.h> // inclus�o de biblioteca com fun�oes de entrada e saida

//inicio do programa principal
int main()
{
    int i,cop, pag, iaux, maior=0;;
    float, custo, cp;
    printf ("Entre com o identificador do livro (valor inteiro), o custo fixo, o n�mero estimado de c�pias e o n�mero de p�ginas:");
    scanf("%d %f %d %d",&i, &custo, &cop, &pag);

    while (i!=0)
    {
        cp=custo+ cop*pag;
        printf("O custo de produ��o � : %.2f",cp);
        if(maior<cp)
        {
            maior=cp;
            iaux=i;
        }
        printf ("Entre com o identificador do livro (valor inteiro), o custo fixo, o n�mero estimado de c�pias e o n�mero de p�ginas:");
        scanf("%d %f %d %d",&i, &custo, &cop, &pag);
    }
    printf("o maior custo � %.2f do identificador �: %d.\n", maior,iaux);
return 0;
}

/*
======================================================================================
Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
Professora  : MELISE MARIA VEIGA DE PAULA
Autores :     Ivan Leoni Vilas Boas - RU: 2018009073

Data atual  : 15/04/2018
======================================================================================
Exercício 15: while
O departamento de marketing de uma editora está com o problema de calcular o
ponto de equilíbrio para qualquer livro que se propõe publicar. O ponto de equilíbrio
representa o valor do preço de venda que cobre os custos de produção. Já os custos
de produção consistem em um custo fixo mais um custo de cópia que é igual ao
número estimado de cópias multiplicado pelo número de páginas. Logo:
custo de produção = custo fixo + (num estimado de cópias x num de páginas)
Leia uma lista contendo, para cada livro, o identificador do livro (valor inteiro), o
custo fixo, o número estimado de cópias e o número de páginas e imprima:
• o custo de produção de cada livro,
• o código identificador e o custo do livro com o maior custo de produção.
Considere que o custo de produção será sempre diferente. Além disso, o programa
deve ser encerrado quando for digitado um identificador negativo.
======================================================================================
*/

#include <stdio.h> // inclusão de biblioteca com funçoes de entrada e saida

//inicio do programa principal
int main()
{
    int i,cop, pag, iaux, maior=0;;
    float, custo, cp;
    printf ("Entre com o identificador do livro (valor inteiro), o custo fixo, o número estimado de cópias e o número de páginas:");
    scanf("%d %f %d %d",&i, &custo, &cop, &pag);

    while (i!=0)
    {
        cp=custo+ cop*pag;
        printf("O custo de produção é : %.2f",cp);
        if(maior<cp)
        {
            maior=cp;
            iaux=i;
        }
        printf ("Entre com o identificador do livro (valor inteiro), o custo fixo, o número estimado de cópias e o número de páginas:");
        scanf("%d %f %d %d",&i, &custo, &cop, &pag);
    }
    printf("o maior custo é %.2f do identificador é: %d.\n", maior,iaux);
return 0;
}

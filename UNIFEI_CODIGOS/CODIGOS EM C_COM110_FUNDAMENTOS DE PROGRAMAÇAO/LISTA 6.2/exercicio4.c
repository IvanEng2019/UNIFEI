/*
=====================================================================================
Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
Professora  : MELISE MARIA VEIGA DE PAULA
Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
           Fabricio Guedes da Silva - RU: 2018014476
Data atual  :09/04/2018
======================================================================================
Exercício 4:
Elabore um algoritmo para calcular e imprimir H, sendo H = 1 + ½ + 1/3 + ¼ + ...1/N;
onde o N deve ser fornecido pelo usuário.
======================================================================================
*/

#include <stdio.h> //inclui a biblioteca de funções de entrada e saida

//inicia-se o progrma principal
int main()
{
    //declaração de variaveis globais
    float n; //variavel que recebera o valor fornecido pelo usuario e contolará a parada do laço de repetição
    float h; //variavel que recebera o resultado da formula estabelecida H = 1 + ½ + 1/3 + ¼ + ...1/N
    int i; //varivel que auxiliará a execução do laço de repetição

    //inicialização de variaveis
    h=0;//atribui-se 0 a variavel h

    //solicitação de entrada de dados
    printf("Entre com o valor de n:\n");//pede para o usuario o valor de n
    scanf("%f",&n); //salva o valor no endereço de menoria

    //executa o laço de repetição
    for(i=1;i<=n;i++)// para o i de 0 a n executa o laço
    {
        h=h+(1/(float)i);//calcula a formula especificada H = 1 + ½ + 1/3 + ¼ + ...1/N
    }
    printf("O valor de H é %.2f\n",h);//fornece o resultado de H ao usuario
return 0;
}

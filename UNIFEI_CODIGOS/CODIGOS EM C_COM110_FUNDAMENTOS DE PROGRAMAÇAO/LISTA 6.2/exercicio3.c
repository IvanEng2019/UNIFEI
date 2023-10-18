/*
======================================================================================
Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
Professora  : MELISE MARIA VEIGA DE PAULA
Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
           Fabricio Guedes da Silva - RU: 2018014476
Data atual  :09/04/2018
======================================================================================
Exercício 3:
Elabore um algoritmo para calcular e imprimir o valor dos seguintes somatórios:
• ∑i de i=1 até 20
• ∑i2 de i=1 até 20
======================================================================================
*/

#include <stdio.h> // inclusão de biblioteca com funçoes de entrada e saida

//inicio do programa principal
int main()
{
    //inicialização de variaveis
    int i, soma1, soma2;
    //atribuições de variavel
    soma1=0; // atribui 0 a soma1
    soma2=0; // atribui 0 a soma2

    //executa o laco de repetição para realizar a soma 1 e 2
    for(i=1;i<=20;i++)
    {
        soma1=soma1+i; // faz o somatorio ∑i
        soma2=soma2+(i*i);// faz o somatorio ∑i2
    }
    //imprime na tela o resultado para o usuario
    printf("O valor de ∑i de i=1 até 20 e igual a %d\nO valor de ∑i2 de i=1 até 20 é igual a %d\n",soma1,soma2);

return 0;
}

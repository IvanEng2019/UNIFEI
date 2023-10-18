/*
Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
Professora  : MELISE MARIA VEIGA DE PAULA
Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
           Fabricio Guedes da Silva - RU: 2018014476
Data atual  :09/04/2018
======================================================================================
Exercício 2:
Faça um programa que leia o salário de um funcionário, calcule o salário reajustado de
acordo com a regra abaixo e imprima o novo salário.
• salários até 300, reajuste 50%
• salários maiores que 300, reajuste 30%
*/

#include <stdio.h> //inclui biblioteca com função de entrada e saida

//começa o programa principal
int main()
{
    float sal; //declara variavel salario
    printf("Entre com o salario do funcionario\n");//pede a vaiavel ao usuário
    scanf("%f",&sal);//salava valor fornecido no endereço de memoria

    if(sal>0 && sal<=300) //se o salrio for maior que 0 e menor ou igual a 300 o reajuste será de 50%
        printf ("O novo salario é: %.2f\n",sal*1.5);
    else
    {
        if (sal>300) //se o salrio for maior que 300 o reajuste será de 30%
            printf ("O novo salario é: %.2f\n",sal*1.3);
        else
            printf ("Não exite salario igual ou inferior a 0.");//se o salario for igual ou menor a zero impossibilidade ou inexistencia de salario
    }
return 0;
}

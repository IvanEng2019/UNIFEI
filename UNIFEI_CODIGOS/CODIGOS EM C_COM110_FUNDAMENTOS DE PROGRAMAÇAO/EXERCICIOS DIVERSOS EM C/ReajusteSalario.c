/*Faça um programa que leia o salário de um funcionário, calcule o salário reajustado de acordo
com a regra abaixo e imprima o novo salário.
• salários até 300, reajuste 50%
• salários maiores que 300, reajuste 30%*/

#include <stdio.h>
int main ()
 {
     float sal;
     printf ("Entre com o valor do salario:");
     scanf("%f",&sal);
     if(sal<=300)
        sal=sal*1.5;
     else
        sal=sal*1.3;
     printf("\nO salario atualizado é:%.3f\n",sal);
     return 0;
 }

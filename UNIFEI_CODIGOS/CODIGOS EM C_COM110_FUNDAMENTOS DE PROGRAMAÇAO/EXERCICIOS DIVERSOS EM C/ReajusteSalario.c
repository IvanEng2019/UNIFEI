/*Fa�a um programa que leia o sal�rio de um funcion�rio, calcule o sal�rio reajustado de acordo
com a regra abaixo e imprima o novo sal�rio.
� sal�rios at� 300, reajuste 50%
� sal�rios maiores que 300, reajuste 30%*/

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
     printf("\nO salario atualizado �:%.3f\n",sal);
     return 0;
 }

/*Faça um algoritmo que receba o peso de uma pessoa, calcule e mostre:
a. O novo peso quando a pessoa engorda 15% do peso digitado
b. O novo peso quando a pessoa engorda 20% do peso digitado  */

#include <stdio.h>
#include <math.h>
int main ()
 {
     float p,paux;
     printf ("Entre com o valor do peso:");
     scanf("%f",&p);
     paux=p;
     printf("\no peso aumentado em 15% é:%.3f.",p*1.15);
     printf("\no peso aumentado em 20% é:%.3f.",paux*1.2);
     return 0;
 }

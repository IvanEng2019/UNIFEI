/*Escreva um algoritmo para calcular e escrever a área de um triângulo,
sendo dados a sua base e a sua altura (Área = (base X altura) / 2)   */

#include <stdio.h>

int main ()
 {
     float b,h;
     printf ("Entre com o valor do base e altura respectivamente:");
     scanf("%f %f",&b,&h);
     printf("\nA area do triangulo é:%.2f.\n",(b*h/2));
     return 0;
 }

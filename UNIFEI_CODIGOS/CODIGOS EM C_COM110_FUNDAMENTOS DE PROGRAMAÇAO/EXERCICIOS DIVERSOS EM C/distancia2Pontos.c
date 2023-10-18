 /* Construa um algoritmo que, tendo como dados de entrada dois pontos quaisquer do plano,
  P(x1,y1) e Q(x2, y2), imprima a distância entre eles.*/

#include <stdio.h>
#include <math.h>

 int main ()
 {
     float x1,x2,y1,y2,d;
     printf ("Entre com os valores do ponto A ( x1 e y1):");
     scanf("%f %f",&x1, &y1);
     printf ("Entre com os valores do ponto B ( x2 e y2):");
     scanf("%f %f",&x2, &y2);
     d=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
     printf("A distância entre os pontos A e B : %2f \n",d);
     return 0;
 }

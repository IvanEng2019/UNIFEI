/*A partir de valores digitados pelo usuário, das notas b1 e b2 de um aluno,
 informar se ele foi aprovado (media > = 6), reprovado (media < 3), ou se ficou de exame (3<=media<6).
  Se ficou de exame, solicitar a nota do exame ex e informar se o aluno foi aprovado ou reprovado.*/

#include <stdio.h>
int main ()
 {
     float num1,num2,ex;
     printf ("Entre com o valor dos 2 notas:");
     scanf("%f %f",&num1,&num2);
     if((num1+num2)/2>=6)
        printf("Aprovado!\n");
     else
     {
         if((num1+num2)/2<3)
            printf("Reprovado!\n");
         else
         {
             printf ("Entre com a nota do exame:");
             scanf("%f",&ex);
             if (ex>=6)
                 printf("Aprovado!\n");
             else
                 printf ("Reprovado!\n");
         }
     }
     return 0;
 }

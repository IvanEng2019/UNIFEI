/*Considere um caixa automático com apenas um repositório com capacidade para armazenar 1000 notas de 10 reais.
 Elabore um algoritmo para ler um valor e fornecer a quantidade de notas correspondente a esse valor.
 O repositório começa sempre com 1000 notas. A cada valor digitado, o seu algoritmo deve manter a quantidade de notas
 no repositório atualizada. Caso o valor lido não possa ser fornecido por falta de notas, o algoritmo deve imprimir
 uma mensagem indicando o fato. O algoritmo também deve imprimir uma mensagem se o valor não for múltiplo de 10.
 Após o tratamento do valor lido, com a impressão da mensagem ou o fornecimento da quantidade de notas,
o procedimento deve ser repetido solicitando ao usuário que digite um novo valor.
O algoritmo deve parar quando um valor lido for negativo ou quando não houver mais notas para o saque */

#include <stdio.h>
int main ()
 {
     int valor,qtdC,vtotal;
     qtdC=1000;
     vtotal=10000;
     printf ("Entre com o valor:");
     scanf("%d",&valor);
    while((valor>0) && (qtdC!=0))
    {
        if (valor <= vtotal)
        {
           if(valor%10==0)
           {
              printf ("O valor da quantidade de notas de 10 são: %d.\n",valor/10);
              vtotal= vtotal-valor;
              qtdC= qtdC -(valor/10);
              printf("\nA quantidade de notas no caixa de 10 são:%d\n",qtdC);
              printf("O valor no caixa são:%d\n",vtotal);
           }
           else
             printf("Não é multiplo de 10!.\n");
        }
        else
            printf("Valor insuficiente no caixa:%d\n",vtotal);
        if(qtdC==0)
                  printf("A nota acabou!\n");
        else
        {
           printf ("\nEntre com o valor:");
           scanf("%d",&valor);
        }
    }
     return 0;
 }

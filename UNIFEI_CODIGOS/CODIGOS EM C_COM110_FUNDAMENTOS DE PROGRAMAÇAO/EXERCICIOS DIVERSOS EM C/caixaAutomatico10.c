/*Considere um caixa autom�tico com apenas um reposit�rio com capacidade para armazenar 1000 notas de 10 reais.
 Elabore um algoritmo para ler um valor e fornecer a quantidade de notas correspondente a esse valor.
 O reposit�rio come�a sempre com 1000 notas. A cada valor digitado, o seu algoritmo deve manter a quantidade de notas
 no reposit�rio atualizada. Caso o valor lido n�o possa ser fornecido por falta de notas, o algoritmo deve imprimir
 uma mensagem indicando o fato. O algoritmo tamb�m deve imprimir uma mensagem se o valor n�o for m�ltiplo de 10.
 Ap�s o tratamento do valor lido, com a impress�o da mensagem ou o fornecimento da quantidade de notas,
o procedimento deve ser repetido solicitando ao usu�rio que digite um novo valor.
O algoritmo deve parar quando um valor lido for negativo ou quando n�o houver mais notas para o saque */

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
              printf ("O valor da quantidade de notas de 10 s�o: %d.\n",valor/10);
              vtotal= vtotal-valor;
              qtdC= qtdC -(valor/10);
              printf("\nA quantidade de notas no caixa de 10 s�o:%d\n",qtdC);
              printf("O valor no caixa s�o:%d\n",vtotal);
           }
           else
             printf("N�o � multiplo de 10!.\n");
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

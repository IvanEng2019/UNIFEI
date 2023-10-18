/*Escreva um programa que exiba o menu abaixo e retorne o valor de acordo com a opção
desejada. Caso o usuário escolher uma opção diferente das apresentadas, exibir uma
mensagem informando o erro.
Digite a opção:
1- Multiplicar x e y
2- Dividir x e y
3- Sair do programa */

#include <stdio.h> // inclussão de biblioteca com funções de entrada e saida

int main() {

//declaração de variaveis
int opcao,aux;
float x,y;

//fornece o menu pro usuario escolher qual operação realizar
printf("Escolha uma das opções:\n1- Multiplicar x e y \n2- Dividir x e y\n3- Sair do programa\n");
scanf("%d", &opcao);

aux=1;

while (aux!=0)
{
       switch (opcao)
       {
               case 1:
                        printf("Entre com o valor de  x e y respectivamente:\n");
                        scanf("%f %f", &x, &y);
                        printf ("A multiplicação é: %.2f",x*y);
                        break;
               case 2:
                        printf("Entre com o valor de  x e y respectivamente:\n");
                        scanf("%f %f", &x, &y);
                        if(y!=0)
                          printf ("A divisão é: %.2f",x/y);
                        else
                        printf ("Não existe divisão por zero.\n");

                        break;
                case 3:
                        aux=0;
                        break;
                default:
                        printf ("Erro escolha a opção correta.\n");

       }
       if (aux==1)
       {
           printf("\nEscolha uma das opções:\n1- Multiplicar x e y \n2- Dividir x e y\n3- Sair do programa\n");
           scanf("%d", &opcao);
       }
}
return 0;
}

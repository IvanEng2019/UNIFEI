/*
Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
Professora   : MELISE MARIA VEIGA DE PAULA
Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
           Fabricio Guedes da Silva - RU: 2018014476
Data atual  :09/04/2018
==================================================================================
Exercício 1:
Escreva um programa que exiba o menu abaixo e retorne o valor de acordo com a opção
desejada. Caso o usuário escolher uma opção diferente das apresentadas, exibir uma
mensagem informando o erro.
Digite a opção:
1- Multiplicar x e y
2- Dividir x e y
3- Sair do programa
*/

#include <stdio.h> // inclusão de biblioteca com funções especoficas de entrada e saida

//inicio do programa principal
int main() {

    //declaração de variaveis
    int opcao; //represta a escolha do usuario
    int aux;// controla o laço de repetição. se opção igual a 3 encerra o programa
    float x,y; // representará os numeros fornecidos pelo usuario caso opte por opção 1 ou 2

    //fornece o menu pro usuario escolher qual operação realizar
    printf("Escolha uma das opções:\n1- Multiplicar x e y \n2- Dividir x e y\n3- Sair do programa\n");
    scanf("%d", &opcao);

    //atribuições
    aux=1; //inicializa aux com 1

    //inicia o laço de repetição
    while (aux!=0)// enquando o aux for diferente de 0 o laço ira se repetir
    {
       if (opcao==1)//caso o usuario opte pela opção 1
       {
           printf("Entre com o valor de  x e y respectivamente:\n");
           scanf("%f %f", &x, &y);
           printf ("A multiplicação é: %.2f\n",x*y);
       }
       else
       {
           if(opcao==2)//caso o usuario opte pela opção 2
           {
              printf("Entre com o valor de  x e y respectivamente:\n");
              scanf("%f %f", &x, &y);
              if(y!=0)// valor do y tem de ser diferente de zero
                 printf ("A divisão é: %.2f\n",x/y);
              else // mensagem ao usuario caso tente dividir qualquer numero por 0
                 printf ("Não existe divisão por zero.\n");
            }
            else // caso o usuario opite por 3 encerra o laço e o programa
            {
                if(opcao==3)
                   aux=0; // atribui-se 1 a variavel aux
                else // caso o usuario escolha qualquer opção diferente de 1,2 e 3
                   printf ("Erro escolha a opção correta.\n");
            }
       }
 // depois de ter feito a escolha inicial caso o usuario opte por continuar escolhendo:
       if (aux==1) // executara se o usuario não optou por 3
       {
           printf("\nEscolha uma das opções:\n1- Multiplicar x e y \n2- Dividir x e y\n3- Sair do programa\n");
           scanf("%d", &opcao);
       }
    }
return 0;
}

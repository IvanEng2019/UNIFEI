/****************************************************************************************************************************
5. Faça um programa que imprima invertidos os nomes dos algarismos de um número inteiro de três dígitos. Use a sua função
no programa principal. Não é necessário validar a entrada do número. Ex: 234 saída: quatro três dois.
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca
void cabecalho();

void div(int n, int *c, int *d,int *u)
{
    *c=n/100;
    *d=(n%100)/10;
    *u=(n%100)%10;
}
void imprime(int num)
{
    switch(num)
    {
      case 1: printf ("Um ");
      break;
      case 2: printf ("Dois ");
      break;
      case 3: printf ("Tres ");
      break;
      case 4: printf ("Quatro ");
      break;
      case 5: printf ("Cinco ");
      break;
      case 6: printf ("Seis ");
      break;
      case 7: printf ("Sete ");
      break;
      case 8: printf ("Oito ");
      break;
      case 9: printf ("Nove ");
      break;
      default: printf ("Zero ");

    }

}

int main (){ //função principal
    cabecalho();

    int n,pc,pu,pd;
    printf("\nEntrar com o valor do numero de 3 algarismos:");
    scanf(" %d",&n);
    div(n,&pc,&pd,&pu);
    imprime(pu);
    imprime(pd);
    imprime(pc);

    printf("\n");for(int i=0;i<100;i++) printf("=");
return 0;
}

void cabecalho(){ // funçao que imprime cabeçalho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informação\nDisciplina:Fundamentos de Programação\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajubá.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nPrograma imprime o numeral em ordem contraria.\n");
}

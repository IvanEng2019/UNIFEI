/****************************************************************************************************************************
3. Fa�a uma fun��o que receba um valor inteiro como refer�ncia e retorne o resto da divis�o deste n�mero por 10.
Altere tamb�m o valor da vari�vel passada por refer�ncia, dividindo-a por 10.
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca
void cabecalho();

int funcD(int *div)
{
     int n=*div;
     *div= *div/10;
     return n%10;
}

int main (){ //fun��o principal
    cabecalho();

    int num, resto;
    printf("\nEntrar com o valor  inteiro:");
    scanf(" %d",&num);
    resto=funcD(&num);
    printf("O resto da divis�o = %d e numero agora vale %d.\n",resto, num);

    printf("\n");for(int i=0;i<100;i++) printf("=");
return 0;
}

void cabecalho(){ // fun�ao que imprime cabe�alho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informa��o\nDisciplina:Fundamentos de Programa��o\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajub�.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nPrograma mostra o resta da divis�o por 10 e o inteiro da divis�o.\n");
}

/****************************************************************************************************************************
4. Fa�a uma fun��o que receba um par�metro (inteiro por valor) com o total de minutos passados ao longo do dia e receba
 tamb�m dois par�metros (inteiros por refer�ncia) no qual deve preencher com o valor da hora e do minuto corrente.
 Fa�a um programa que leia do teclado quantos minutos se passaram desde meia-noite e imprima a hora corrente (use a sua fun��o).
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca
void cabecalho();

void meianoite( int min, int *hora, int *m)
{
    *hora=min/60;
    *m=min%60;
    return;

}

int main (){ //fun��o principal
    cabecalho();

    int minutos,h,mc;
    printf("\nEntrar com o valor dos minutos passados:");
    scanf(" %d",&minutos);
    meianoite(minutos,&h,&mc);
    printf("\nA hora corrente � %d:%d.",h,mc);

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
   return;
}

/****************************************************************************************************************************
4. Faça uma função que receba um parâmetro (inteiro por valor) com o total de minutos passados ao longo do dia e receba
 também dois parâmetros (inteiros por referência) no qual deve preencher com o valor da hora e do minuto corrente.
 Faça um programa que leia do teclado quantos minutos se passaram desde meia-noite e imprima a hora corrente (use a sua função).
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca
void cabecalho();

void meianoite( int min, int *hora, int *m)
{
    *hora=min/60;
    *m=min%60;
    return;

}

int main (){ //função principal
    cabecalho();

    int minutos,h,mc;
    printf("\nEntrar com o valor dos minutos passados:");
    scanf(" %d",&minutos);
    meianoite(minutos,&h,&mc);
    printf("\nA hora corrente é %d:%d.",h,mc);

    printf("\n");for(int i=0;i<100;i++) printf("=");
return 0;
}

void cabecalho(){ // funçao que imprime cabeçalho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informação\nDisciplina:Fundamentos de Programação\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajubá.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nPrograma mostra o resta da divisão por 10 e o inteiro da divisão.\n");
   return;
}

/****************************************************************************************************************************
Quest�o 1. Elabore uma fun��o que receba uma hora completa (hora/minuto/segundo) e converta para segundo.
Use a fun��o no programa principal para converter um valor hora completo fornecido pelo usu�rio.
Dica: um dos par�metros recebidos pela fun��o deve ser o endere�o da vari�vel que
dever� guardar o resultado da convers�o.
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // fun�ao que imprime cabe�alho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informa��o\nDisciplina:Fundamentos de Programa��o\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajub�.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nPrograma que converte o numero de horas em segundos\n");
}

void segundos(int h, int min, int seg, int *pResp){
     *pResp= (h*3600) + (min*60) + seg;
}

int main (){ //fun��o principal
    cabecalho();

    int h,m,s,resp;
    printf ("\nEntre com valor das horas:");
    scanf(" %d",&h);
    printf ("\nEntre com valor dos minutos:");
    scanf(" %d",&m);
    printf ("\nEntre com valor dos segundos:");
    scanf(" %d",&s);
    segundos(h,m,s,&resp);
    printf("O valor de %d horas em segundos � %d.",h,resp);

    printf("\n");for(int i=0;i<100;i++) printf("=");
return 0;
}

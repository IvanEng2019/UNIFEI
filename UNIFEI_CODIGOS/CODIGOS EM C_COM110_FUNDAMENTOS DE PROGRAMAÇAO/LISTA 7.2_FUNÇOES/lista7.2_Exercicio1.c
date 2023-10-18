/****************************************************************************************************************************
Questão 1. Elabore uma função que receba uma hora completa (hora/minuto/segundo) e converta para segundo.
Use a função no programa principal para converter um valor hora completo fornecido pelo usuário.
Dica: um dos parâmetros recebidos pela função deve ser o endereço da variável que
deverá guardar o resultado da conversão.
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // funçao que imprime cabeçalho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informação\nDisciplina:Fundamentos de Programação\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajubá.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nPrograma que converte o numero de horas em segundos\n");
}

void segundos(int h, int min, int seg, int *pResp){
     *pResp= (h*3600) + (min*60) + seg;
}

int main (){ //função principal
    cabecalho();

    int h,m,s,resp;
    printf ("\nEntre com valor das horas:");
    scanf(" %d",&h);
    printf ("\nEntre com valor dos minutos:");
    scanf(" %d",&m);
    printf ("\nEntre com valor dos segundos:");
    scanf(" %d",&s);
    segundos(h,m,s,&resp);
    printf("O valor de %d horas em segundos é %d.",h,resp);

    printf("\n");for(int i=0;i<100;i++) printf("=");
return 0;
}

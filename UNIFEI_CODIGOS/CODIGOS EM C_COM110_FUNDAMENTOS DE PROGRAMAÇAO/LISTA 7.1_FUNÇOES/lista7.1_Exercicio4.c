/**********************************************************************************************************
4. Fa�a uma fun��o que recebe por par�metro o raio de uma esfera e calcula o seu volume (v = 4/3.P .R3).
***********************************************************************************************************/
#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // fun�ao que imprime cabe�alho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informa��o\nDisciplina:Fundamentos de Programa��o\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajub�.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nCalcula o Volume de uma esfera:\n");
}

float volEsfera (int r){//fun��o que retorna o volume da esfera
    return (4/3*3.14*r*r*r); //pow (base,expoente)
}

int main (){ //fun��o principal
    cabecalho();
    float raio;
    printf("\nEntre com valor do raio:");//solicita��o de valor ao usuario
    scanf("%f",&raio);//entrada de valores
    printf("O valor do volume da espera de raio %.3f � %.4f.\n\n",raio,volEsfera(raio));

    for(int i=0;i<100;i++) printf("=");
return 0;
}

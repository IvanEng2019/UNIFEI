/********************************************************************************************************************
Quest�o 4. Fa�a uma fun��o que imprima na tela o seguinte cabe�alho:
Curso Sistemas de Informa��o
Disciplina � Fundamentos de Programa��o
Universidade Federal de Itajub�
N�o � necess�rio implementar a fun��o principal. Nos demais exerc�cios, use essa fun��o para imprimir esse cabe�alho.
Com o que sabemos, voc� vai precisar copiar o c�digo dessa fun��o para o c�digo dos respectivos programas.
********************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // fun�ao que imprime cabe�alho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informa��o\nDisciplina:Fundamentos de Programa��o\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajub�.\n");
    for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
}

int main (){ //fun��o principal
    cabecalho();
return 0;
}

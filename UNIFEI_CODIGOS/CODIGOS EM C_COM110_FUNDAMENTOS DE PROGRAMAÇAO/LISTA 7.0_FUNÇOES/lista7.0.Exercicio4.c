/********************************************************************************************************************
Questão 4. Faça uma função que imprima na tela o seguinte cabeçalho:
Curso Sistemas de Informação
Disciplina – Fundamentos de Programação
Universidade Federal de Itajubá
Não é necessário implementar a função principal. Nos demais exercícios, use essa função para imprimir esse cabeçalho.
Com o que sabemos, você vai precisar copiar o código dessa função para o código dos respectivos programas.
********************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // funçao que imprime cabeçalho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informação\nDisciplina:Fundamentos de Programação\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajubá.\n");
    for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
}

int main (){ //função principal
    cabecalho();
return 0;
}

/**********************************************************************************************************
1. Escreva uma fun��o que receba o ano e escreva o seguinte menu na tela:
Programa de Treinamento em C
Universidade Federal de Itajub�
Curso Sistemas de Informa��o
Nome: (30 espa�os) Ano_Recebido
Os comandos de formato da fun��o printf podem ter modificadores que especificam a largura do campo, n�mero de casas
decimais e o alinhamento (direita ou esquerda). Veja os dois exemplos a seguir:
� %8d: imprime o valor inteiro com largura igual a 20. Se o valor a ser impresso tiver menos de 8 d�gitos,
ser� deixado um espa�o em branco antes do n�mero at� que a largura do n�mero na tela tenha 8 d�gitos.
� %.4f indica que o valor float ser� impresso com 4 casas decimais.
Para cada formato, um determinado modificador pode ter um efeito diferente.
Pesquise na bibliografia indicada no plano da disciplina, como usar os modificadores de formato na fun��o printf.
Este assunto ser� cobrado em prova.
***********************************************************************************************************/
#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // fun�ao que imprime cabe�alho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informa��o\nDisciplina:Fundamentos de Programa��o\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajub�.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
}

void menu(int a){//fun��o imprime menu
    printf("Programa de Treinamento em C\nUniversidade Federal de Itajub�\nCurso Sistemas de Informa��o\n");
    printf("Nome:%34d",a);
}

int main (){ //fun��o principal
    int ano;
    printf ("Entre com o ano:");
    scanf("%d",&ano);
    menu(ano);
return 0;
}

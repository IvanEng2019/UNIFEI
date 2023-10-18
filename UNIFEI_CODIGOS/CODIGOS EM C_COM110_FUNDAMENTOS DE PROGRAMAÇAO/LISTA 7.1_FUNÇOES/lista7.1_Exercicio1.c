/**********************************************************************************************************
1. Escreva uma função que receba o ano e escreva o seguinte menu na tela:
Programa de Treinamento em C
Universidade Federal de Itajubá
Curso Sistemas de Informação
Nome: (30 espaços) Ano_Recebido
Os comandos de formato da função printf podem ter modificadores que especificam a largura do campo, número de casas
decimais e o alinhamento (direita ou esquerda). Veja os dois exemplos a seguir:
• %8d: imprime o valor inteiro com largura igual a 20. Se o valor a ser impresso tiver menos de 8 dígitos,
será deixado um espaço em branco antes do número até que a largura do número na tela tenha 8 dígitos.
• %.4f indica que o valor float será impresso com 4 casas decimais.
Para cada formato, um determinado modificador pode ter um efeito diferente.
Pesquise na bibliografia indicada no plano da disciplina, como usar os modificadores de formato na função printf.
Este assunto será cobrado em prova.
***********************************************************************************************************/
#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // funçao que imprime cabeçalho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informação\nDisciplina:Fundamentos de Programação\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajubá.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
}

void menu(int a){//função imprime menu
    printf("Programa de Treinamento em C\nUniversidade Federal de Itajubá\nCurso Sistemas de Informação\n");
    printf("Nome:%34d",a);
}

int main (){ //função principal
    int ano;
    printf ("Entre com o ano:");
    scanf("%d",&ano);
    menu(ano);
return 0;
}

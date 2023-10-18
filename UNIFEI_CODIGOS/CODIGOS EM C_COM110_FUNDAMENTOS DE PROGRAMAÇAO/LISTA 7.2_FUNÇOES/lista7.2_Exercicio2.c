/****************************************************************************************************************************
Questão 2. Elabore uma função que receba dois números inteiros e positivos e calcule a soma dos números no intervalo fechado
definido entre o primeiro e o segundo número. Use a função no programa principal para calcular a soma entre dois
números fornecidos pelo usuário. A função só deverá ser executada caso o primeiro valor seja maior ou igual ao segundo.
Dica: um dos parâmetros recebidos pela função deve ser o endereço da variável que deverá guardar o valor da soma.
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // funçao que imprime cabeçalho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informação\nDisciplina:Fundamentos de Programação\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajubá.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nPrograma que calcula a soma entre os numeros do intervalo de 2 inteiros fornecido.\n");
}

void soma(int n1, int n2, int *pSoma){
     int i, sAux=0;
     for(i=n2+1;i<n1;i++)
         sAux=sAux+i;
     *pSoma=sAux;
}

int main (){ //função principal
    cabecalho();
    int num1,num2,resp;
    printf ("\nEntre com 2 valores:");
    scanf(" %d %d",&num1,&num2);
    if(num1>num2)
    {
        soma(num1,num2,&resp);
        printf("O valor da soma de %d a %d = %d.",num2+1,num1-1,resp);
    }
    else
        printf("Segundo valor é maior que o primeiro.\n");

    printf("\n");for(int i=0;i<100;i++) printf("=");
return 0;
}

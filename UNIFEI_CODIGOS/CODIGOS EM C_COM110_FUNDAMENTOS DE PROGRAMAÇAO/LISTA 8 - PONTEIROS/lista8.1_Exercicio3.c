/****************************************************************************************************************************
3. Faça uma função que receba um valor inteiro como referência e retorne o resto da divisão deste número por 10.
Altere também o valor da variável passada por referência, dividindo-a por 10.
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca
void cabecalho();

int funcD(int *div)
{
     int n=*div;
     *div= *div/10;
     return n%10;
}

int main (){ //função principal
    cabecalho();

    int num, resto;
    printf("\nEntrar com o valor  inteiro:");
    scanf(" %d",&num);
    resto=funcD(&num);
    printf("O resto da divisão = %d e numero agora vale %d.\n",resto, num);

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
}

/****************************************************************************************************************************
Questão 3. Elabore uma função que receba um valor numérico (podendo ter casas decimais) e um valor inteiro. O segundo valor
 (inteiro) corresponde à porcentagem de aumento do primeiro valor (real). A função deve somar o valor correspondente à
taxa (segundo valor) no primeiro valor. Por exemplo, caso a função receba 100 e 20, o primeiro valor deve ser alterado para
 120 (100 + 20%). Utilize a função no programa principal para calcular o aumento de uma lista de produtos (um de cada
vez). O valor original do produto e a taxa de aumento deve ser fornecido pelo usuário (um de cada vez).
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca
void cabecalho();

float atualizaTaxa(float n,int x,float *pAt){
      *pAt=(n*(1+(float)x/100));
}

int main (){ //função principal
    cabecalho();
    int taxa;
    float valor;
    printf ("\nEntre com o valor do produto:");
    scanf(" %f",&valor);
    printf ("Entre com a taxa de aumento:");
    scanf(" %d",&taxa);
    atualizaTaxa(valor,taxa,&valor);
    printf("O novo valor atualizado do produto = %.2f.\n",valor);

    printf("\n");for(int i=0;i<100;i++) printf("=");
return 0;
}
void cabecalho(){ // funçao que imprime cabeçalho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informação\nDisciplina:Fundamentos de Programação\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajubá.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nPrograma atualiza o valor do produto conforme taxa de aumento dada.\n");
}

/**********************************************************************************************************
Questão 7. Faça um programa que contenha uma função que recebe dois números positivos e retorna a soma dos
N números inteiros existentes entre eles (inclusive). Use a função no programa principal.
***********************************************************************************************************/
#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // funçao que imprime cabeçalho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informação\nDisciplina:Fundamentos de Programação\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajubá.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
}

int soma (int a,int b){//funão que retorna a soma dos intieors entre dois umeros dados
    int i,soma=0; //declaração de variavel local e atribuição de valor innicial 0 para soma
    for(i=a; i<=b;i++) //laço para fazer a soma entre os inteiros
        soma=soma+i; //soma recebe ela mesmo mais o valor de i
    return soma; //retorna o valor da soma para maisn()
}

int main (){ //função principal
    cabecalho();
    int a,b,s; // variaveis locais de main()
    printf("\nEntre com dois numeros:");//solicitação de valor ao usuario
    scanf("%d %d",&a,&b);//entrada de valores
    s=soma(a,b);//chamada da função soma atribuindo uma copia do valor a e b respetivamente para a e b da função soma
    printf("A Soma de %d a % d é %d\n",a,b,s);//apresentado resultado ao usuario
return 0;
}

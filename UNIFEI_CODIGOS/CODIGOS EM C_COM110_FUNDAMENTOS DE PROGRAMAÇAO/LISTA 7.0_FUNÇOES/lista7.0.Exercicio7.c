/**********************************************************************************************************
Quest�o 7. Fa�a um programa que contenha uma fun��o que recebe dois n�meros positivos e retorna a soma dos
N n�meros inteiros existentes entre eles (inclusive). Use a fun��o no programa principal.
***********************************************************************************************************/
#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // fun�ao que imprime cabe�alho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informa��o\nDisciplina:Fundamentos de Programa��o\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajub�.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
}

int soma (int a,int b){//fun�o que retorna a soma dos intieors entre dois umeros dados
    int i,soma=0; //declara��o de variavel local e atribui��o de valor innicial 0 para soma
    for(i=a; i<=b;i++) //la�o para fazer a soma entre os inteiros
        soma=soma+i; //soma recebe ela mesmo mais o valor de i
    return soma; //retorna o valor da soma para maisn()
}

int main (){ //fun��o principal
    cabecalho();
    int a,b,s; // variaveis locais de main()
    printf("\nEntre com dois numeros:");//solicita��o de valor ao usuario
    scanf("%d %d",&a,&b);//entrada de valores
    s=soma(a,b);//chamada da fun��o soma atribuindo uma copia do valor a e b respetivamente para a e b da fun��o soma
    printf("A Soma de %d a % d � %d\n",a,b,s);//apresentado resultado ao usuario
return 0;
}

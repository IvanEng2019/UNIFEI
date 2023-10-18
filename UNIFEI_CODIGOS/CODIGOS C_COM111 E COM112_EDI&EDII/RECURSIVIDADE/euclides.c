/***********************************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa de Cássia Silva Rodrigues
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 28/08/2018
-----------------------------------------------------------------------------------------------------------
Exercicio 1.
A seguinte função calcula o maior divisor comum dos inteiros positivos m e n. Escreva uma
função recursiva equivalente.
1. int Euclides(int m, int n)
1. int Euclides(int m, int n){
2. int r;
3. do{
4. r = m % n;
5. m = n;
6. n = r;
7. while(r != 0);
8. return m;}

************************************************************************************************************
 Inclusão de biblioteca
************************************************************************************************************/
#include <stdio.h>

/************************************************************************************************************
 Função recursiva de Euclides : Renorna o maior divisor comum de dois numeros inteiros
************************************************************************************************************/
int euclides(int m,int n){
    if(m%n==0)
        return n;
    else
       return euclides(n,m%n);
}
/************************************************************************************************************
 Função principal
************************************************************************************************************/
int main(){
    int n1,n2;
    printf("Programa que descobre o maior divisor comum de dois numeros inteiros.\n\nEntre com os valores de dois numeros inteiros:\n");
    scanf(" %d %d",&n1,&n2);
    //if (n1>n2)
        printf("O maior divisor comum de %d e %d é %d.\n",n1,n2,euclides(n1,n2));
    //else
     //   printf("O maior divisor comum de %d  e %d é %d.\n",n1,n2,euclides(n2,n1));
return 0;
}


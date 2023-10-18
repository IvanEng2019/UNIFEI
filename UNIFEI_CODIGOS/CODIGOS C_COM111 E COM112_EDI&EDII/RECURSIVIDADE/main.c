/***********************************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa de Cássia Silva Rodrigues
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 28/08/2018
-----------------------------------------------------------------------------------------------------------
Exercicio 2.
 Implemente uma TAD para representar números complexos. Sabe-se que um número complexo
é representado por a + bi, onde a e b são números reais e i a unidade imaginária. O TAD deve
implementar as seguintes operações:
(a) Função para criar um número complexo, dados a e b.
(b) Função para liberar um número complexo previamente criado.
(c) Função para somar dois números complexos, retornando um novo número com o resultado
da operação. Sabe-se que (a + bi) + (c + di) = (a + c) + (b + d)i (1)
(d) Função para subtrair dois números complexos, retornando um novo número com o resultado
da operação. Sabe-se que (a + bi) − (c + di) = (a − c) + (b − d)i (2)
(e) Função para multiplicar dois números complexos, retornando um novo número com o
resultado da operação. Sabe-se que (a + bi)(c + di) = (ac − bd) + (bc + ad)i (3)
(f) Função para dividir dois números complexos, retornando um novo número com o resultado
da operação. Sabe-se que (a + bi)/(c + di) = ((ac + bd)/(c2 + d2)) + ((bc − ad)/(c2 + d2))i (4)
Escreva uma função main que use números complexos para testar as funções implementadas.
(Sugestão: criar dois números complexos, executar todas as operações (+, -, *, /), imprimir
os resultados e liberar a memória.)
************************************************************************************************************
 Inclusão de bibliotecas
************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ILVB_Num_Complexo.h"

/************************************************************************************************************
 Função principal
************************************************************************************************************/
int main(){

    ///definição de variaveis
    float a,b,c,d; /// tipo real
    im *pri,*seg,*rOpComp; ///tipo ponteiro para im

    printf("Programa que realiza as 4 operações matematicas basicas com numeros completos.\n");
    printf("\nPrimeiro numero complexo:\nEntre com os valores de a e bi respectivamente:\n");
    scanf("%f %f",&a,&b);
    pri=alocarIm(); ///alocação para o primeiro numero complexo
    criaComplexo(a,b,pri);/// atribuição do 1º numero complexo
    printf ("Primeiro numero complexo (a + bi) = ");
    imprime(pri);/// imprime o 1º numero complexo

    printf("\nSegundo numero complexo:\nEntre com os valores de c e di respectivamente:\n");
    scanf("%f %f",&c,&d);
    seg=alocarIm(); ///alocação para o segundo numero complexo
    criaComplexo(c,d,seg);/// atribuição do 2º numero complexo
    printf ("Segundo numero complexo (c + di) =");
    imprime (seg);/// imprime o 2º numero complexo

    rOpComp=alocarIm();/// aloca memoria para o resultado das operações

    printf("\nOperações basicas:\n\nSoma do numero completo:\n(a+bi )+(c+di)= (%.2f+%.2fi)+(%.2f+%.2fi)= ",a,b,c,d);
    somaComplexo(pri,seg,rOpComp);///realiza a soma de 2 numeros complexos
    imprime(rOpComp);///imprime o resultado da soma
    printf("\nSubtração do numero completo:\n(a+bi)-(c +di)= (%.2f+%.2fi)-(%.2f + %.2fi)= ",a,b,c,d);
    subComplexo(pri,seg,rOpComp);///realiza a subtração de 2 numeros complexos
    imprime(rOpComp);///imprime o resultado da subtração
    printf("\nMultiplicação do numero completo:\n(a+bi)X(c+di)= (%.2f+%.2fi )X(%.2f+%.2fi)= ",a,b,c,d);;
    multComplexo(pri,seg,rOpComp);///realiza a multiplicação de 2 numeros complexos
    imprime(rOpComp);///imprime o resultado da multiplicação
    printf("\nDivisão do numero completo\n(a+bi)/(c+di)= (%.2f+%.2fi)/(%.2f+%.2fi)= ",a,b,c,d);
    divComplexo(pri,seg,rOpComp);///realiza a soma de 2 numeros complexos
    imprime(rOpComp);///imprime o resultado da divisão

    ///libera a memorias alocada
    libera(pri);
    libera(seg);
    libera(rOpComp);

    return 0;
}

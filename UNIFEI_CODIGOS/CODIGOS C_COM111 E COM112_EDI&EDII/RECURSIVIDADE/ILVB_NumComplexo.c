/********************************************************************/
/** Inclusão de bibliotecas                                         */
/********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ILVB_Num_Complexo.h"
/********************************************************************/
/** Função para alocar memória                                      */
/********************************************************************/
im *alocarIm(){
  im *p =(im*)malloc(sizeof(im));
  if(p==NULL)
    printf("Memória insuficiente!");
  return p;
}
/********************************************************************/
/** Função para criar numero complexo                               */
/********************************************************************/
void criaComplexo(float ac, float bd, im *numi){
      numi->n1=ac;
      numi->n2=bd;
}
/********************************************************************/
/** Função para imprimir numero complexo                            */
/********************************************************************/
void imprime (im *numi){
     printf("%.2f + %.2fi\n",numi->n1,numi->n2);
}
/********************************************************************/
/** Função para somar numero complexo                               */
/********************************************************************/
void somaComplexo(im *num1,im *num2,im *soma){
    soma->n1=num1->n1+num2->n1;
    soma->n2=num1->n2+num2->n2;
}
/********************************************************************/
/** Função para subtrair numero complexo                            */
/********************************************************************/
void subComplexo(im *num1,im *num2,im *sub){
    sub->n1=num1->n1-num2->n1;
    sub->n2=num1->n2-num2->n2;
}
/********************************************************************/
/** Função para multiplicar numero complexo                         */
/********************************************************************/
void multComplexo(im *num1,im *num2,im *mult){
    mult->n1=(num1->n1*num2->n1)-(num1->n2*num2->n2);
    mult->n2= (num1->n2*num2->n1)+(num1->n1*num2->n2);
}
/********************************************************************/
/** Função para dividir numero complexo                             */
/********************************************************************/
void divComplexo(im *nun1,im *nun2, im *div){
    if((nun2->n1+nun2->n2)!= 0){
        div->n1=((nun1->n1*nun2->n1)+(nun1->n2*nun2->n2))/((nun2->n1*nun2->n1)+(nun2->n2*nun2->n2));
        div->n2=((nun1->n2*nun2->n1)-(nun1->n1*nun2->n2))/((nun2->n1*nun2->n1)+(nun2->n2*nun2->n2));
    }
    else
        printf("Não existe divisão entre estes 2 numeros.\n");
}
/********************************************************************/
/** Função para liberar memória                                     */
/********************************************************************/
void libera (im *num){
     free(num);
}

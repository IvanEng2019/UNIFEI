/****************************************************************************************************************************
2. Escrever uma fun��o que tem como par�metros de entrada tr�s valores inteiros a, b e c e retorna a posi��o do maior e a
posi��o do menor valor.
 Exemplo: Se a = 7, b = 1 e c = 5, o procedimento deve retornar 2 como a posi��o do menor e 1 como a posi��o do maior.
 Use a fun��o no programa principal considerando tr�s valores  digitados pelo usu�rio.
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca
void cabecalho();

void minmax(int a, int b, int c, int *pMaior, int *pMenor)
{
    *pMaior=3;
    if(a<b && a<c)
    {
      *pMenor=1;
      if(b>c)
        *pMaior=2;
    }
    else
      if(b<a && b<c)
      {
         *pMenor=2;
          if(a>c)
            *pMaior=1;
      }
      else
      {
        //if(c<a && c<b;)
        *pMenor=3;
        if(a>b)
          *pMaior=1;
        else
          *pMaior=2;
      }

}

int main (){ //fun��o principal
    cabecalho();

    int a,b,c,pMax,pMin;
    printf("\nEntrar com 3 valores:");
    scanf(" %d %d %d",&a,&b,&c);
    minmax(a,b,c,&pMax,&pMin);
    printf("O menor valor esta na posi��o = %d e o maior esta na posi��o = %d.\n",pMin,pMax);

    printf("\n");for(int i=0;i<100;i++) printf("=");
return 0;
}

void cabecalho(){ // fun�ao que imprime cabe�alho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informa��o\nDisciplina:Fundamentos de Programa��o\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajub�.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nPrograma determina o minimo e maximo de n numeros fornecidos.\n");
}

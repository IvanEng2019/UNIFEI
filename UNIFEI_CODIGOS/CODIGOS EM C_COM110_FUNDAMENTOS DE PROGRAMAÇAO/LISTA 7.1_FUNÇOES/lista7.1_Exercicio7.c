/****************************************************************************************************************************
7. Fa�a uma fun��o que receba 3 valores inteiros por par�metro e imprima-os de forma ordenada.
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // fun�ao que imprime cabe�alho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informa��o\nDisciplina:Fundamentos de Programa��o\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajub�.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nPrograma que ordena 3 valores inteiros fornecidos:\n");
}

void ordemc (int a, int b, int c){ //fun��o que ordenar� os valores
    if(a<b && a<c)
    {
        printf("%d,",a);
        if(b<c)
           printf("%d,%d",b,c);
        else
           printf("%d,%d",c,b);
    }
    else
    {
        if(b<a && b<c)
        {
            printf("%d,",b);
            if(a<c)
                printf("%d,%d",a,c);
            else
                printf("%d,%d",c,a);
        }
        else //  if(c<a && c<b)
        {
           printf("%d,",c);
           if(a<b)
              printf("%d,%d",a,b);
           else
              printf("%d,%d",b,a) ;
        }
    }
}

int main (){ //fun��o principal
    cabecalho();
    int a,b,c;
    printf ("\nEntre com 3 valores:");
    scanf(" %d %d %d", &a,&b,&c);
    ordemc(a,b,c);

    printf("\n");for(int i=0;i<100;i++) printf("=");
return 0;
}

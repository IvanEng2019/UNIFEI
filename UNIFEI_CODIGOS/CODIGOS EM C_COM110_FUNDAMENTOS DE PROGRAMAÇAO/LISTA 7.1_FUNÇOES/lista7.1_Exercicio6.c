/****************************************************************************************************************************
6. Fa�a uma fun��o que receba, por par�metro, a altura (alt) e o sexo de uma pessoa e retorna o seu peso ideal.
Para homens, calcular o peso ideal usando a f�rmula peso ideal = 72.7 x alt - 58 e, para mulheres,
peso ideal = 62.1 x alt - 44.7. Utilize esta fun��o no programa principal para retornar o peso ideal de uma lista de pessoas.
O programa deve ser finalizado quando a altura digitada for menor ou igual a 0.
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // fun�ao que imprime cabe�alho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informa��o\nDisciplina:Fundamentos de Programa��o\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajub�.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nPrograma que Calcula o peso ideal conforme o sexo ate que altura digitada seja 0:\n");
}

float pIdeal (float alt, char s){//fun��o que retorna o peso ideal conforme o sexo
    if(s=='h' || s=='H')
       return 72.7*alt - 58;
    else
       return 62.1*alt - 44.7;
}

int main (){ //fun��o principal
    cabecalho();
    float h;
    char sexo;
    printf ("\nEntre com a altura:");
    scanf("%f",&h);
    while(h!=0)
    {
         do{
            printf("Entre com o sexo m/M ou h/H:");
            scanf(" %c",&sexo);
            if (sexo!='m' && sexo!='M' && sexo!='h' && sexo!='H')
                printf("Sexo incorreto.\n");
        }while (sexo!='m' && sexo!='M' && sexo!='h' && sexo!='H');
        printf("O peso ideal �: %2.f.",pIdeal(h,sexo));
        printf ("\nEntre com a altura de outra pessoa:");
        scanf("%f",&h);
    }
    for(int i=0;i<100;i++) printf("=");
return 0;
}

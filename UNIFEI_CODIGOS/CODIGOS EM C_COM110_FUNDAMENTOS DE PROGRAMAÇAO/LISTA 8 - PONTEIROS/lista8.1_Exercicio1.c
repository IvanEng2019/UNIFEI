/****************************************************************************************************************************
1. Escrever uma fun��o que retorne o valor m�nimo e m�ximo de uma sequ�ncia de n valores fornecidos pelo usu�rio.
 A leitura dos valores digitados no teclado deve ser feita dentro da fun��o. Contudo, a quantidade de valores a
 ser lido (n) deve ser um par�metro de entrada da fun��o.
****************************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca
void cabecalho();

void minmax(int q,int *min, int *max)
{
   int n;
   printf("Entre com um valor:");
   scanf("%d",&n);
   *min=n;
   *max=n;
   q--;
   while(q>0)
   {

        printf("Entre com um valor:");
        scanf("%d",&n);
        if(*max<n)
           *max=n;
        if(*min>n)
           *min=n;
        q--;

   }

}

int main (){ //fun��o principal
    cabecalho();

    int qtd,menor,maior;
    printf("\nEntrar com a quantidade de valores serem lidos:");
    scanf("%d",&qtd);
    minmax(qtd,&menor,&maior);
    printf("O valor do menor = %d e do maior = %d.\n",menor,maior);

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

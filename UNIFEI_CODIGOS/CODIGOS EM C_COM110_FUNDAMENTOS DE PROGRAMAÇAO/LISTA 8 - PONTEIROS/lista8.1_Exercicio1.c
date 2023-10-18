/****************************************************************************************************************************
1. Escrever uma função que retorne o valor mínimo e máximo de uma sequência de n valores fornecidos pelo usuário.
 A leitura dos valores digitados no teclado deve ser feita dentro da função. Contudo, a quantidade de valores a
 ser lido (n) deve ser um parâmetro de entrada da função.
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

int main (){ //função principal
    cabecalho();

    int qtd,menor,maior;
    printf("\nEntrar com a quantidade de valores serem lidos:");
    scanf("%d",&qtd);
    minmax(qtd,&menor,&maior);
    printf("O valor do menor = %d e do maior = %d.\n",menor,maior);

    printf("\n");for(int i=0;i<100;i++) printf("=");
return 0;
}

void cabecalho(){ // funçao que imprime cabeçalho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informação\nDisciplina:Fundamentos de Programação\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajubá.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nPrograma determina o minimo e maximo de n numeros fornecidos.\n");
}

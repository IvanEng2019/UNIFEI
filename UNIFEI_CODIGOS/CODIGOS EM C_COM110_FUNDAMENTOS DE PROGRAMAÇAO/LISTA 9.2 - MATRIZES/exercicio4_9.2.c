/***************************************************************************************************
4. Escreva uma função que receba dois vetores de tamanho máximo 10 e retorne um terceiro vetor cujos
 elementos são a soma dos elementos dos dois vetores. Considere que os dois vetores recebidos terão
 o mesmo número de elementos ocupados. Use a função no programa principal para preenche um vetor a
 partir de outros dois vetores de números digitados pelo usuário que deverão possuir 10 elementos.
*****************************************************************************************************/

#include<stdio.h>
#define MAX 10

void soma(float a[], float b[], float c[])
{
    for(int i=0;i<MAX;i++)
        c[i]=a[i]+b[i];
    return;
}
 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");//i+j=n-1;
}
int main(){
    cabecalho(); //imprime os dados do aluno
    //freopen("l.in","r",stdin); // copia os dados do arquivo txt
    float a[MAX],b[MAX], c[MAX];
    for(int i=0;i<MAX;i++)
    {
       printf("Entre com o valor da A[%d] = ",i);
       scanf("%f",&a[i]);
    }
    for(int i=0;i<MAX;i++)
    {
       printf("Entre com o valor da B[%d] = ",i);
       scanf("%f",&b[i]);
    }
    soma(a,b,c);
    for(int i=0;i<MAX;i++)
    {
        printf("C[%d]=%.2f\n",i,c[i]);
    }
    return 0;
}

/***************************************************************************************************
4. Escreva uma fun��o que receba dois vetores de tamanho m�ximo 10 e retorne um terceiro vetor cujos
 elementos s�o a soma dos elementos dos dois vetores. Considere que os dois vetores recebidos ter�o
 o mesmo n�mero de elementos ocupados. Use a fun��o no programa principal para preenche um vetor a
 partir de outros dois vetores de n�meros digitados pelo usu�rio que dever�o possuir 10 elementos.
*****************************************************************************************************/

#include<stdio.h>
#define MAX 10

void soma(float a[], float b[], float c[])
{
    for(int i=0;i<MAX;i++)
        c[i]=a[i]+b[i];
    return;
}
 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
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

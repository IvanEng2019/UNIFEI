/***************************************************************************************************
5. Elabore uma função que receba dois vetores de caracter de tamanho máximo = 10 e retorne um terceiro
vetor que deverá conter somente os caracteres que estão nos dois vetores.
*****************************************************************************************************/

#include<stdio.h>
#define MAX 3

int caracter(char a[], char b[], char c[])
{
    int cont=0;
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            if(a[i]==b[j])
            {
                c[cont]=a[i];
                cont++;
            }
        }
    }
    return cont;
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
    char a[MAX],b[MAX],c[MAX];
    int tam;
    for(int i=0;i<MAX;i++)
    {
       printf("Entre com o caracter de A[%d] = ",i);
       scanf(" %c",&a[i]);
    }
    for(int i=0;i<MAX;i++)
    {
       printf("Entre com o caracter de B[%d] = ",i);
       scanf(" %c",&b[i]);
    }
    tam=caracter(a,b,c);
    for(int i=0;i<tam;i++)
    {
        printf("C[%d]=%c\n",i,c[i]);
    }
    return 0;
}

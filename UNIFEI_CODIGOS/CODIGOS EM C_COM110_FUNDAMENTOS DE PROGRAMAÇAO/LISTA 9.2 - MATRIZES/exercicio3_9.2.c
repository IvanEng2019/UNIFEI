/***************************************************************************************************
3. Escreva uma fun��o que receba um vetor de n�meros reais de tamanho m�ximo = 20, a quantidade de
elementos preenchidos no vetor e um valor de acr�scimo (tamb�m real) e modifique os elementos do
vetor acrescentando o valor passado. Utilize a fun��o no programa principal para atualizar a lista
de sal�rios de n funcion�rios que dever�o ser digitados pelo usu�rio (n<=20).
*****************************************************************************************************/

#include<stdio.h>
#define MAX 20

void alteraSalario(float s[],int n, float aum)
{
    for(int i=0;i<n;i++)
        s[i]+=aum;
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
    float s[MAX], alt;
    int n;
    printf("Entre com o valor o numero de funcion�rios:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       printf("Entre com o valor do sal�rio S[%d] = ",i);
       scanf("%f",&s[i]);
    }
    printf("Deseja aumentar os salarios em quantos?");
    scanf("%f",&alt);
    alteraSalario(s,n,alt);
    for(int i=0;i<n;i++)
    {
        printf("s[%d]=%.2f\n",i,s[i]);
    }
    return 0;
}

/***************************************************************************************************
3. Escreva uma função que receba um vetor de números reais de tamanho máximo = 20, a quantidade de
elementos preenchidos no vetor e um valor de acréscimo (também real) e modifique os elementos do
vetor acrescentando o valor passado. Utilize a função no programa principal para atualizar a lista
de salários de n funcionários que deverão ser digitados pelo usuário (n<=20).
*****************************************************************************************************/

#include<stdio.h>
#define MAX 20

void alteraSalario(float s[],int n, float aum)
{
    for(int i=0;i<n;i++)
        s[i]+=aum;
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
    float s[MAX], alt;
    int n;
    printf("Entre com o valor o numero de funcionários:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       printf("Entre com o valor do salário S[%d] = ",i);
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

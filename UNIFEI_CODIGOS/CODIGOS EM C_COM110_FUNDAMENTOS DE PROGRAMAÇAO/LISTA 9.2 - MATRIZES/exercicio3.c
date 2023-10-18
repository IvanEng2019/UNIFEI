/*****************************************************************************************************
3.Elabore um programa que leia o código e a quantidade em estoque de 10 produtos e armazene
esses dados em uma matriz. Depois de preenchida a matriz, imprima a quantidade total de
produtos e o código de todos os produtos com quantidade maior que 10.
*****************************************************************************************************/
#include<stdio.h>
#define LIN 3
#define COL 2

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 07/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    //freopen("l.in","r",stdin); // copia os dados do arquivo txt
    int qtdp[LIN][COL],j,qtd=0;
    for(int i=0;i<LIN;i++)
    {
        j=0;
            printf("Entre com o codigo Produto[%d][%d] = ",i,j);
            scanf("%d",&qtdp[i][j]);
            printf("Entre com a qtd produto [%d][%d] = ",i,j+1);
            scanf("%d",&qtdp[i][j+1]);
            qtd+=qtdp[i][j+1];
    }
    printf("Codigo dos produtos > 10:\n");
    for(int i=0;i<LIN;i++)
    {
        j=0;
        if(qtdp[i][j+1]>10)
            printf("Codigo: %d\n",qtdp[i][j]);
    }
     printf("A quantidade total de produtos :%d\n",qtd);
    return 0;
}

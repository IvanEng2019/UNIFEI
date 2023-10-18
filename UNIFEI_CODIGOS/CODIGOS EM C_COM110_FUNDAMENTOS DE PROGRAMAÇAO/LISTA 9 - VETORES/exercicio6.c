/*******************************************************************************************************
Faça um programa que receba o total das vendas de cada vendedor de uma loja e armazene-as em um vetor.
Receba também o percentual de comissão a que cada vendedor tem direito e armazene-os em outro vetor.
Receba os nomes desses vendedores e armazene-os em um terceiro vetor. Existem apenas dez vendedores na
loja. Calcule e mostre:
■ um relatório com os nomes dos vendedores e os valores a receber referentes à comissão;
■ o total das vendas de todos os vendedores;
■ o maior valor a receber e o nome de quem o receberá;
■ o menor valor a receber e o nome de quem o receberá.
********************************************************************************************************/
//inclusão da bibliotecas
 #include<stdio.h>
 #include <stdlib.h>
 #define MAX 10

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 03/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno total das vendas de cada vendedor
    int tv[MAX],j,k,tot=0;
    float maior, menor, com[MAX],aux;
    char nom[MAX];
    for(int i=0;i<MAX;i++)
    {
        setbuf(stdin,NULL);
        printf("Entre com a primeira letra do nome do vendedor:");
        scanf(" %c",&nom[i]);
        printf("Entre com o total de vendas do vendedor:");
        scanf(" %d",&tv[i]);
        tot= tot+tv[i];
        printf("Entre com o percentual da comissão:");
        scanf(" %f",&com[i]);
        aux=(float)tv[i]*com[i];
        if(i==0)
        {
            menor=aux;
            maior=menor;
            j=i;
            k=j;
        }
        if(maior<aux)
        {
          maior= aux;
          j=i;
        }
        if(menor>aux)
        {
          menor= aux;
          k=i;
        }

    }
     for(int i=0;i<MAX;i++)
     {
         aux=(float)tv[i]*com[i];
         printf(" O vendedor de letra %c tem a receber o valor de %.2f\n", nom[i],aux);
     }
    printf(" O total de vendas de todos os vendedores deu %d.\n",tot);
    printf(" O maior valor é do vendedor %c com %.2f a receber.\n",nom[j],maior);
    printf(" O Menor valor é do vendedor %c com %.2f a receber.\n",nom[k],menor);
    return 0;
}

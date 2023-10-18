/*******************************************************************************************************
Faça um programa que receba dez números inteiros e armazene-os em um vetor. Calcule e mostre dois
vetores resultantes: o primeiro com os números pares e o segundo, com os números ímpares.
********************************************************************************************************/
//inclusão da bibliotecas
 #include<stdio.h>
 #define MAX 3

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 03/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    int v[MAX],r1[MAX],r2[MAX],cont1=0,cont2=0;
    for(int i=0;i<MAX;i++)
    {
        printf("Entre com o valor do numero:");
        scanf("%d",&v[i]);
    }
    for(int i=0;i<MAX;i++)
    {
        if(v[i]%2==0)
        {
            r1[cont1]=v[i];
            cont1++;
        }
        else
        {
            r2[cont2]=v[i];
            cont2++;
        }

    }
    printf("\nOs numeros pares são:");
    for(int i=0;i<cont1;i++)
        printf("%d,",r1[i]);
    printf("\nOs numeros impares são:");
    for(int i=0;i<cont2;i++)
        printf("%d,",r2[i]);
    return 0;
}

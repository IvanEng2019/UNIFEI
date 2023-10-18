/*******************************************************************************************************
Faça um programa que receba cinco números e mostre a saída a seguir:
Digite o 1º número 5
Digite o 2º número 3
Digite o 3º número 2
Digite o 4º número 0
Digite o 5º número 2
Os números digitados foram: 5 + 3 + 2 + 0 + 2 = 12
********************************************************************************************************/
//inclusão da bibliotecas
 #include<stdio.h>
 #define MAX 5

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 03/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    int n[MAX],cont=0;
    for(int i=0;i<MAX;i++)
    {
        printf("digite o %dº numero:",i+1);
        scanf("%d",&n[i]);
        cont=cont+n[i];
    }
    printf("Os numero digitados foram:");
    for(int i=0;i<MAX;i++)
    {
        printf("%d",n[i]);
        if(i<MAX-1)
            printf ("+");
    }
     printf("= %d",cont);
    return 0;
}

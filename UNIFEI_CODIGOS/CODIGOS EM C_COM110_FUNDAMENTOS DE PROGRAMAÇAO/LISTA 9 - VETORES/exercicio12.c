/*******************************************************************************************************
Fa�a um programa que receba cinco n�meros e mostre a sa�da a seguir:
Digite o 1� n�mero 5
Digite o 2� n�mero 3
Digite o 3� n�mero 2
Digite o 4� n�mero 0
Digite o 5� n�mero 2
Os n�meros digitados foram: 5 + 3 + 2 + 0 + 2 = 12
********************************************************************************************************/
//inclus�o da bibliotecas
 #include<stdio.h>
 #define MAX 5

 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 03/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    int n[MAX],cont=0;
    for(int i=0;i<MAX;i++)
    {
        printf("digite o %d� numero:",i+1);
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

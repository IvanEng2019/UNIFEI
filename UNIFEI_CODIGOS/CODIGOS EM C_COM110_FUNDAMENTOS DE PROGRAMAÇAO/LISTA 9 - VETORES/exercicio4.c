/*******************************************************************************************************
Fa�a um programa que preencha um vetor com quinze elementos inteiros e verifique a exist�ncia de elementos
iguais a 30, mostrando as posi��es em que apareceram.
********************************************************************************************************/
//inclus�o da bibliotecas
 #include<stdio.h>

 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 03/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    int vet[15], qtdp =0, qtdi=0;
    for(int i=0;i<15;i++)
    {
        printf("Entre com o valor:");
        scanf("%d",&vet[i]);
    }
    printf("\nAparece 30 na(s) posi��o(�es");
    for(int i=0;i<15;i++)
    {5
        if(vet[i]==30)
            printf("%d",i);
    }
    return 0;
}

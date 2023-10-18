/*******************************************************************************************************
Faça um programa que preencha um vetor com sete números inteiros, calcule e mostre:
■ os números múltiplos de 2;
■ os números múltiplos de 3;
■ os números múltiplos de 2 e de 3.
********************************************************************************************************/
//inclusão da bibliotecas
 #include<stdio.h>

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 03/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    int vet[7], qtdp =0, qtdi=0;
    for(int i=0;i<7;i++)
    {
        printf("Entre com o valor:");
        scanf("%d",&vet[i]);
    }
    printf("Os numeros multiplos de 2 são:\n");
    for(int i=0;i<7;i++)
    {
        if(vet[i]%2==0)
           printf("%d,",vet[i]);
    }
    printf("\nOs numeros  multiplos de 3 são:\n");
    for(int i=0;i<7;i++)
    {
        if(vet[i]%3==0)
            printf("%d,",vet[i]);
    }
    printf("\nOs numeros  multiplos de 2 e 3 são:\n");
    for(int i=0;i<7;i++)
    {
        if(vet[i]%6==0)
            printf("%d,",vet[i]);
    }
    return 0;
}

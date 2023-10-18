/*******************************************************************************************************
Faça um programa que preencha um vetor com seis elementos numéricos inteiros. Calcule e mostre:
■ todos os números pares;
■a quantidade de números pares;
■ todos os números ímpares;
■ a quantidade de números ímpares.
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
    int vet[6], qtdp =0, qtdi=0;
    for(int i=0;i<6;i++)
    {
        printf("Entre com o valor:");
        scanf("%d",&vet[i]);
    }
    printf("Os numeros pares são:\n");
    for(int i=0;i<6;i++)
    {
        if(vet[i]%2==0)
        {
            qtdp++;
            printf("%d,",vet[i]);
        }
    }
    printf("\nOs numeros impares são:\n");
    for(int i=0;i<6;i++)
    {
        if(vet[i]%2!=0)
        {
            qtdi++;
            printf("%d,",vet[i]);
        }
    }
    printf("\nExistem %d numeros pares",qtdp);
    printf("\nExistem %d numeros impares\n",qtdi);
    return 0;
}

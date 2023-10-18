/*******************************************************************************************************
Faça um programa que preencha um vetor com dez números reais, calcule e mostre a quantidade de números
negativos e a soma dos números positivos desse vetor.
********************************************************************************************************/
//inclusão da bibliotecas
 #include<stdio.h>
 #define MAX 10
 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 03/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    int vet[MAX],qtd=0, soma=0;
    for(int i=0;i<MAX;i++)
    {
        printf("Entre com o valor:");
        scanf("%d",&vet[i]);
        if(vet[i]<0)
            qtd++;
        else
            soma=soma+vet[i];
    }
    printf("\nA soma dos vetores de valores positivo deu %d.",soma);
    printf("\nExistem %d numeros negativos.\n",qtd);
    return 0;
}

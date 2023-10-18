/*******************************************************************************************************
Faça um programa que preencha um vetor com os nomes de sete alunos e carregue outro vetor com a média
final desses alunos. Calcule e mostre:
■ o nome do aluno com maior média (desconsiderar empates);
■ para cada aluno não aprovado, isto é, comm édia menor que 7, mostrar quanto essea luno precisa tirar
na prova de exame final para ser aprovado. Considerar que a médiap ara aprovação no exame é 5.
********************************************************************************************************/
//inclusão da bibliotecas
#include<stdio.h>
#include <stdlib.h>

#define MAX 3

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 03/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno

    float med[MAX], maior=0, aux;
    int m;
    char nom[MAX];

    for(int i=0;i<MAX;i++)
    {
        setbuf(stdin,NULL);
        printf("Entre com a primeira letra do nome do Aluno:");
        scanf(" %c",&nom[i]);
        printf("Entre com a media do aluno:");
        scanf(" %f",&med[i]);
        if(maior<med[i])
        {
            maior=med[i];
            m=i;
        }
    }
    printf("O aluno %c com maior media %.2f.\n",nom[m],maior);
    for(int i=0;i<MAX;i++)
    {
        if(med[i]<7)
        {
            aux=10-med[i];
            printf("O aluno %c tem que tirar no minimo %.2f na prova final.\n",nom[i],aux);
        }
    }
    return 0;
}

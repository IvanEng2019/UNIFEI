/*******************************************************************************************************
Faça um programa que receba o nome e duas notas de seis alunos e mostre o relatório a seguir.
Relatório de notas:
ALUNO 1PRova 2Prova MÉDIA SITUAÇÃO
Carlos 8,0    9,0   8,5  Aprovado
Pedro 4,0     5,0   4,5 Reprovado
■ média da classe = ?
■ percentual de alunos aprovados = ?%
■ percentual de alunos de exame = ?%
■ percentual de alunos reprovados = ?%
********************************************************************************************************/
//inclusão da bibliotecas
#include<stdio.h>
#include <stdlib.h>

#define MAX 6
 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 03/06/2018\n\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
    float p1[MAX],p2[MAX], m[MAX],soma,sm=0;
    char nom[MAX];
    int contr=0,conte=0,conta=0;
    for(int i=0;i<MAX;i++)
    {
        setbuf(stdin,NULL);
        printf("Entre com a 1ªletra do nome do %dº aluno:",i+1);
        scanf(" %c",&nom[i]);
        printf("Entre com o valor da 1ª prova de %c:", nom[i]);
        scanf(" %f",&p1[i]);
        printf("Entre com o valor da 2ª prova de %c:", nom[i]);
        scanf(" %f",&p2[i]);
        soma=p1[i]+p1[i];
        m[i]=soma/2;
        sm=sm+m[i];
    }
    printf("Relatorio de notas:\n");
    printf("ALUNO  1PRova  2Prova  MÉDIA  SITUAÇÃO\n");
    for(int i=0;i<MAX;i++)
    {
        printf("%c %9.2f %5.2f %8.2f ",nom[i],p1[i],p2[i],m[i]);
        if(m[i]>=0 && m[i]<5)
        {
            printf("Reprovado.\n");
            contr++;
        }
        else
           if( m[i]>=5 && m[i]<=6)
           {
               conte++;
               printf("EXAME.\n");
           }
           else
           {
               conta++;
               printf("Aprovado.\n");
           }
    }

    printf("\nMedia da clase: %f\n",sm/MAX);
    printf("Percentual de alunos aprovados: %.2f\n",(float)conta/MAX);
    printf("Percentual de alunos de exame: %.2f\n",(float)conte/MAX);
    printf("Percentual de alunos reprovados: %.2f\n",(float)contr/MAX);
    return 0;
}

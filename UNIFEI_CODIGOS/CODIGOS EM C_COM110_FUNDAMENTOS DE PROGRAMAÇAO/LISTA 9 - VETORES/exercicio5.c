/*******************************************************************************************************
Uma escola deseja saber se existem alunos cursando, simultaneamente, as disciplinas L�gica e Linguagem de
Programa��o. Coloque os n�meros das matr�culas dos alunos que cursam L�gicam em um vetor de quinze alunos.
Coloque os n�meros das matr�culas dos alunos que cursam Linguagem de Programa��o em outro vetor, dez
alunos. Mostre o n�mero das matr�culas que aparecem nos dois vetores.
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
    int log[15],prog[10];
    for(int i=0;i<15;i++)
    {
        printf("Entre com o numero da matricula do aluno de logica:");
        scanf("%d",&log[i]);
    }
    printf("\n");
    for(int i=0;i<10;i++)
    {
        printf("Entre com o numero da matricula do aluno de progrma��o:");
        scanf("%d",&prog[i]);
    }
    printf("\n O numero da matricula que aparece nas duas diciplinas s�o:");
    for(int i=0;i<10;i++)
    {
         for(int j=0;j<15;j++)
         {
             if(prog[i]==log[j])
                printf("%d,",prog[i]);
         }
    }
    return 0;
}

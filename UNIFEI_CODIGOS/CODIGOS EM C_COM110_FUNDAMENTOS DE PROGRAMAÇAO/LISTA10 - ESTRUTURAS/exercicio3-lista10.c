/*******************************************************************************************************************************
3. A partir da estrutura criada no exerc�cio 1, crie um vetor para armazenar uma lista de, no m�ximo, 40 alunos.
    a. Elabore uma fun��o que preencha o vetor com informa��es digitadas pelo usu�rio. A quantidade de alunos da lista tamb�m
       deve ser passada como par�metro.
    b. Elabore uma fun��o que retorne a quantidade de alunos que possuem rendimento maior que X, X deve ser passado como
       par�metro. Analise a fun��o e veja se � necess�rio definir outros par�metros.
    c. Elabore uma fun��o para aumente em X% os rendimentos acad�micos de todos os alunos do curso de c�digo = Y.
       O valor de X e Y devem ser passados como par�metro. Analise a fun��o e veja se � necess�rio definir outros par�metros.
    d. Elabore uma fun��o que receba a lista de alunos e um c�digo de curso e imprima as informa��es dos alunos que possuem
       c�digo recebido. As informa��es de cada aluno devem ser impressas em linhas separadas.
*********************************************************************************************************************************/
#include <stdio.h>
struct aluno{
    int matricula,cod;
    float rend;
    char nome[100];
};
void imprime(struct aluno lista[],int qtd,float codigo)
{
    for(int i=0;i<qtd;i++)
    {
        if(lista[i].cod==codigo)
        {
            printf("\nNome: %s\nMatricula:%d\nRendimento:%.2f\n",lista[i].nome,lista[i].matricula,lista[i].rend);
        }
    }
}
void aumentar(struct aluno lista[],int qtd,float X,int Y)
{
    for(int i=0;i<qtd;i++)
    {
        if(lista[i].cod==Y)
            lista[i].rend*=1+(X/100);
    }
}
int contaRend(struct aluno lista[],int qtd,int r)
{
    int cont=0;
    for(int i=0;i<qtd;i++)
    {
        if(lista[i].rend>r)
            cont++;
    }
    return cont;
}
void cadastro(struct aluno listaAluno[],int n)
{
    for(int i=0;i<n;i++)
    {
        fflush(stdin);
        printf("Entre com o nome do aluno:");
        scanf("%[^\n]",listaAluno[i].nome);
        printf("Entre com a matricula,o codigo do curso e o rendimento respectivamente:");
        scanf("%d %d %f", &listaAluno[i].matricula,&listaAluno[i].cod,&listaAluno[i].rend);
    }
}
int main(){
    struct aluno la[40];
    int qtd,qtdRend,Y;
    float rendimento,X;
    printf("Entre com a quantidade de alunos a cadastrar:");
    scanf("%d",&qtd);
    cadastro(la,qtd);
    for(int i=0;i<qtd;i++)
        printf("\nNome: %s Cod curso.:%d Matricula:%d Rendimento:%.2f",la[i].nome,la[i].cod,la[i].matricula,la[i].rend);

    printf("\nEntre com o valor do rendimento, o qual deseja saber a quantidade de alunos que possuir rendimento maior que este:");
    scanf("%f",&rendimento);
    qtdRend= contaRend(la,qtd,rendimento);
    printf("A quantidade de alunos com rendimento maior que %.2f s�o %d.\n",rendimento,qtdRend);

    printf("Entre com o valor da porcentagem X% que deseja aumentar para todos os alunos de um curso:");
    scanf("%f",&X);
    printf("Entre com o codigo do curso para para o qual deseja aumentar a porcentagem do rendimento:");
    scanf("%d",&Y);
    aumentar(la,qtd,X,Y);
    for(int i=0;i<qtd;i++)
        printf("\nNome: %s Cod curso.:%d Matricula:%d Rendimento:%.2f\n",la[i].nome,la[i].cod,la[i].matricula,la[i].rend);

    printf("\nEntre com o codigo do curso para imprimir os dados dos alunos especificos deste codigo:");
    scanf("%d",&Y);
    imprime(la,qtd,Y);
return 0;
}

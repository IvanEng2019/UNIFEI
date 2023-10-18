/*******************************************************************************************************************************
3. A partir da estrutura criada no exercício 1, crie um vetor para armazenar uma lista de, no máximo, 40 alunos.
    a. Elabore uma função que preencha o vetor com informações digitadas pelo usuário. A quantidade de alunos da lista também
       deve ser passada como parâmetro.
    b. Elabore uma função que retorne a quantidade de alunos que possuem rendimento maior que X, X deve ser passado como
       parâmetro. Analise a função e veja se é necessário definir outros parâmetros.
    c. Elabore uma função para aumente em X% os rendimentos acadêmicos de todos os alunos do curso de código = Y.
       O valor de X e Y devem ser passados como parâmetro. Analise a função e veja se é necessário definir outros parâmetros.
    d. Elabore uma função que receba a lista de alunos e um código de curso e imprima as informações dos alunos que possuem
       código recebido. As informações de cada aluno devem ser impressas em linhas separadas.
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
    printf("A quantidade de alunos com rendimento maior que %.2f são %d.\n",rendimento,qtdRend);

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

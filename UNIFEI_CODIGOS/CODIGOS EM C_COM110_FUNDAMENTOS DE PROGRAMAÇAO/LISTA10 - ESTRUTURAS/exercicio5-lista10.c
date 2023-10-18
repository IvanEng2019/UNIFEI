/*******************************************************************************************************************************
5. Utilizando a estrutura do exerc�cio 1, crie um programa para facilitar o gerenciamento das informa��es dos alunos de uma turma.
   A turma tem, no m�ximo, 50 alunos. A quantidade de alunos deve ser fornecida pelo usu�rio. Crie fun��es para:
    a. Preencher a lista de alunos;
    b. Imprimir os dados de todos os alunos da lista;
    c. Dado um n�mero de matr�cula, verificar se o aluno existe na lista. Se existir, imprima o nome.
       Caso contr�rio, imprima uma mensagem de notifica��o;
    d. Dado um nome, imprimir os dados de todos os alunos com o mesmo nome. Considere que h� alunos com nomes repetidos.
    e. Dado um nome, retornar a quantidade de alunos com o nome fornecido.
*********************************************************************************************************************************/
//inclus�o de bibliotecas com fun��es pre-definidas
#include <stdio.h>
#include <string.h>
// cria��o de estrutura aluno
struct aluno{
    int matricula,cod; // vaiabel matricula e codigo do curso do tipo intiera
    float rend; // rendimento do aluno do tipo float
    char nome[101]; // variavel nome � uma string com ate 100 digitos uteis
};
//fun��o que calcula e retorna o numero de alunos com mesmo nome
int iguaisQtd(struct aluno listaAluno[],int total,char nome[])
{
    int qtd=0;// variavel qtd tera o valor da quantidade de alunos com mesmo nome e inicialmente � atribuido 0
    for(int i=0;i<total;i++)//la�o percorre a lista com todos os nomes atraves da variavel i
    {
        if(strcmp(listaAluno[i].nome,nome)==0)//a fun��o retorna 0 caso as duas cadeias de caracter sejam iguais
           qtd++;// se o nome dado pelo usuario for igual ao nome do aluno da lista qtd sera incremetado em uma unidade
    }
    return qtd; //retorna o valor de qtd
}
//fun��es que imprime os dados dos alunos de mesmo nome
void iguais(struct aluno listaAluno[],int total,char nome[])
{
    for(int i=0;i<total;i++)//ira percorrer todos os nomes cadastrados
    {
        //atraves da fun��o strcamp compara de as duas cadeais de carcter (da lista e a fornecida pelo usuario) s�o iguais
        //se forem igauis strcmp retorna 0
        if(strcmp(listaAluno[i].nome,nome)==0)
            printf("\nAluna de mesmo nome:\nMatricula:%d\nCodigo do Curso:%d\nRendimento: %.2f\n",listaAluno[i].matricula,listaAluno[i].cod,listaAluno[i].rend);
    }
}
//fun��o que pesquisa se o aluno esta ou nao matriculado
void pesquisar(struct aluno listaAluno[],int total,int mat)
{
    int aux=0;// variavel de controle que indicara se existe ou nao a matricula cadastrada,no caso 0 indica que nao existe a matricula
    for(int i=0;i<total;i++)//faz a varredura na lista atravez de i posi��es
    {
        if(listaAluno[i].matricula==mat)//caso a matricula fornecida pelo usuario seja igual a matricula cadastrada
        {
            printf("Aluno %s matriculado.\n",listaAluno[i].nome);// imprime o nome do aluno da matricula pesquisada
            aux=1;//caso exista a matricula sera atribuindo 1 a variavel
            break; // como nao existe aluno de mesma matricula quando encontrada sai do la�o
        }
    }
    if(aux==0)//executa apenas se nao encontrar a matricula na lista
      printf("N�o existe esta matricula cadastrada.\n");
}
//fun��o para cadastrar os dados dos alunos na lista
void cadastrar(struct aluno listaAluno[],int total)
{
    for(int i=0;i<total;i++) //A cada intera��o do for os dados serao amazenados conforme valor da variavel i (posi��o de i)
    {
        fflush(stdin);
        printf("Entre com o nome, a matricula, o codigo e rendimento respectivamente:\n");
        scanf("%[^\n] %d %d %f",listaAluno[i].nome,&listaAluno[i].matricula,&listaAluno[i].cod,&listaAluno[i].rend);
    }
}
//fun��o para imprimir os dados de todos os alunos da lista
void imprimir(struct aluno listaAluno[],int total)
{
    printf("\nLista de todos os alunos com seus dados:\n");
    for(int i=0;i<total;i++)//A cada intera��o do for os dados serao apresentados conforme valor da variavel i (posi��o de i)
       printf("\nAluno:%s\nMatricula:%d\nCodigo do Curso:%d\nRendimento: %.2f\n",listaAluno[i].nome,listaAluno[i].matricula,listaAluno[i].cod,listaAluno[i].rend);
}
int main(){
    struct aluno a[3];// criando a variavel a do tipo struct aluno que tera uma lista de ate no maximo 50 alunos
    // variaveis locais da main que receberao dados de entrada = do usu�rio
    int qtd,mat;
    char nom[101];
    printf("Entre com a quantidade de alunos a cadastrar:");// pede pro usuario informar o numero de alunos que ira cdastrar
    scanf(" %d",&qtd);
    cadastrar(a,qtd);//chama a fun��o cadastrar passando a estrutura "a" por referencia e a variavel qtd por valor
    imprimir(a,qtd);//chama a fun��o imprimir passando a estrutura  "a" por referencia e a variavel qtd por valor
    printf("\nEntre com o numero de Matricula para pesquisar se o aluno existe:");//pede ao usuario uma matricula
    scanf("%d",&mat);// armazena o dado do usuario na variavel mat
    pesquisar(a,qtd,mat);//chama a fun��o pesquisar passando  a por referencia e qtd e mat por valor
    fflush(stdin);
    printf("\nEntre com o nome do aluno para verificar os dados de todos os alunos de mesmo nome:");//pede um nome ao usuario
    scanf("%[^\n]",nom);// � amrzenado um nome de ate 100 caracteres na variavel nom
    iguais(a,qtd,nom);//chama a fun��o igauis passando a e nom por referencia e qtd por valor
     fflush(stdin);
    printf("\nEntre com o nome do aluno para verificar a quantidade de alunos de mesmo nome:");;//pede novamente um nome ao usuario
    scanf("%[^\n]",nom);// � amrzenado um nome de ate 100 caracteres na variavel nom
    printf("Existem %d alunos com este mesmo nome.\n",iguaisQtd(a,qtd,nom));//imprimi o valor retornado ple afun��o iguaisQtd()
return 0;
}

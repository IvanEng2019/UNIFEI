/*******************************************************************************************************************************
2. Elabore uma estrutura para armazenar as informações de um livro contendo os seguintes dados:
código (inteiro), título (cadeia de caractere de tamanho máximo = 100) e ano de publicação (inteiro)
   g. Modifque a função da letra (e) de maneira que, caso o título do livro seja igual ao título recebido pela função, o ano
   de publicação do livro deve ser alterado somando 10 ao valor atual. Nesse caso, é necessário passar o endereço do livro?
   sim, uma vez q sera alterado o valor deve passar o endereço da variavel
   h. Crie um vetor de, no máximo, 50 livros e preencha as informações dos livros com dados digitados no teclado.
   A quantidade de livros na lista a ser preenchida deve ser fornecida pelo usuário.
   i. Altere a estrutura criada e adicione um campo que deve ser chamado de status que deverá receber uma letra
   (A (ativo) ou I (inativo)).
   j. Elabore uma função que receba as informações dos livros (a lista de livros) e caso o livro tenha sido publicado
   antes do ano 1950, preencher o status do livro com o valor I, caso contrário, preencher o status do livro com o valor A.
*********************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
struct livro{
    int cod, ano;
    char status, titulo[100];
};
void atribuiEstatus(struct livro le[],int qtd)
{
    for(int i=0;i<qtd;i++)
    {
        if(le[i].ano<1950)
            le[i].status='I';
        else
            le[i].status='A';
    }
}
void imprimirLivro(struct livro li[],int qtd)
{
    for(int i=0;i<qtd;i++)
       printf("\nNome: %s\nCodigo do livro:%d\nAno:%d\nStatus:%c\n",li[i].titulo,li[i].cod,li[i].ano,li[i].status);
}
void procuraLivro(struct livro pl[], char tit[],int n)
{
    int aux=0,i;
    for(i=0;i<n;i++)
    {
        if(strcmp(pl[i].titulo,tit)==0)
        {
            pl[i].ano+=10;
            aux=1;
            i=n;//break;
        }
        else
          aux=0;
    }
     if(aux==0)
        printf("O Livro %s não existe.\n",tit);
}

int main(){
    struct livro l[51];
    int codigo, data, qtd;
    char nome[100];
    printf("Entre com a quantidade de livros a cadastrar:");
    scanf("%d",&qtd);
    for(int i=0;i<qtd;i++)
    {
        fflush(stdin);
        printf("Entre com o nome do livro:");
        scanf("%[^\n]",l[i].titulo);
        printf("Entre com o codigo  e ano respectivamente:");
        scanf("%d %d",&l[i].cod,&l[i].ano);
    }
    for(int i=0;i<qtd;i++)
       printf("Nome: %s Codigo do livro:%d Ano:%d\n",l[i].titulo,l[i].cod,l[i].ano);
    printf("\nEntre com o titulo do livro que deseja procurar a alterar o ano:");
    scanf(" %[^\n]",nome);
    procuraLivro(l,nome,qtd);
    for(int i=0;i<qtd;i++)
       printf("Nome: %s Codigo do livro:%d Ano:%d\n",l[i].titulo,l[i].cod,l[i].ano);
    printf("\nAtribuindo status.\n");
    atribuiEstatus(l,qtd);
    imprimirLivro(l,qtd);

return 0;
}

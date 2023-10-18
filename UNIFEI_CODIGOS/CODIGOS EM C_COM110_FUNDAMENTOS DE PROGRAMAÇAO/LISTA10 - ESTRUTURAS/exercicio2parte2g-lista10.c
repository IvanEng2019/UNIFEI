/*******************************************************************************************************************************
2. Elabore uma estrutura para armazenar as informa��es de um livro contendo os seguintes dados:
c�digo (inteiro), t�tulo (cadeia de caractere de tamanho m�ximo = 100) e ano de publica��o (inteiro)
   g. Modifque a fun��o da letra (e) de maneira que, caso o t�tulo do livro seja igual ao t�tulo recebido pela fun��o, o ano
   de publica��o do livro deve ser alterado somando 10 ao valor atual. Nesse caso, � necess�rio passar o endere�o do livro?
   sim, uma vez q sera alterado o valor deve passar o endere�o da variavel
   h. Crie um vetor de, no m�ximo, 50 livros e preencha as informa��es dos livros com dados digitados no teclado.
   A quantidade de livros na lista a ser preenchida deve ser fornecida pelo usu�rio.
   i. Altere a estrutura criada e adicione um campo que deve ser chamado de status que dever� receber uma letra
   (A (ativo) ou I (inativo)).
   j. Elabore uma fun��o que receba as informa��es dos livros (a lista de livros) e caso o livro tenha sido publicado
   antes do ano 1950, preencher o status do livro com o valor I, caso contr�rio, preencher o status do livro com o valor A.
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
        printf("O Livro %s n�o existe.\n",tit);
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

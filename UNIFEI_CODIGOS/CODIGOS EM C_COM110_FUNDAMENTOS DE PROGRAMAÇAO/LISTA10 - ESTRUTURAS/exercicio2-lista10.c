/*******************************************************************************************************************************
2. Elabore uma estrutura para armazenar as informações de um livro contendo os seguintes dados:
código (inteiro), título (cadeia de caractere de tamanho máximo = 100) e ano de publicação (inteiro)
   a. No programa principal, use a estrutura elaborada para preencher as informações de um livro com dados digitados no teclado.
   b. Imprima estas informações na tela.
   c. Elabore uma função que receba as informações de um livro, um código e um valor de ano.
      Caso o livro recebido tenha o código igual ao que foi passado como parâmetro, altere o ano do livro para o novo valor.
      Como essa estrutura deve ser passada como parâmetro? Referência ou valor? E os demais parâmetros?
   d. Elabore uma função que receba uma estrutura livro e imprima as informações do livro na tela (um dado por linha).
   e. Elabore uma função que receba um livro e um título, caso o título do livro seja igual ao título recebido,
   imprimir uma mensagem informando que o livro foi encontrado, caso contrário, informar que o livro não existe.
   f. Nas funções (d) e (e), como foi a passagem de parâmetro? Foi necessário passar a  referência (ou o endereço) da
   estrutura livro? por valor. Não é nescessario afinal não a mudança de valor.
*********************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
struct livro{
    int cod, ano;
    char titulo[100];
};

void alteraAno(struct livro *liv,int codigo, int a )
{
    if(liv->cod==codigo)
        liv->ano=a;
}
void imprimirLivro(struct livro implivro)
{
     printf("\nNome: %s\nCodigo do livro:%d\nAno:%d\n",implivro.titulo,implivro.cod,implivro.ano);
}
void procuraLivro(struct livro pl, char tit[])
{
     if(strcmp(pl.titulo,tit)==0)
        printf("O Livro %s foi encontrado.\n",tit);
     else
        printf("O Livro %s não existe.\n",tit);
}

int main(){
    struct livro l;
    int codigo, data;
    char nome[100];

    printf("Entre com o nome do livro:");
    scanf("%[^\n]",l.titulo);
    printf("Entre com o codigo  e ano respectivamente:");
    scanf("%d %d", &l.cod,&l.ano);
    printf("\nNome: %s Codigo do livro:%d Ano:%d\n",l.titulo,l.cod,l.ano);

    printf("Entre com o codigo do livro e ano a alterar respectivamente:");
    scanf("%d %d",&codigo,&data);
    alteraAno(&l,codigo,data);

    imprimirLivro(l);
    fflush(stdin);
    printf("Entre com o titulo do livro que deseja procurar:");
    scanf(" %[^\n]",nome);
    procuraLivro(l,nome);
return 0;
}

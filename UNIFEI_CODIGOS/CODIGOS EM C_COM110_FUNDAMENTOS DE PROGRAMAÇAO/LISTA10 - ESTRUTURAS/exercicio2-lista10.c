/*******************************************************************************************************************************
2. Elabore uma estrutura para armazenar as informa��es de um livro contendo os seguintes dados:
c�digo (inteiro), t�tulo (cadeia de caractere de tamanho m�ximo = 100) e ano de publica��o (inteiro)
   a. No programa principal, use a estrutura elaborada para preencher as informa��es de um livro com dados digitados no teclado.
   b. Imprima estas informa��es na tela.
   c. Elabore uma fun��o que receba as informa��es de um livro, um c�digo e um valor de ano.
      Caso o livro recebido tenha o c�digo igual ao que foi passado como par�metro, altere o ano do livro para o novo valor.
      Como essa estrutura deve ser passada como par�metro? Refer�ncia ou valor? E os demais par�metros?
   d. Elabore uma fun��o que receba uma estrutura livro e imprima as informa��es do livro na tela (um dado por linha).
   e. Elabore uma fun��o que receba um livro e um t�tulo, caso o t�tulo do livro seja igual ao t�tulo recebido,
   imprimir uma mensagem informando que o livro foi encontrado, caso contr�rio, informar que o livro n�o existe.
   f. Nas fun��es (d) e (e), como foi a passagem de par�metro? Foi necess�rio passar a  refer�ncia (ou o endere�o) da
   estrutura livro? por valor. N�o � nescessario afinal n�o a mudan�a de valor.
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
        printf("O Livro %s n�o existe.\n",tit);
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

/****************************************************************************************************
1. Crie uma estrutura para representar as informa��es de um aluno contendo os seguintes dados:
 matr�cula (inteiro), c�digo do curso (inteiro) e rendimento acad�mico (float).
  a. No programa principal, use a estrutura elaborada para preencher as informa��es de um aluno
     com dados digitados no teclado.
  b. Imprima estas informa��es na tela.
  c. Crie um campo nome na estrutura que deve ser uma cadeia de caractere de tamanho m�ximo = 100.
  d. No programa, depois de imprimir as informa��es do aluno, verifique se o nome do aluno � �Jo�o Jose da Silva�.
     Se for, imprima a matr�cula do aluno. Caso contr�rio, imprima �Aluno n�o encontrado�.
*****************************************************************************************************/
#include <stdio.h>
#include <string.h> // fun�oes de strings:
// strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
// strlen - fornece o tamanho da cadeia
// strcmp - compara se s�o iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 � maior que a segunda em ordem alfabetica
struct aluno{
    int matricula,cod;
    float rend;
    char nome[100];
};
int main(){
    struct aluno a;
    printf("Entre com o nome do aluno:");
    scanf("%[^\n]",a.nome);
    printf("Entre com a matricula,o codigo do curso e o rendimento respectivamente:");
    scanf("%d %d %f", &a.matricula,&a.cod,&a.rend);
    printf("\nNome: %s\nMatricula:%d\nCodigo do curso:%d\nRedimento academico:%.2f.",a.nome,a.matricula,a.cod,a.rend);
    if(strcmp(a.nome,"Joao Jose da Silva")==0)
        printf("\nA Matricula do aluno %s �:%d",a.nome,a.matricula);
    else
        printf("\nMatricula n�o encontrada de Joao Jose da Silva.\n");
return 0;
}

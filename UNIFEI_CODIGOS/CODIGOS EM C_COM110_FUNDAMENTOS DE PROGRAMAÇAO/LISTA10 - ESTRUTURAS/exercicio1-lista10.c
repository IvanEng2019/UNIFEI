/****************************************************************************************************
1. Crie uma estrutura para representar as informações de um aluno contendo os seguintes dados:
 matrícula (inteiro), código do curso (inteiro) e rendimento acadêmico (float).
  a. No programa principal, use a estrutura elaborada para preencher as informações de um aluno
     com dados digitados no teclado.
  b. Imprima estas informações na tela.
  c. Crie um campo nome na estrutura que deve ser uma cadeia de caractere de tamanho máximo = 100.
  d. No programa, depois de imprimir as informações do aluno, verifique se o nome do aluno é “João Jose da Silva”.
     Se for, imprima a matrícula do aluno. Caso contrário, imprima “Aluno não encontrado”.
*****************************************************************************************************/
#include <stdio.h>
#include <string.h> // funçoes de strings:
// strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
// strlen - fornece o tamanho da cadeia
// strcmp - compara se são iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 é maior que a segunda em ordem alfabetica
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
        printf("\nA Matricula do aluno %s é:%d",a.nome,a.matricula);
    else
        printf("\nMatricula não encontrada de Joao Jose da Silva.\n");
return 0;
}

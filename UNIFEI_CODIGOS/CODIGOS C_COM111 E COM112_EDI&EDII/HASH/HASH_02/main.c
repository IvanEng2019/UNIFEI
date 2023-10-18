#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int menu();
struct aluno criaAluno();
void imprimeAluno(struct aluno a1);

int main(void) {
  menu();

}


int menu(){     //menu de opções
  int aux, tam, temp, matric;
  do
  {
    printf("\n\n\n__________________________________________________________________\n");
    printf("\n___________________________TABELA  HASH___________________________\n");
    printf("\n1. Criar tabela hash");
    printf("\n2. Liberar tabela hash");
    printf("\n3. Inserir elemento (sem colisão)");
    printf("\n4. Consultar elemento (sem colisão) ");
    printf("\n5. Sair do programa");
    printf("\n__________________________________________________________________\n");
    printf("\nSelecione uma das opcoes:");
    scanf("%d", &aux);


    switch(aux){
      case 1:
        printf("\n\n_______________________Criar Tabela Hash!!!_______________________\n\n");
        printf("Lembre-se de que o ideal eh escolher um numero primo como tamanho \nda tabela hash (reduz a probabilidade de colisoes)\n\n");
        printf("Tamanho da tabela: ");
        scanf("%d", &tam);
        Hash* h1 = criaHash(tam);
        printf("Hash criada com sucesso!!!");
      break;

      case 2:
        printf("\n\n______________________Libera Tabela Hash!!!______________________\n\n");
        liberaHash(h1);
        printf("Hash liberada com sucesso!!!");
      break;

      case 3:
        printf("\n\n______________________Inserir Aluno______________________\n\n");
        struct aluno a1;
        a1 = criaAluno();
        temp = insereSemColisao(h1, a1);
        //imprimeAluno(a1);
        if(temp==1)
          printf("Insercao realizada com sucesso");
        else
          printf("\nFalha na insercao");
      break;

      case 4:
        printf("\n\n______________________Consultar Aluno______________________\n\n");
        printf("Matricula: ");
        scanf("%d", &matric);
        temp = buscaSemColisao(h1, matric, &a1);
        if(temp==1){
          printf("Aluno localizado");
          imprimeAluno(a1);
        }
        else
          printf("Aluno nao encontrado");
      break;

    }
  }while(aux!=5);
  return 1;
}


struct aluno criaAluno(){
  struct aluno a1;
  printf("Criando Aluno:\n");
  printf("Matricula: ");
  scanf("%d", &a1.matricula);
  printf("Nome: ");
  scanf("%s", a1.nome);
  printf("Nota 1: ");
  scanf("%f", &a1.n1);
  printf("Nota 2: ");
  scanf("%f", &a1.n2);

  return a1;
}


void imprimeAluno(struct aluno a1){
  printf("\nMatricula:%d\nNome:%s\nNota 1:%.2f\nNota 2:%.2f\n", a1.matricula,a1.nome,a1.n1,a1.n2);
}
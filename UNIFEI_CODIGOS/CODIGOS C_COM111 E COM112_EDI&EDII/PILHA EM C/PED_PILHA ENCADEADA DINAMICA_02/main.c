#include <stdio.h>
#include "pilhaEncS.h"

int main(void) {
  Pilha *li=NULL;
  int opcao, valor;
  do{
    printf("Menu de opções:");
    printf("\n1 - Criar pilha");
    printf("\n2 - Liberar Pilha");
    printf("\n3 - Inserir elemento - no fim -");
    printf("\n4 - Remover elemento - no Fim -");
    printf("\n5 - Mostrar Pilha");
    printf("\n6 - Pesquisa Pilha: Mostra ultimo Elemento");
    printf("\n7 - Tamanho do Pilha");
    printf("\n8 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    switch(opcao){
      case 1:
        li = criar_pilha();
        if(li != NULL)
          printf("Pilha criada com sucesso!");
        else
          printf("Pilha não criada!");
        break;
      case 2:
        if(liberar_pilha(li)==1)
            printf("Pilha liberada com sucesso.");
        else
            printf("Pilha não liberada.");
        break;
      case 3:
        if(li!=NULL){
            printf("\nElemento a ser inserido: ");
            scanf("%d", &valor);
            if(enfileirar(li, valor) == 1)
                printf("Inserção realizada com sucesso!");
        }
        else
            printf("Não existe lista.");
        break;
      case 4:
        valor=desinfileirar(li);
        if(valor == 1)
          printf("Remoção realizada com sucesso!");
        else{
            if(valor==-1)
                printf("Pilha não existe.");
            else
                printf("Pilha vazia.");
        }
        break;
      case 5:
        if(imprime_pilha(li) == 0)
          printf("Não existe fila.\n");
        break;
      case 6:
        valor=pesquisa_pilha_ultimo(li);
        if(valor== 0)
          printf("Não existe elemento na Pilha.");
        else
            printf("O Ultimoºelemento é %d.",valor);
        break;
      case 7:
        valor= tamanho_pilha(li);
        if(valor == -1)
          printf("Não existe pilha.");
        else{
            if(valor == 0)
                printf("Pilha Vazia.");
            else
                printf("A Pilha tem tamanho %d.",valor);
        }
        break;
      case 8:
        if(liberar_pilha(li)==1)
            printf("Pilha liberada com sucesso.");
        else
            printf("Pilha não liberada.");
        printf("\nFinalizando...");
        break;
      default:
        printf("\nOpção inválida!");
        break;
    }
    printf("\n\n
           ");
  }while(opcao!=8);
  return 0;
}

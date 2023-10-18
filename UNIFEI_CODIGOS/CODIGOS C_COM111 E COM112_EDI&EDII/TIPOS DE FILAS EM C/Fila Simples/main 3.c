#include <stdio.h>
#include "filaEncS.h"

int main(void) {
  Fila *li=NULL;
  int opcao, valor;
  do{
    printf("Menu de opções:");
    printf("\n1 - Criar fila");
    printf("\n2 - Liberar Fila");
    printf("\n3 - Inserir elemento - no fim -");
    printf("\n4 - Remover elemento - no inicio -");
    printf("\n5 - Mostrar Fila");
    printf("\n6 - Pesquisa Fila: Mostra 1º Elemento");
    printf("\n7 - Tamanho do fila");
    printf("\n8 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    switch(opcao){
      case 1:
        li = criar_fila();
        if(li != NULL)
          printf("Lista criada com sucesso!");
        else
          printf("Fila não criada!");
        break;
      case 2:
        if(liberar_fila(li)==1)
            printf("Fila liberada com sucesso.");
        else
            printf("Fila não liberada.");
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
                printf("Fila não existe.");
            else
                printf("lista vazia.");
        }
        break;
      case 5:
        if(imprime_fila(li) == 0)
          printf("Não existe fila.\n");
        break;
      case 6:
        valor=pesquisa_fila_primeiro(li);
        if(valor== 0)
          printf("Não existe elemento na fila.");
        else
            printf("O 1ºelemento é %d.",valor);
        break;
      case 7:
        valor= tamanho_fila(li);
        if(valor == -1)
          printf("Não existe fila.");
        else{
            if(valor == 0)
                printf("Fila Vazia.");
            else
                printf("A fila tem tamanho %d.",valor);
        }
        break;
      case 8:
        if(liberar_fila(li)==1)
            printf("Fila liberada com sucesso.");
        else
            printf("Fila não liberada.");
        printf("\nFinalizando...");
        break;
      default:
        printf("\nOpção inválida!");
        break;
    }
    printf("\n");
  }while(opcao!=8);
  return 0;
}

#include <stdio.h>
#include "pilhaEncS.h"

int main(void) {
  Pilha *li=NULL;
  int opcao, valor;
  do{
    printf("Menu de op��es:");
    printf("\n1 - Criar pilha");
    printf("\n2 - Liberar Pilha");
    printf("\n3 - Inserir elemento - no fim -");
    printf("\n4 - Remover elemento - no Fim -");
    printf("\n5 - Mostrar Pilha");
    printf("\n6 - Pesquisa Pilha: Mostra ultimo Elemento");
    printf("\n7 - Tamanho do Pilha");
    printf("\n8 - Sair");
    printf("\nOp��o: ");
    scanf("%d", &opcao);
    switch(opcao){
      case 1:
        li = criar_pilha();
        if(li != NULL)
          printf("Pilha criada com sucesso!");
        else
          printf("Pilha n�o criada!");
        break;
      case 2:
        if(liberar_pilha(li)==1)
            printf("Pilha liberada com sucesso.");
        else
            printf("Pilha n�o liberada.");
        break;
      case 3:
        if(li!=NULL){
            printf("\nElemento a ser inserido: ");
            scanf("%d", &valor);
            if(enfileirar(li, valor) == 1)
                printf("Inser��o realizada com sucesso!");
        }
        else
            printf("N�o existe lista.");
        break;
      case 4:
        valor=desinfileirar(li);
        if(valor == 1)
          printf("Remo��o realizada com sucesso!");
        else{
            if(valor==-1)
                printf("Pilha n�o existe.");
            else
                printf("Pilha vazia.");
        }
        break;
      case 5:
        if(imprime_pilha(li) == 0)
          printf("N�o existe fila.\n");
        break;
      case 6:
        valor=pesquisa_pilha_ultimo(li);
        if(valor== 0)
          printf("N�o existe elemento na Pilha.");
        else
            printf("O Ultimo�elemento � %d.",valor);
        break;
      case 7:
        valor= tamanho_pilha(li);
        if(valor == -1)
          printf("N�o existe pilha.");
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
            printf("Pilha n�o liberada.");
        printf("\nFinalizando...");
        break;
      default:
        printf("\nOp��o inv�lida!");
        break;
    }
    printf("\n\n
           ");
  }while(opcao!=8);
  return 0;
}

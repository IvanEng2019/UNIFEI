#include <stdio.h>
#include "filaEncCirc.h"

int main(void) {
  Fila *li=NULL;
  int opcao, valor;
  do{
    printf("Menu de op��es:");
    printf("\n1 - Criar fila Circular");
    printf("\n2 - Liberar Fila");
    printf("\n3 - Inserir elemento - no fim -");
    printf("\n4 - Remover elemento - no inicio -");
    printf("\n5 - Mostrar Fila");
    printf("\n6 - Pesquisa Fila: Mostra 1� Elemento");
    printf("\n7 - Tamanho do fila");
    printf("\n8 - Sair");
    printf("\nOp��o: ");
    scanf("%d", &opcao);
    switch(opcao){
      case 1:
        li = criar_fila_circ();
        if(li != NULL)
          printf("Lista criada com sucesso!");
        else
          printf("Fila n�o criada!");
        break;
      case 2:
        if(liberar_fila(li)==1)
            printf("Fila liberada com sucesso.");
        else
            printf("Fila n�o liberada.");
        break;
      case 3:
        if(li!=NULL){
            printf("\nElemento a ser inserido: ");
            scanf("%d", &valor);
            if(enfileirar(li, valor) == 1)
                printf("Inser��o realizada com sucesso!");
        }
        else
            printf("N�o existe Fila.");
        break;
      case 4:
        valor=desinfileirar(li);
        if(valor == 1)
          printf("Remo��o realizada com sucesso!");
        else{
            if(valor==-1)
                printf("Fila n�o existe.");
            else
                printf("lista vazia.");
        }
        break;
      case 5:
        valor=imprime_fila(li);
        if(valor == -1)
           printf("N�o existe fila.");
        if(valor == 0)
           printf("Fila Vazia.");
        break;
      case 6:
        valor=pesquisa_fila_primeiro(li);
        if(valor== 0)
          printf("N�o existe elemento na fila.");
        else
            printf("O 1�elemento � %d.",valor);
        break;
      case 7:
        valor= tamanho_fila(li);
        if(valor == -1)
          printf("N�o existe fila.");
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
            printf("Fila n�o liberada.");
        printf("\nFinalizando...");
        break;
      default:
        printf("\nOp��o inv�lida!");
        break;
    }
    printf("\n\n");
  }while(opcao!=8);
  return 0;
}

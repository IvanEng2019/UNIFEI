
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "pilha_estatica.h"


int criar_dado(int *dado);


// funcao principal
int main(void) {

  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Pilha *pi;
  int opcao, dado, ok, pos;

  // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar Pilha");
    printf("\n2 - Destruir Pilha");
    printf("\n3 - Inserir elemento (no topo)");
    printf("\n4 - Remover elemento (do topo)");
    printf("\n5 - Consultar o elemento do topo");
    printf("\n6 - Imprimir pilha");
    printf("\n7 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

        // criar lista
        pi = criar_pilha();

        if(pi != NULL){
          printf("\n Pilha criada com sucesso!");
        }else{
          printf("\n Pilha não criada!");
        }
        break;


      case 2:

        // liberar lista
        ok = liberar_pilha(pi);

        if(ok){
          printf("\n Pilha liberada com sucesso!");
        }else{
          printf("\n Pilha não liberada!");
        }
        break;

      case 3:

        // inserir elemento no final
        ok = criar_dado(&dado);
        ok = inserir_pilha(pi, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;


      case 4:

        // remover elemento do início
        ok = remover_pilha(pi);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;


      case 5:

        // busca primeiro elemento
          printf("\n Busca realizada com sucesso!");
          printf("\n Primeiro elemento: %d", buscar_pilha(pi));

        break;


      case 6:

        // imprime a lista
        printf("\n Pilha estática: ");
        ok = imprimir_pilha(pi);

        break;

      case 7:

        // libera memória e finaliza programa
        liberar_pilha(pi);
        printf("\nFinalizando...");
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 7);

  return 0;
}





int criar_dado(int *dado)
{
    printf("\nDigite um valor: ");
    scanf("%d", dado);

    return 1;
}

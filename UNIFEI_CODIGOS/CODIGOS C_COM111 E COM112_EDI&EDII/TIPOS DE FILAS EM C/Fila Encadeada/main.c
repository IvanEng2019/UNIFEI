
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "fila_encadeada.h"


int criar_dado(int *dado);


// funcao principal
int main(void) {

  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Fila *fi;
  int opcao, dado, ok, pos;

  // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar Fila");
    printf("\n2 - Destruir Fila");
    printf("\n3 - Inserir elemento (no final)");
    printf("\n4 - Remover elemento (no inicio)");
    printf("\n5 - Consultar o primeiro elemento");
    printf("\n6 - Imprimir fila");
    printf("\n7 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

        // criar lista
        fi = criar_fila();

        if(fi != NULL){
          printf("\n Fila criada com sucesso!");
        }else{
          printf("\n Fila não criada!");
        }
        break;


      case 2:

        // liberar lista
        ok = liberar_fila(fi);

        if(ok){
          printf("\n Fila liberada com sucesso!");
        }else{
          printf("\n Fila não liberada!");
        }
        break;

      case 3:

        // inserir elemento no final
        ok = criar_dado(&dado);
        ok = inserir_fila(fi, dado);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;


      case 4:

        // remover elemento do início
        ok = remover_fila(fi);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;


      case 5:

        // busca primeiro elemento
          printf("\n Busca realizada com sucesso!");
          printf("\n Primeiro elemento: %d", buscar_fila(fi));

        break;


      case 6:

        // imprime a lista
        printf("\n Fila estática: ");
        ok = imprimir_fila(fi);

        break;

      case 7:

        // libera memória e finaliza programa
        liberar_fila(fi);
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

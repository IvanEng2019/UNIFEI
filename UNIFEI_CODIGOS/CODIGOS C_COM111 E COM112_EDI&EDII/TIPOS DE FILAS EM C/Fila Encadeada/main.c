
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "fila_encadeada.h"


int criar_dado(int *dado);


// funcao principal
int main(void) {

  // no in�cio a lista est� vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conter� o endere�o do primeiro elemento da lista
  Fila *fi;
  int opcao, dado, ok, pos;

  // menu de op��es para execu��es de opera��es sobre a lista
  do
  {
    printf("\n\nMenu de op��es");
    printf("\n1 - Criar Fila");
    printf("\n2 - Destruir Fila");
    printf("\n3 - Inserir elemento (no final)");
    printf("\n4 - Remover elemento (no inicio)");
    printf("\n5 - Consultar o primeiro elemento");
    printf("\n6 - Imprimir fila");
    printf("\n7 - Sair");
    printf("\nOp��o: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

        // criar lista
        fi = criar_fila();

        if(fi != NULL){
          printf("\n Fila criada com sucesso!");
        }else{
          printf("\n Fila n�o criada!");
        }
        break;


      case 2:

        // liberar lista
        ok = liberar_fila(fi);

        if(ok){
          printf("\n Fila liberada com sucesso!");
        }else{
          printf("\n Fila n�o liberada!");
        }
        break;

      case 3:

        // inserir elemento no final
        ok = criar_dado(&dado);
        ok = inserir_fila(fi, dado);

        if(ok == 1){
          printf("\n Inser��o realizada com sucesso!");
        }else{
          printf("\n Falha na inser��o!");
        }

        break;


      case 4:

        // remover elemento do in�cio
        ok = remover_fila(fi);

        if(ok == 1){
          printf("\n Remo��o realizada com sucesso!");
        }else{
          printf("\n Falha na remo��o!");
        }
        break;


      case 5:

        // busca primeiro elemento
          printf("\n Busca realizada com sucesso!");
          printf("\n Primeiro elemento: %d", buscar_fila(fi));

        break;


      case 6:

        // imprime a lista
        printf("\n Fila est�tica: ");
        ok = imprimir_fila(fi);

        break;

      case 7:

        // libera mem�ria e finaliza programa
        liberar_fila(fi);
        printf("\nFinalizando...");
        break;

      default:
        printf("\nOp��o inv�lida!");
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

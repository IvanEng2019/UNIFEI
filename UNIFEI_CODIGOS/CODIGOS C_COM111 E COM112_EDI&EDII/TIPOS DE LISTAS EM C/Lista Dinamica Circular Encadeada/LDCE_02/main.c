
// bibliotecas do sistema
#include <stdio.h>

// bibliotecas do projeto
#include "listadec.h"

// funcao principal
int main(void) {

  // no inÃ­cio a lista estÃ¡ vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterÃ¡ o endereÃ§o do primeiro elemento da lista
  Lista *li = NULL;
  Lista *li2 = NULL;
  Lista *li3 = NULL;

  Produto *produto;
  int opcao, dado, ok, x,pos;

  // menu de opÃ§Ãµes para execuÃ§Ãµes de operaÃ§Ãµes sobre a lista
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Inserir elemento no início");
    printf("\n4 - Inserir elemento no final");
    printf("\n5 - Inserir elemento (ordenado)");
    printf("\n6 - Remover elemento do início");
    printf("\n7 - Remover elemento do final");
    printf("\n8 - Remover elemento (qualquer)");
    printf("\n9 - Buscar elemento pela posição");
    printf("\n10 - Buscar elemento pelo dado");
    printf("\n11 - Imprimir lista");
    printf("\n12 - Sair");
    printf("\n13 - Criar lista 2");
    printf("\n14 - Liberar lista 2");
    printf("\n15 - Inserir elemento no início 2");
    printf("\n16 - Remover elemento do início 2");
    printf("\n17 - Imprimir lista");
    printf("\n18 - Concatena.");
    printf("\n19 - Troca 2 elementos de posição na lista ");
    printf("\n20 - Remove n elementos da lista 1");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

        // criar lista
        li = criar_lista();

        if(li != NULL){
          printf("\n Lista criada com sucesso!");
        }else{
          printf("\n Lista não criada!");
        }
        break;


      case 2:

        // liberar lista
        ok = liberar_lista(li);

        if(ok){
          printf("\n Lista liberada com sucesso!");
        }else{
          printf("\n Lista não liberada!");
        }
        break;

      case 3:

        // inserir elemento no inÃ­cio
        ok = criar_produto(&produto);
        ok = inserir_lista_inicio(li, produto);

        if(ok == 1){
          printf("\n InserÃ§Ã£o realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 4:

        // inserir elemento no final
        ok = criar_produto(&produto);
        ok = inserir_lista_final(li, produto);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 5:

        // inserir elemento de forma ordenada
        ok = criar_produto(&produto);
        ok = inserir_lista_ordenada(li, produto);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 6:

        // remover elemento do inÃ­cio
        ok = remover_lista_inicio(li);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 7:

        // remover elemento do final
        ok = remover_lista_final(li);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 8:

        // remover elemento do meio
        printf("\n Código do produto a ser removido: ");
        scanf("%d", &dado);

        ok = remover_lista_meio(li, dado);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;


      case 9:

        // busca elemento pela posicao
        printf("\n Posição do elemento a ser buscado: ");
        scanf("%d", &pos);

        produto = buscar_lista_posicao(li, pos);

        if(produto != NULL){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ", pos);
          imprimir_produto(produto);
        }else{
          printf("\n Posição não existe!");
        }

        break;

      case 10:

        // busca elemento pelo dado
        printf("\n Código do produto a ser buscado: ");
        scanf("%d", &dado);

        produto = buscar_lista_dado(li, dado);

        if(produto != NULL){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento com código %d na lista: ", dado);
          imprimir_produto(produto);
        }else{
          printf("\n Elemento não encontrado!");
        }

        break;

      case 11:

        // imprime a lista
        printf("\n Lista encadeada circular: ");
        ok = imprimir_lista(li);

        break;

      case 12:

        // libera memÃ³ria e finaliza programa
        liberar_lista(li);
        printf("\nFinalizando...");
        break;

        case 13:
        li2=criar_lista();
        if(li2!= NULL) printf("\nLista criada com sucesso!\n");
        else printf("\nLista não criada!\n");
        break;

        case 14:
        if(li2!=NULL){
            x=liberar_lista(li2);
            if(x){
                printf("\nLista liberada com sucesso!\n");
                li2=NULL;
            }
        }
        else printf("\nLista não existe.\n");
        break;
        case 15:
             ok = criar_produto(&produto);
             ok = inserir_lista_inicio(li2, produto);
             if(ok == 1)printf("\n InserÃ§Ã£o realizada com sucesso!");
             else printf("\n Falha na inserção!");
        break;
       case 16 :
          if(li2!=NULL){
                x=remover_lista_inicio(li2);
                if(x) printf("\nRemoção realizada com sucesso!\n");
                else printf("\nLista vazia.\n");
          }
          else printf("\nLista inexistente.\n");
        break;
       case 17:
        printf("\n Lista encadeada circular 2: ");
        ok = imprimir_lista(li2);
        break;

      case 18:
        li3=criar_lista();
        if(li3 == NULL) printf("\nLista não criada!\n");
        else{
            li3=concatena(li,li2);
            printf("\n Lista encadeada circular concatenada:");
            ok = imprimir_lista(li3);
        }
        break;
        case 19:
        if(li!=NULL){
          printf("Qual primeira e segunda posiçao quer trocar:");
          scanf(" %d %d",&dado,&pos);
          x=Troca_El2_Circular(li,dado,pos);
          if(x) printf("\nTroca realizada com sucesso!\n");
          else printf("\ntroca Não realizada.\n");
         }else printf("\nLista inexistente.\n");
        break;
       case 20:
         if(li!=NULL){
          printf("Qntos elementos da lista 1 quer remover:");
          scanf("%d",&dado);
          x=Remover_n_ultimos_lista_Circular(li,dado);
          if(x) printf("\nRemoção realizada com sucesso!\n");
          else printf("\nElementos Não removidos.\n");
         }else printf("\nLista inexistente.\n");
        break;
      default:
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 12);

  return 0;
}

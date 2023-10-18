
// bibliotecas do sistema
#include <stdio.h>

// bibliotecas do projeto
#include "listadec.h"

// funcao principal
int main(void) {
  
  // no inÃ­cio a lista estÃ¡ vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterÃ¡ o endereÃ§o do primeiro elemento da lista
  Lista *li = NULL;
  Produto *produto; 
  int opcao, dado, ok, pos;

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

      default: 
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 12);

  return 0;
}

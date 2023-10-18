// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
// bibliotecas do projeto
#include "lista_simples_ILVB.h"

// funcao principal
int main(){
  // no in�cio a lista est� vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conter� o endere�o do primeiro elemento da lista
  Lista *li=NULL;
  Lista *li2=NULL;
  Lista *li3=NULL;
  Lista *li4;

  int op,dado,dado2,x;
  do{
        printf("\nMenu de op��es");
        printf("\n1 - Criar lista 1");
        printf("\n2 - Liberar lista 1");
        printf("\n3 - Inserir elemento no In�cio da lista 1");
        printf("\n4 - Inserir elemento no Fim da lista 1");
        printf("\n5 - Inserir elemento Ordenado da lista 1");
        printf("\n6 - Remover elemento do In�cio da lista 1");
        printf("\n7 - Remover elemento do FIM da lista 1");
        printf("\n8 - Remover elemento Especifico(meio)da lista 1");
        printf("\n9 - Verificar existenica do Dado via posi��o da lista 1.");
        printf("\n10 - Verificar existencia Dado via Dado da lista 1.");
        printf("\n11 - Imprimir lista 1");
        printf("\n12 - Sair");
        printf("\n13 - Cria lista 2:");
        printf("\n14 - Liberar lista 2");
        printf("\n15 - Inserir elemento no In�cio da lista 2");
        printf("\n16 - Remover elemento do In�cio da lista 2");
        printf("\n17 - Imprimir lista 2");
        printf("\n18 - Concatena e imprime a lista");
        printf("\n19 - Troca 2 elemntos de posi��o na lista ");
        printf("\n20 - Remove n elementos da lista 1");
         printf("\n21 - Remove elementos repetidos da lista 1");
        printf("\nOp��o: ");
        scanf("%d", &op);
    switch(op){
      case 1:
        li=criar_lista();
        if(li!= NULL) printf("\nLista criada com sucesso!\n");
        else printf("\nLista n�o criada!\n");
        break;
      case 2:
        if(li!=NULL){
            x=liberar_lista(li);
            if(x){
                printf("\nLista liberada com sucesso!\n");
                li=NULL;
            }
        }
        else printf("\nLista n�o existe.\n");
        break;
      case 3:
        if(li!=NULL){
            printf("\nElemento a ser inserido: ");
            scanf("%d",&dado);
            x=inserir_lista_inicio(li,dado);
            if(x) printf("\nInser��o realizada com sucesso!\n");
        }
        else printf("\nN�o existe lista.\n");
        break;
      case 4:
        if(li!=NULL){
          printf("\nElemento a ser inserido: ");
          scanf("%d",&dado);
          x=inserir_lista_final(li,dado);
          if(x) printf("\nInser��o realizada com sucesso!\n");
        }
        else printf("\nN�o existe lista.\n");
        break;
      case 5:
        if(li!=NULL){
          printf("\nElemento a ser inserido: ");
          scanf("%d",&dado);
          x=inserir_lista_ordenada(li,dado);
          if(x) printf("\nInser��o realizada com sucesso!\n");
        }
        else printf("\nN�o existe lista.\n");
        break;
      case 6 :
          if(li!=NULL){
                x=remover_lista_inicio(li);
                if(x) printf("\nRemo��o realizada com sucesso!\n");
                else printf("\nLista vazia.\n");
          }
          else printf("\nLista inexistente.\n");
        break;
      case 7 :
          if(li!=NULL){
            x= remover_lista_final(li);
            if(x) printf("\nRemo��o realizada com sucesso!\n");
            else printf("\nLista vazia.\n");
          }
           else printf("\nLista vazia.\n");
        break;
      case 8:
          if(li!=NULL){
            printf("\nElemento a ser removido: ");
            scanf("%d",&dado);
            x= remover_lista_meio(li,dado);
            if(x) printf("\nRemo��o realizada com sucesso!\n");
            else printf("\nN�o existe este elemento na lista ou lista vazia");
          }
          else printf("\nLista inexistente.\n");
          break;
      case 9:
          if(li!=NULL){
            printf("\nEntre com a posi��o: ");
            scanf(" %d",&dado);
            x=buscar_lista_posicao(li,dado);
            if(x!=0) printf("\n Elemento %d existe na lista na posi�ao %d!\n",x,dado);
            else printf("\nPosi��o inexistente ou lista vazia.\n");
          }
          else printf("\nLista inexistente.\n");
          break;
      case 10:
          if(li!=NULL){
            printf("\nEntre com o dado: ");
            scanf("%d",&dado);
            x= buscar_lista_dado(li,dado);
            if(x!=0) printf("\n Elemento %d existe, esta na posi��o %d da lista!\n",dado,x);
            else printf("\nElemento nao existe ou lista vazia.\n");
          }
          else printf("\nLista inexistente.\n");
          break;
      case 11:
        imprime(li);
        break;
      case 12:
        printf("\nFinalizando...\n");
        break;
      case 13:
        li2=criar_lista();
        if(li2!= NULL) printf("\nLista criada com sucesso!\n");
        else printf("\nLista n�o criada!\n");
        break;
      case 14:
        if(li2!=NULL){
            x=liberar_lista(li2);
            if(x){
                printf("\nLista liberada com sucesso!\n");
                li2=NULL;
            }
        }
        else printf("\nLista n�o existe.\n");
        break;
      case 15:
        if(li2!=NULL){
            printf("\nElemento a ser inserido: ");
            scanf("%d",&dado);
            x=inserir_lista_inicio(li2,dado);
            if(x) printf("\nInser��o realizada com sucesso!\n");
        }
        else printf("\nN�o existe lista.\n");
        break;
       case 16 :
          if(li2!=NULL){
                x=remover_lista_inicio(li2);
                if(x) printf("\nRemo��o realizada com sucesso!\n");
                else printf("\nLista vazia.\n");
          }
          else printf("\nLista inexistente.\n");
        break;
       case 17:
        imprime(li2);
        break;
      case 18:
        li3=criar_lista();
        if(li3 == NULL) printf("\nLista n�o criada!\n");
        else{
            li3=concatena(li,li2);
            imprime(li3);
        }
        break;
         case 19:
         if(li!=NULL){
          printf("Qual primeira e segunda posi�ao quer trocar:");
          scanf(" %d %d",&dado,&dado2);
          x=Troca_El2_Simples(li,dado,dado2);
          if(x) printf("\nTroca realizada com sucesso!\n");
          else printf("\ntroca N�o realizada.\n");
         }else printf("\nLista inexistente.\n");
        break;
      case 20:
         if(li!=NULL){
          printf("Qntos elementos da lista 1 quer remover:");
          scanf("%d",&dado);
          x=Remover_n_ultimos_lista_simples(li,dado);
          if(x) printf("\nRemo��o realizada com sucesso!\n");
          else printf("\nElementos N�o removidos.\n");
         }else printf("\nLista inexistente.\n");
        break;

      /*  case 21:
              li4 = Retira_Repetidos_Simples(li);
              if(li4==NULL) printf("\nLista n�o criada!\n");
              else
                   imprime(li4);
        break;*/

      default:
        printf("\nOp��o inv�lida!");
        break;
    }
  }while(op!=12);
  return 0;
}

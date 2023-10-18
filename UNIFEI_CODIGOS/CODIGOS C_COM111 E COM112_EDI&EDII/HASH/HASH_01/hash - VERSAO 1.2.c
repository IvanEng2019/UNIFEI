 // O ideal escolher um n�mero primo como tamanho mais proximo
 // da tabela hash evitando valores que sejam pot�ncia de dois.
 // Um n�mero primo reduz a probabilidade de colis�es e
 // Pot�ncia de dois pode gerar mais colis�es.
 // entao optou pelo umo do primo 97 para calculo da fun��o hash

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

struct registro{
  int valor;
  char nome[20];
  struct registro *prox;
};

typedef struct registro reg;
typedef reg* Hash[MAX];

int funcaoHash(int n){
  return (int)(n%2);//7);//(n%97);
}

void inicializaHash(Hash tab){
 for(int i = 0; i < MAX; i++)
  tab[i] = NULL;
}

void insereHash(int valor, char* nome, Hash tab){
     if(valor < 0 || valor > MAX ){
       printf("Posicao nao valida!\n");
       return;
     }
     int chave = funcaoHash(valor);
     reg* aux = tab[chave];
     while(aux != NULL) {
        if(aux->valor == valor)  {
          printf("Valor do registro ja existente:%d = %s\n",aux->valor,aux->nome);
          break;
        }
        aux = aux->prox;
     }
     if(aux == NULL) {
        aux = (reg*)malloc(sizeof(reg));
        aux->valor = valor;
        strcpy(aux->nome,nome);
        aux->prox = tab[chave];
        tab[chave] = aux;
      }
}

void consultaHash(Hash tab,int valor){
     for(int i = 0; i < MAX; i++){
       if(tab[i] != NULL){
         if(tab[i]->valor==valor){
            printf("|%d = %s|",tab[i]->valor,tab[i]->nome );
         }
         reg* aux =tab[i]->prox;
         while(aux!=NULL){
            if(aux->valor==valor){
                printf(" -> |%d = %s|",aux->valor,aux->nome);
            }
            aux=aux->prox;
         }
       }
    }
    printf("\n");
}

void deletaHash(Hash tab, int valor){
    for(int i = 0; i < MAX; i++){
       if(tab[i] != NULL){
         if(tab[i]->valor==valor){
            if(tab[i]->prox==NULL){
               tab[i]=NULL;
            }
            else{ //(tab[i]->prox!=NULL){
                reg* cel = tab [i]->prox;
                tab[i]->valor= tab[i]->prox->valor;
                strcpy(tab[i]->nome,tab[i]->prox->nome);
                tab[i]->prox = tab[i]->prox->prox;
                free(cel);
            }
         }
         else {  //if(tab[i]->valor!=valor){
             reg* atual = tab[i]->prox;
             reg* ant = tab[i];
             while(atual!=NULL){
                reg* cel = atual;
                if(atual->valor==valor){
                   if(atual->prox==NULL){
                      atual=NULL;
                      ant->prox=NULL;
                   }
                   else{//(atual->prox!=NULL){
                       ant->prox=atual->prox;
                   }
                   free(cel);
                   return;
                }
                //else{(atual->prox->valor!=valor)
                ant=atual;
                atual=atual->prox;
             }
           }
         }
    }
}

void imprimeHash(Hash tab){
    for(int i = 0; i < MAX; i++){
       if(tab[i] != NULL){
         printf("\n|%d = %s|",tab[i]->valor,tab[i]->nome );
         reg* aux =tab[i]->prox;
         while(aux!=NULL){
            printf(" -> |%d = %s|",aux->valor,aux->nome);
            aux=aux->prox;
         }
       }
    }
    printf("\n\n");
}

int main(int argc, char *argv[]){
    reg cel;
    Hash tab ;
    inicializaHash(tab);
    int valorChave,chave;
    char escolha, nome[100];
    do{
        escolha =  getchar(); //getc(stdin);
        if(escolha == 'i'){
            scanf(" %d %[^\n]c%*c",&valorChave, nome);
            insereHash(valorChave,nome,tab);
        }
        if(escolha == 'c'){// consulta chave e retorna nada ou imprime chave e registro
           scanf("%d",&valorChave);
           consultaHash(tab,valorChave);
        }
        if(escolha == 'r'){//para remover o registro
          scanf("%d",&valorChave);
          deletaHash(tab,valorChave);
        }
        if(escolha == 'p'){////imprimir em ordem de chave
           imprimeHash(tab);
        }
    }while(escolha != 'x');
    return 0;
}

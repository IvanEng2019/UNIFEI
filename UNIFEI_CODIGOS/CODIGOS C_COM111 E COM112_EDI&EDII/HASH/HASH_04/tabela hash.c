 // O ideal escolher um número primo como tamanho mais proximo
 // da tabela hash evitando valores que sejam potência de dois.
 // Um número primo reduz a probabilidade de colisões e
 // Potência de dois pode gerar mais colisões.
 // entao optou pelo umo do primo 97 para calculo da função hash

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct registro{
  int valor;
  char nome[20];
  struct registro *prox;
};

typedef struct registro reg;
typedef reg* Hash[MAX];

int funcaoHash(int n){
  return (int)(n%97);
}

void inicializaHash(Hash tab){
 for(int i = 0; i < MAX; i++)
  tab[i] = NULL;
}

void insereHash(int valor, char* nome, Hash tab){
     if(valor < 0 || valor > MAX ){
       printf("\nPosicao nao valida!");
       return;
     }
     int chave = funcaoHash(valor);
     reg* aux = tab[chave];
     while(aux != NULL) {
          if(aux->valor == valor)  {
              printf("Valor Existente.\n");
              printf("%d = %s",aux->valor,aux->nome);
              break;
          }
          aux = aux->prox;
     }
     if(aux == NULL) {
        aux = (reg*)malloc(sizeof(reg));
        aux->valor = valor;
        strcpy(aux->nome,nome);
        aux->prox = tab[chave];// circular
        tab[chave] = aux;
      }
}

void consultaHash(Hash tab,int pos){
    reg* aux = tab[pos];
    if(aux == NULL){
      printf("Esta posicao esta vazia!");
      return;
    }
    else{ //if(aux != NULL){
          printf("%3d %s",aux->valor, aux->nome);
          while(aux->prox != NULL){
            printf("%d = %s",aux->prox->valor, aux->prox->nome);
            aux = aux->prox;
          }
     }
}

void imprimeHash(Hash tab){
    for(int i = 0; i < MAX; i++){
       if(tab[i] != NULL){
         printf("\n %d %s \n",tab[i]->valor,tab[i]->nome );
         reg* aux =tab[i]->prox;
         while(aux!=NULL){
            printf(" %3d = %s \n",aux->valor,aux->nome);
            aux=aux->prox;
         }
       }
    }
}

void auxRemoveHash(Hash tab, int pos){
    reg* ant = NULL;
    reg* aux = tab[pos]->prox;
    while(aux->prox != NULL  && aux->valor != pos){
     ant = aux;
     aux = aux->prox;
    }
    if(aux->valor != pos){
     printf("\nRegistro nao encontrado!\n");
     return;
    }
    else{
      if(ant == NULL){
         tab[pos]->prox = aux->prox;
      }
      else{
        ant->prox = aux->prox;
      }
      aux = NULL;
      free(aux);
    }
}

void deletaHash(Hash tab, int pos){
     if(tab[pos] == NULL){
        printf("Esta posição esta vazia!");
        return;
     }
     if(tab[pos]->valor == pos){
       if(tab[pos]->prox == NULL){
         tab[pos] = NULL;
         return;
        }
        else{ //if(tab[pos]->prox != NULL){
         tab[pos]->valor = tab[pos]->prox->valor;
         tab[pos]->prox = tab[pos]->prox->prox;
         return;
        }
     }
     else{ // if(tab[pos]->valor != pos){
       if(tab[pos]->prox == NULL){
          printf("\nRegistro nao encontrado!");
          return;
       }
       else{
         auxRemoveHash(tab, pos);
         return;
       }
    }
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
           chave = funcaoHash(valorChave);
           consultaHash(tab,chave);
        }
        if(escolha == 'r'){//para remover o registro
          scanf("%d",&valorChave);
          chave = funcaoHash(valorChave);
          deletaHash(tab,chave);
        }
        if(escolha == 'p'){////imprimir em ordem de chave
           imprimeHash(tab);
        }
    }while(escolha != 'x');
    return 0;
}
/*O procedimento cor recebe como parametro uma variavel do tipo WORD.
sua funcao é possibilitar que o programador modifique as cores do texto
ou do fundo
void cor(WORD cor){
 HANDLE SaidaSTD = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(SaidaSTD, cor);
}
/*O procedimento posicao tem como parametro duas variaveis do tipo inetiro
. Sua funcao é possibilitar que o programador escolha a posicao na tela
que deseja visualizar determinada instrucao.
void posicao(int x, int y){
 HANDLE SaidaSTD = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(SaidaSTD, coord);
}*/

// TAD para Lista Dinâmica Encadeada Circular dupla

#include <stdio.h>
#include <stdlib.h>
#include "Lista_Dupla_Circular.h"

struct produto{
  int codigo;
  char descricao[50];
  float preco;
  int qtd;
};

// definição do struct elemento
struct elemento{
  Produto *produto;
  struct elemento *prox;
  struct elemento *ant;
};

// definição de tipos abstratos
typedef struct elemento Elemento;
typedef Elemento* Lista;

//**************************************************************************
int imprimir_produto(Produto *produto){
  printf("\n\n   Código: %d", produto->codigo);
  printf("\n   Descrição: %s", produto->descricao);
  printf("\n   Preço: %.2f", produto->preco);
  printf("\n   Quantidade: %d", produto->qtd);
  return 1;
}
//**************************************************************************
int criar_produto(Produto **produto){
  *produto = (Produto*) malloc(sizeof(Produto));
  printf("\n Código: ");
  scanf("%d", &(*produto)->codigo);
  printf(" Descrição: ");
  scanf(" %[^\n]", (*produto)->descricao);
  printf(" Preço: ");
  scanf("%f", &(*produto)->preco);
  printf(" Quantidade: ");
  scanf("%d", &(*produto)->qtd);
  return 1;
}
//**************************************************************************
// função para alocar memória do tipo Lista
Lista* criar_lista(){
  // 'li' é um ponteiro para ponteiro do tipo Elemento
  Lista *li = (Lista*) malloc(sizeof(Lista));
  if(li != NULL)// se a alocação estiver correta 'li' aponta para NULL (lista vazia)
    *li = NULL;
  else
    return NULL;
  return li;
}

//**************************************************************************
// função para liberar memória
int liberar_lista(Lista *li){
  // verifica se a lista foi alocada corretamente
  if(li == NULL) return 0;
  if((*li) != NULL){// verifica se a lista não está vazia
    Elemento *aux,*no = *li;
    while(no->prox!=(*li)){// laço percorre a lista até o último elemento, liberando o anterior
      aux = no;
      no = no-> prox;
      free(aux);
    }
    free(no);// libera o último elemento
  }
  free(li);  // libera o ponteiro de ponteiro (Lista)
  return 1;
}
//**************************************************************************
// função para obter o tamanho da lista
int tamanho_lista(Lista *li){
  // verifica se a lista foi alocada corretamente ou se a lista está vazia
  if(li == NULL || (*li) == NULL)return 0;
  int cont = 0;// inicializa o contador de elementos
  Elemento *no = *li;//cria um ponteiro do tipo Elemento que aponta para o primeiro elemento da lista
  // incrementa 'cont' até acabar o último elemento da lista
  do{
    cont++;
    no = no->prox;
  }while(no!=(*li));
  return cont;// retorna a quantidade de elementos da lista
}
//**************************************************************************
// função para verificar se a lista está vazia
int lista_vazia(Lista *li){
  // verifica se houve problema na criação da lista ou seja, 'li' não é uma lista válida
  if(li == NULL) return -1;
  // verifica se a lista foi criada corretamente mas não contém nenhum valor (lista vazia)
  if(*li == NULL) return 1;
  return 0; // se houver elementos, retorna 0
}
//**************************************************************************
// função para alocar memória do tipo Elemento
Elemento* criar_elemento(){
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));// 'no' é um ponteiro do tipo Elemento
  if(no == NULL) return 0; // verifica se a memória foi alocada corretamente
  return no;// retorna ponteiro alocado
}

//**************************************************************************
// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, Produto *produto){
  if(li == NULL) return 0;  // verifica se a lista foi criada corretamente
  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  Elemento *no = criar_elemento();
  no->produto = produto; // atribui valores ao elemento novo
  if((*li) == NULL){ // verifica se a lista está vazia
    // insere elemento único no início da lista
    no->prox = no;// próximo elemento na lista circular dupla é ele mesmo
    no->ant = no;// o anterior elemento na lista circular dupla é ele mesmo
    *li = no;   // 'no' passa a ser o primeiro elemento da lista
  }else{
    Elemento *aux= *li;
    while(aux->prox !=(*li))// percorre a lista até o último elemento
          aux = aux->prox;
    // insere elemento no início da lista
    aux->prox = no; // 'no' é o próximo elemento na lista circular após o último
    no->ant=aux; /// o anterior do 'no' aponta tambem para o ultimo
    no->prox = (*li); // primeiro elemento antigo '*li' é o próximo após o 'no'
    (*li)->ant=no;/// primeiro elemento antigo "*li" tem seu anterior apontado para o "no"
    *li = no;       // 'no' passa a ser o primeiro elemento
  }
  return 1;
}

//**************************************************************************
// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, Produto *produto){
  if(li == NULL)return 0;// verifica se a lista foi criada corretamente
  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  Elemento *no = criar_elemento();
  no->produto = produto;// atribui valores ao elemento novo
  if((*li) == NULL ){ // verifica se a lista está vazia
    // insere elemento único no início da lista
    no->prox = no;  // próximo elemento na lista circular dupla é ele mesmo
    no->ant=no; /// o anterior elemento na lista circular dupla é ele mesmo
    *li = no;       // 'no' passa a ser o primeiro elemento da lista
  }else{
    Elemento *aux = *li;
    while(aux->prox != (*li))// percorre a lista até o último elemento
      aux = aux->prox;
    // insere elemento no final da lista
    aux->prox = no;  // 'no' é o próximo elemento na lista circular após o último
    no->ant=aux; /// o anterior do 'no' aponta tambem para o antigo ultimo
    no->prox = (*li);  // primeiro elemento '*li' é o próximo após o 'no'
    (*li)->ant=no;/// primeiro elemento "*li" tem seu anterior apontado para o "no"
  }

  return 1;
}
//**************************************************************************
// função para inserir elemento na lista de forma ordenada
int inserir_lista_ordenada(Lista *li, Produto *produto){
  if(li == NULL) return 0;// verifica se a lista foi criada corretamente
  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  Elemento *no = criar_elemento();
  no->produto = produto;// atribui valores ao elemento novo
  if( (*li) == NULL ){// verifica se a lista está vazia
    // insere elemento único no início da lista
    no->prox = no;  // próximo elemento na lista circular é ele mesmo
    no->ant=no; /// o anterior elemento na lista circular dupla é ele mesmo
    *li = no;       // 'no' passa a ser o primeiro elemento da lista
  }else{
    // primeira posição é a correta para inserção do elemento novo
    if((*li)->produto->codigo > produto->codigo){
      Elemento *aux= *li;
      while(aux->prox != (*li))// percorre a lista até o último elemento
        aux = aux->prox;
       // insere elemento no início da lista
        aux->prox = no; // 'no' é o próximo elemento na lista circular após o último
        no->ant=aux; /// o anterior do 'no' aponta tambem para o ultimo
        no->prox = (*li); // primeiro elemento antigo '*li' é o próximo após o 'no'
        (*li)->ant=no;/// primeiro elemento antigo "*li" tem seu anterior apontado para o "no"
        *li = no;       // 'no' passa a ser o primeiro elemento
    }else{// senão, percorre a lista, a partir do segundo elemento, até achar o local correto e insere
        Elemento *anterior=(*li), *atual= (*li)->prox;
        // percorre a lista até o último elemento ou até encontrar um elemento maior que o novo
        while(atual != (*li) && atual->produto->codigo < produto->codigo){
            anterior = atual;
            atual = atual->prox;
        }
        // insere elemento na posição correta da lista (meio ou final)
        anterior->prox = no; // 'no' é o próximo elemento na lista circular dupla após o anterior
        no->ant=anterior;/// o anterior do novo 'no' deve apontara para o no anterior a ele
        no->prox = atual;    // 'atual' é o próximo elemento após o 'no'
        atual->ant=no;/// o anterior ao atual(cujo valor é maior) tem que apontar para o novo 'no'
    }
  }
  return 1;
}

//**************************************************************************
// função para remover elemento do início da lista
int remover_lista_inicio(Lista *li){
  if(li == NULL)return 0;// verifica se a lista foi criada corretamente
  if((*li) == NULL)return 0;// verifica se a lista está vazia (não existem elementos a serem removidos)
  // verifica se existe apenas um elemento na lista (após remoção a lista fica vazia)
  if ((*li)->prox == (*li)){
    free(*li); // libera elemento único
    *li = NULL;// indica que a lista ficou vazia
    return 1;
  }
  Elemento *aux =(*li),*no=(*li); // 'no' é o elemento a ser removido
  while(aux->prox != (*li))// percorre a lista até o último elemento
    aux = aux->prox;
  // remove o primeiro elemento da lista
  aux->prox = no->prox; /// o prox do ultimo nó tem que apontar para o segundo (futuro 1º) da lista
  no->prox->ant=aux; /// o segundo (futuro 1º) tem apontar o seu ant para o ultimo
  *li = no->prox;// primeiro elemento da lista '*li' passa a ser o 'no->prox'
  free(no);// libera Elemento 'no'
  return 1;
}

//**************************************************************************
// função para remover elemento do final da lista
int remover_lista_final(Lista *li){
  if(li == NULL)return 0;// verifica se a lista foi criada corretamente
  if((*li) == NULL)return 0;// verifica se a lista está vazia (não existem elementos a serem removidos)
  // verifica se existe apenas um elemento na lista (após remoção a lista fica vazia)
  if ((*li)->prox == (*li)){
    free(*li);// libera elemento único
    *li = NULL;// indica que a lista ficou vazia
    return 1;
  }
  Elemento *no = *li; // 'no' é o elemento a ser removido
  while(no->prox!=(*li))// percorre a lista até 'no' ser o último elemento
    no = no->prox;
  // remove o último elemento da lista
  no->ant->prox=no->prox; /// o penultimo (futuro ultimo) tem que apontar o prox para o 1º no
  no->prox->ant=no->ant; ///ou (*li)->ant=no->Ant - o 1º no da lista terá seu ant apontando para penultimo (futuro ultimo)
  free(no);// libera Elemento 'no'
  return 1;
}

//**************************************************************************
// função para remover elemento do meio da lista
int remover_lista_meio(Lista *li, int codigo){
  if(li == NULL) return 0;// verifica se a lista foi criada corretamente
  if((*li) == NULL)return 0;// verifica se a lista está vazia (não existem elementos a serem removidos)
  Elemento *no= *li;
  ///se for 1ª posição com elemento unico ou nao
  if(no->produto->codigo == codigo){// elemento a ser removido está no início da lista
    if(no->prox==no){///elemento unico: verifica se existe apenas um elemento na lista (após remoção a lista fica vazia)
      *li= NULL;// indica que a lista ficou vazia e remove o 'no'
      free(no);// libera Elemento 'no'
      return 1;// remove o primeiro  elemento
    }else{///primeiro posição porem mais lista com + de um elemento
      Elemento *ultimo = *li;
      while(ultimo->prox != (*li))// percorre a lista até o último elemento
        ultimo = ultimo->prox;
      // remove primeiro elemento 'no' (no = *li)
      ultimo->prox = no->prox;/// o prox do ultimo tera de apontar para o segundo
      no->prox->ant=ultimo;/// o ant do segundo(futuro 1º) tem q apontar para o ultimo
      *li = no->prox;/// a cabeça aponta para o segundo (futuro 1º)
      free(no); // libera Elemento 'no'
      return 1;
    }
  }///se nao for na primeira posição sera no meio ou no fim
  no = no->prox;
  // percorre a lista até achar o elemento a ser removido, ou até encontrar o primeiro elemento
  while(no!=(*li) && no->produto->codigo!=codigo)
    no=no->prox;
  if(no==(*li)) return 0;/// elemento a ser removido não foi encontrado
  no->ant->prox= no->prox;/// O prox do no anterior ao que sera removido devera apontar para o proximo
  no->prox->ant=no->ant;///o ant do no no posterior ao que sera removido devera apontar para o anterior
  free(no);  // libera Elemento 'no'
  return 1;
}
// função para buscar o elemento que está na posição 'pos' (primeiro elemento está na posição '1')
Produto *buscar_lista_posicao(Lista *li, int pos){
  // verifica se a lista foi criada corretamente, se está vazia ou se a posição 'pos' é inválida
  if(li == NULL || (*li) == NULL || pos <= 0) return NULL;
  int i=1;
  Elemento *no=(*li);
  // percorre a lista até achar posicao desejada, ou até encontrar o último elemento
  while(no->prox!=(*li) && i<pos){
    no = no->prox;
    i++;
  }
  if(i!=pos)return NULL;// verifica se a posicao desejada existe na lista
  return no->produto;// retorna o valor do elemento na posicao 'pos'
}

// função para buscar o elemento "dado"
Produto *buscar_lista_dado(Lista *li, int codigo){
  if(li == NULL || (*li) == NULL) return NULL;   // verifica se a lista foi criada corretamente ou se está vazia
  int i = 1;
  Elemento *no= *li;
  // percorre a lista até achar o elemento desejado, ou até encontrar o último elemento
  while( no->prox != (*li) && no->produto->codigo != codigo){
    no = no->prox;
    i++;
  }
  if(no->produto->codigo!=codigo) return NULL;// verifica se a posicao desejada existe na lista
  return no->produto;// retorna a posicao do elemento buscado na lista
}

int imprimir_lista(Lista *li){
  if(li == NULL)return 0;// verifica se a lista foi criada corretamente
  if((*li) == NULL) printf(" Lista vazia!");
  // imprime primeiro elemento
  Elemento *no=(*li);
  // percorre lista até o último elemento
  while(no->prox!=(*li)){
    imprimir_produto(no->produto);
    no = no->prox;
  }
  // imprime último elemento
  imprimir_produto(no->produto);
  return 1;
}



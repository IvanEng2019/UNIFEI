#include <stdio.h>
#include <stdlib.h>
#include "com111_lista.h"

struct produto{
  int codigo;
  char descricao[30];
  float preco;
  int qtd;
};

// definição do struct elemento
struct elemento{
  Produto *produto;
  struct elemento *prox;
};

// definição de tipos abstratos
typedef struct elemento Elemento;
typedef Elemento* Lista;


//****************************************************************************************************************
int imprimir_produto(Produto *produto)
{
  printf("\n\n   Código: %d", produto->codigo);
  printf("\n   Descrição: %s", produto->descricao);
  printf("\n   Preço: %.2f", produto->preco);
  printf("\n   Quantidade: %d", produto->qtd);

  return 1;
}

//****************************************************************************************************************
int criar_produto(Produto **produto)
{
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


//****************************************************************************************************************
// função para alocar memória do tipo Lista
Lista* criar_lista()
{
    Lista  *li = (Lista*)malloc(sizeof(Lista));//alocaçao de memoria para lista
    if(li!= NULL){
        return li;
    }
    else
      return NULL;

}


//****************************************************************************************************************
// função para liberar memória
int liberar_lista(Lista *li)
{
  // verifica se a lista foi alocada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista não está vazia
  if((*li) != NULL){
    Elemento *no, *aux;
    no = *li;

    // laço percorre a lista até o último elemento, liberando o anterior
    while( no->prox !=  (*li) ){
      aux = no;
      no = no-> prox;
      free(aux);
    }

    // libera o último elemento
    free(no);

    // libera o ponteiro de ponteiro (Lista)
    free(li);
  }

  return 1;
}

//****************************************************************************************************************
// função para obter o tamanho da lista
int tamanho_lista(Lista *li)
{
  // verifica se a lista foi alocada corretamente ou se a lista está vazia
  if(li == NULL || (*li) == NULL){
    return 0;
  }

  // inicializa o contador de elementos
  int cont = 0;

  // cria um ponteiro do tipo Elemento que aponta para o primeiro elemento da lista
  Elemento *no;
  no = *li;

  // incrementa 'cont' até acabar o último elemento da lista
  do{
    cont++;
    no = no->prox;
  }while(no != (*li));

  // retorna a quantidade de elementos da lista
  return cont;
}

//****************************************************************************************************************
// função para verificar se a lista está vazia
int lista_vazia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, 'li' não é uma lista válida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista foi criada corretamente
  // mas não contém nenhum valor (lista vazia)
  if(*li == NULL){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


//****************************************************************************************************************
// função para alocar memória do tipo Elemento
Elemento* criar_elemento()
{
  // 'no' é um ponteiro do tipo Elemento
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));

  // verifica se a memória foi alocada corretamente
  if(no == NULL){
    return 0;
  }

  // retorna ponteiro alocado
  return no;
}


//****************************************************************************************************************
// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, Produto *produto)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  Elemento *no;
  no = criar_elemento();

  // atribui valores ao elemento novo
  no->produto = produto;

  // verifica se a lista está vazia
  if((*li) == NULL){

    // insere elemento único no início da lista
    no->prox = no;  // próximo elemento na lista circular é ele mesmo
    *li = no;       // 'no' passa a ser o primeiro elemento da lista

  }else{

    Elemento *aux;
    aux = *li;

    // percorre a lista até o último elemento
    while(aux->prox != (*li)){
      aux = aux->prox;
    }

    // insere elemento no início da lista
    aux->prox = no; // 'no' é o próximo elemento na lista circular após o último
    no->prox = *li; // primeiro elemento antigo '*li' é o próximo após o 'no'
    *li = no;       // 'no' passa a ser o primeiro elemento

  }

  return 1;
}


//****************************************************************************************************************
// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, Produto *produto)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  Elemento *no;
  no = criar_elemento();

  // atribui valores ao elemento novo
  no->produto = produto;

  // verifica se a lista está vazia
  if( (*li) == NULL ){

    // insere elemento único no início da lista
    no->prox = no;  // próximo elemento na lista circular é ele mesmo
    *li = no;       // 'no' passa a ser o primeiro elemento da lista

  }else{

    Elemento *aux;
    aux = *li;

    // percorre a lista até o último elemento
    while(aux->prox != (*li)){
      aux = aux->prox;
    }

    // insere elemento no final da lista
    aux->prox = no;  // 'no' é o próximo elemento na lista circular após o último
    no->prox = *li;  // primeiro elemento '*li' é o próximo após o 'no'
  }

  return 1;
}


//****************************************************************************************************************
// função para inserir elemento na lista de forma ordenada (ordenação pelo código do produto)
int inserir_lista_ordenada(Lista *li, Produto *produto)
{
    if(li== NULL){
        return 0;
    }
    else{

        Elemento *no=criar_elemento();//cria no
        no->produto=produto;

        if((*li) == NULL){
            no->prox = no;
            *li = no;
        }

        Elemento *anterior, *aux= (*li);
        // percorre a lista até o último elemento
        while(aux->prox!= (*li) && aux->produto->codigo < produto->codigo){//percorre ate encontrar o elemento menor
            anterior=aux;
            aux = aux->prox;

        }
         Elemento *ult=(*li);
        //percorre a' lista até o último elemento
        while(ult->prox != (*li)){
            ult = ult->prox;
        }

        //se codigo menor for primeira posição
        if(aux==(*li)){
            no->prox=(*li);
            ult->prox=no;
            (*li)=no;
            return 1;
        }
        //se o codigo for na ultima posiçao
        if(aux->prox==(*li)){
            aux->prox=no;
            no->prox=(*li);
            return 1;
        }
        else{ //se for posição do meio
            no->prox=aux->prox;
            anterior->prox=no;
            return 1;
        }

    }
}


//****************************************************************************************************************
// função para remover elemento do início da lista
int remover_lista_inicio(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista está vazia (não existem elementos a serem removidos)
  if((*li) == NULL){
    return 0;
  }

  // verifica se existe apenas um elemento na lista (após remoção a lista fica vazia)
  if ((*li)->prox == (*li)){

    // libera elemento único
    free(*li);
    // indica que a lista ficou vazia
    *li = NULL;

    return 1;
  }

  Elemento *no, *aux;
  no = *li; // 'no' é o elemento a ser removido
  aux = *li;

  // percorre a lista até o último elemento
  while(aux->prox != (*li)){
    aux = aux->prox;
  }

  // remove o primeiro elemento da lista
  aux->prox = no->prox; // 'no->prox' é o próximo elemento na lista circular após o último
  *li = no->prox;       // primeiro elemento da lista '*li' passa a ser o 'no->prox'

  // libera Elemento 'no'
  free(no);

  return 1;
}


//****************************************************************************************************************
// função para remover elemento do final da lista
int remover_lista_final(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista está vazia (não existem elementos a serem removidos)
  if((*li) == NULL){
    return 0;
  }

  // verifica se existe apenas um elemento na lista (após remoção a lista fica vazia)
  if ((*li)->prox == (*li)){

    // libera elemento único
    free(*li);
    // indica que a lista ficou vazia
    *li = NULL;

    return 1;
  }

  Elemento *anterior, *no;
  no = *li; // 'no' é o elemento a ser removido

  // percorre a lista até 'no' ser o último elemento, armazenando o elemento anterior
  while(no->prox != (*li)){
    anterior = no;
    no = no->prox;
  }

  // remove o último elemento da lista
  anterior->prox = no->prox; // 'no->prox' passa a ser o próximo elemento na lista circular após o 'anterior'

  // libera Elemento 'no'
  free(no);

  return 1;

}


//****************************************************************************************************************
// função para remover elemento do meio da lista (remove o produto com o código desejado)
int remover_lista_meio(Lista *li, int codigo)
{
   if(li== NULL){
     return 0;
   }
   else{
   Elemento *aux= *li;
    // percorre a lista até o último elemento
    while(aux->prox != (*li) && aux->produto->codigo == (*li)->produto->codigo){//percorre ate encontrar o elemento menor
      aux = aux->prox;
    }
    if( aux==(*li)){ //se o codigo for o menor da lista
       remover_lista_inicio(li);
    }
    if(aux->prox==(*li)){//se o codigo for o maior da lista o fim da lista
       remover_lista_final(li);
    }
    else{
        Elemento *anterior;
        Elemento *no= *li; // 'no' é o elemento a ser removido

       // percorre a lista até 'no' ser o último elemento, armazenando o elemento anterior
      while(no->prox != (*li)&& no->produto->codigo == (*li)->produto->codigo){
          anterior = no;
          no = no->prox;
       }
      anterior->prox=aux->prox;
      free(no);
    }
    return 1;
  }
}


//****************************************************************************************************************
// função para buscar o elemento que está na posição 'pos' (primeiro elemento está na posição '1')
Produto *buscar_lista_posicao(Lista *li, int pos)
{
  // verifica se a lista foi criada corretamente, se está vazia ou se a posição 'pos' é inválida
  if(li == NULL || (*li) == NULL || pos <= 0){
    return NULL;
  }

  int i = 1;
  Elemento *no;
  no = *li;

  // percorre a lista até achar posicao desejada, ou até encontrar o último elemento
  while( no->prox != (*li) && i < pos){
    no = no->prox;
    i++;
  }

  // verifica se a posicao desejada existe na lista
  if(i != pos){
    return NULL;
  }

  // retorna o valor do elemento na posicao 'pos'
  return no->produto;

}


//***************************************************************************************************************
// função para buscar o elemento código do produto (retorna o produto com o código desejado)
Produto *buscar_lista_dado(Lista *li, int codigo)
{
   if(li==NULL)
     return NULL;
  else{
    Elemento *no=(*li);
    Produto *prod;
    while(no->prox != (*li)&& no->produto->codigo == (*li)->produto->codigo)
            no=no->prox;
    prod=no->produto;
    return prod;
  }
}


//****************************************************************************************************************
// função para imprimir a lista de produtos (retorna 1 quando a impressão foi realizada corretamente)
int imprimir_lista(Lista *li)
{

    if((*li)==NULL)
        printf("Lista vazia.\n");
    if(li==NULL)
        printf("Não existe lista criada");
    else{
        printf("Descrição dos produtos da lista:\n");
        Elemento *no=(*li);
        do{
            printf("Codigo: %d\nDescrição: %s\nPreço: %.2f\nQuantidade: %d\n",(*li)->produto->codigo,(*li)->produto->descricao,(*li)->produto->preco,(*li)->produto->qtd);
            no=no->prox;
               printf("\n\n");
       }while(no->prox != (*li));
    }
    return 1;
}


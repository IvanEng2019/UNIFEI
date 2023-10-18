// TAD para Lista Din�mica Encadeada Circular dupla

#include <stdio.h>
#include <stdlib.h>
#include "Lista_Dupla_Circular.h"

struct produto{
  int codigo;
  char descricao[50];
  float preco;
  int qtd;
};

// defini��o do struct elemento
struct elemento{
  Produto *produto;
  struct elemento *prox;
  struct elemento *ant;
};

// defini��o de tipos abstratos
typedef struct elemento Elemento;
typedef Elemento* Lista;

//**************************************************************************
int imprimir_produto(Produto *produto){
  printf("\n\n   C�digo: %d", produto->codigo);
  printf("\n   Descri��o: %s", produto->descricao);
  printf("\n   Pre�o: %.2f", produto->preco);
  printf("\n   Quantidade: %d", produto->qtd);
  return 1;
}
//**************************************************************************
int criar_produto(Produto **produto){
  *produto = (Produto*) malloc(sizeof(Produto));
  printf("\n C�digo: ");
  scanf("%d", &(*produto)->codigo);
  printf(" Descri��o: ");
  scanf(" %[^\n]", (*produto)->descricao);
  printf(" Pre�o: ");
  scanf("%f", &(*produto)->preco);
  printf(" Quantidade: ");
  scanf("%d", &(*produto)->qtd);
  return 1;
}
//**************************************************************************
// fun��o para alocar mem�ria do tipo Lista
Lista* criar_lista(){
  // 'li' � um ponteiro para ponteiro do tipo Elemento
  Lista *li = (Lista*) malloc(sizeof(Lista));
  if(li != NULL)// se a aloca��o estiver correta 'li' aponta para NULL (lista vazia)
    *li = NULL;
  else
    return NULL;
  return li;
}

//**************************************************************************
// fun��o para liberar mem�ria
int liberar_lista(Lista *li){
  // verifica se a lista foi alocada corretamente
  if(li == NULL) return 0;
  if((*li) != NULL){// verifica se a lista n�o est� vazia
    Elemento *aux,*no = *li;
    while(no->prox!=(*li)){// la�o percorre a lista at� o �ltimo elemento, liberando o anterior
      aux = no;
      no = no-> prox;
      free(aux);
    }
    free(no);// libera o �ltimo elemento
  }
  free(li);  // libera o ponteiro de ponteiro (Lista)
  return 1;
}
//**************************************************************************
// fun��o para obter o tamanho da lista
int tamanho_lista(Lista *li){
  // verifica se a lista foi alocada corretamente ou se a lista est� vazia
  if(li == NULL || (*li) == NULL)return 0;
  int cont = 0;// inicializa o contador de elementos
  Elemento *no = *li;//cria um ponteiro do tipo Elemento que aponta para o primeiro elemento da lista
  // incrementa 'cont' at� acabar o �ltimo elemento da lista
  do{
    cont++;
    no = no->prox;
  }while(no!=(*li));
  return cont;// retorna a quantidade de elementos da lista
}
//**************************************************************************
// fun��o para verificar se a lista est� vazia
int lista_vazia(Lista *li){
  // verifica se houve problema na cria��o da lista ou seja, 'li' n�o � uma lista v�lida
  if(li == NULL) return -1;
  // verifica se a lista foi criada corretamente mas n�o cont�m nenhum valor (lista vazia)
  if(*li == NULL) return 1;
  return 0; // se houver elementos, retorna 0
}
//**************************************************************************
// fun��o para alocar mem�ria do tipo Elemento
Elemento* criar_elemento(){
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));// 'no' � um ponteiro do tipo Elemento
  if(no == NULL) return 0; // verifica se a mem�ria foi alocada corretamente
  return no;// retorna ponteiro alocado
}

//**************************************************************************
// fun��o para inserir elemento no in�cio da lista
int inserir_lista_inicio(Lista *li, Produto *produto){
  if(li == NULL) return 0;  // verifica se a lista foi criada corretamente
  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  Elemento *no = criar_elemento();
  no->produto = produto; // atribui valores ao elemento novo
  if((*li) == NULL){ // verifica se a lista est� vazia
    // insere elemento �nico no in�cio da lista
    no->prox = no;// pr�ximo elemento na lista circular dupla � ele mesmo
    no->ant = no;// o anterior elemento na lista circular dupla � ele mesmo
    *li = no;   // 'no' passa a ser o primeiro elemento da lista
  }else{
    Elemento *aux= *li;
    while(aux->prox !=(*li))// percorre a lista at� o �ltimo elemento
          aux = aux->prox;
    // insere elemento no in�cio da lista
    aux->prox = no; // 'no' � o pr�ximo elemento na lista circular ap�s o �ltimo
    no->ant=aux; /// o anterior do 'no' aponta tambem para o ultimo
    no->prox = (*li); // primeiro elemento antigo '*li' � o pr�ximo ap�s o 'no'
    (*li)->ant=no;/// primeiro elemento antigo "*li" tem seu anterior apontado para o "no"
    *li = no;       // 'no' passa a ser o primeiro elemento
  }
  return 1;
}

//**************************************************************************
// fun��o para inserir elemento no final da lista
int inserir_lista_final(Lista *li, Produto *produto){
  if(li == NULL)return 0;// verifica se a lista foi criada corretamente
  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  Elemento *no = criar_elemento();
  no->produto = produto;// atribui valores ao elemento novo
  if((*li) == NULL ){ // verifica se a lista est� vazia
    // insere elemento �nico no in�cio da lista
    no->prox = no;  // pr�ximo elemento na lista circular dupla � ele mesmo
    no->ant=no; /// o anterior elemento na lista circular dupla � ele mesmo
    *li = no;       // 'no' passa a ser o primeiro elemento da lista
  }else{
    Elemento *aux = *li;
    while(aux->prox != (*li))// percorre a lista at� o �ltimo elemento
      aux = aux->prox;
    // insere elemento no final da lista
    aux->prox = no;  // 'no' � o pr�ximo elemento na lista circular ap�s o �ltimo
    no->ant=aux; /// o anterior do 'no' aponta tambem para o antigo ultimo
    no->prox = (*li);  // primeiro elemento '*li' � o pr�ximo ap�s o 'no'
    (*li)->ant=no;/// primeiro elemento "*li" tem seu anterior apontado para o "no"
  }

  return 1;
}
//**************************************************************************
// fun��o para inserir elemento na lista de forma ordenada
int inserir_lista_ordenada(Lista *li, Produto *produto){
  if(li == NULL) return 0;// verifica se a lista foi criada corretamente
  // cria um elemento novo ('no' precisa ser alocado pois estamos inserindo ele na lista)
  Elemento *no = criar_elemento();
  no->produto = produto;// atribui valores ao elemento novo
  if( (*li) == NULL ){// verifica se a lista est� vazia
    // insere elemento �nico no in�cio da lista
    no->prox = no;  // pr�ximo elemento na lista circular � ele mesmo
    no->ant=no; /// o anterior elemento na lista circular dupla � ele mesmo
    *li = no;       // 'no' passa a ser o primeiro elemento da lista
  }else{
    // primeira posi��o � a correta para inser��o do elemento novo
    if((*li)->produto->codigo > produto->codigo){
      Elemento *aux= *li;
      while(aux->prox != (*li))// percorre a lista at� o �ltimo elemento
        aux = aux->prox;
       // insere elemento no in�cio da lista
        aux->prox = no; // 'no' � o pr�ximo elemento na lista circular ap�s o �ltimo
        no->ant=aux; /// o anterior do 'no' aponta tambem para o ultimo
        no->prox = (*li); // primeiro elemento antigo '*li' � o pr�ximo ap�s o 'no'
        (*li)->ant=no;/// primeiro elemento antigo "*li" tem seu anterior apontado para o "no"
        *li = no;       // 'no' passa a ser o primeiro elemento
    }else{// sen�o, percorre a lista, a partir do segundo elemento, at� achar o local correto e insere
        Elemento *anterior=(*li), *atual= (*li)->prox;
        // percorre a lista at� o �ltimo elemento ou at� encontrar um elemento maior que o novo
        while(atual != (*li) && atual->produto->codigo < produto->codigo){
            anterior = atual;
            atual = atual->prox;
        }
        // insere elemento na posi��o correta da lista (meio ou final)
        anterior->prox = no; // 'no' � o pr�ximo elemento na lista circular dupla ap�s o anterior
        no->ant=anterior;/// o anterior do novo 'no' deve apontara para o no anterior a ele
        no->prox = atual;    // 'atual' � o pr�ximo elemento ap�s o 'no'
        atual->ant=no;/// o anterior ao atual(cujo valor � maior) tem que apontar para o novo 'no'
    }
  }
  return 1;
}

//**************************************************************************
// fun��o para remover elemento do in�cio da lista
int remover_lista_inicio(Lista *li){
  if(li == NULL)return 0;// verifica se a lista foi criada corretamente
  if((*li) == NULL)return 0;// verifica se a lista est� vazia (n�o existem elementos a serem removidos)
  // verifica se existe apenas um elemento na lista (ap�s remo��o a lista fica vazia)
  if ((*li)->prox == (*li)){
    free(*li); // libera elemento �nico
    *li = NULL;// indica que a lista ficou vazia
    return 1;
  }
  Elemento *aux =(*li),*no=(*li); // 'no' � o elemento a ser removido
  while(aux->prox != (*li))// percorre a lista at� o �ltimo elemento
    aux = aux->prox;
  // remove o primeiro elemento da lista
  aux->prox = no->prox; /// o prox do ultimo n� tem que apontar para o segundo (futuro 1�) da lista
  no->prox->ant=aux; /// o segundo (futuro 1�) tem apontar o seu ant para o ultimo
  *li = no->prox;// primeiro elemento da lista '*li' passa a ser o 'no->prox'
  free(no);// libera Elemento 'no'
  return 1;
}

//**************************************************************************
// fun��o para remover elemento do final da lista
int remover_lista_final(Lista *li){
  if(li == NULL)return 0;// verifica se a lista foi criada corretamente
  if((*li) == NULL)return 0;// verifica se a lista est� vazia (n�o existem elementos a serem removidos)
  // verifica se existe apenas um elemento na lista (ap�s remo��o a lista fica vazia)
  if ((*li)->prox == (*li)){
    free(*li);// libera elemento �nico
    *li = NULL;// indica que a lista ficou vazia
    return 1;
  }
  Elemento *no = *li; // 'no' � o elemento a ser removido
  while(no->prox!=(*li))// percorre a lista at� 'no' ser o �ltimo elemento
    no = no->prox;
  // remove o �ltimo elemento da lista
  no->ant->prox=no->prox; /// o penultimo (futuro ultimo) tem que apontar o prox para o 1� no
  no->prox->ant=no->ant; ///ou (*li)->ant=no->Ant - o 1� no da lista ter� seu ant apontando para penultimo (futuro ultimo)
  free(no);// libera Elemento 'no'
  return 1;
}

//**************************************************************************
// fun��o para remover elemento do meio da lista
int remover_lista_meio(Lista *li, int codigo){
  if(li == NULL) return 0;// verifica se a lista foi criada corretamente
  if((*li) == NULL)return 0;// verifica se a lista est� vazia (n�o existem elementos a serem removidos)
  Elemento *no= *li;
  ///se for 1� posi��o com elemento unico ou nao
  if(no->produto->codigo == codigo){// elemento a ser removido est� no in�cio da lista
    if(no->prox==no){///elemento unico: verifica se existe apenas um elemento na lista (ap�s remo��o a lista fica vazia)
      *li= NULL;// indica que a lista ficou vazia e remove o 'no'
      free(no);// libera Elemento 'no'
      return 1;// remove o primeiro  elemento
    }else{///primeiro posi��o porem mais lista com + de um elemento
      Elemento *ultimo = *li;
      while(ultimo->prox != (*li))// percorre a lista at� o �ltimo elemento
        ultimo = ultimo->prox;
      // remove primeiro elemento 'no' (no = *li)
      ultimo->prox = no->prox;/// o prox do ultimo tera de apontar para o segundo
      no->prox->ant=ultimo;/// o ant do segundo(futuro 1�) tem q apontar para o ultimo
      *li = no->prox;/// a cabe�a aponta para o segundo (futuro 1�)
      free(no); // libera Elemento 'no'
      return 1;
    }
  }///se nao for na primeira posi��o sera no meio ou no fim
  no = no->prox;
  // percorre a lista at� achar o elemento a ser removido, ou at� encontrar o primeiro elemento
  while(no!=(*li) && no->produto->codigo!=codigo)
    no=no->prox;
  if(no==(*li)) return 0;/// elemento a ser removido n�o foi encontrado
  no->ant->prox= no->prox;/// O prox do no anterior ao que sera removido devera apontar para o proximo
  no->prox->ant=no->ant;///o ant do no no posterior ao que sera removido devera apontar para o anterior
  free(no);  // libera Elemento 'no'
  return 1;
}
// fun��o para buscar o elemento que est� na posi��o 'pos' (primeiro elemento est� na posi��o '1')
Produto *buscar_lista_posicao(Lista *li, int pos){
  // verifica se a lista foi criada corretamente, se est� vazia ou se a posi��o 'pos' � inv�lida
  if(li == NULL || (*li) == NULL || pos <= 0) return NULL;
  int i=1;
  Elemento *no=(*li);
  // percorre a lista at� achar posicao desejada, ou at� encontrar o �ltimo elemento
  while(no->prox!=(*li) && i<pos){
    no = no->prox;
    i++;
  }
  if(i!=pos)return NULL;// verifica se a posicao desejada existe na lista
  return no->produto;// retorna o valor do elemento na posicao 'pos'
}

// fun��o para buscar o elemento "dado"
Produto *buscar_lista_dado(Lista *li, int codigo){
  if(li == NULL || (*li) == NULL) return NULL;   // verifica se a lista foi criada corretamente ou se est� vazia
  int i = 1;
  Elemento *no= *li;
  // percorre a lista at� achar o elemento desejado, ou at� encontrar o �ltimo elemento
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
  // percorre lista at� o �ltimo elemento
  while(no->prox!=(*li)){
    imprimir_produto(no->produto);
    no = no->prox;
  }
  // imprime �ltimo elemento
  imprimir_produto(no->produto);
  return 1;
}



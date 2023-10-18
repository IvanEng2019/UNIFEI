// TAD para Lista Dinâmica Encadeada Circular

#include <stdio.h>
#include <stdlib.h>
#include "listadec.h"

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


//**************************************************************************
int imprimir_produto(Produto *produto)
{
  printf("\n\n   Código: %d", produto->codigo);
  printf("\n   Descrição: %s", produto->descricao);
  printf("\n   Preço: %.2f", produto->preco);
  printf("\n   Quantidade: %d", produto->qtd);

  return 1;
}

//**************************************************************************
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


//**************************************************************************
// função para alocar memória do tipo Lista
Lista* criar_lista()
{
  // 'li' é um ponteiro para ponteiro do tipo Elemento
  Lista *li = (Lista*) malloc(sizeof(Lista));

  // se a alocação estiver correta 'li' aponta para NULL (lista vazia)
  if(li != NULL){
    *li = NULL;
  }else{
    return NULL;
  }

  return li;
}


//**************************************************************************
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

//**************************************************************************
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

//**************************************************************************
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


//**************************************************************************
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


//**************************************************************************
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


//**************************************************************************
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


//**************************************************************************
// função para inserir elemento na lista de forma ordenada
int inserir_lista_ordenada(Lista *li, Produto *produto)
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

    // primeira posição é a correta para inserção do elemento novo
    if((*li)->produto->codigo > produto->codigo){

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

    // senão, percorre a lista, a partir do segundo elemento, até achar o local correto e insere
    Elemento *anterior, *atual;

    anterior = *li;
    atual = anterior->prox;

    // percorre a lista até o último elemento ou até encontrar um elemento maior que o novo
    while(atual != (*li) && atual->produto->codigo < produto->codigo){
      anterior = atual;
      atual = atual->prox;
    }

    // insere elemento na posição correta da lista (meio)
    anterior->prox = no; // 'no' é o próximo elemento na lista circular após o anterior
    no->prox = atual;    // 'atual' é o próximo elemento após o 'no'
  }

  return 1;
}


//**************************************************************************
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


//**************************************************************************
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


//**************************************************************************
// função para remover elemento do meio da lista
int remover_lista_meio(Lista *li, int codigo)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  // verifica se a lista está vazia (não existem elementos a serem removidos)
  if((*li) == NULL){
    return 0;
  }

  Elemento *no;
  no = *li;

  // elemento a ser removido está no início da lista
  if(no->produto->codigo == codigo){

    // verifica se existe apenas um elemento na lista (após remoção a lista fica vazia)
    if (no->prox == no){

      // indica que a lista ficou vazia e remove o 'no'
      *li = NULL;
      free(no);

      // libera Elemento 'no'
      return 1;

    // remove o primeiro elemento
    }else{

      Elemento *ultimo;
      ultimo = *li;

      // percorre a lista até o último elemento
      while(ultimo->prox != (*li)){
        ultimo = ultimo->prox;
      }

      // remove primeiro elemento 'no' (no = *li)
      ultimo->prox = no->prox;
      *li = no->prox;

      // libera Elemento 'no'
      free(no);

      return 1;
    }

  }

  Elemento *anterior;
  anterior = no;
  no = no->prox;

  // percorre a lista até achar o elemento a ser removido, ou até encontrar o primeiro elemento
  while(no != (*li) && no->produto->codigo != codigo){
    anterior = no;
    no = no->prox;
  }

  // elemento a ser removido não foi encontrado
  if(no == (*li)){
    return 0;
  }

  // remove o elemento 'no'
  anterior->prox = no->prox;  // 'no->prox' passa a ser o próximo elemento na lista circular após o 'anterior'

  // libera Elemento 'no'
  free(no);

  return 1;

}


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


// função para buscar o elemento "dado"
Produto *buscar_lista_dado(Lista *li, int codigo)
{
  // verifica se a lista foi criada corretamente ou se está vazia
  if(li == NULL || (*li) == NULL){
    return NULL;
  }

  int i = 1;
  Elemento *no;
  no = *li;

  // percorre a lista até achar o elemento desejado, ou até encontrar o último elemento
  while( no->prox != (*li) && no->produto->codigo != codigo){
    no = no->prox;
    i++;
  }

  // verifica se a posicao desejada existe na lista
  if(no->produto->codigo != codigo){
    return NULL;
  }

  // retorna a posicao do elemento buscado na lista
  return no->produto;

}


int imprimir_lista(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL){
    return 0;
  }

  if((*li) == NULL){
    printf(" Lista vazia!");
  }

  // imprime primeiro elemento
  Elemento *no;
  no = (*li);

  // percorre lista até o último elemento
  while(no->prox != (*li)){
    imprimir_produto(no->produto);
    no = no->prox;
  }

  // imprime último elemento
  imprimir_produto(no->produto);

  return 1;
}

Lista* concatena(Lista *li1,Lista *li2){
    Lista *list1=li1;
    Lista *list2=li2;

    if(list1==NULL && list2==NULL) return NULL;
    if(list1==NULL && list2!=NULL) return list2;
    if(list1!=NULL && list2==NULL) return list1;

    Elemento *l1 = (*list1);
    while(l1->prox!=(*list1))
        l1=l1->prox;
    l1->prox= (*list2);

    Elemento *l2 = (*list2);
    while(l2->prox!= (*list2))
        l2=l2->prox;
    l2->prox= (*list1);

    return list1;
}

int Remover_n_ultimos_lista_Circular(Lista *li,int n){
     if(li==NULL ) return 0;
     int tam=0;
     Elemento *no=(*li);
     do{
        no=no->prox;
        tam++;
     } while(no!=(*li));
     if(n>tam) return 0;
     else{
           Elemento *ant,*DEL;
           int cont=0;
           no=(*li);
// acha a penultima e ultima posiçao de (tam-n)
           while(cont<tam-n && no!=(*li)->prox){
              ant=no; //penultima
              no=no->prox; //ultima
              cont++;
           }
//se so tem um elemento e se for pedido pra retirar este unico
           if(no==(*li)){
               (*li)=NULL;
               free(no);
               return 1;
           }
           else{// se tem mais de um elemento a ser retirado
              while (no->prox!=(*li)){// começa em (tam-n) e vai ate  o FIM (NULL)
                DEL= no;
                no=no->prox;
                free(DEL);
               }
           ant->prox=(*li); //faz o ultimo apontar pra o 1º da lista
           return 1;
           }
     }
}
/*int Troca_El2_Circular(Lista *li,int p1, int p2){
    if( li==NULL  ) return 0;
    Elemento * antp1,*antp2,*no1,*no2,*auxp1p;
    int t=1;
    no1=(*li); //começa pelo segundo se for o 1 aposta para list
    while(no1->prox!=(*li) && t<p1){
            antp1=no1;
            no1=no1->prox;
            t++;
}
    if(no1==(*li)) return 0;// não tem a posição p1 dada na lista
    t=1;
    no2=(*li);
    while(no2->prox!=(*li) && t<p2){
            antp2=no2;
            no2=no2->prox;
            t++;
    }
    if(no2==(*li)) return 0;// não tem a posição p2 dada na lista
    auxp1p=no1->prox;
    // auxiliar ira armazenar a posição do elemento posterior da posição p1
    antp1->prox=no2;
    antp2->prox=no1;
    no1->prox=no2->prox;
    no2->prox=auxp1p;
    return 1;
}
*/
int Troca_El2_Circular(Lista *li, int p1, int p2){
     if( li==NULL || (*li)== NULL ) return 0;
     if(p1>p2){
        int pos1=p1;
        p1=p2;
        p2=pos1;
    }

     Elemento *aux=(*li);
     int cont=0;
     do{
        cont++;
        aux = aux->prox;
    }while(aux != (*li));

     Elemento *antp1;
     Elemento *no1=(*li);
     int t=1;
     while(no1->prox!=(*li) && t<p1){
            antp1=no1;
            no1=no1->prox;
            t++;
    }
    if(no1->prox==(*li) &&  t>cont) return 0;

    Elemento *antp2;
    Elemento *no2=(*li)->prox;
    t=2;
    while(no2->prox!=(*li) && t<p2){
            antp2=no2;
            no2=no2->prox;
            t++;
    }
    if(no2->prox==(*li) && t>cont) return 0;

    if(p1==1){
          if(no2->prox!=(*li)){
              no1->prox=no2->prox;
              no2->prox=no1;
              Elemento* ult=(*li);
              while(ult->prox != (*li))
                    ult= ult->prox;
              ult->prox=no2;
             }
         else{
            no2->prox=no1->prox;
            antp2->prox=no1;
            no1->prox=no2;
         }
         (*li)=no2;
          return 1;
    }
    else{//se a 1ª posição for diferente do 1º no
        if(no1->prox==no2){//se for nos consecutivos
            no1->prox=no2->prox;
            no2->prox=no1;
            antp1->prox=no2;
        }
        else{//se nao for nó consecutivo
            aux=no1->prox;
            no1->prox=no2->prox;
            no2->prox=aux;
            antp1->prox=no2;
            antp2->prox=no1;
        }
    return 1;
    }
}

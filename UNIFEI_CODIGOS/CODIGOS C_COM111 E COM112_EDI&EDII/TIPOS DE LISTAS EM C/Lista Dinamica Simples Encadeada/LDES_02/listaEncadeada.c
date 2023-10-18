#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

// defini��o do struct elemento
typedef struct elemento{
  int dado;
  struct elemento *prox;
}Elemento;


// fun��o para alocar mem�ria do tipo Lista
Lista* criar_lista()
{
  Lista *li = (Lista*) malloc(sizeof(Lista));

  // se a lista foi criada corretamente, indica que ela est� vazia
  if(li != NULL){
    *li = NULL;
  }

  return li;
}


// fun��o para liberar mem�ria
int liberar_lista(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  // libera todos os n�s da lista que foram alocados
  Elemento *no;
  while( (*li) != NULL ){
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  // libera o ponteiro da lista
  free(li);

  return 1;
}

// fun��o para obter o tamanho da lista
int tamanho_lista(Lista *li)
{
  // a lista n�o foi criada corretamente
  if(li == NULL){
    return 0;
  }

  int cont = 0;
  Elemento *no = *li;

  // acrescenta cont at� acabar a lista
  while(no != NULL){
    cont++;
    no = no->prox;
  }

  return cont;
}

// fun��o para verificar se a lista est� vazia
int lista_vazia(Lista *li)
{
  // verifica se houve problema na cria��o da lista
  // ou seja, li n�o � uma lista v�lida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista foi criada corretamente
  // mas n�o cont�m nenhum valor
  if(*li == NULL){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


// fun��o para verificar se a lista est� cheia (n�o se aplica)
int lista_cheia(Lista *li)
{
  return 0;
}


// fun��o para alocar mem�ria do tipo Elemento
Elemento* criar_elemento()
{
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));

  return no;
}


// fun��o para inserir elemento no in�cio da lista
int inserir_lista_inicio(Lista *li, int dado)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = (*li);

  // insere elemento no in�cio da lista
  *li = no;

  return 1;
}


// fun��o para inserir elemento no final da lista
int inserir_lista_final(Lista *li, int dado)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = NULL;

  // se a lista estiver vazia, insere no in�cio da lista
  if( (*li) == NULL ){
    *li = no;

  }else{

    // sen�o percorre a lista at� o fim e insere no final
    Elemento *aux;
    aux = *li;

    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = no;
  }

  return 1;
}


// fun��o para inserir elemento na lista de forma ordenada
int inserir_lista_ordenada(Lista *li, int dado)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;

  // se a lista estiver vazia, insere no in�cio da lista
  if( (*li) == NULL ){
    no->prox = NULL;
    *li = no;

  }else{

    // sen�o percorre a lista at� achar o local correto e insere
    Elemento *anterior, *atual;
    atual = *li;

    while(atual != NULL && atual->dado < dado){
      anterior = atual;
      atual = atual->prox;
    }

    // insere na primeira posi��o
    if( atual == (*li) ){
      no->prox = (*li);
      *li = no;

    }else{
      no->prox = atual;
      anterior->prox = no;
    }
  }

  return 1;
}


// fun��o para remover elemento do in�cio da lista
int remover_lista_inicio(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, n�o remove nada
  if((*li) == NULL){
    return 0;
  }

  // muda inicio para o proximo elemento
  Elemento *no;
  no = *li;
  *li = no->prox;

  // libera Elemento no
  free(no);

  return 1;
}


// fun��o para remover elemento do final da lista
int remover_lista_final(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, n�o remove nada
  if((*li) == NULL){
    return 0;
  }

  // percorre lista at� o final
  Elemento *anterior, *no;
  no = *li;

  while(no->prox != NULL){
    anterior = no;
    no = no->prox;
  }

  // remove o primeiro elemento, se este for o �nico da lista
  if(no == (*li)){
    *li = no->prox;

  }else{
    anterior->prox = no->prox;
  }

  //libera Elemento no
  free(no);

  return 1;

}


// fun��o para remover elemento do meio da lista
int remover_lista_meio(Lista *li, int dado)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, n�o remove nada
  if((*li) == NULL){
    return 0;
  }

  // percorre a lista at� achar o elemento e remove
  Elemento *anterior, *no;
  no = *li;

  while(no != NULL && no->dado != dado){
    anterior = no;
    no = no->prox;
  }

  // elemento n�o foi encontrado
  if(no == NULL){
    return 0;
  }

  // remove o primeiro elemento
  if(no == (*li)){
    *li = no->prox;

  }else{
    anterior->prox = no->prox;
  }

  free(no);
  return 1;

}

int buscar_lista_posicao(Lista *li, int pos, int *dado)
{
  // verifica se a lista foi criada corretamente, se n�o est� vazia e se a posi��o � v�lida (note que � a posi��o na lista e n�o o �ndice do vetor)
  if(li == NULL || (*li) == NULL || pos <= 0){
    return 0;
  }

  Elemento *no = *li;
  int i = 1;

  while(no != NULL && i < pos){
    no = no->prox;
    i++;
  }

  // posi��o n�o existe na lista
  if(no == NULL){
    return 0;
  }

  // copia o dado da posi��o desejada (par�metro passado por refer�ncia)
  *dado = no->dado;

  return 1;
}


int buscar_lista_dado(Lista *li, int dado, int *pos)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL || (*li) == NULL){
    return 0;
  }

  // procura a posi��o no vetor onde o dado desejado se encontra
  Elemento *no = *li;
  int i = 1;

  while(no != NULL && no->dado != dado){
    no = no->prox;
    i++;
  }

  // verifica se elemento n�o foi encontrado
  if(no == NULL){
    return 0;
  }

  // copia a posi��o da lista onde o dado foi encontrado (par�metro passado por refer�ncia)
  *pos = i;

  return 1;
}



//**************************************************************************
// fun��o para imprimir a lista din�mica
int imprimir_lista(Lista *li)
{
    if(li == NULL || (*li) == NULL){
      return 0;
    }

    Elemento *aux = (*li);

    while(aux->prox != NULL){
      printf(" %d ", aux->dado);
      aux = aux->prox;
    }

    printf(" %d ", aux->dado);

    return 1;
}

Lista* concatena( Lista *lista1, Lista *lista2 ){
    Lista*  L1= (*lista1);
    Lista*  L2= (*lista2);

    if(L1==NULL)
        return L2;
    if(L2==NULL)
     return L1;

    while(L1->prox!=NULL)
        L1 = L1->prox;

    L1->prox = (*L2);
    return L1;
}


Lista *retira_repetidos( Lista * L1){
    if(L1==NULL || (*L1)==NULL)  ||(*L1)->prox==NULL)
        return NULL;

    Lista *L2 = (lista*)malloc(sizeof(lista));

    if(L2!=NULL) {
        (*L2)= NULL;
        Elemento *no1, *aux,*no2=(*L2);
        int x=0;
        while(no2!=NULL){
            do{
                if(x==no1->valor)
                    no1=no1->prox;
                else{
                    no1=(Elemento*)malloc(sezeof(Elemento));
                    no1->valor=valor2->valor;
                    no1->prox=NULL;
                    x=no1->valor;

                if((*L2)== NULL)
                    (*L2)=no1;
                else
                    aux->prox=no1;
                    aux=no1;
                    }
            }while(no1!=NULL);
	        no2=no2->prox;
            no1=(*L2);
            }
    Return L2;
}



Lista * inverte_lista( Lista * L1){
    If(L1==NULL || (*L1)==NULL )
        return NULL;
    Lista *L2= (lista*)malloc(sizeof(lista));
    if(L2!=NULL){
        elemento *no=(*L1)->prox;
        elemento *post=(*L1)->prox;
        elemento *ant=(*L1);
    while(no!=NULL){
        post=post->prox;
        no->prox=ant;
        ant=no;
        no=post;
        }
    (*L2)->ant;
    (*L1)->prox=NULL;
     return L2;
}
}


int verifica_ordena�ao_simples(Lista *li){
    if(li==NULL || (*li)=NULL || (*li)->prox=NULL)
        return 0;
    Elemento *no=(*li),*no2=(*li)->prox;
    int des=1; // valor 1 indica que esta ordenado na ordem crescente
    //crescente
    While(no!=NULL){
        if(no->aluno->matriculo < no2->aluno->matricula){
            no=no2;
            no2=no2->prox;
        }
        else{
            no=NULL;//caso algum valor seja maior j� saira do la�o
            des=0;// indica que n�o esta ordenada  na onde crescente
        }
    }
    if(des==0){// se n�o esta ordenado na ordem crescente pode estar na decrescente
        no=(*li),no2=(*li)->prox;
        des=2;//indica que esta ordenado na ordem decrescente
        //decrescente
        while(no!=NULL){
            if(no->aluno->matricula > no2->aluno->matricula){
                no=no2;
                no2=no2->prox;
            }
            else{
                no=NULL;//se existir um valor que seja menor ja sai do la�o
                des=0; // indica que n�o esta ordenado na ordem decrescente
            }
        }
    }
    return des; //1 esta crecente, 2 decrescente e 0 nenhuma ordena��o
}


int recursiva_tamanho_lista(Lista *lista, int tam){
    if( (*lista)==NULL || lista == NULL)
        return 0;
    if (list->prox== NULL)
        return tam;
    else
        return recursiva_tamanho_lista(list->prox, tam++);
}



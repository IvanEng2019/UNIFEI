#include <stdio.h>
#include <stdlib.h>
#include "lista_simples_ILVB.h"

// defini��o do struct elemento
struct elemento{
  int dado;
  struct elemento *prox;
};
// defini��o de tipos abstratos
typedef struct elemento Elemento;

// fun��o para alocar mem�ria do tipo Lista
Lista* criar_lista(){
  Lista *li = (Lista*) malloc(sizeof(Lista));
  if(li!= NULL)
    *li= NULL;
  return li;
}
//fun�ao verifica se a lista existe/foi criada com sucesso
int lista_existe(Lista *li){
    if(li!=NULL)
        return 1;
    return 0; //li==NULL
}
// fun��o para verificar se a lista est� vazia
int lista_vazia(Lista *li){
  // verifica se a lista foi criada corretamente, mas n�o cont�m nenhum valor
  if((*li)!=NULL)
    return 1;//se ela tiver valor retorna 1
  // se n�o houver elementos retorna 0
  return 0;
}

//fun�ao retorna o ultimo elemento da lista
Elemento* ultimo(Lista *li){
    Elemento *ult=(*li); //Recebe o inicio da lista e caso so tenha um elemento retorna ele mesmo
    while(ult->prox!= NULL)
      ult=ult->prox;//vira null
    return ult;
}
//fun�ao retorna o Penultimo elemento da lista: so sera chamada se tivar mais de um elemento
Elemento* penultimo(Lista *li){
    Elemento *aux= (*li); //Recebe o inicio da lista
    Elemento *pen;
    while(aux->prox!= NULL){
        pen = aux;
        aux = aux->prox;
    }
    return pen;
}
// fun��o para liberar mem�ria
int liberar_lista(Lista *li){
    if(lista_existe(li)){//se lista existe li!=NULL
      Elemento *no;
      while((*li)!=NULL){
        no=(*li);
        (*li)= (*li)->prox;
        free(no);
      }
      free(li);
      return 1;
      }
    else
      return 0;
}
// fun��o para obter o tamanho da lista
int tamanho_lista(Lista *li){
  //se lista nao existe
  if(li!=NULL)//if(lista_existe(li)==0) //se a lista nao li==NULL
    return 0;
  // a lista existe e est� vazia
  if((*li)!=NULL)//if(lista_vazia(li)==0) //cabe�alho aponta para null => (*li) == NULL
    return 0;
  int cont = 0;
  Elemento *no = (*li);
  // Acrescenta cont at� acabar a lista
  while(no!=NULL){
    cont++;
    no = no->prox;
  }
  return cont;
}
// fun��o para alocar mem�ria do tipo Elemento
Elemento* criar_elemento(){
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));
  return no;
}
// fun��o para inserir elemento no in�cio da lista
int inserir_lista_inicio(Lista *li, int dado){
  if(lista_existe(li)==0) //se a lista nao existe li==NULL
    return 0;
  else{
    // cria um elemento novo
    Elemento* no = criar_elemento();
    if(no!=NULL){
        // atribui valores ao elemento novo
        no->dado =dado;
        no->prox = (*li);// o novo elemento aponta para o que o *li apontava antes
        // insere elemento no in�cio da lista
        *li = no;
        return 1;
    }
    else
        return 0;
  }
}
// fun��o para inserir elemento no final da lista
int inserir_lista_final(Lista *li,int dado){
  if(!lista_existe(li)) //se a lista nao existe li==NULL
    return 0;
  // se a lista estiver vazia, insere no in�cio da lista
  if(!lista_vazia(li)) //cabe�alho aponta para null => (*li) == NULL
      inserir_lista_inicio(li,dado);
  else{
      // cria um elemento novo
      Elemento *no= criar_elemento();
      // atribui valores ao elemento novo
      no->dado = dado;
      no->prox = NULL;//o ultimo elemento tem que apontar paa NULL
      //se n�o percorre a lista at� o fim e insere no final
      Elemento *aux=ultimo(li);
    aux->prox = no; //faz o ultimo apontar pro novo no. Agora no passara a ser o ultimo da lista
  }
  return 1;
}
// fun��o para inserir elemento na lista de forma ordenada
// como nao tem ordena��o ele vai interir no depois do ultimo menor
int inserir_lista_ordenada(Lista *li, int dado){
  if(lista_existe(li)==0) //se a lista nao existe li==NULL
    return 0;
  // se a lista estiver vazia, insere no in�cio da lista
  if(lista_vazia(li)==0) //cabe�alho aponta para null => (*li) == NULL
    inserir_lista_inicio(li,dado);
  else{
    Elemento *no = criar_elemento();// cria um elemento novo
    no->dado = dado;// atribui valores ao elemento novo
    // sen�o percorre a lista at� achar o local correto e insere
    Elemento *anterior;
    Elemento *atual_li = (*li);
    while(atual_li != NULL && atual_li->dado < dado){
      anterior = atual_li;
      atual_li = atual_li->prox;
    }
    // insere na primeira posi��o caso o atual primeiro que esta inserido seja maior
    if( atual_li == (*li) ){
      no->prox = (*li);
      *li = no;
    }
    else{
      no->prox = atual_li;
      anterior->prox = no;
    }
  }
  return 1;
}
// fun��o para remover elemento do in�cio da lista
int remover_lista_inicio(Lista *li){
  if(lista_existe(li)==0) //se a lista nao existe li==NULL
    return 0;
  // lista vazia, n�o remove nada
  if(lista_vazia(li)==0) //cabe�alho aponta para null => (*li) == NULL
    return 0;
  else{// muda inicio para o proximo elemento
  Elemento *no= *li;
  *li = no->prox;
  // libera Elemento no
  free(no);
  return 1;
  }
}
// fun��o para remover elemento do final da lista
int remover_lista_final(Lista *li){
   if(lista_existe(li)==0) //se a lista nao existe li==NULL
    return 0;
   // lista vazia, n�o remove nada
   if(lista_vazia(li)==0) //cabe�alho aponta para null => (*li) == NULL
    return 0;
  // percorre lista at� o final
  Elemento *anterior;
  Elemento *no;
  no=ultimo(li);
  // remove o primeiro elemento, se este for o �nico da lista
  if(no == (*li))
    *li = no->prox;
  else{ //se tiver + de ul elemento
    anterior=penultimo(li);
    anterior->prox = NULL; //no->prox;
  }
  free(no);
  return 1;
}
// fun��o para remover elemento do meio da lista
int remover_lista_meio(Lista *li, int dado){
   if(lista_existe(li)==0) //se a lista nao existe li==NULL
    return 0;
   // lista vazia, n�o remove nada
   if(lista_vazia(li)==0) //cabe�alho aponta para null => (*li) == NULL
    return 0;
  // percorre a lista at� achar o elemento e remove
   Elemento *anterior;
   Elemento *no=*li;
   while(no!= NULL && no->dado!= dado){
       anterior = no;
       no = no->prox;
   }
  // elemento n�o foi encontrado
  if(no == NULL)
    return 0;
  // remove o primeiro elemento
  if(no == (*li))
    *li = no->prox;
  else
    anterior->prox = no->prox;
  free(no);
  return 1;
}
// fun��o para buscar o elemento que est� na posi��o "pos"
int buscar_lista_posicao(Lista *li, int pos){
    if(li==NULL || pos<=0) return 0;
    Elemento *no=(*li);
    int posicao=1;
    while(no!= NULL && posicao<pos){
       posicao++;
       no = no->prox;
   }
   if(no == NULL) return 0;
   return no->dado;
}
// fun��o para buscar o elemento "dado"
int buscar_lista_dado(Lista *li,int dado){
    if(li==NULL) return 0;
    Elemento *no=(*li);
    int pos=1;
    while(no!= NULL && no->dado!= dado){
       pos++;
       no=no->prox;
   }
    if(no == NULL) return 0;
    return pos;
}
void imprime(Lista *li){
    if(li==NULL || (*li)==NULL) printf("\nLista vazia ou inexistente.\n");
    else{
        Elemento *aux=(*li);
        while(aux!=NULL){
            printf("%d\n",aux->dado);
            aux=aux->prox;
        }
   }
}
Lista* concatena(Lista *li1,Lista *li2){
    Lista *list1=li1;
    Lista *list2=li2;

    if(list1==NULL && list2==NULL) return NULL;
    if(list1==NULL && list2!=NULL) return list2;
    if(list1!=NULL && list2==NULL) return list1;

    Elemento *l1 = (*list1);
    while(l1->prox!=NULL)
        l1=l1->prox;
    l1->prox= (*list2);
    return list1;
}
int Remover_n_ultimos_lista_simples(Lista *li, int n){
    if( li==NULL || (*li)== NULL ) return 0;
     int tam=0;
     Elemento *ant,*DEL,*no=(*li);
     while(no!=NULL){
            no=no->prox;
            tam++;
     }
     if(n>tam) return 0;
     else{
           int cont=0;
           no=(*li);
// acha a penultima e ultima posi�ao de (tam-n)
           while(cont<tam-n && no->prox!=NULL){
              ant=no; //penultima
              no=no->prox; //ultima
              cont++;
           }
           if(no==(*li)){//se so tem um elemento e se for pedido pra retirar este unico
               (*li)=no->prox; //NULL
               free(no);
               return 1;
           }
           else{// se tem mais de um elemento a ser retirado
              while (no->prox!=NULL){// come�a em (tam-n) e vai ate  o FIM (NULL)
                DEL= no;
                no=no->prox;
                free(DEL);
               }
           ant->prox=no->prox; //faz o ultimo apontar pra null
           return 1;
           }
     }
}

int Troca_El2_Simples(Lista *li, int p1, int p2){
     if( li==NULL || (*li)== NULL ) return 0;
     if(p1>p2){
        int pos1=p1;
        p1=p2;
        p2=pos1;
    }
     Elemento *antp1,*antp2,*no1,*aux,*no2;
     no1=(*li);
     int t=1;
     while(no1!=NULL && t<p1){
            antp1=no1;
            no1=no1->prox;
            t++;
    }
    if(no1==NULL) return 0;// n�o tem a posi��o p1 dada na lista
    no2=(*li)->prox;
    t=2;
    while(no2!=NULL && t<p2){
            antp2=no2;
            no2=no2->prox;
            t++;
    }
    if(no2==NULL) return 0;// n�o tem a posi��o p2 dada na lista
    if(p1==1){//no1=(*li) //se a primeira posi��o for 1 ( 1 elemento)
         aux=no2->prox;
         if(t==2){//se a segundo posi��o for 2 (2elemento)
            no2->prox=no1;
            no1->prox=aux;
         }
         else{// se a segunda posi��o for a partir do 3 elemento
            no2->prox=no1->prox;
            antp2->prox=no1;
            no1->prox=aux;
         }
         (*li)=no2;//muda o cabe�alho da lista para apontar para o novo 1� da lista
          return 1;
    }
    else{//se a 1� posi��o for diferente do 1� no
        if(no1->prox==no2){//se for nos consecutivos
            no1->prox=no2->prox;
            no2->prox=no1;
            antp1->prox=no2;
        }
        else{//se nao for n� consecutivo
            aux=no1->prox;
            no1->prox=no2->prox;
            no2->prox=aux;
            antp1->prox=no2;
            antp2->prox=no1;
        }
        return 1;
    }
}

/*Lista* Retira_Repetidos_Simples(Lista *L1){
        if(L1==NULL || (*L1)==NULL)return NULL;
        Elemento *aux=(*L1);
        Lista *L2 =(Lista*)malloc(sizeof(Lista));
        if(L2!= NULL){
            (*L2)=NULL;
          while(aux!=NULL){
            Elemento *no= criar_elemento();
            if((*L2)==NULL)
                (*L2)=no;
            no->dado=aux->dado;
            no->prox=NULL;
            if((*L2)!=NULL){
                Elemento *pen=penultimo(L2);
                pen->prox=no;
            }
            aux=aux->prox;
          }
          Elemento *no1= (*L2);
          while(no1!=NULL){
                    Elemento *no2=(*L2)->prox,*ant;
                    do{
                      while(no1->dado!=no2->dado && no2!=NULL){
                           ant=no2;
                           no2=no2->prox;
                     }
                     if(no2!=NULL){
                       ant->prox=no2->prox;
                       free(no2);
                       no2=ant->prox;
                     }
                    }while(no2!=NULL);
                }
            no1=no1->prox;
        }
return L2;
}*/

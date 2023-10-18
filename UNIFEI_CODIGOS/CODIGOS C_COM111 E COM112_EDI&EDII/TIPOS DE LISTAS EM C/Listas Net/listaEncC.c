//bibliotecas do sistemas
#include <stdlib.h>
#include <stdio.h>

//outras bibliotecas
#include "listaEncC.h"


//definição do struct elemento
struct elemento{
    int dado;
    struct elemento *prox;
};

//definição de tipos abstratos
typedef struct elemento Elemento;
typedef Elemento* Lista;  //criando uma lista do tipo Elemento


/*==== FUNÇÕES QUE ALOCAM E DASALOCAM MEMORIA ================ */
//função que aloca memoria do tipo Lista
Lista* criar_listaCirc(){
    //alocando memoria
    Lista *li = (Lista*) malloc(sizeof(Lista));

    //se li for alocado com sucesso
    if(li != NULL){
        *li = NULL; //adiciono o valor(*) de NULL para indicar lista vazia
    }else{
        return NULL;
    }
    return li;
}

//função que libera memoria
void liberarListaCirc(Lista *li){
    //se exisitir memoria alocada para li
    if(li != NULL){
        Elemento *no;

        //enquanto o valor da minha lista for diferente de NULL(vazio)
        while (*li != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }

        free(li);
    }
}
/*==== FIM FUNÇÕES QUE ALOCAM E DASALOCAM MEMORIA ================ */


/*====  FUNÇÃO QUE CRIA ELEMENTO =================== */

//cria um elemento quando necessario
Elemento* criarElementoCir(){
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no ==  NULL){
        return 0;
    }
    return no;
}
/*==== FIM FUNÇÃO QUE CRIA ELEMENTO ================ */

/*==== FUNÇÕES DE INSERÇÃO A LISTA  =================== */

//inserir elemento no inicio da lista
int inserirInicioListaCir(Lista *li, int dado){

    Elemento *no, *atual; //criando um elemento

    //se a lista estiver vazia(-1) retorna -1
    if(listaVazia(li) == -1){
        return -1;
    }

    //caso a lista esteja vazia soh faz a li apontar para o primeiro valor
    if(*li == NULL){
        no = criarElementoCir();       //criar o elemento a ser inserido

        no->dado = dado;   //no->dado recebe o dado
        no->prox = no;   //no->prox recebe NULL

        *li = no; //li recebendo o valor de no
        return 1;
    }

    //caso a lista nao esteja vazia, executa o codigo abaixo

    //cria elemento;
    no = criarElementoCir();

    atual = (*li); //recebe o valor da primeira posição da lista atual

    while(atual->prox != (*li)){
        atual = atual->prox;
    }

    atual->prox = no;
    no->prox = (*li);
    *li = no;

    return 1;
}//fim inserir no iniicioDaLista


//para inserir no meio da lista iremos inserir de modo ordenado ou seja vamos inserir o numero antes no numero maior
// que ele
int inserirMeioListaCir(Lista *li, int dado){

    //verificando se lista existe, se nao exister retorna -1
    if(listaVazia(li) == -1){
        return -1;
    }

    //criando elemento no que vai ser adicionado
    Elemento *no;


    //verificando se a lista esta vazia, se estiver meu ponteiro li recebe o elemento recem adicionado como primeira
    // posicao
    if(listaVazia(li) == 1){
        no = criarElementoCir(); //cria elemento a ser adicionado

        *li = no; //li recebe no
        no->prox = no; // no->prox apontando para meu propio no;

        return 1; // fim da execução
    }

    //se a lista nao estiver vazia executa o codigo abaixo

    Elemento *atual, *before; // crias os ponteiros para manipulação dos dados
    no = criarElementoCir();  //cria o elemento a ser adicionado

    no->dado = dado;     //no->dado recebe o dado ( nao criei no->prox pois ainda nao sei qual o proximo para quem ele
    //vai apontar

    //caso o numero digitado seje menor que a minha primeira posição da lista
    if(dado < (*li)->dado){
        //descobrindo o ultimo elemento da lista
            while (atual->prox != (*li)){
                atual = atual->prox;
            }
            atual->prox = no;
            no->prox = (*li);
            *li = no;
            return 1;
    }else{ //caso o numero digitado seja maior q minha primeira posicao
        atual = (*li);//atual recebe minha li, para atual percorrer a lista até encontrar seu lugar

        //pegando a ultima posção da lista
        while (atual->prox != (*li)){
            atual = atual->prox;
        }

        if(dado > atual->dado){
                atual->prox = no;  //ultimo elemento aponta para meu no que vai ser adicionado
                no->prox = (*li); //no->prox aponta para li

                return 1;
            }else{
                Elemento *aux;
                aux = (*li);

                while (aux->prox != (*li) && aux->dado < dado){
                    before = aux;
                    aux = aux->prox;
                }

                no->prox = aux;
                before->prox = no;

                return 1;
            }

        return 1;
    }
}

//função para inserir o elemento no fim da minha fila
int inserirFimListaCir(Lista *li, int dado){
    //verificando se a lista nao existe, caso nao exista(-1) retorna -1
    if(listaVazia(li) == -1){
        return -1;
    }

    Elemento *no;

    //vericando se a lista esta vazia, se ela estiver vazia meu ponteiro lista recebe o no adicionado com priemeiro
    //iten
    if(listaVazia(li) == 1){
        *li = no; //li recebe no
        no->prox = no; // no->prox apontando para meu propio no;
        return 1;
    }

    //caso a lista nao estaja vazia executa o codigo abaixo

    Elemento *atual; //ponteiro para manipular dados

    no = criarElemento(); //criando elemento atual a ser inserido
    no->dado = dado;   //no->dado recebe o dado

    atual = (*li);

    //verificando o ultimo elemento da lista
    while (atual->prox != (*li)){
        atual = atual->prox;
    }

    atual->prox = no;  //ultimo elemento aponta para meu no que vai ser adicionado
    no->prox = (*li); //no->prox aponta para li

    return 1;


}
/*==== FIM FUNÇÕES DE INSERÇÃO A LISTA  =================== */


/*========= FUNÇÃO QUE CONCATENA A LISTA 1 COM A LISTA 2 ==================*/
Lista* concatenarListasCir(Lista *li, Lista *li2){

    Elemento *atual, *aux;

    atual = (*li);

    printf("\nlala\n");
    //achando o ultimo valor da lista um
    while (atual->prox != (*li)){   //aki comparo o atual->prox para nao entrar no valor null, quando o prox for nu, saio do laço com a ultima opção
        printf("\nlili\n");
        atual = atual->prox;
    }

    aux = (*li);
    //achando o ultimo valor da lista um
    while (atual->prox != (*li2)){   //aki comparo o atual->prox para nao entrar no valor null, quando o prox for nu, saio do laço com a ultima opção
        printf("\nlila\n");
        aux = aux->prox;
    }

    atual->prox = (*li2);
    aux->prox = (*li);

    return li;
}
/*=========FIM FUNÇÃO QUE CONCATENA A LISTA 1 COM A LISTA 2 ==================*/


void acessarTodasPosicoesListaCir(Lista *li){
    //criar em elemento no
    Elemento *no = *li;
    int size;
    //enquanto o no nao for null printo o dado na tela
    while (no->prox != (*li)){
        printf(" %d ", no->dado);
        no = no->prox;
    }

    printf(" %d ", no->dado);

}
/*====FIM FUNÇÕES QUE ACESSAM A LISTA =================== */

//bibliotecas do sistemas
#include <stdlib.h>
#include <stdio.h>

//outras bibliotecas
#include "lista.h"


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
Lista* criar_lista(){
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
void liberarLista(Lista *li){
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
Elemento* criarElemento(){
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no ==  NULL){
        return 0;
    }
    return no;
}
/*==== FIM FUNÇÃO QUE CRIA ELEMENTO ================ */

/*==== FUNÇÕES DE INSERÇÃO A LISTA  =================== */

//inserir elemento no inicio da lista
int inserirInicioLista(Lista *li, int dado){

    Elemento *no, *atual; //criando um elemento

    //se a lista estiver vazia(-1) retorna -1
    if(listaVazia(li) == -1){
        return -1;
    }

    //caso a lista esteja vazia soh faz a li apontar para o primeiro valor
    if(*li == NULL){
        no = criarElemento();       //criar o elemento a ser inserido

        no->dado = dado;   //no->dado recebe o dado
        no->prox = NULL;   //no->prox recebe NULL

        *li = no; //li recebendo o valor de no
        return 1;
    }

    //caso a lista nao esteja vazia, executa o codigo abaixo

    //cria elemento;
    no = criarElemento();

    atual = (*li); //recebe o valor da primeira posição da lista atual
    no->dado = dado; //no que vai ser adicionado recebe valor digitado
    no->prox = atual; //no que vai ser adicionado recebe o ponteiro atual(antigo primeiro dado da lista)

    *li = no; //li aponta para o novo primeiro iten da lista

    return 1;
}//fim inserir no iniicioDaLista


//para inserir no meio da lista iremos inserir de modo ordenado ou seja vamos inserir o numero antes no numero maior
// que ele
int inserirMeioLista(Lista *li, int dado){

    //verificando se lista existe, se nao exister retorna -1
    if(listaVazia(li) == -1){
        return -1;
    }

    //criando elemento no que vai ser adicionado
    Elemento *no;


    //verificando se a lista esta vazia, se estiver meu ponteiro li recebe o elemento recem adicionado como primeira
    // posicao
    if(listaVazia(li) == 1){
        no = criarElemento(); //cria elemento a ser adicionado
        no->dado = dado;   //no->dado recebe o dado
        no->prox = NULL;   //no->prox recebe NULL (por que é minha primeira posição)

        *li = no; //li recebendo o valor de no

        return 1; // fim da execução
    }

    //se a lista nao estiver vazia executa o codigo abaixo

    Elemento *atual, *before; // crias os ponteiros para manipulação dos dados
    no = criarElemento();  //cria o elemento a ser adicionado

    no->dado = dado;     //no->dado recebe o dado ( nao criei no->prox pois ainda nao sei qual o proximo para quem ele
    //vai apontar

    //caso o numero digitado seje menor que a minha primeira posição da lista
    if(dado < (*li)->dado){
        //printf("\nlala\n");
        //printf("\n  dado = %d < (*li)->dado = %d \n",dado, (*li)->dado);

        atual = (*li); //meu numero atual recebe o valor antigo da primeira poscição
        no->prox = atual; //no->prox(para quem meu no q esta sendo inserido vai apontar, no caso pro meu atual
        *li = no; //li recebe o no inserido q é menor q o antigo

        return 1;//fim da execução
    }else{ //caso o numero digitado seja maior q minha primeira posicao
        atual = (*li);//atual recebe minha li, para atual percorrer a lista até encontrar seu lugar

        //ira percorrer a lista enquanto atual foi diferente de NULL ou atual seguir sendo menor q o numero digitado
        while (atual != NULL && atual->dado < dado){
            before = atual; //posição anterior aonde o numero sera inseirdo Ex recebe o 4 ->( 4 inserido aki 6 )
            atual = atual->prox; //atual recebe a proxima posição da anterior (para quem 4 apontava(6))
        }
        no->prox = atual; //no->proximo  do meu numero inseirdo aponta para o (6) recebendo meu atual

        before->prox = no; // before->prox(que é para onde o 4 aponta) recebe meu numero inserido agra( 4 passa apontar;
        //para o inserido aki)
        return 1;
    }
}

//função para inserir o elemento no fim da minha fila
int inserirFimLista(Lista *li, int dado){
    //verificando se a lista nao existe, caso nao exista(-1) retorna -1
    if(listaVazia(li) == -1){
        return -1;
    }

    Elemento *no; //cria no;

    //vericando se a lista esta vazia, se ela estiver vazia meu ponteiro lista recebe o no adicionado com priemeiro
    //iten
    if(listaVazia(li) == 1){

        no = criarElemento(); //alocando o elemento no

        no->dado = dado;   //no->dado recebe o dado
        no->prox = NULL;   //no->prox recebe NULL

        *li = no; //li recebendo o valor de no

        return 1;  //fim da execução
    }


    //caso a lista nao estaja vazia executa o codigo abaixo

    Elemento *atual; //ponteiro para manipular dados

    no = criarElemento(); //criando elemento atual a ser inserido
    no->dado = dado;   //no->dado recebe o dado
    no->prox = NULL;   //no->prox recebe NULL indicando que ele é o ultimo da lista

    atual = (*li);     //atual recebe a primeira poscição da lista, que sera percorrida

    //enquanto o campo atual->prox for diferente de NULL(que indica o fim da lista)
    while (atual->prox != NULL){
        atual = atual->prox;  //atual recebe o proximo iten da lista
    }
    atual->prox = no; //quando chegar o final da lista, atual aponta para o numero que sera a ultima posição da lista

    return 1;
}
/*==== FIM FUNÇÕES DE INSERÇÃO A LISTA  =================== */


/*======= FUNÇÕES PARA REMOVER ELEMENTOS DA LISTA  =================== */

//removendo elemento do inicio da fila
int removerElementoInicioLista(Lista *li){

    //verifica se a lista nao existe, se nao existir retorna -1
    if(listaVazia(li) == -1){
        return -1;
    }

    //verifica se a lista esta vazia(1) e setiver retorna 0
    if(listaVazia(li) == 1){
        return 0;
    }

    //caso a lista nao esteja vazia executa os codigos abaixo

    Elemento *no;  //ponteiro aux para manipular os dados
    no = *li; // no recebe minha primeira posição da lista que sera removida
    *li = no->prox;  //li recebe o proximo item da lista que sera sua nova posição 1

    free(no);   //desaloco memoria para o no;
    return 1;
}

//removendo elemento do meio da fila
int removerElementoMeioLista(Lista *li, int dado){

    //verificando se a lista existe, se nao existir retorna -1
    if(listaVazia(li) == -1){
        return -1;
    }

    //verifica se a lista esta vazia, se sim retorna 0
    if(listaVazia(li) == 1){
        return 0;
    }

    //caso a lista nao esteja vazia retorna o codigo abaixo


    //chamo função que verifica se o numero digitado pelo usuario existe na lista se nao existir(0) programa retorna 2
    if(existeNumeroNaLista(li, dado) == 0){
        return 2;   //fim da execução
    }else{//se tiver o numero vou remove-lo

        Elemento *atual; //crio ponteiro para ajudar na manipulaçao mantendo o valor atual da consulta

        //se o numero digitado pelo usuario for igual a minha primeira posição da lista
        if(dado == (*li)->dado){
            atual = (*li);  //atual(aux) recebe minha primeira posição
            *li = atual->prox;  //minha (*li) recebe  ponteiro do  proximo item da lista
            free(atual);  //libero memoria da atual
            return 1; //fim execução
        }else{  //caso nao seja igual
            Elemento *before;   //crio um ponteiro antes

            atual = (*li);  //atual recebe minha primeira posição da lista

            //enquanto atual->dado for diferente do dado digitado
            while (atual->dado != dado){
                before = atual;   //minha posição que vai ficar com a posição antes da removida recebe atual
                atual = atual->prox;   //atual recebe o proximo item da lista ( pode ser uma strutura ou NULL)
            }

            //ira sair quando os numeros forem iguais

            before->prox = atual->prox;    //antes->prox recebe o proximo numero
            free(atual);   //e dou free na atual
            return 1;
        }
    }
}

//removendo elementos do fim da lista
int removerElementoFimLista(Lista *li, int quant){
    //verificando se a lista nao existe, se nao existir retorna -1
    if(listaVazia(li) == -1){
        return -1;
    }

    //verificando se a lista esta vazia, caso esteja vazia retorna 0
    if(listaVazia(li) == 1){
        return 0;
    }

    //caso a lista nao esteja vazia iremos remover a quantidade de ultimos elementos da lista
    Elemento *atual, *before;
    int tam;

    //pegando tamanho da lista
    tam = tamanhoLista(li);

    if(quant < tam){
        //faz a remoção normal

        for (int i = 0; i < quant; i++) {

            atual = (*li);

            while (atual->prox != NULL){
                before = atual; //recebe valor anterior a consulta
                atual = atual->prox; //recebe prox da lista
            }
            if(tamanhoLista(li) == 1){
                *li = NULL;

            }else{
                //printf("\nlele\n");
                before->prox = NULL; // ultimo numero consultado vai apontar para null
                free(atual);
            }
        }
        return 1;     //continuar os teste daki parece q deu certo inserir da lista 1
    }else{
        //nao é possivel remover da tabela, nao existe posições suficientes a serem removidas
        return 2;
    }




}
/*====FIM FUNÇÕES PARA REMOVER ELEMENTOS DA LISTA  =================== */


/*======= FUNÇÕES QUE ACESSAM A LISTA =================== */

//acessando a lista pela posicao
void acessoPorPosicaoLista(Lista *li, int dado){
    int cont=0, cont2=0;

    //criar em elemento no
    Elemento *no = *li;

    //enquanto o no nao apontar para null
    while (no != NULL){
        if(cont == dado-1){// valor de cont for igual a posição - 1 eu printo o o dado do ponteiro no
            printf(" %d ", no->dado);
            cont2++;// caso nao entre aaqui significa q a posção digitada nao existe
        }
        cont++; //para se dizer a posição 2 da lista
        no = no->prox; //ponteiro atual recebe a proxima struct de elementos caso haja
    }
    //se nao entra na condição do for o numero digitado nao existe
    if(cont2 == 0){
        printf("\na posicao %d nao existe na lista\n", dado);
    }
}

//acessar por algum dado da lista
void acessoPorDadoLista(Lista *li, int dado){
    int cont=0;

    //criar em elemento no
    Elemento *no = *li;

    //enquanto o no nao apontar para null
    while (no != NULL){
        if(dado == no->dado){// valor de cont for igual a posição eu printo o dado
            printf(" %d existe na lista", no->dado);
            cont++;// caso nao entre aaqui significa q o numero digitado nao existe
        }
        no = no->prox; //ponteiro atual recebe a proxima struct de elementos caso haja
    }

    if(cont == 0){
        printf("\na numero %d nao existe na lista\n", dado);
    }
}

void acessarTodasPosicoesLista(Lista *li){
    //criar em elemento no
    Elemento *no = *li;
    int size;

    //enquanto o no nao for null printo o dado na tela
    while (no != NULL){
        printf(" %d ", no->dado);
        no = no->prox;
    }

    //verifico o tamanho da minha lista e printo ele na tela
    size = tamanhoLista(li);
    printf("\nTamanho da lista: %d itens\n", size);
}
/*====FIM FUNÇÕES QUE ACESSAM A LISTA =================== */


/*====  FUNÇÃO QUE OBTÉM INFORMAÇÕES DA LISTA ======================*/

//função que calcula tamanho da lista
int tamanhoLista(Lista *li){
    int cont = 0;
    Elemento *no = *li;
    //se a lista nao existir continuamos retornando 0 se estiver vazia retornamos 1
    if (listaVazia(li) == -1){
        return -1;
    }
    if (listaVazia(li) == 1){
        return 0;
    }
    //acrescenta cont ao acabar a lista
    while (no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

//função que veirifica o status da lista(e ela existe ou esta vazia)
int listaVazia(Lista *li){

    //verifica se a lista existe se nao existir retorna -1
    if(li == NULL){
        return -1;
    }

    //verifica se a lista esta vazia, se estiver vazia retorna 1
    if((*li) == NULL){
        return 1;
    }

    return 0; //se nao estiver vazia retorna 0
}

//função que verifica se existe numero na lista
int existeNumeroNaLista(Lista *li, int dado){
    int cont = 0;
    Elemento *atual;

    atual = (*li);

    while (atual != NULL){
        if(atual->dado == dado){
            cont++;
        }
        atual = atual->prox;
    }

    return cont;
}
/*==== FIM FUNÇÃO QUE MOSTRAM CARACTERISTICAS DA LISTA =================== */

/*========= FUNÇÃO QUE CONCATENA A LISTA 1 COM A LISTA 2 ==================*/
Lista* concatenarListas(Lista *li, Lista *li2){

    Elemento *atual;

    atual = (*li);

    //achando o ultimo valor da lista um
    while (atual->prox != NULL){   //aki comparo o atual->prox para nao entrar no valor null, quando o prox for nu, saio do laço com a ultima opção
        atual = atual->prox;
    }
    atual->prox = (*li2); //aponto minha ultima opção para a segunda lista

    return li;
}
/*=========FIM FUNÇÃO QUE CONCATENA A LISTA 1 COM A LISTA 2 ==================*/

/*========= FUNÇÃO TROCA POSCIÇÃO DA LISTA==================*/

Lista* trocaLugar(Lista *li, int posi1, int posi2){

    Elemento *atual, *antes, *antes1, *antes2, *muda1, *muda2, *prox2;
    int cont = 1, auxi;


    if(posi1 > posi2){
        auxi = posi1; //5
        posi1 = posi2;  //3
        posi2 = auxi;
    }

    atual = (*li);

    /* CONTINUAR DAKI
            TROCAR O PRIMEIRO COM O ULTIMO.
            DEPOIS TROCAR O ULTIMO COM OS DO MEIO

            DEPOIS TENTAR CRIAR UMA CONDIÇÃO ANTES DE SAIR PARA O MENU PRINCIPAL, OPÇÃO COM A MESMA LISTA SEM PRECISAR DIGITAR OUTRA
    */

    //se a posição desejada de troca for a primeira posição
    if(posi1 == 1){
        //recebendo a primeira posição da lista que é a primeira a ser mudada
        muda1 = atual;

        //mudando posição 1 com a 2
        if(posi2 == 2){
            for(int i = 1; i <= 2; i++){
                if(i == posi2){
                    muda2 = atual;
                }
                atual = atual->prox;
            }

            //testando valores
            printf("\nValores\n");
            printf("Muda 1 = %d\n", muda1->dado);
            printf("Muda 2 = %d\n", muda2->dado);

            *li = muda2;
            muda1->prox = muda2->prox;
            muda2->prox = muda1;

            return li;
        }else{// mudando posição 1 com o a ultima e com o  meio

            //mudando primeira com a ultima
            if(tamanhoLista(li) == posi2){

                while(atual->prox != NULL){
                    antes2 = atual;
                    atual = atual->prox;
                }
                printf("\nValores\n");
                printf("tam lista = %d\n", tamanhoLista(li));
                printf("Muda 1 = %d\n", atual->dado);
                printf("Antes 2 = %d\n", antes2->dado);
                printf("Muda 1 = %d\n", muda1->dado);

                atual->prox = muda1->prox;
                antes2->prox = muda1;
                muda1->prox = NULL;
                *li = atual;

                return li;
            }else{
                // mudando a primeira posição com o resto

                //procurando a proxima posição
                while(atual != NULL){

                    if(cont == posi2){
                        antes2 = antes;
                        muda2 = atual;
                        prox2 = atual->prox;
                    }

                    antes = atual;
                    cont++;
                    atual = atual->prox;
                }

                //testando valores
                printf("\nValores\n");
                printf("Antes 2 = %d\n", antes2->dado);
                printf("Muda 1 = %d\n", muda1->dado);
                printf("Muda 2 = %d\n", muda2->dado);
                printf("Prox2 = %d\n", muda2->prox->dado);

                *li = muda2;
                muda2->prox = muda1->prox;
                antes2->prox = muda1;
                muda1->prox = prox2;

                return li;
            }//fim mudando primeira o resto
        }//fim else mudando a posição 1 com a ultima e com o resto
    }//fim if se for igual a primeira poicao
    else if(tamanhoLista(li) == posi2 && posi1 != 1){

        if(tamanhoLista(li) == posi2 && tamanhoLista(li) - 1 == posi1){

            while(atual->prox != NULL){
                if(cont == posi1){
                    antes1 = antes;
                    muda1 = atual;
                }
                antes = atual;
                cont++;
                atual = atual->prox;
            }

            //testando valores
            printf("\nValores\n");
            printf("Antes 1 = %d\n", antes1->dado);
            printf("Muda 1 = %d\n", muda1->dado);
            printf("Atual %d\n", atual->dado);

            atual->prox = muda1;
            muda1->prox = NULL;
            antes1->prox = atual;

            return li;
        }//fim troca ultimo com a penultimo
        else{//troca ultimo com o meio

            //percorrendo a lista achando os requisitos necessários para funcionar
            while(atual != NULL){

                if(cont == posi1){
                    antes1 = antes;
                    muda1 = atual;
                }

                if(cont == posi2){
                    antes2 = antes;
                    muda2 = atual;
                }
                antes = atual;
                cont++;
                atual = atual->prox;
            }

            //testando valores
            printf("\nValores\n");
            printf("Antes 1 = %d\n", antes1->dado);
            printf("Muda 1 = %d\n", muda1->dado);
            printf("Antes 2 = %d\n", antes2->dado);
            printf("Muda 2  %d\n", muda2->dado);

            muda2->prox = muda1->prox;
            antes1->prox = muda2;
            antes2->prox = muda1;
            muda1->prox = NULL;

            return li;
        }//fim troca ultimo com o o meio

    }else{

        /*TROCANDO OS VALORES DO MEIO DE POSIÇÃO*/
        //percorre a lista ate o fim
        while(atual != NULL){
            //quando a posicao atual da lista for igual a posicao  q o usuario deseja trocar
            if(cont == posi1){
                printf("\nEntrou cont %d = posi1 %d\n", cont, posi1);
                antes1 = antes;  //pego o antecessor da primeira posição a ser trocada
                muda1 = atual;  //pego o valor atual a ser mudado
            }

            //quando a posicao atuaç da lista for igual a posicao 2 q o usuario deseja trocar
            if(cont == posi2){
                printf("\nEntrou cont %d = posi1 %d\n", cont, posi2);
                antes2 = antes;   //antecessor da segunda posição
                muda2 = atual;  //pega valor a ser mudado
                prox2 = atual->prox;  //pega o proximo valor da posicaç 2
            }
            antes = atual;   //anoto meu antecessor *obs: anoto no final pq no começo do while toda vez vai ser meu atual
            cont++;  //ando posicao da lista
            atual = atual->prox;
        }

        //testando valores
        printf("\nValores\n");
        printf("Antes 1 = %d\n", antes1->dado);
        printf("Antes 2 = %d\n", antes2->dado);
        printf("Muda 1 = %d\n", muda1->dado);
        printf("Muda 2 = %d\n", muda2->dado);
        printf("Prox2 = %d\n", muda2->prox->dado);


        antes1->prox = muda2;
        antes2->prox = muda1;
        muda2->prox = muda1->prox;
        muda1->prox = prox2;

        return li;
    }//fim else
}//fim função

/*=========FIM  FUNÇÃO TROCA POSCIÇÃO DA LISTA==================*/

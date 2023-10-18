/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

struct noArvore
{
    int chave;
    char cor; //'v' para vermelho e 'p' para preto
    struct noArvore *esq;
    struct noArvore *dir;
    struct noArvore *pai;
    
};

struct avp
{
    struct noArvore *sentinela;
};


avp* criaArvore()
{
    avp *A = (avp*)malloc(sizeof(avp));
    if (!A)
    {
        return NULL;
    }
    noArvore *s = (noArvore*)malloc(sizeof(noArvore));
    s->chave = -1000;
    s->esq = NULL;
    s->dir = NULL;
    s->pai = NULL;
    A->sentinela = s;
    return A;
}

int insereNo(avp *A, int valor)
{
    //Declarar variaveis auxiliares
    noArvore *novoNo, *noAtual, *noPai;
    
    //Alocar o novo no
    novoNo = (noArvore*)malloc(sizeof(noArvore));
    if(!novoNo)
    {
        return -1;
    }
    novoNo->chave = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->pai = NULL;
    novoNo->cor = 'v';
    
    
    //Encontrar o local de insercao
    noAtual = A->sentinela->dir;
    if(noAtual == NULL) //arvore vazia
    {
        A->sentinela->dir = novoNo;
        novoNo->pai = A->sentinela;
        balanceamento_insercao(A, novoNo);
        return 1;
    }
    while(noAtual != NULL)
    {
        noPai = noAtual;
        if(valor < noAtual->chave)
            noAtual = noAtual->esq;
        else
            noAtual = noAtual->dir;
    }
    //Insere o novo no na arvore 
    if(valor < noPai->chave)
        noPai->esq = novoNo;
    else
        noPai->dir = novoNo;
    novoNo->pai = noPai;
    balanceamento_insercao(A, novoNo);
    return 1;
}

int removeNo(avp *A, int valor)
{
    //declaraçao de variaveis
    noArvore *aux = A->sentinela->dir;
    noArvore *predecessor;
    noArvore *pai;
    noArvore *filho;
    char corNoRemovido;
    
    //encontra o no com o valor a ser removido
    if (aux == NULL)
    {
        return -1;
    }
    while((aux != NULL) && (aux->chave != valor))
    {
        if(valor < aux->chave)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    if (aux == NULL)
    {
        return -1;
    }
    //encontrar o grau do no a ser removido
    if((aux->esq!=NULL) && (aux->dir!=NULL))//o no tem dois filhos
    {
        //encontrar o sucessor
        predecessor = aux->esq;
        while(predecessor->dir != NULL)
        {
            predecessor = predecessor->dir;
        }
        //troca a chave do sucessor com o aux
        valor = predecessor->chave;
        aux->chave = predecessor->chave;
        aux = predecessor;
    }
    corNoRemovido = aux->cor;
    pai = aux->pai;
    if((aux->esq == NULL) && (aux->dir ==NULL)) //O no e folha
    {
        if(aux->chave < pai->chave)
            pai->esq = NULL;
        else
            pai->dir = NULL;
        filho = NULL;
    }
    else
    {
        if(aux->esq != NULL) //o no tem filhos a esquerda
        {
            if(aux->chave < pai->chave)
                pai->esq = aux->esq;
            else
                pai->dir = aux->esq;
            aux->esq->pai = pai;
            filho = aux->esq;
        }
        else
        {
            if(aux->chave < pai->chave)
                pai->esq = aux->dir;
            else
                pai->dir = aux->dir;
            aux->dir->pai = pai;
            filho = aux->dir;
        }
    }
    free(aux);
    if(corNoRemovido=='p')
        balanceamento_remocao(A, pai, filho);
    return 1;
}

void percorreEmOrdem(noArvore *noAtual)
{
    if(noAtual != NULL)
    {
        percorreEmOrdem(noAtual->esq);
        printf("%d -- %c\n", noAtual->chave, noAtual->cor);
        percorreEmOrdem(noAtual->dir);
    }
    return;
}

noArvore* retornaSentinelaRaiz(avp *A)
{
    return A->sentinela->dir;
}

void balanceamento_insercao(avp *A, noArvore *novoNo)
{
    noArvore *pai, *tio, *avo;
    char corTio;
    if(novoNo == A->sentinela->dir)//se o nó é raíz
    {
        novoNo->cor = 'p';
        return;
    }
    pai = novoNo->pai;
    if(pai->cor == 'p')//não quebra as propriedades
        return;
    avo = pai->pai;
    if(novoNo->chave < avo->chave)//o novo no está a esquerda do avo
    {
        tio = avo->dir;
        if(tio == NULL)
            corTio = 'p';
        else
            corTio = tio->cor;
        //CASO 1
        if(corTio == 'v')
        {
            pai->cor = 'p';
            tio->cor = 'p';
            avo->cor = 'v';
            if((avo == A->sentinela->dir) || (avo->pai->cor == 'v'))
                balanceamento_insercao(A, avo);
        }
        //CASO 2
        else
        {
            if(novoNo == pai->dir)//o novo no é um filho a direita
            {
                novoNo = pai;
                rotacaoEsq(novoNo);
                pai = novoNo->pai;
            }
            //CASO 3
            pai->cor = 'p';
            avo->cor = 'v';
            rotacaoDir(avo);
        }
    }
    else //o no está a direita do avo
    {
        tio = avo->esq;
        if(tio == NULL)
            corTio = 'p';
        else
            corTio = tio->cor;
        //CASO 1
        if(corTio == 'v')
        {
            pai->cor = 'p';
            tio->cor = 'p';
            avo->cor = 'v';
            if((avo == A->sentinela->dir) || (avo->pai->cor == 'v'))
                balanceamento_insercao(A, avo);
        }
        //CASO 2
        else
        {
            if(novoNo->chave < pai->chave)//o novo no é um filho a esquerda
            {
                novoNo = pai;
                rotacaoDir(novoNo);
                pai = novoNo->pai;
            }
            //CASO 3
            pai->cor = 'p';
            avo->cor = 'v';
            rotacaoEsq(avo);
        }
    }
    A->sentinela->dir->cor = 'p';
    return;
}

void rotacaoDir(noArvore *noDesbalanceado)
{
    noArvore *filho = noDesbalanceado->esq;
    noArvore *neto = filho->dir;
    if (noDesbalanceado->chave < noDesbalanceado->pai->chave) //ele está à esquerda do pai
    {
        noDesbalanceado->pai->esq = filho;
    }
    else
    {
         noDesbalanceado->pai->dir = filho;
    }
    filho->pai = noDesbalanceado->pai;
    noDesbalanceado->pai = filho;
    filho->dir = noDesbalanceado;
    noDesbalanceado->esq = neto;
    if (neto != NULL)
        neto->pai = noDesbalanceado;    
    return;
}


void rotacaoEsq(noArvore *noDesbalanceado)
{
    noArvore *filho = noDesbalanceado->dir;
    noArvore *neto = filho->esq;
    if (noDesbalanceado->pai->esq == noDesbalanceado)
    {
        noDesbalanceado->pai->esq = filho;
    }
    else
    {
        noDesbalanceado->pai->dir = filho;
    }
    filho->pai = noDesbalanceado->pai;
    filho->esq = noDesbalanceado;
    noDesbalanceado->pai = filho;
    noDesbalanceado->dir = neto;
    if(neto != NULL)
        neto->pai = noDesbalanceado;
    return;
}

void balanceamento_remocao(avp *A, noArvore *noPai, noArvore *noFilho)
{
    char corFilho, corIrmao;
    noArvore *irmao;
    if (noFilho == NULL)
        corFilho = 'p';
    else
        corFilho = noFilho->cor;
    ///quem ficou no lugar do no removido foi um no vermelho
    //condição de um no vermelho e preto
    //troca a cor do no para preto e reestabelece o balanceamento
    if (corFilho == 'v')
    {
        noFilho->cor = 'p';
        return;
    }
    //quem ficou no lugar do no removido foi um preto
    //condição do no duplo preto
    //usa a tabela para reestabelecer o balanceamento
    if (noFilho == noPai->esq)
    {
        irmao = noPai->dir;
        if(irmao == NULL)
            corIrmao = 'p';
        else
            corIrmao = irmao->cor;
        //CASO 1
        if(corIrmao == 'v')
        {
            irmao->cor = 'p';
            noPai->cor = 'v';
            rotacaoEsq(noPai);
            irmao = noPai->dir;
        }
        //CASO 2
        if((irmao == NULL) || ((irmao->esq == NULL || irmao->esq->cor == 'p') && 
                (irmao->dir == NULL|| irmao->dir->cor == 'p')))
        {
            if(noPai->cor == 'v')
            {
                irmao->cor = 'v';
                noPai->cor = 'p';
            }
            else
            {
                irmao->cor = 'v';
            }
        }
        //CASO 3
        else{
            if((irmao->esq->cor == 'v') && (irmao->dir == NULL || irmao->dir->cor == 'p'))
            {
                irmao->esq->cor = 'p';
                irmao->cor = 'v';
                rotacaoDir(irmao);
                irmao = noPai->dir;
            }
            //CASO 4
            irmao->cor = noPai->cor;
            noPai->cor = 'p';
            irmao->dir->cor = 'p';
            rotacaoEsq(noPai);
        }
    }
    else //se o no estiver a direita
    {
        
    }
    A->sentinela->dir->cor = 'p';
    return;
}

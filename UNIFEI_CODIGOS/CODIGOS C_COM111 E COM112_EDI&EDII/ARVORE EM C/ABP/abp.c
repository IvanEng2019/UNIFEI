/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

struct noArvore
{
    int chave;
    struct noArvore *esq;
    struct noArvore *dir;
    struct noArvore *pai;
    int fb;
};

struct abp
{
    struct noArvore *sentinela;
};


abp* criaArvore()
{
    abp *A = (abp*)malloc(sizeof(abp));
    if (!A)
    {
        return NULL;
    }
    noArvore *s = (noArvore*)malloc(sizeof(noArvore));
    s->chave = -1000;
    s->esq = NULL;
    s->dir = NULL;
    s->pai = NULL;
    s->fb = 0;
    A->sentinela = s;
    return A;
}

int insereNo(abp *A, int valor)
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
    novoNo->fb = 0;
    
    //Encontrar o local de insercao
    noAtual = A->sentinela->dir;
    if(noAtual == NULL) //arvore vazia
    {
        A->sentinela->dir = novoNo;
        novoNo->pai = A->sentinela;
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
    atualizaFB(novoNo);
    return 1;
}

int removeNo(abp *A, int valor)
{
    //declaraçao de variaveis
    noArvore *aux = A->sentinela->dir;
    noArvore *sucessor;
    
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
        sucessor = aux->dir;
        while(sucessor->esq != NULL)
        {
            sucessor = sucessor->esq;
        }
        //troca a chave do sucessor com o aux
        aux->chave = sucessor->chave;
        aux = sucessor;
    }
    if((aux->esq == NULL) && (aux->dir ==NULL)) //O no e folha
    {
        if(aux->chave < aux->pai->chave)
            aux->pai->esq = NULL;
        else
            aux->pai->dir = NULL;
        free(aux);        
    }
    else
    {
        if(aux->esq != NULL) //o no tem filhos a esquerda
        {
            if(aux->chave < aux->pai->chave)
                aux->pai->esq = aux->esq;
            else
                aux->pai->dir = aux->esq;
            aux->esq->pai = aux->pai;
        }
        else
        {
            if(aux->chave < aux->pai->chave)
                aux->pai->esq = aux->dir;
            else
                aux->pai->dir = aux->dir;
            aux->dir->pai = aux->pai;
        }
        free(aux);
    }
    return 1;
}

void percorreEmOrdem(noArvore *noAtual)
{
    if(noAtual != NULL)
    {
        percorreEmOrdem(noAtual->esq);
        printf("%d -- %d", noAtual->chave, noAtual->fb);
        percorreEmOrdem(noAtual->dir);
    }
    return;
}

noArvore* retornaSentinelaRaiz(abp *A)
{
    return A->sentinela->dir;
}


void atualizaFB(noArvore *novoNo)
{
    noArvore *noAux = novoNo->pai;
    if (noAux->chave < novoNo->chave)
        noAux->fb = noAux->fb - 1;
    else
        noAux->fb = noAux->fb + 1;
    while ((noAux->chave != -1000) && (noAux->fb != 0) && (noAux->fb !=2) && (noAux->fb != -2))
    {
        noAux = noAux->pai;
        if (noAux->chave != -1000)
        {
            if (noAux->chave < novoNo->chave)
                noAux->fb = noAux->fb - 1;
            else
                noAux->fb = noAux->fb + 1;
        }
    }
    if ((noAux->fb == 2) || (noAux->fb == -2))
        balanceamento(noAux);
    return;
}


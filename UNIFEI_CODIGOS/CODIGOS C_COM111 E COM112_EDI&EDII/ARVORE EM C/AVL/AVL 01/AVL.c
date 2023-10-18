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
    atualizaFB_insercao(novoNo);
    return 1;
}

int removeNo(abp *A, int valor)
{
    //declaraçao de variaveis
    noArvore *aux = A->sentinela->dir;
    noArvore *sucessor;
    noArvore *pai;
    
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
        valor = sucessor->chave;
        aux->chave = sucessor->chave;
        aux = sucessor;
    }
    pai = aux->pai;
    if((aux->esq == NULL) && (aux->dir ==NULL)) //O no e folha
    {
        if(aux->chave < pai->chave)
            pai->esq = NULL;
        else
            pai->dir = NULL;     
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
        }
        else
        {
            if(aux->chave < pai->chave)
                pai->esq = aux->dir;
            else
                pai->dir = aux->dir;
            aux->dir->pai = pai;
        }
    }
    free(aux);
    atualizaFB_remocao(pai, valor);
    return 1;
}

void percorreEmOrdem(noArvore *noAtual)
{
    if(noAtual != NULL)
    {
        percorreEmOrdem(noAtual->esq);
        printf("%d -- %d\n", noAtual->chave, noAtual->fb);
        percorreEmOrdem(noAtual->dir);
    }
    return;
}

noArvore* retornaSentinelaRaiz(abp *A)
{
    return A->sentinela->dir;
}


void atualizaFB_insercao(noArvore *novoNo)
{
    noArvore *noAux = novoNo->pai;
    if (noAux->chave < novoNo->chave)
        noAux->fb = noAux->fb + 1;
    else
        noAux->fb = noAux->fb - 1;
    while ((noAux->chave != -1000) && (noAux->fb != 0) && (noAux->fb !=2) && (noAux->fb != -2))
    {
        noAux = noAux->pai;
        if (noAux->chave != -1000)
        {
            if (noAux->chave < novoNo->chave)
                noAux->fb = noAux->fb + 1;
            else
                noAux->fb = noAux->fb - 1;
        }
    }
    if ((noAux->fb == 2) || (noAux->fb == -2))
        balanceamento_insercao(noAux);
    return;
}

void balanceamento_insercao(noArvore *noDesbalanceado)
{
    noArvore *filho, *neto;
    //Rotaçoes a esquerda
    if(noDesbalanceado->fb == 2)
    {
        filho = noDesbalanceado->dir;
        if((filho->fb == 0) || (filho->fb == 1))
        {
            //rotacao simples a esquerda
            rotacaoEsq(noDesbalanceado);
            filho->fb = 0;
            noDesbalanceado->fb = 0;
        }
        else
        {
            //rotacao dupla dir-esq
            neto = filho->esq;
            rotacaoDir(filho);
            rotacaoEsq(noDesbalanceado);
            filho->fb = 0;
            noDesbalanceado->fb = 0;
            if(neto->fb == -1)
                filho->fb = 1;
            if(neto->fb == 1)
                noDesbalanceado->fb = -1;
            neto->fb = 0;            
        }
    }
    else ////nó desbalanceado à esquerda - rotação à direita
    {
        filho = noDesbalanceado->esq;
        if ((filho->fb == -1) || (filho->fb == 0))
        {
           //rotacao simples à direita
            rotacaoDir(noDesbalanceado);
            noDesbalanceado->fb = 0;
            filho->fb = 0;
        }
        else
        {
            //rotacao dupla esq-dir
            neto = filho->dir;
            rotacaoEsq(filho);
            rotacaoDir(noDesbalanceado);
            filho->fb = 0;
            noDesbalanceado->fb = 0;
            if (neto->fb == -1)
            {
                noDesbalanceado->fb = 1;
            }
            if (neto->fb == 1)
            {
                filho->fb = -1;
            }
            neto->fb = 0;
        }
        
    }
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

void atualizaFB_remocao(noArvore *paiNoRemovido, int valor)
{
    noArvore *noAux = paiNoRemovido;
    if (valor <= noAux->chave)
        noAux->fb = noAux->fb + 1;
    else
        noAux->fb = noAux->fb - 1;
    
    
    while ((noAux->chave != -1000) && (noAux->fb != 1) && (noAux->fb != -1))
    {
        if ((noAux->fb ==2) || (noAux->fb == -2))
        {
            noAux = balanceamento_remocao(noAux);
            if ((noAux->fb == 1) || (noAux->fb == -1))
                return;
        }
        noAux = noAux->pai;
        if (noAux->chave != -1000)
        {
            if (valor <= noAux->chave)
                noAux->fb = noAux->fb + 1;
            else
                noAux->fb = noAux->fb - 1;
        }
    }
    return;
}

noArvore* balanceamento_remocao(noArvore *noDesbalanceado)
{
    noArvore *filho, *neto;
    //Rotaçoes a esquerda
    if(noDesbalanceado->fb == 2)
    {
        filho = noDesbalanceado->dir;
        if((filho->fb == 0) || (filho->fb == 1))
        {
            //rotacao simples a esquerda
            rotacaoEsq(noDesbalanceado);
            if (filho->fb==0)
            {
                noDesbalanceado->fb = 1;
                filho->fb = -1;
            }
            else
            {
                filho->fb = 0;
                noDesbalanceado->fb = 0;
            }           
        }
        else
        {
            //rotacao dupla dir-esq
            neto = filho->esq;
            rotacaoDir(filho);
            rotacaoEsq(noDesbalanceado);
            filho->fb = 0;
            noDesbalanceado->fb = 0;
            if(neto->fb == -1)
                filho->fb = 1;
            if(neto->fb == 1)
                noDesbalanceado->fb = -1;
            neto->fb = 0;            
        }
    }
    else ////nó desbalanceado à esquerda - rotação à direita
    {
        filho = noDesbalanceado->esq;
        if ((filho->fb == -1) || (filho->fb == 0))
        {
           //rotacao simples à direita
            rotacaoDir(noDesbalanceado);
            if(filho->fb == 0)
            {
                noDesbalanceado->fb = -1;
                filho->fb = 1;
            }
            else
            {
                noDesbalanceado->fb = 0;
                filho->fb = 0;
            }
        }
        else
        {
            //rotacao dupla esq-dir
            neto = filho->dir;
            rotacaoEsq(filho);
            rotacaoDir(noDesbalanceado);
            filho->fb = 0;
            noDesbalanceado->fb = 0;
            if (neto->fb == -1)
            {
                noDesbalanceado->fb = 1;
            }
            if (neto->fb == 1)
            {
                filho->fb = -1;
            }
            neto->fb = 0;
        }
        
    }
    return noDesbalanceado->pai;
}

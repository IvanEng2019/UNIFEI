#include <stdio.h>
#include <stdlib.h>
#include "avrbin.h"

struct no{
    int dado;
    struct no *left;
    struct no *right;
};

arvBin* cria_arvore()
{
    arvBin* raiz = (arvBin*) malloc(sizeof(arvBin));
    if(raiz == NULL)
        printf("Árvore não criada!\n");
    else{
        *raiz = NULL;
        printf("Árvore criada!\n");
    }
    return raiz;
}

void libera_no(struct no* NO)
{
    if(NO == NULL){
        printf("Falha na remoção!\n");
        return;
    }
    libera_no(NO->left);
    libera_no(NO->right);
    free(NO);
    NO = NULL;
}

void libera_arvore(arvBin *raiz)
{
    if(raiz == NULL)
        printf("Árvore não alocada!\nImpossível remover!\n");
    else{
        libera_no(*raiz);//Passa cabeça de lista para desalocar todos nos
        free(raiz);
    }
}

int altura(arvBin* raiz)
{
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int alt_esq = altura(&((*raiz)->left));
    int alt_dir = altura(&((*raiz)->right));
    if(alt_esq > alt_dir)
        return(alt_esq + 1);
    else
        return(alt_dir + 1);
}

int totalNo(arvBin* raiz)
{
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int total_esq = totalNo(&((*raiz)->left));
    int total_dir = totalNo(&((*raiz)->right));
    return(total_esq + total_dir + 1);
}

int inserir(arvBin* raiz, int dado)
{
    if(raiz == NULL)
        return 0;
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    if(novo == NULL)
        return 0;
    novo->dado = dado;
    novo->left = NULL;
    novo->right = NULL;
    if((*raiz) == NULL)
        *raiz = novo;
    else{
        struct no* atual = *raiz;
        struct no* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(dado == atual->dado)
                free(novo);
            if(dado < atual->dado)
                atual = atual->left;
            else
                atual = atual->right;
        }
        if(dado < ant->dado)
            ant->left = novo;
        else
            ant->right = novo;
    }
    return 1;
}

int pre_ordem(arvBin* raiz)
{
    if(raiz == NULL || (*raiz) == NULL)
        return 0;
    printf("%d\n", (*raiz)->dado);
    pre_ordem(&((*raiz)->left));
    pre_ordem(&((*raiz)->right));
    return 1;
}

int ordem(arvBin* raiz)
{
    if(raiz == NULL || (*raiz) == NULL)
        return 0;
    ordem(&((*raiz)->left));
    printf("%d\n", (*raiz)->dado);
    ordem(&((*raiz)->right));
    return 1;
}

int pos_ordem(arvBin* raiz)
{
    if(raiz == NULL || (*raiz) == NULL)
        return 0;
    ordem(&((*raiz)->left));
    ordem(&((*raiz)->right));
    printf("%d\n", (*raiz)->dado);
    return 1;
}
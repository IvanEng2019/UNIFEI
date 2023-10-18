#include<stdio.h>
#include<stdlib.h>

typedef struct no * pno;

typedef struct no{
    int chave;
    pno esq;
    pno dir;
    int alt;
} no;

pno criar_no(int ch){
    pno aux = (pno) malloc(sizeof(no));
    aux->chave = ch;
    aux->esq = NULL;
    aux->dir = NULL;
    aux->alt = 0;
    return aux;
}

void print_arvore(pno arvore){
    if(arvore == NULL) return;
    printf(" (%d, ", arvore->chave);
    print_arvore(arvore->esq);
    printf(", ");
    print_arvore(arvore->dir);
    printf(")");
    return;
}

int altura(pno n){
    if(n == NULL) return -1;
    return n->alt;
}

int fator_balanceamento(pno n){
    if(n == NULL) return 0;
    return altura(n->dir) - altura(n->esq);
}

int max(int x, int y){
    if(x>y) return x;
    return y;
}

pno rotacao_direita(pno n){
    pno aux = n->esq;
    n->esq = aux->dir;
    aux->dir = n;

    n->alt = max(altura(n->esq), altura(n->dir)) + 1;
    aux->alt = max(altura(aux->esq), altura(aux->dir)) + 1;

    return aux;
}

pno rotacao_esquerda(pno n){
    pno aux = n->dir;
    n->dir = aux->esq;
    aux->esq = n;

    n->alt = max(altura(n->esq), altura(n->dir)) + 1;
    aux->alt = max(altura(aux->esq), altura(aux->dir)) + 1;

    return aux;
}

pno rotacao_esquerda_direita(pno n){
    n->esq = rotacao_esquerda(n->esq);
    n = rotacao_direita(n);
    return n;
}

pno rotacao_direita_esquerda(pno n){
    n->dir = rotacao_direita(n->dir);
    n = rotacao_esquerda(n);
    return n;
}

pno insere(int c, pno arvore){
    if(arvore == NULL) return criar_no(c);
    if(arvore->chave == c){
        printf("Chave Existente!");
        return arvore;
    }
    if(arvore->chave > c){
        //Vamos adicionar na sub-árvore esquerda
        arvore->esq = insere(c, arvore->esq);
        if(fator_balanceamento(arvore) == -2){
            if(arvore->esq->chave > c) arvore = rotacao_direita(arvore);
            else arvore = rotacao_esquerda_direita(arvore);
        }
    }
    if(arvore->chave < c){
    //Vamos adicionar na sub-árvore direita
    arvore->dir = insere(c, arvore->dir);
        if(fator_balanceamento(arvore) == 2){
            if(arvore->dir->chave < c) arvore = rotacao_esquerda(arvore);
            else arvore = rotacao_direita_esquerda(arvore);
        }
    }
    arvore->alt = max(altura(arvore->dir), altura(arvore->esq)) + 1;
    return arvore;
}

int main(int argc, char *argv[]){
    pno arvore = NULL;

    arvore = insere(30, arvore); print_arvore(arvore); printf("\n");
    arvore = insere(20, arvore); print_arvore(arvore); printf("\n");
    arvore = insere(10, arvore); print_arvore(arvore); printf("\n");
    arvore = insere(40, arvore); print_arvore(arvore); printf("\n");
    arvore = insere(50, arvore); print_arvore(arvore); printf("\n");
    arvore = insere(15, arvore); print_arvore(arvore); printf("\n");
    arvore = insere(25, arvore); print_arvore(arvore); printf("\n");
    arvore = insere(27, arvore); print_arvore(arvore); printf("\n");
    arvore = insere(23, arvore); print_arvore(arvore); printf("\n");
    arvore = insere(22, arvore); print_arvore(arvore); printf("\n");
    arvore = insere(21, arvore); print_arvore(arvore); printf("\n");

    /*
    //Para teste
    arvore = criar_no(30);
    arvore->esq = criar_no(20);
    arvore->esq->esq = criar_no(15);
    arvore->esq->dir = criar_no(25);
    arvore->esq->dir->dir = criar_no(27);
    arvore->dir = criar_no(40);


    //Para teste
    arvore->alt = arvore->alt + 1;

    arvore->esq->esq = criar_no(10);
    arvore->esq->alt++;
    arvore->alt++;

    arvore = rotacao_esquerda_direita(arvore);*/

    print_arvore(arvore);
    printf("\n");

    return 0;

}

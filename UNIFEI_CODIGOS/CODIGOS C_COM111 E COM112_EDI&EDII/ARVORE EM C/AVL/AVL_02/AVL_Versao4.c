https://pt.slideshare.net/rodrigocasca/uml-criando-diagramas-eficientes

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no * pno;

typedef struct no{
    int chave;
    char nome[30];
    pno esq;
    pno dir;
    int alt;
} no;

pno criar_no(int ch, char nome[]){
    pno aux = (pno) malloc(sizeof(no));
    aux->chave = ch;
    strcpy(aux->nome,nome);
    aux->esq = NULL;
    aux->dir = NULL;
    aux->alt = 0;
    return aux;
}

/*void print_arvore(pno arvore){
    if(arvore == NULL) return;
    printf(" (%d, ", arvore->chave);
    print_arvore(arvore->esq);
    printf(",");
    print_arvore(arvore->dir);
    printf(")");
    return;
}*/
void print_arvore(pno arvore){
    if(arvore == NULL) return;
        printf(" ( %s, ", arvore->nome);
        print_arvore(arvore->esq);
        printf(",");
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
    n->alt=(max(altura(n->esq), altura(n->dir)) + 1);
    aux->alt=(max(altura(n->esq), altura(n->dir)) + 1);
    return aux;
}

pno rotacao_esquerda(pno n){
    pno aux = n->dir;
    n->dir = aux->esq;
    aux->esq = n;
    n->alt=(max(altura(n->esq), altura(n->dir)) + 1);
    aux->alt=(max(altura(n->esq), altura(n->dir)) + 1);
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

pno insere(int c, char nome[], pno arvore){
    if(arvore == NULL) return criar_no(c,nome);
    if(arvore->chave == c){
        printf("Chave Existente!");
        return arvore;
    }
    if(arvore->chave > c){
        //Vamos adicionar na sub-árvore esquerda
        arvore->esq = insere(c,nome, arvore->esq);
        if(fator_balanceamento(arvore) == -2){
            if(arvore->esq->chave > c)
                arvore = rotacao_direita(arvore);
            else
                arvore = rotacao_esquerda_direita(arvore);
        }
    }
    if(arvore->chave < c){
    //Vamos adicionar na sub-árvore direita
        arvore->dir = insere(c,nome,arvore->dir);
        if(fator_balanceamento(arvore) == 2){
            if(arvore->dir->chave < c)
                arvore = rotacao_esquerda(arvore);
            else
                arvore = rotacao_direita_esquerda(arvore);
        }
    }
    arvore->alt = max(altura(arvore->dir), altura(arvore->esq)) + 1;
    return arvore;
}
pno noMenor(pno n){
    pno no1= n;
    pno no2= n->esq;
    while(no2!=NULL){
        no1=no2;
        no2=no2->esq;
    }
    return no1;
}

pno deleta(pno arvore, pno anterior, int chave){
    if( arvore == NULL){
        return NULL;
    }
    if(arvore->chave > chave){
        if(deleta(arvore->esq,arvore,chave)==arvore){
            if(fator_balanceamento(arvore) == -2){
                if(altura(arvore->dir->esq)<= altura(arvore->dir->dir))
                  rotacao_direita(arvore);
                else
                  rotacao_direita_esquerda(arvore);
            }
        }
    }
    if(arvore->chave < chave){
        if(deleta(arvore->dir,arvore,chave)==arvore){
            if(fator_balanceamento(arvore) == 2){
                if(altura(arvore->esq->dir)<= altura(arvore->esq->esq))
                  rotacao_esquerda(arvore);
                else
                  rotacao_esquerda_direita(arvore);
            }
        }
    }
    if(arvore->chave == chave){
        pno velho= arvore;
        if((arvore->esq == NULL) || (arvore->dir == NULL)){
            if(arvore->esq !=NULL){//arvore->dir==NULL
                arvore=arvore->esq;
            }
            else{ //(arvore->esq===NULL && arvore->dir!=NULL)
                arvore=arvore->dir;
            }
            if(anterior->chave > velho->chave )
               anterior->esq=arvore;
            else
               anterior->dir=arvore;
            free(velho);
        }
        else{
           pno menor =  noMenor(arvore->dir);
           arvore->chave = menor->chave;
           strcpy(arvore->nome,menor->nome); //arvore->nome= menor->nome;
           if(deleta(arvore->dir,arvore,arvore->chave)==arvore){
               if(fator_balanceamento(arvore) == 2){
                    if(altura(arvore->esq->dir)<= altura(arvore->esq->esq))
                      rotacao_esquerda(arvore);
                    else
                      rotacao_esquerda_direita(arvore);
               }
          }
        }
      return anterior;
    }
    return arvore;
}

int main(int argc, char *argv[]){
    pno ant=NULL,arvore=NULL;
    int chave;
    char nome[100];

    for(int i=1; i<5; i++){
        printf("%d Chave:",i);
        scanf(" %d",&chave);
        printf("Nome:");
        scanf(" %[^\n]c",nome);
        //fflush(stdin);
        if(arvore==NULL)
             arvore=criar_no(chave,nome);
        else
            arvore=insere(chave,nome,arvore);
    }
    print_arvore(arvore);
    printf("\n");

    printf("Remover Chave:");
    scanf(" %d",&chave);
    ant= deleta(arvore,arvore,chave);
    if(ant!=NULL){
        printf(" \n\nAnterior: %d\n",ant->chave);;
        print_arvore(arvore);
        printf("\n");
    }
    else
        printf("Arvore vazia.\n");

    return 0;
}

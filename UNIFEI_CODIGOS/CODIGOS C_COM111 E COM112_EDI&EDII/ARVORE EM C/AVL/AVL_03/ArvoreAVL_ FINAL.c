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

void print_arvore_inOrdem(pno arvore){
    if(arvore == NULL)
        return;
    print_arvore_inOrdem(arvore->esq);
    printf("%d %s\n", arvore->chave,arvore->nome);
    print_arvore_inOrdem(arvore->dir);
    return;
}
int altura(pno n){
    if(n == NULL) return 0;
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

void alturaNova(pno n){
    n->alt=(max(altura(n->esq), altura(n->dir)) + 1);
}

pno rotacao_direita(pno n){
    pno aux = n->esq;
    n->esq = aux->dir;
    aux->dir = n;
    alturaNova(n);
    alturaNova(aux);
    return aux;
}

pno rotacao_esquerda(pno n){
    pno aux = n->dir;
    n->dir = aux->esq;
    aux->esq = n;
    alturaNova(n);
    alturaNova(aux);
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
        return arvore;
    }
    if( c < arvore->chave ){
        arvore->esq = insere(c,nome, arvore->esq);
        if(fator_balanceamento(arvore) == -2){
            if(arvore->esq->chave > c)
                arvore = rotacao_direita(arvore);
            else
                arvore = rotacao_esquerda_direita(arvore);
        }
    }
    if( c > arvore->chave ){
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

pno consultaNo(pno arvore, int chave){
    if(arvore == NULL)
        return NULL;
    if(arvore->chave == chave)
        return arvore;
    if(chave < arvore->chave)
       return consultaNo(arvore->esq,chave);
    else//(chave > arvore->chave){
       return consultaNo(arvore->dir,chave);
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
            if(arvore->esq !=NULL){
                arvore=arvore->esq;
            }
            else{
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
           strcpy(arvore->nome,menor->nome);
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
    anterior->alt = max(altura(arvore->dir), altura(arvore->esq)) - 1;
    return arvore;
}

int main(int argc, char *argv[]){
    pno no,arvore=NULL;
    int chave;
    char escolha, nome[100];
    do{
        escolha =  getchar();
        if(escolha == 'i'){
            scanf(" %d %[^\n]c%*c",&chave, nome);
            arvore=insere(chave,nome,arvore);
        }
        if(escolha == 'c'){
           scanf("%d",&chave);
           no=consultaNo(arvore,chave);
           if(no!=NULL)
             printf("%d %s\n",chave,no->nome);
        }
        if(escolha == 'p'){
           print_arvore_inOrdem(arvore);
        }
        if(escolha == 'r'){
          scanf("%d",&chave);
          deleta(arvore, arvore,chave);
        }
        if(escolha == 'v'){
          if(fator_balanceamento(arvore)== -1 || fator_balanceamento(arvore) == 0 || fator_balanceamento(arvore) == 1 )
             printf("SIM\n");
          else
             printf("NAO\n");
        }
    }while(escolha != 'x');
    return 0;
}

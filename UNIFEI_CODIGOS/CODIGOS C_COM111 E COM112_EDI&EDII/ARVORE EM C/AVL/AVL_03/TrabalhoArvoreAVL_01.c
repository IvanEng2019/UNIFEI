/*****************************************************************************************************************************************************************************
 Nome: Ivan Leoni Vilas Boas
 Matricula: 2018009073
 Professor: Hokama
 Descrição: Trabalho de arvore AVL
 Graduação:Sistemas de Informação
 Curso: Estrutura de dados II
 UNIFEI
 Data: 28/05/2019 a 01/06/2019

Lembretes importantes:
0- Arvore  insere o menor a (minha) esquerda e o maior a direita
I- Uma árvore AVL é uma árvore de pesquisa binária que é de altura balanceada : para cada nó, as alturas das subárvores esquerda e direita deste nó diferem por no máximo 1.
II- O fator de balanceamento da arvore AVL de cada nó é a altura da subárvore a direita menos a altura da subárvore a esquerda.
III- Quando a árvore torna-se desbalanceada é necessário aplicar transformações denominadas de Rotação, que façam a árvore voltar a ficar balanceada.
IV- Rotação à esquerda é feita quando a sub-árvore à direita é maior (FB positivo) e a Rotação à direita é feita quando a sub-árvore à esquerda é maior (FB negativo).
*******************************************************************************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10000

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
    printf(" %d %s \n", arvore->chave,arvore->nome);
    print_arvore_inOrdem(arvore->dir);
    return;
}
/*void print_arvore_preOrdem(pno arvore){
    if(arvore == NULL)
        return;
    printf(" %d %s \n", arvore->chave,arvore->nome);
    print_arvore_preOrdem(arvore->esq);
    print_arvore_preOrdem(arvore->dir);
    return;
}
void print_arvore_posOrdem(pno arvore){
    if(arvore == NULL)
        return;
    print_arvore_posOrdem(arvore->esq);
    print_arvore_posOrdem(arvore->dir);
    printf(" %d %s \n", arvore->chave,arvore->nome);
    return;
}*/
int altura(pno n){
    if(n == NULL) return -1;
    return n->alt;
}

int fator_balanceamento(pno n){
    if(n == NULL) return -1000;
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
    if( c < arvore->chave ){
        //Vamos adicionar na sub-árvore esquerda
        arvore->esq = insere(c,nome, arvore->esq);
        if(fator_balanceamento(arvore) == -2){
            if(arvore->esq->chave > c)
                arvore = rotacao_direita(arvore);
            else
                arvore = rotacao_esquerda_direita(arvore);
        }
    }
    if( c > arvore->chave ){
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

pno consulta(pno arvore, int chave){
    if(arvore == NULL || arvore->chave == chave){
        return arvore;
    }
    if(chave < arvore->chave)
       return consulta(arvore->esq,chave);
    if(chave > arvore->chave)
       return consulta(arvore->dir,chave);
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
    pno no,arvore=NULL;
    int chave,i=1;
    char escolha, nome[100];

   // printf("Entre com a chave  e nome para inserir na arvore AVL\n << zero para parar de inserir>>\n\n");
        do{
            printf("%d ",i);
            scanf(" %d %[^\n]c%*c",&chave, nome);
            if(chave == 0)
                break;
            if(arvore==NULL)
                 arvore=criar_no(chave,nome);
            else
                arvore=insere(chave,nome,arvore);
            i++;
        }while(i<=MAX);
        do{
            escolha =  getchar(); //getc(stdin);
            if(escolha == 'c'){// consulta chave e retorna nada ou imprime chave e registro
               scanf("%d",&chave);
               no=consulta(arvore, chave);
               if(no!=NULL){
                 printf(" %d %s\n", chave, no->nome);
               }
            }
            if(escolha == 'p'){////imprimir em ordem de chave
               print_arvore_inOrdem(arvore);
            }
            if(escolha == 'r'){//para remover o registro
              scanf("%d",&chave);
              deleta(arvore, arvore,chave);
            }
            if(escolha == 'v'){//para verificar se esta balanciada (1,-1,0) sim ou nao
               int fb= fator_balanceamento(arvore);
               if(fb<-1 && fb>1)
                  printf("Não\n");
               else
                 printf("Sim\n");
            }
        }while(escolha != 'x');
    return 0;
}

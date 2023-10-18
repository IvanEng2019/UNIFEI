#include <stdio.h>
#include <stdlib.h>

#include "arvoreRB.h"

TreeRB* createTreeRB(){
    TreeRB *arv = (TreeRB*)malloc(sizeof(TreeRB));
    arv->root = NULL;
    return arv;
}

NodoRB* alocaNoRB(int val){
    NodoRB *no = (NodoRB*)malloc(sizeof(NodoRB));
    if(no){
        no->val = val;
        no->cor = RED;
        no->sad = NULL;
        no->sae = NULL;
        no->pai = NULL;
        return no;
    }else{
        printf("Memory fail - error 493\n");
        exit(-1);
    }
}

void rotateLeft(NodoRB *no,TreeRB *arv){
    NodoRB *filho = no->sad;
    
    no->sad = filho->sae;
    if(filho->sae)
        filho->sae->pai = no;
    filho->sae = no;
    if(!no->pai){
        arv->root = filho;
        filho->pai = NULL;
    }else{
        filho->pai = no->pai;
        if(filho->pai->val <= filho->val)
            filho->pai->sad = filho;
        else
            filho->pai->sae = filho;
    }    
    no->pai = filho;
}

void rotateRigth(NodoRB *no,TreeRB *arv){
    NodoRB *filho = no->sae;

    no->sae = filho->sad;
    if(filho->sad)
        filho->sad->pai = no;
    filho->sad = no;
    if(!no->pai){
        arv->root = filho;
        filho->pai = NULL;
    }else{
        filho->pai = no->pai;
        if(filho->pai->val <= filho->val)
            filho->pai->sad = filho;
        else
            filho->pai->sae = filho;
    }
    no->pai = filho;
}

int color(NodoRB* no){
    if(!no){
        return BLACK;
    }else{
        return no->cor;
    }
}

void balanceiaRB(NodoRB *no,TreeRB *arv){
    if(no){
        NodoRB *avo = no->pai->pai; // avo
        NodoRB *pai = no->pai; // pai
        NodoRB *tio = NULL; // tio

        //Define o avo
        if(avo)
            if(avo->sad != pai)
                tio = avo->sad;
            else if(avo->sae != pai)
                tio = avo->sae;

        if(color(tio) == RED){// Caso o tio for vermelho
            tio->cor = BLACK;
            pai->cor = BLACK;
            avo->cor = RED;
            if(avo == arv->root)
                avo->cor = BLACK;
            else if(avo->pai->cor == RED)
                balanceiaRB(avo,arv);
        }else if(color(tio) == BLACK){// Caso o tio for preto
            if(avo->sad == pai){
                if(pai->sae == no){
                    rotateRigth(pai,arv);
                    rotateLeft(avo,arv);
                    no->cor = BLACK;
                }else if(pai->sad == no){
                    rotateLeft(avo,arv);
                    pai->cor = BLACK;
                }
            }else if(avo->sae == pai){
                if(pai->sad == no){
                    rotateLeft(pai,arv);
                    rotateRigth(avo,arv);
                    no->cor = BLACK;
                }else if(pai->sae == no){
                    rotateRigth(avo,arv);
                    pai->cor = BLACK;
                }
            }
            avo->cor = RED;
        }
    }
}

void insertNodeRB(TreeRB *arv, int val){
    if(!arv->root){
        NodoRB *no = alocaNoRB(val);
        arv->root = no;
        no->cor = BLACK;
    }else{
        NodoRB *atual = arv->root;
        NodoRB *pai = arv->root;
        NodoRB *newNo = alocaNoRB(val);

        /* Insercao */
        while(atual != NULL){
            if(atual->val <= val){
                pai = atual;
                atual = atual->sad;
            }else{
                pai = atual;
                atual = atual->sae;
            }
        }
        newNo->pai = pai;
        if(val >= pai->val){
            pai->sad = newNo;
        }
        else{
            pai->sae = newNo;
        }

        if(newNo->pai->cor == RED)
            balanceiaRB(newNo,arv);
    }
}

NodoRB* searchNodeRB(NodoRB *no, int val){
    NodoRB* aux = no;
    while(aux != NULL){
        if(aux->val > val){
            aux = aux->sae;
        }else if(aux->val < val){
            aux = aux->sad;
        }else{
            break;
        }
    }
    return aux;
}

//Deleta um node
void deleteNodeRB(TreeRB *arv,int val){
    NodoRB *no = searchNodeRB(arv->root,val);
    
    if(!no){
        printf("Elemento nao encontrado!\n");
    }else{
        NodoRB *pai = no->pai;
        NodoRB *sucessor = no->sad;
        
        NodoRB *irmao;
        
            
        if(sucessor){
            sucessor->pai = no;
            while(sucessor->sae != NULL){
                sucessor->pai = sucessor;
                sucessor = sucessor->sae;
            }
        }
        
        if(pai)
            if(pai->sad == no){
                irmao = pai->sae;
            }else{
                irmao = pai->sad;
            }
            

        if(!no->sad && !no->sae && color(no) == RED){//Se o no for uma folha vermelha
            if(pai->sad == no){
                pai->sad = NULL;
            }else{
                pai->sae = NULL;
            }
            free(no);
        }else if(color(sucessor) == RED){//se o sucessor for vermelho
            if(sucessor->pai->sad == sucessor){//aqui
                sucessor->pai->sad = sucessor->sad;
            }else{
                sucessor->pai->sae = sucessor->sad;
            }
            no->val = sucessor->val;
            free(sucessor);
            //Se o no for preto e tiver apenas um filho vermelho
        }else if(color(no) == BLACK && ((!no->sae && color(no->sad) == RED) || (!no->sad && color(no->sae) == RED))){
            if(pai){
                if(pai->sad == no){
                    if(no->sad){
                        pai->sad = no->sad;
                        no->sad->pai = pai;
                    }else{
                        pai->sad = no->sae;
                        no->sae->pai = pai;
                    }
                    pai->sad->cor = BLACK;
                }else{
                    if(no->sad){
                        pai->sae = no->sad;
                        no->sad->pai = pai;
                    }
                    else{
                        pai->sae = no->sae;
                        no->sae->pai = pai;
                    }
                    pai->sae->cor = BLACK;
                }
            }else{
                if(no->sad){
                    arv->root = no->sad;
                }else{
                    arv->root = no->sae;
                }
                                
                arv->root->pai = NULL;
            }
            free(no);
        }else{
            if(sucessor){
                int aux = no->val;
                no->val = sucessor->val;
                sucessor->val = aux;
                NodoRB *aux2 = no;
                no = sucessor;
                sucessor = aux2;
                pai = no->pai;
                if(pai->sad == no){
                    irmao = pai->sae;
                }else{
                    irmao = pai->sad;
                }
            }
            if(color(pai) == RED && color(irmao) == BLACK){
                pai->cor = BLACK;
                irmao->cor = RED;
                if(pai->sad == no){
                    pai->sad = NULL;
                }else{
                    pai->sae = NULL;
                }
            }else if(color(irmao) == BLACK){
                if(color(irmao->sae) == RED){
                    if(pai->sad == no){
                        pai->sad = NULL;
                        rotateRigth(pai,arv);
                        irmao->cor = RED;
                    }else{
                        pai->sae = NULL;
                        rotateRigth(irmao,arv);
                        rotateLeft(pai,arv);
                        irmao->cor = BLACK;
                    }
                    pai->cor = BLACK;
                    irmao->sae->cor = BLACK;
                }else if(color(irmao->sad) == RED){
                    if(pai->sae == no){
                        pai->sae = NULL;
                        rotateLeft(pai,arv);
                        irmao->cor = RED;
                    }else{
                        pai->sad = NULL;
                        rotateLeft(irmao,arv);
                        rotateRigth(pai,arv);
                        irmao->cor = BLACK;
                    }
                    pai->cor = BLACK;
                    if(irmao->sad)
                            irmao->sad->cor = BLACK;
                }else if(color(irmao->sae) == BLACK && color(irmao->sae) == BLACK){
                    if(arv->root == no && !no->sad && !no->sae){
                        arv->root = NULL;
                    }else{
                        if(pai->sad == no){
                            pai->sad = NULL;
                        }else{
                            pai->sae = NULL;
                        }
                        irmao->cor = RED;
                        pai->cor = BLACK;
                    }
                }
                free(no);
            }else{
                if(pai->sad == no){
                    pai->sad = NULL;
                    if(irmao->sad)
                        irmao->sad->cor = RED;
                    rotateRigth(pai,arv);
                }else{
                    pai->sae = NULL;
                    if(irmao->sae)
                        irmao->sae->cor = RED;
                    rotateLeft(pai,arv);
                }
                
                free(no);
            }
        }
        
        if(arv->root)
            if(arv->root->cor == RED)
               arv->root->cor = BLACK;
    }
}

void printArvoreRB(NodoRB *no){
    if(no!=NULL){
        if(no->cor == RED)
            printf("Red - Valor %d\n",no->val); 
        else
            printf("Black - Valor %d\n",no->val);
        printArvoreRB(no->sae);
        printArvoreRB(no->sad);
    }
}

void printRB(TreeRB *arv){
    if(arv->root){
        printf("\nArvore Rubro-Negra: \n");
        printArvoreRB(arv->root);
        printf("\n");
    }else{
        printf("Arvore vazia!\n");
    }
}
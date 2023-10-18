#include <stdio.h>
#include <stdlib.h>

#include "arvore234.h"
#include "arvoreRB.h"
#include "convert.h"

void convert234intoRB(TreeRB *ArvRB,Node234 *no234,Node234 *noPai234,NodoRB *noPaiRB){
    if(no234){
        NodoRB *noRB;
        if(no234->elementos == 1){
            noRB = alocaNoRB(no234->val[0]);
            noRB->cor = BLACK;
        }else if(no234->elementos == 2){
            noRB = alocaNoRB(no234->val[1]);
            NodoRB *no2RB = alocaNoRB(no234->val[0]);

            noRB->cor = BLACK; 
            no2RB->cor = RED;
            no2RB->pai = noRB;
            noRB->sae = no2RB;
            
            
        }else if(no234->elementos == 3){
            noRB = alocaNoRB(no234->val[1]);
            NodoRB *no2RB = alocaNoRB(no234->val[0]);
            NodoRB *no3RB = alocaNoRB(no234->val[2]);

            noRB->cor = BLACK; 
            no2RB->cor = RED;
            no3RB->cor = RED;
            
            no2RB->pai = noRB;
            no3RB->pai = noRB;
            
            noRB->sae = no2RB;
            noRB->sad = no3RB;
        }
        
        if(!ArvRB->root){
            ArvRB->root = noRB;
            noRB->pai = NULL;
        }else{
            if(noPai234->elementos == 1){
                if(noRB->val < noPaiRB->val){
                    noPaiRB->sae = noRB;
                }else{
                    noPaiRB->sad = noRB;
                }
                noRB->pai = noPaiRB;
            }else if(noPai234->elementos == 2){
                if(noPaiRB->val > noRB->val){
                    if(noRB->val < noPaiRB->sae->val){
                        noPaiRB->sae->sae = noRB;
                    }else{
                        noPaiRB->sae->sad = noRB;
                    }
                    noRB->pai = noPaiRB->sae;
                }else{
                    noPaiRB->sad = noRB;
                    noRB->pai = noPaiRB->sad;
                }
            }else if(noPai234->elementos == 3){
                if(noPaiRB->val > noRB->val){
                    if(noRB->val < noPaiRB->sae->val){
                        noPaiRB->sae->sae = noRB;
                    }else{
                        noPaiRB->sae->sad = noRB;
                    }
                    noRB->pai = noPaiRB->sae;
                }else{
                    if(noRB->val < noPaiRB->sad->val){
                        noPaiRB->sad->sae = noRB;
                    }else{
                        noPaiRB->sad->sad = noRB;
                    }
                    noRB->pai = noPaiRB->sad;
                }
            }
        }
        
        noPai234 = no234;
        noPaiRB = noRB;

        convert234intoRB(ArvRB,no234->filho[0],noPai234,noPaiRB);
        convert234intoRB(ArvRB,no234->filho[1],noPai234,noPaiRB);
        convert234intoRB(ArvRB,no234->filho[2],noPai234,noPaiRB);
        convert234intoRB(ArvRB,no234->filho[3],noPai234,noPaiRB);
    }
    
}

TreeRB* convertToRBTree(Tree234 *Arv234){
    TreeRB *ArvoreRB = createTreeRB();
        
    convert234intoRB(ArvoreRB,Arv234->root,NULL,NULL);
    
    return ArvoreRB;
}


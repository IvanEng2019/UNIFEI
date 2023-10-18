#include <stdio.h>
#include <stdlib.h>

#include "arvore234.h"

/*Cria uma arvore*/
Tree234* createTree234(){
    Tree234 *arv = (Tree234*)malloc(sizeof(Tree234));
    arv->root = NULL;
    return arv;
}

/*Cria uma pagina*/
Node234* createNode234(){
    int i;
    Node234 *nodo = (Node234*)malloc(sizeof(Node234));
    for(i=0;i<m-1;i++){
        nodo->val[i] = -1;
    }
    nodo->elementos = 0;
    nodo->pai = NULL;
}

/*Acha a pagina desejada para se inserir*/
Node234* searchNode234(Node234 *no, int val){
    int pos;
    Node234* aux = no;
    
    while(1){
        if(val < aux->val[0]){
            pos = 0;
        }else if(aux->val[0] <= val && (val < aux->val[1] || aux->val[1] == -1)){
            pos = 1;
        }else if(aux->val[1] <= val && (val < aux->val[2] || aux->val[2] == -1)){
            pos = 2;
        }else{
            pos = 3;
        }
        
        if(aux->filho[pos]){
            aux = aux->filho[pos];
        }else{
            break;
        }
    }
    
    return aux;
}

/*Insere a chave na pagina e retorna em qual posicao ele foi inserido*/
int insere234(Node234 *no, int val){
    int i = no->elementos;
    for(;i>=0;i--){
        if(val < no->val[i-1]){
            no->val[i] = no->val[i-1];
        }else{
            break;
        }
    }
    
    no->val[i] = val;
    no->elementos++;
    return i;
}

/*Organiza uma pagina*/
void organizaNodo234(Node234 *no){
    int i;
    for(i=2;i>=0;i--){
        if(no->val[i] != -1 && no->val[i-1] == -1){
            no->val[i-1] = no->val[i];
            no->val[i] = -1;
        }
    }
}

/*Funcao que realiza o split*/
 void split234(Tree234 *arv,Node234 *no, int val){
     if(no->elementos >= 3){
         if(no->pai){
            if(no->pai->elementos >= 3)
               split234(arv,no->pai,no->val[1]);
            Node234 *n1 = createNode234();

            int pos = insere234(no->pai,val); 
            n1->val[0] = no->val[0];
            n1->elementos = 1;
            n1->pai = no->pai;

            no->val[0] = -1;
            no->val[1] = -1;
            no->elementos = 1;
            organizaNodo234(no);
            
            if(pos <= 0)
                no->pai->filho[pos+3] = no->pai->filho[pos+2];
            if(pos <= 1)
                no->pai->filho[pos+2] = no->pai->filho[pos+1];
            if(pos <= 2)
                no->pai->filho[pos+1] = no;
            no->pai->filho[pos] = n1;
            
            n1->filho[0] = no->filho[0];
            no->filho[0]->pai = n1;
            no->filho[1]->pai = n1;
            n1->filho[1] = no->filho[1];
            no->filho[0] = no->filho[2];
            no->filho[1] = no->filho[3];
            no->filho[2] = NULL;
            no->filho[3] = NULL;
         }else{
            Node234 *n1 = createNode234();
            Node234 *n2 = createNode234();
                 
            n1->val[0] = no->val[1];
            no->val[1] = -1;
            n1->elementos++;
            
            n2->val[0] = no->val[2];
            no->val[2] = -1;
            no->elementos = 1;
            n2->elementos++;
            
            n1->filho[0] = no;
            n1->filho[1] = n2;
            
            no->pai = n1;
            n2->pai = n1;
            
            n2->filho[0] = no->filho[2];
            n2->filho[1] = no->filho[3];
            n2->filho[0]->pai = n2;
            n2->filho[1]->pai = n2;
            no->filho[2] = NULL;
            no->filho[3] = NULL;
            
            arv->root = n1;
         }
     }else{
         insere234(no,val);
     }
 }

 
 /*Funcao que insere uma chave ou pagina na arvore*/
void insertNode234(Tree234 *arv,int val){
    if(!arv->root){//primeiro elemento da arvore
        Node234* no = createNode234();
        arv->root = no;
        no->val[0] = val;
        no->elementos++;
        no->pai = NULL;
    }else{
        Node234* no = searchNode234(arv->root,val);
        if(no->elementos < m-1){//No folha
            insere234(no,val);
        }else{
            if(no == arv->root){//Se for o root
                Node234* no1 = createNode234();
                Node234 *no2 = createNode234();
                
                no1->val[0] = no->val[0];
                no2->val[0] = no->val[2];
                no1->elementos++;
                no2->elementos++;
                no1->pai = no;
                no2->pai = no;
                
                no->val[0] = no->val[1];
                no->val[1] = -1;
                no->val[2] = -1;
                no->filho[0] = no1;
                no->filho[1] = no2;
                no->elementos = 1;
                
                no = searchNode234(arv->root,val);
                insere234(no,val);
            }else{
                if(no->pai->elementos < 3){//Caso o pai nao esteje cheio
                    Node234 *no1 = createNode234();                                     
                    int pos = insere234(no->pai,no->val[1]);

                    no1->val[0] = no->val[0];
                    no1->elementos = 1;
                    no1->pai = no->pai;
                    
                    no->val[0] = -1;
                    no->val[1] = -1;
                    no->elementos = 1;
                    organizaNodo234(no);
                    
                    if(pos <= 0)
                        no->pai->filho[pos+3] = no->pai->filho[pos+2];
                    if(pos <= 1)
                        no->pai->filho[pos+2] = no->pai->filho[pos+1];
                    if(pos <= 2)
                        no->pai->filho[pos+1] = no;
                    no->pai->filho[pos] = no1;
                    
                    no = searchNode234(arv->root,val);
                    insere234(no,val);
                }else{//Caso o pai esteje cheio
                    split234(arv,no->pai,no->pai->val[1]);
                    insertNode234(arv,val);
                }
            }
            
        }
    }    
}

/*Retorna a posicao da chave desejada*/
int getPosChave(Node234 *no,int val){
    int i;
    for(i=0;i<3;i++){
        if(val == no->val[i])
            return i;
    }
    return -1;
}

/*Retorna a maior posicao do maior elemento da pagina*/
int getPosMaior(Node234 *no){
    int i;
    int maior = 0;
    for(i=1;i<3;i++){
        if(no->val[maior] < no->val[i]){
            maior = i; 
        }
    }
    return maior;
}

/*Acha a chave a ser deletada*/
Node234* searchNode234Delete(Node234 *no, int val){
    int pos,i;
    Node234* aux = no;
    
    while(1){
        pos = getPosChave(aux,val);
        if(pos != -1)
            if(val == aux->val[pos])
                return aux;
        
        if(val < aux->val[0]){
            pos = 0;
        }else if(aux->val[0] <= val && (val < aux->val[1] || aux->val[1] == -1)){
            pos = 1;
        }else if(aux->val[1] <= val && (val < aux->val[2] || aux->val[2] == -1)){
            pos = 2;
        }else{
            pos = 3;
        }
        
        if(aux->filho[pos]){
            aux = aux->filho[pos];
        }else{
            return NULL;
        }
    }
    
}

/*Realiza a juncao das duas paginas*/
void merge(Tree234 *arv,Node234 *no,int val){
    int i,pos;
    if(no->pai && no->pai->elementos > 1){
        for(i=0;i<4;i++){
            if(no->pai->filho[i] == no){
                pos = i;
            }
        }

        if(pos != 3){
            insere234(no->pai->filho[pos+1],no->pai->val[pos]);
            no->pai->val[pos] = -1;
            no->pai->elementos--;
            no->pai->filho[pos] = NULL;
            organizaNodo234(no->pai);
            free(no->pai->filho[pos]);

            for(i=pos;i<3;i++){
                no->pai->filho[i] = no->pai->filho[i+1];
            }
        }else{
            insere234(no->pai->filho[pos-1],no->pai->val[pos-1]);
            no->pai->val[pos-1] = -1;
            no->pai->elementos--;
            no->pai->filho[pos] = NULL;
            free(no->pai->filho[pos]);
        }
    }
}

/*funcao que deleta uma chave*/
void deleteNode234(Tree234 *arv,int val){
    Node234 *no = searchNode234Delete(arv->root,val);
    
    if(!no){
        printf("Chave nao encontrada!\n");
    }else{
        int pos = getPosChave(no,val);
        Node234 *sucessor = no->filho[pos];
        Node234 *pai = no->pai;
        if(sucessor){//Substituicao
            while(sucessor->filho[getPosMaior(sucessor)+1]){            
                sucessor = sucessor->filho[getPosMaior(sucessor)+1]; 
            }
            no->val[getPosChave(no,val)] = sucessor->val[getPosMaior(sucessor)];
            if(sucessor->elementos > 1){
                sucessor->val[getPosMaior(sucessor)] = -1;
                sucessor->elementos--;
                organizaNodo234(sucessor);
                
            }else{
                sucessor->val[0] = val;
                organizaNodo234(sucessor);
                no = sucessor;
                pai = sucessor->pai;
                sucessor = NULL;
            }
        }
        if(!sucessor){
            int pos = getPosChave(no,val);
            if(no->elementos > 1){//caso o no seja folha e o numero de chavez > 1
                no->val[pos] = -1;
                no->elementos--;
                organizaNodo234(no);
            }else if(pai){//Caso o irmao possa emprestar
                if(pai->filho[0] == no){
                    if(pai->filho[1]->elementos > 1){
                        int aux = pai->val[0];
                        pai->val[0] = pai->filho[1]->val[0];
                        pai->filho[1]->val[0] = -1;
                        pai->filho[1]->elementos--;
                        organizaNodo234(pai->filho[1]);
                        no->val[0] = aux;
                    }else{//Juntar duas paginas
                        merge(arv,no,no->val[getPosChave(no,val)]);
                    }
                }else if(pai->filho[1] == no){
                    if(pai->filho[0]->elementos > 1){
                        int aux = pai->val[0];
                        pai->val[0] = pai->filho[0]->val[getPosMaior(pai->filho[0])];
                        pai->filho[0]->val[getPosMaior(pai->filho[0])] = -1;
                        pai->filho[0]->elementos--;
                        no->val[0] = aux;  
                    }else if(pai->filho[2]){
                        if(pai->filho[2]->elementos > 1){
                            int aux = pai->val[1];
                            pai->val[1] = pai->filho[2]->val[0];
                            pai->filho[2]->val[0] = -1;
                            pai->filho[2]->elementos--;
                            organizaNodo234(pai->filho[2]);
                            no->val[0] = aux;
                        }else{//Juntar duas paginas
                            merge(arv,no,no->val[getPosChave(no,val)]);
                        }
                    }
                }else if(pai->filho[2] == no){
                    if(pai->filho[1]->elementos > 1){
                        int aux = pai->val[1];
                        pai->val[1] = pai->filho[1]->val[getPosMaior(pai->filho[1])];
                        pai->filho[1]->val[getPosMaior(pai->filho[1])] = -1;
                        pai->filho[1]->elementos--;
                        no->val[0] = aux;  
                    }else if(pai->filho[3]){
                        if(pai->filho[3]->elementos > 1){
                            int aux = pai->val[2];
                            pai->val[2] = pai->filho[3]->val[0];
                            pai->filho[3]->val[0] = -1;
                            pai->filho[3]->elementos--;
                            organizaNodo234(pai->filho[3]);
                            no->val[0] = aux;
                        }else{//Juntar duas paginas
                            merge(arv,no,no->val[getPosChave(no,val)]);
                        }
                    }
                }else if(pai->filho[3] == no){
                    if(pai->filho[2]->elementos > 1){
                        int aux = pai->val[2];
                        pai->val[2] = pai->filho[2]->val[getPosMaior(pai->filho[2])];
                        pai->filho[2]->val[getPosMaior(pai->filho[2])] = -1;
                        pai->filho[2]->elementos--;
                        no->val[0] = aux;
                    }else{//Juntar duas paginas
                        merge(arv,no,no->val[getPosChave(no,val)]);
                    }
                }
            }
         }
    }
}

/*Printa a arvore 234*/
void printArvore234(Node234 *no){
    if(no){
        int i;
        for(i=0;i<3;i++){
            if(no->val[i] != -1)
                printf("| %d ",no->val[i]);
        }
        printf("|\n");
        printArvore234(no->filho[0]);
        printArvore234(no->filho[1]);
        printArvore234(no->filho[2]);
        printArvore234(no->filho[3]);
    }
}

/*Funcao que chama a print arvore*/
void print234(Tree234 *Arv){
    if(Arv->root){
        printf("\nArvore 2-3-4: \n");
        printArvore234(Arv->root);
        printf("\n");
    }else
        printf("Arvore Vazia\n");
}
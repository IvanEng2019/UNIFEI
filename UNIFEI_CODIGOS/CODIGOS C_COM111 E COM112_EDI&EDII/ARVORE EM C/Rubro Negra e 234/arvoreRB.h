#ifndef ARVORERB_H
#define ARVORERB_H

#define RED 1
#define BLACK 0

typedef struct treeRB TreeRB;
typedef struct nodoRB NodoRB;

struct treeRB{
    NodoRB *root;
};

struct nodoRB{
    int val;
    int cor;
    struct nodoRB* sad;
    struct nodoRB* sae;
    struct nodoRB* pai;
};

void insertNodeRB(TreeRB *arv, int val);
void deleteNodeRB(TreeRB *arv,int val);
void printRB(TreeRB *arv);
TreeRB* createTreeRB();
NodoRB* alocaNoRB(int val);

#endif /* ARVORERB_H */


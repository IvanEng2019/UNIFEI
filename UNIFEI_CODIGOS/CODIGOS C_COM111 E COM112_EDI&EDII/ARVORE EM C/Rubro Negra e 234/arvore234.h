#ifndef ARVORE234_H
#define ARVORE234_H

#define m 4

typedef struct tree234 Tree234;
typedef struct node234 Node234;

struct node234{
    int val[m-1];
    Node234* pai;
    Node234* filho[m];
    int elementos;
};

struct tree234{
    Node234 *root;
};

Tree234* createTree234();
void insertNode234(Tree234 *arv,int val);
void print234(Tree234 *Arv);
void deleteNode234(Tree234 *arv,int val);

#endif /* ARVORE234_H */



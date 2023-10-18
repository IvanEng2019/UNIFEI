
typedef struct senha{
    int pref;
    int cod;
    struct senha *prox;
}Sen;

typedef struct f{
    Sen *primeiro;
    Sen *ult;
}FilaM;

FilaM* criaFilaMesa();
void insereSenhaMesa(FilaM *filaMesa,int pref);
int chamaSenhaMesa(FilaM *filaMesa,FilaM *dest,int del);
void inserirSenha(Sen *sInseir, FilaM *mesaDest);
void liberaFilaMesa(FilaM *filaMesa);
void imprimeFilaMesa();

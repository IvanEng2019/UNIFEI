typedef struct Senha{
    int pref;
    int codigo;
    struct Senha* prox;
}Senha;

typedef struct{
    Senha *primeiro;
    Senha *ultimo;
}Fila;

Fila* criaFila();
void insereSenha(Fila *filaa,int preferencial);
int chamaSenha(Fila * filaa, Fila * filaaDestino, int apagar);
void insereEstaSenha(Senha * senhaInserida, Fila * filaaDestino);
void liberaFila( Fila * filaa);
void imprimeFila();

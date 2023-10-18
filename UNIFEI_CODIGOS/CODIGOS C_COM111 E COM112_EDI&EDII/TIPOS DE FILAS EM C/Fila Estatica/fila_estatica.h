
// TAD para Fila Estática

#ifndef _FILA_ESTATICA
#define _FILA_ESTATICA

typedef struct fila Fila;

// funções para alocar e desalocar memória
Fila* criar_fila();

int liberar_fila(Fila *fi);

int tamanho_fila(Fila *fi);

int fila_vazia(Fila *fi);

int fila_cheia(Fila *fi);

int inserir_fila(Fila *fi, int dado);

int remover_fila(Fila *fi);

int buscar_fila(Fila *fi);

int imprimir_lista(Fila *fi);


#endif


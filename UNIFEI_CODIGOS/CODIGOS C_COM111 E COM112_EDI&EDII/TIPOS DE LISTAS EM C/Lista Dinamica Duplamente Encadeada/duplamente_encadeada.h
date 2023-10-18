#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

typedef struct elemento* Lista;

// fun��es para alocar e desalocar mem�ria
Lista* criar_lista();
int liberar_lista(Lista *li);

// fun��es para obter informa��es da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// fun��es para inser��o de elementos da lista
int inserir_lista_inicio(Lista *li, int dado);
int inserir_lista_final(Lista *li, int dado);
int inserir_lista_ordenada(Lista *li, int dado);

// fun��es para remo��o de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int dado);

// fun��es para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos, int *dado);
int buscar_lista_dado(Lista *li, int dado, int *pos);

int imprimir_lista(Lista *li);

#endif




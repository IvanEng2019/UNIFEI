
// TAD para Lista Din�mica Encadeada Circular

#ifndef _LISTA_DEC
#define _LISTA_DEC

typedef struct produto Produto;
typedef struct elemento* Lista;

// fun��o para criar produto
int criar_produto(Produto **produto);

// fun��es para alocar e desalocar mem�ria
Lista* criar_lista();
int liberar_lista(Lista *li);
Lista *concatena(Lista *li, Lista *li2);
int Troca_El2_Circular(Lista *li,int p1,int p2);

// fun��es para obter informa��es da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// fun��es para inser��o de elementos da lista
int inserir_lista_inicio(Lista *li, Produto *produto);
int inserir_lista_final(Lista *li, Produto *produto);
int inserir_lista_ordenada(Lista *li, Produto *produto);

// fun��es para remo��o de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int codigo);
int Remover_n_ultimos_lista_Circular(Lista *li,int n);

// fun��es para buscar elementos na lista
Produto *buscar_lista_posicao(Lista *li, int pos);
Produto *buscar_lista_dado(Lista *li, int codigo);

int imprimir_lista(Lista *li);
int imprimir_produto(Produto *produto);

#endif

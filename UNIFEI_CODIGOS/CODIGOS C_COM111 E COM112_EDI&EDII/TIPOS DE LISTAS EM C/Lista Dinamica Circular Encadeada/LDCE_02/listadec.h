
// TAD para Lista Dinâmica Encadeada Circular

#ifndef _LISTA_DEC
#define _LISTA_DEC

typedef struct produto Produto;
typedef struct elemento* Lista;

// função para criar produto
int criar_produto(Produto **produto);

// funções para alocar e desalocar memória
Lista* criar_lista();
int liberar_lista(Lista *li);
Lista *concatena(Lista *li, Lista *li2);
int Troca_El2_Circular(Lista *li,int p1,int p2);

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, Produto *produto);
int inserir_lista_final(Lista *li, Produto *produto);
int inserir_lista_ordenada(Lista *li, Produto *produto);

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int codigo);
int Remover_n_ultimos_lista_Circular(Lista *li,int n);

// funções para buscar elementos na lista
Produto *buscar_lista_posicao(Lista *li, int pos);
Produto *buscar_lista_dado(Lista *li, int codigo);

int imprimir_lista(Lista *li);
int imprimir_produto(Produto *produto);

#endif

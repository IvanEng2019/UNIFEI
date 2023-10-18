// TAD para �rvore Din�mica Encadeada

#ifndef _ARVORE_BIN_DE
#define _ARVORE_BIN_DE

// defini��o de tipos abstratos
typedef struct no No;
typedef No* ArvoreBin;

// fun��es para alocar e desalocar mem�ria
ArvoreBin* criar_arvore_binaria();
int liberar_arvore_binaria(ArvoreBin *raiz);

// fun��es para obter informa��es da arvore binaria
int quantidade_nos_arvore_binaria(ArvoreBin *raiz);
int altura_arvore_binaria(ArvoreBin *raiz);
int esta_vazia_arvore_binaria(ArvoreBin *raiz);

// fun��o para inser��o de elementos da arvore binaria
int inserir_arvore_binaria(ArvoreBin *raiz, int valor);

// fun��o para remo��o de elementos da arvore binaria
int remover_arvore_binaria(ArvoreBin *raiz, int valor);

// fun��o para buscar elementos na arvore binaria
int consultar_arvore_binaria(ArvoreBin *raiz, int valor);

// fun��es para percorrer a arvore binaria
void percorrer_em_ordem_arvore_binaria(ArvoreBin *raiz);
void percorrer_pre_ordem_arvore_binaria(ArvoreBin *raiz);
void percorrer_pos_ordem_arvore_binaria(ArvoreBin *raiz);

#endif

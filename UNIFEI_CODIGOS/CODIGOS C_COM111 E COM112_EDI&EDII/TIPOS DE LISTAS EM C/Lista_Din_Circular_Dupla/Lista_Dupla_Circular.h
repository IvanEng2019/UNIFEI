// TAD para Lista Din�mica Encadeada Circular dupla

typedef struct produto Produto;
typedef struct elemento* Lista;

// fun��o para criar produto
int criar_produto(Produto **produto);

// fun��es para alocar e desalocar mem�ria
Lista* criar_lista();
int liberar_lista(Lista *li);

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

// fun��es para buscar elementos na lista
Produto *buscar_lista_posicao(Lista *li, int pos);
Produto *buscar_lista_dado(Lista *li, int codigo);

int imprimir_lista(Lista *li);
int imprimir_produto(Produto *produto);

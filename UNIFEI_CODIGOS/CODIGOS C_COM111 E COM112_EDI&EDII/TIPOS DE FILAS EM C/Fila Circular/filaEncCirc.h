

typedef struct elemento Elemento;
typedef struct descritor Fila;

// fun��es para alocar e desalocar mem�ria
Fila* criar_fila_circ();
int liberar_fila(Fila *li);

// fun��es para obter informa��es da lista
int tamanho_fila(Fila*li);
int imprime_fila(Fila *li);

int enfileirar(Fila *li, int dado);
int desinfileirar(Fila *li);

// fun��es para buscar elementos na lista
int pesquisa_fila_primeiro(Fila *li);



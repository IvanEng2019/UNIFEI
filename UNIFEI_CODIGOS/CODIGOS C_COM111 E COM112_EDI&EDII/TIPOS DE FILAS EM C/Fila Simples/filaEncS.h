
typedef struct elemento Elemento;
typedef struct descritor Fila;

// funções para alocar e desalocar memória
Fila* criar_fila();
int liberar_fila(Fila *li);

// funções para obter informações da lista
int tamanho_fila(Fila*li);
int imprime_fila(Fila *li);

int enfileirar(Fila *li, int dado);
int desinfileirar(Fila *li);

// funções para buscar elementos na lista
int pesquisa_fila_primeiro(Fila *li);



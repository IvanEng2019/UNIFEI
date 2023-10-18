typedef struct elemento Elemento;
typedef struct descritor Fila;

// fun��es para alocar e desalocar mem�ria
Fila* criar_fila();
void liberar_fila(Fila *li);

// fun��es para obter informa��es da lista
int tamanho_fila(Fila*li);
int imprime_fila(Fila *li);

int enfileirar(Fila *li, int dado);
int desinfileirar(Fila *li);

// fun��es para buscar elementos na lista
int buscar_fila_posicao(Fila *li, int pos);

int preenche_senha(Fila *li,Fila *SE, char ta, char cp);
int imprime_senha(Fila *li);

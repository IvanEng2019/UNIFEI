
typedef struct elemento Elemento;
typedef struct descritor Pilha;

// fun��es para alocar e desalocar mem�ria
Pilha* criar_pilha();
int liberar_pilha(Pilha *li);

// fun��es para obter informa��es da lista
int tamanho_pilha(Pilha*li);
int imprime_pilha(Pilha *li);

int enfileirar(Pilha *li, int dado);
int desinfileirar(Pilha *li);

// fun��es para buscar elementos na lista
int pesquisa_pilha_ultimo(Pilha *li);



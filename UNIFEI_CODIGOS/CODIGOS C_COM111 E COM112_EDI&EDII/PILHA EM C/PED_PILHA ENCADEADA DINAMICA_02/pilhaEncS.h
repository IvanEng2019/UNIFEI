
typedef struct elemento Elemento;
typedef struct descritor Pilha;

// funções para alocar e desalocar memória
Pilha* criar_pilha();
int liberar_pilha(Pilha *li);

// funções para obter informações da lista
int tamanho_pilha(Pilha*li);
int imprime_pilha(Pilha *li);

int enfileirar(Pilha *li, int dado);
int desinfileirar(Pilha *li);

// funções para buscar elementos na lista
int pesquisa_pilha_ultimo(Pilha *li);



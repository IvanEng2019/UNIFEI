#ifndef Lista_Encadeada_Simples_ILVB
#define Lista_Encadeada_Simples_ILVB

typedef struct elemento Elemento;
typedef struct elemento* Lista;

// funções para alocar e desalocar memória
Lista *criar_lista();
int liberar_lista(Lista *li);

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
void imprime(Lista *li);

Lista* concatena(Lista* li1,Lista*li2);
int Troca_El2_Simples(Lista *li,int p1, int p2);
Lista* Retira_Repetidos_Simples(Lista *L1);


//int lista_cheia(Lista *li);
int lista_existe(Lista *li);
Elemento* ultimo(Lista *li);
Elemento* penultimo(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, int dado);
int inserir_lista_final(Lista *li, int dado);
int inserir_lista_ordenada(Lista *li, int dado);

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int dado);
int Remover_n_ultimos_lista_simples(Lista *li, int n);

// funções para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos);
int buscar_lista_dado(Lista *li, int dado);

#endif

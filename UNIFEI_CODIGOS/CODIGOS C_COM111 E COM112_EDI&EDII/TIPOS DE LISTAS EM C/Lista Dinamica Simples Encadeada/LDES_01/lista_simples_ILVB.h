#ifndef Lista_Encadeada_Simples_ILVB
#define Lista_Encadeada_Simples_ILVB

typedef struct elemento Elemento;
typedef struct elemento* Lista;

// fun��es para alocar e desalocar mem�ria
Lista *criar_lista();
int liberar_lista(Lista *li);

// fun��es para obter informa��es da lista
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

// fun��es para inser��o de elementos da lista
int inserir_lista_inicio(Lista *li, int dado);
int inserir_lista_final(Lista *li, int dado);
int inserir_lista_ordenada(Lista *li, int dado);

// fun��es para remo��o de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int dado);
int Remover_n_ultimos_lista_simples(Lista *li, int n);

// fun��es para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos);
int buscar_lista_dado(Lista *li, int dado);

#endif

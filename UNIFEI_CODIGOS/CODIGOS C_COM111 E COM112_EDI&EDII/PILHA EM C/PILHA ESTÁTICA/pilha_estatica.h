
// TAD para Lista Est�tica

#ifndef _PILHA_ESTATICA
#define _PILHA_ESTATICA

typedef struct pilha Pilha;

// fun��es para alocar e desalocar mem�ria
Pilha* criar_fila();

int liberar_pilha(Pilha *pi);

int tamanho_pilha(Pilha *pi);

int pilha_vazia(Pilha *pi);

int pilha_cheia(Pilha *pi);

int inserir_pilha(Pilha *pi, int dado);

int remover_pilha(Pilha *pi);

int buscar_pilha(Pilha *pi);

int imprimir_pilha(Pilha *pi);



#endif



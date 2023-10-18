#ifndef _ARVORE_AVL
#define _ARVORE_AVL

// definição de tipos abstratos
typedef struct no No;
typedef No* ArvoreAVL;

// funções para alocar e desalocar memória
ArvoreAVL* criar_arvore_avl();
int liberar_arvore_avl(ArvoreAVL *raiz);

// funções para obter informações da arvore binaria
int quantidade_nos_arvore_avl(ArvoreAVL *raiz);
int altura_arvore_avl(ArvoreAVL *raiz);
int esta_vazia_arvore_avl(ArvoreAVL *raiz);

// função para inserção de elementos da arvore binaria
int inserir_arvore_avl(ArvoreAVL *raiz, int valor);

// função para remoção de elementos da arvore binaria
int remover_arvore_avl(ArvoreAVL *raiz, int valor);

// função para buscar elementos na arvore binaria
int consultar_arvore_avl(ArvoreAVL *raiz, int valor);

// funções para percorrer a arvore binaria
void percorrer_em_ordem_arvore_avl(ArvoreAVL *raiz);
void percorrer_pre_ordem_arvore_avl(ArvoreAVL *raiz);
void percorrer_pos_ordem_arvore_avl(ArvoreAVL *raiz);

// função auxiliares
int alt_no(No *no);
int fatorBalanceamento_no(No *no);
int maior(int x, int y);
No* procuraMenor(No* atual);

// funções que executam a rotação na inserção e remoção
void rotacaoLL(ArvoreAVL *raiz);
void rotacaoRR(ArvoreAVL *raiz);
void rotacaoLR(ArvoreAVL *raiz);
void rotacaoRL(ArvoreAVL *raiz);

#endif

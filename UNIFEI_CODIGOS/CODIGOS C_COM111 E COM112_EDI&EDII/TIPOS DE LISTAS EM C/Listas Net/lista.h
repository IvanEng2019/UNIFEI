
#ifndef DA_LISTA_DE
#define DA_LISTA_DE

//criando um ponteiro
typedef struct elemento* Lista;

//funções para desalocar e alocar memoria
Lista* criar_lista();
void liberarLista(Lista *li);


//funções que obtem informaçoes de uma lista
int tamanhoLista(Lista *li);
int listaVazia(Lista *li);

//funções para inserção de elementos na lista
int inserirInicioLista(Lista *li, int dado);
int inserirFimLista(Lista *li, int dado);
int inserirMeioLista(Lista *li, int dado);


//funções para remover elementos da lista
int removerElementoInicioLista(Lista *li);
int removerElementoFimLista(Lista *li, int quant);  //nesse caso temos a quant para indicar o numero de numeros removidos ao fim da lista
int removerElementoMeioLista(Lista *li, int dado);

//funções que acessam a lista
void acessoPorPosicaoLista(Lista *li, int dado);
void acessoPorDadoLista(Lista *li, int dado);
void acessarTodasPosicoesLista(Lista *li);


//funcao teste que retorna dados
int retornaDado(Lista *li);

int existeNumeroNaLista(Lista *li, int dado);


//acoes executadas pelo programa
Lista* concatenarListas(Lista *li, Lista *li2);
Lista* trocaLugar(Lista *li,int  posi1, int posi2);

#endif


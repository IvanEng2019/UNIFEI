#ifndef DA_LISTA_DE
#define DA_LISTA_DE

//criando um ponteiro
typedef struct elemento* Lista;

//funções para desalocar e alocar memoria
Lista* criar_listaCirc();
void liberarListaCirc(Lista *li);

//funções que obtem informaçoes de uma lista
int tamanhoListaCir(Lista *li);
int listaVazia(Lista *li);

//funções para inserção de elementos na lista
int inserirInicioListaCir(Lista *li, int dado);
int inserirFimListaCir(Lista *li, int dado);
int inserirMeioListaCir(Lista *li, int dado);


//acoes executadas pelo programa
Lista* concatenarListasCir(Lista *li, Lista *li2);
Lista* trocaLugarCir(Lista *li,int  posi1, int posi2);



#endif // DA_LISTA_DE

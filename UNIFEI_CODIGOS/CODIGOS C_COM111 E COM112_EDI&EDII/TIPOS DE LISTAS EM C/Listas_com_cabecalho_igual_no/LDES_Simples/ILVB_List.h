///Definição do tipo da estrutura da lista simples
typedef struct reg {
      int conteudo;
      struct reg *prox;
}celula;

///Prototiposdas funções do projeto Lista simples
int menu();
void opcao(int op,celula* list);

///Funções auxiliares
void iniciaNoCabecalho(celula *cabeca);
celula *alocaMemoriaCelula();
int listaVazia(celula *list);
int tamanhoLista(celula *list);
void imprimeLista(celula *list);

///Funçoes de busca
celula *buscaUltimaPosicaoConteudo(celula *list,int x);
celula *buscaPenultimaPosicaoConteudo(celula *list,int x);
celula *buscaPenultimaPosicaoLista(celula *list);
celula *buscaUltimaPosicaoLista(celula *list);

///Funçoes para inserir algum dado
void insereConteudoLista(celula *novoElemento);
void insereInicioLista(celula *list);
void insereNaPosicaoDadaLista(celula *list);
void insereFimLista(celula *list);
void insereListaDepoisConteudo(celula *list);
void insereListaAntesConteudo(celula *list);
void insereDadoOrdenado(celula *list);

///Funçoes para deletar um nó da lista
void deletaLista(celula *list);
void removeCelulaInicio(celula *list);
void removeCelulaFim(celula*list);
void removePosicaoLista(celula* list);
void removeConteudoEspecifico(celula *list);

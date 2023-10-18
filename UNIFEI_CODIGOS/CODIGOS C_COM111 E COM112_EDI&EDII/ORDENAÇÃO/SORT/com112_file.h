#ifndef _FILE
#define _FILE

int* copia_vetor(int *dados, int qtd);
void escreve_dado(int *dados, int qtd, int aux);
void le_dado(int aux);
void escreve_relatorio(int *dados_rel, int qtd, int *mov, int *comp, int temp);
void relatorio_arquivo(int *dados_rel, int qtd, int *mov, int *comp, int temp, char nome[40]);

#endif

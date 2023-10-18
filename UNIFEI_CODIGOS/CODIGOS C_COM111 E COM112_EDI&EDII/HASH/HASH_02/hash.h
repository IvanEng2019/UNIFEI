#ifndef _TABELA_HASH
#define _TABELA_HASH

struct aluno{
  int matricula; 
  char nome[30]; 
  float n1;
  float n2;
};


typedef struct hash{
  int qtd, TABLE_SIZE; 
  struct aluno **itens;
}Hash;


Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* h1);

int insereSemColisao(Hash* h1, struct aluno a1);
int buscaSemColisao(Hash* h1, int mat, struct aluno *a1);

int chaveDivisao(int chave, int TABLE_SIZE);

#endif
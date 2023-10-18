#ifndef populacao.h
#define populacao.h

typedef struct {
    int id;
    char olhos,sex,cab;
}pessoa;

void cadastro (int n, pessoa *pes);
float mediab(int n, pessoa *pes);
int mid(int n, pessoa *pes);
int qtdfem (int n, pessoa *pes );
void mat(int n, pessoa *pes, int **m);

#endif

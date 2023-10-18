#define MAX 4

 typedef struct node{
 int numChaves ;
 int chave [MAX] ;
 struct node* filhos[MAX+1];
} node ;

int busca(int buscachave, node* arvB){
     int inicioPag, meio, fimPag ;
     node no* = arvB;
     while (no != NULL) {
          inicioPag = 0;
          fimPag = no->numChaves-1;
          while (inicioPag <= fimPag){
                meio = (inicioPag + fimPag)/2;
                if (no->chaves[meio] == info)
                   return 1; /
                else{
                    if(no->chave[meio] > info)
                        fimPag = meio - 1;
                    else
                        inicioPag = meio + 1;
                }
          }
          no = no->filhos[inicioPag];
    }
  return 0;
}

void em_ordem(arvoreB *raiz){
      if (raiz != NULL){
         for (int i = 0; i < raiz->numChaves; i++)      {
            em_ordem(raiz->filhos[i]);
            printf("\n%d", raiz->chaves[i];
          }
           em_ordem(raiz->filhos[i]);
       }
}

/* Alunos: 2018012346 - Adriel*/
        // 2018009073 - Ivan

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int TipoIndice;
typedef int TipoChave;
typedef struct TipoItem{
  TipoChave Chave;
} TipoItem;

void Insere (TipoItem *x , TipoItem *A, TipoIndice *n);
TipoItem RetiraMin(TipoItem *A, TipoIndice *n);
void Constroi(TipoItem *A, TipoIndice n);
void Refaz(TipoIndice Esq, TipoIndice Dir, TipoItem *A);
void AumentaChave(TipoIndice i, TipoChave ChaveNova, TipoItem *A);
void imprimeHeapMax(TipoItem *A, TipoIndice n);//,TipoIndice Tam);
TipoItem Mim(TipoItem *A);

void Insere (TipoItem *x , TipoItem *A, TipoIndice *n){
  (*n)++;
  A[*n]=*x;
  A[*n].Chave=INT_MIN;//x->Chave;
  AumentaChave(*n,x->Chave,A);
}

void AumentaChave(TipoIndice i, TipoChave ChaveNova, TipoItem *A){
  TipoItem x;
  if(ChaveNova < A[i].Chave){
    printf("ChaveNova menor que atual \n");
    return;
  }
  A[i].Chave=ChaveNova;
  while(i > 1 && (A[i/2].Chave<A[i].Chave)){
    x=A[i/2];
    A[i/2]=A[i];
    A[i]=x;
    i=i/2;
  }
}

TipoItem RetiraMin(TipoItem *A, TipoIndice *n){
  TipoItem Min;
  if (*n < 1)
    printf("Erro: heap vazio \n" );
  else{
    Min = A[1];
    A[1] = A[*n];
    (*n)--;
    Refaz(1, *n, A);
  }
  return Min;
}

void Constroi(TipoItem *A, TipoIndice n){
  TipoIndice Esq;
  Esq = n/2 + 1;
  while (Esq > 1){
    Esq--;
    Refaz(Esq, n, A);
  }
}

void Refaz(TipoIndice Esq, TipoIndice Dir, TipoItem *A){
  TipoIndice i = Esq;
  int j;
  TipoItem x;
  j = i*2;
  x = A[i];
  while (j<=Dir){
    if (j<Dir)
      if (A[j].Chave>A[j+1].Chave)
        j++;
    if (x.Chave<A[j].Chave)
        break;
    A[i]=A[j];
    i=j;
    j=i*2;
  }
  A[i]=x;
}

TipoItem Min(TipoItem *A){
  return (A[1]);
}
void imprimeHeapMin(TipoItem *A, TipoIndice n){//,TipoIndice Tam){
    for(int i=1; i<=n; i++){
        printf("%d - ", A[i].Chave);
    }
 /*   if(n<=Tam)
    {
        TipoIndice dir=2*n;
        TipoIndice esq=2*n+1;
        printf("%d ", A[n].Chave);
        imprimeHeapMax(A,esq,Tam);
        imprimeHeapMax(A,dir,Tam);

    }*/
}


int main(){

  char menu;
  TipoIndice N;
  TipoItem *C,k,topo;

  printf( "\nMetodo de ordenanação HeapSort Minimo:\n");
  do{
  printf( "\n\nDado o Menu de opções abaixo:\n\nTecle:\n");
  printf( " n para numero de chaves(Definir Tamanho do vetor) e inserir as chaves no vetor.\n");
  printf( " i para inserir uma nova chave k no heap\n");
  printf( " r para retirar a chave do topo e imprimir a retirada\n");
  printf( " m para apenas consultar o topo e imprimir a chave atual do topo\n");
  printf( " a para atualizar uma chave k no topo.\n"); // inserte
  printf( " p para imprimir o heap.\n");
  printf( " x para imprimir o heap e fechar.\n\nSua opção:");
  scanf(" %c",&menu);

  if(menu=='n') //n para numero de chaves
  {
    printf("Entre com o numero de chaves:");
    scanf("%d",&N);
    C=calloc(sizeof(TipoItem),N*2);
    if(C==NULL){
        perror("Error while allocating memory.\n");
        exit(EXIT_FAILURE);
   }
   for(int i=1;i<=N;i++){
      printf("Entre com a %d chave:",i);
      scanf("%d",&(C[i].Chave));
   }
   Constroi(C,N);
   imprimeHeapMin(C,N);
  }
  if(menu=='i') //i para inserir uma chave k no heap
  {
      printf("Entre com a chave:");
      scanf("%d", &k.Chave);
      Insere(&k, C, &N);
  }
  if(menu=='r')//r para retirar o topo e imprimi o retirado
  {
     topo= RetiraMin(C,&N);
     printf(" A chave do topo %d foi retirada.\n",topo.Chave);
   }
  if(menu=='m')//m para apenas consultar o topo e imprimi o atual
  {
    topo= Min(C);
    printf("O topo atual é: %d",topo.Chave);
  }
  if(menu=='a')//a para atualizar uma chave k no topo
  {
      printf("Entre com a chave a ser o novo topo:");
      scanf("%d", &k.Chave);
      topo=Min(C);
      C[1].Chave=k.Chave;
      N++;
      C[N].Chave=topo.Chave;//insere na ultima posiçao quem estava no topo
  }
  if(menu=='p' || menu=='x')//p para imprimir o heap
  {
     Constroi(C,N);
     imprimeHeapMin(C,N);
  }

  }while(menu!='x');
  return 0;
}

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
TipoItem RetiraMax(TipoItem *A, TipoIndice *n);
TipoItem RetiraMin(TipoItem *A, TipoIndice *n);
void ConstroiMax(TipoItem *A, TipoIndice n);
void RefazMax(TipoIndice Esq, TipoIndice Dir, TipoItem *A);
void ConstroiMin(TipoItem *A, TipoIndice n);
void RefazMin(TipoIndice Esq, TipoIndice Dir, TipoItem *A);
void AumentaChave(TipoIndice i, TipoChave ChaveNova, TipoItem *A);
void imprimeHeap(TipoItem *A, TipoIndice n);//,TipoIndice Tam);
TipoItem Topo(TipoItem *A);

void Insere (TipoItem *x , TipoItem *A, TipoIndice *n){
  (*n)++;
  A[*n]=*x;
  A[*n].Chave=INT_MIN; //x->Chave;
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

TipoItem RetiraMax(TipoItem *A, TipoIndice *n){
  TipoItem Maximo;
  if (*n < 1)
    printf("Erro: heap vazio \n" );
  else{
    Maximo = A[1];
    A[1] = A[*n];
    (*n)--;
    RefazMax(1, *n, A);
  }
  return Maximo;
}

TipoItem RetiraMin(TipoItem *A, TipoIndice *n){
  TipoItem Min;
  if (*n < 1)
    printf("Erro: heap vazio \n" );
  else{
    Min = A[1];
    A[1] = A[*n];
    (*n)--;
    RefazMin(1, *n, A);
  }
  return Min;
}
void ConstroiMax(TipoItem *A, TipoIndice n){
  TipoIndice Esq;
  Esq = n/2 + 1;
  while (Esq > 1){
    Esq--;
    RefazMax(Esq, n, A);
  }
}

void RefazMax(TipoIndice Esq, TipoIndice Dir, TipoItem *A){
  TipoIndice i = Esq;
  int j;
  TipoItem x;
  j = i*2;
  x = A[i];
  while (j<=Dir){
    if (j<Dir)
      if (A[j].Chave<A[j+1].Chave)
        j++;
    if (x.Chave>=A[j].Chave)
        break;
    A[i]=A[j];
    i=j;
    j=i*2;
  }
  A[i]=x;
}
void ConstroiMin(TipoItem *A, TipoIndice n){
  TipoIndice Esq;
  Esq = n/2 + 1;
  while (Esq > 1){
    Esq--;
    RefazMin(Esq, n, A);
  }
}

void RefazMin(TipoIndice Esq, TipoIndice Dir, TipoItem *A){
  TipoIndice i = Esq;
  int j;
  TipoItem x;
  j = i*2;
  x = A[i];
  while (j<=Dir){
    if (j<Dir)
      if (A[j].Chave>A[j+1].Chave)
        j++;
    if (x.Chave<=A[j].Chave)
        break;
    A[i]=A[j];
    i=j;
    j=i*2;
  }
  A[i]=x;
}

TipoItem Topo(TipoItem *A){
  return (A[1]);
}
void imprimeHeap(TipoItem *A, TipoIndice n){//,TipoIndice Tam){
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


int main(int argc, char *argv[]){

  char menu;
  TipoIndice N;
  TipoItem *C,k,topo;

  printf( "\nMetodo de ordenanação HeapSort MAXIMO e MINIMO:\n");
  do{
  printf( "\n************************************************************************************");
  printf( "\n\nDado o Menu de opções abaixo:\n\nTecle:\n");
  printf( " n para numero de chaves(Definir Tamanho do vetor) e inserir as chaves iniciais no vetor\n");
  printf( " i para inserir uma nova chave k no heap.\n");
  printf( " r para retirar no heap Maximo a chave do topo (maior valor) e imprimir a retirada\n");
  printf( " m para apenas consultar o topo e imprimir a chave atual do topo\n");
  printf( " a para atualizar uma chave k no topo.\n"); // inserte
  printf( " p para imprimir o heap Maximo e tornar o vetor em um heap maximo.\n");
  printf( " z para imprimir o heap Minimo e tornar o vetor em um hep minimo.\n");
  printf( " y para retirar no heap Minimo a chave do topo (menor valor) e imprimir a retirada\n");
  printf( " x para imprimir o heap Maximo e fechar.\n");
  printf( "\n************************************************************************************\nSua opção: ");
  scanf(" %c",&menu);

  if(menu=='n') //n para numero de chaves
  {
    printf("Entre com o numero de chaves:");
    scanf("%d",&N);
    C = calloc(sizeof(TipoItem),2*N+1);
    if(C==NULL){
        perror("Error while allocating memory.\n");
        exit(EXIT_FAILURE);
   }
   for(int i=1;i<=N;i++){
      printf("Entre com a %d chave:",i);
      scanf("%d",&(C[i].Chave));
  }
  printf("\nEstados dos Heaps:");
  ConstroiMax(C,N);
  printf("\nHeap Maximo atual:");
  imprimeHeap(C,N);
  ConstroiMin(C,N);
  printf("\nHeap Minimo atual:");
  imprimeHeap(C,N);

  }
  if(menu=='i') //i para inserir uma chave k no heap
  {
      printf("Entre com a chave:");
      scanf("%d", &k.Chave);
      Insere(&k, C, &N);
  }
  if(menu=='r')//r para retirar o topo e imprimi o retirado
  {
     ConstroiMax(C,N);//garante que esta no hep maximo
     topo= RetiraMax(C,&N);
     printf(" A chave maxima %d foi retirada.\n",topo.Chave);
     printf(" Heap atual: Maximo.\n");
   }
  if(menu=='m')//m para apenas consultar o topo e imprimi o atual
  {
    topo= Topo(C);
    printf("O topo atual é: %d",topo.Chave);
  }
  if(menu=='a')//a para atualizar uma chave k no topo
  {
      printf("Entre com a chave a ser o novo topo:");
      scanf("%d", &k.Chave);
      topo=Topo(C);
      C[1].Chave=k.Chave;
      N++;
      C[N].Chave=topo.Chave;//insere na ultima posiçao quem estava no topo
  }
  if(menu=='p' || menu=='x')//p para imprimir o heap
  {
     ConstroiMax(C,N);
     printf(" Heap atual Maximo: ");
     imprimeHeap(C,N);
  }
  if(menu=='z')
  {
     ConstroiMin(C,N);
     printf(" Heap atual Minimo: ");
     imprimeHeap(C,N);
  }
   if(menu=='y')
  {
     ConstroiMin(C,N);//garante q esta no hep minimo
     topo= RetiraMin(C,&N);
     printf(" A chave minima %d foi retirada.\n",topo.Chave);
     printf(" Heap atual: Minimo.");
   }

  }while(menu!='x');
  return 0;
}

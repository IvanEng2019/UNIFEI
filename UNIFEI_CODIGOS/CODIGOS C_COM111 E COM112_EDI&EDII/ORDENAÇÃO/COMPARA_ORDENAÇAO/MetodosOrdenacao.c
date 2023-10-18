void bubbleSort(Pessoas *P, int n){
   int i, j; Pessoas aux;
   for (i = 1; i < n; i++) {
     for (j = n; j > i; j--) {
       if (P[j].Chave < P[j - 1].Chave){ aux = P[j];P[j] = P[j - 1];P[j - 1]= aux;}}}}
void selectionSort(Pessoas *P, int n){
  int i, j, Min; Pessoas x;
  for (i = 0; i < n - 1; i++){
    Min = i;
    for (j = i + 1; j < n; j++){if (P[j].Chave < P[Min].Chave) Min = j;}
     x = P[Min];P[Min] = P[i]; P[i] = x; } }
void insertionSort(Pessoas *A, int n){
    int i, j;Pessoas x;
    for(i=2; i<=n; i++){
        x = A[i]; j = i - 1;
        A[0] = x;///Sentinela
        while(x.Chave<A[j].Chave){ A[j+1] = A[j]; j--;}
        A[j+1] = x;}
///Metodo Quicksort
void particao(int Esq, int Dir, int *i, int *j, Pessoas *A){
 Pessoas x, aux; *i=Esq;*j=Dir; x=A[(((*i)+(*j))/2)]; ///PIVO
  do{
    while(x.Chave>A[*i].Chave) (*i)++;
    while(x.Chave<A[*j].Chave) (*j)--;
    if(*i<=*j){ aux=A[*i]; A[*i]=A[*j]; A[*j]=aux;(*i)++;(*j)--;}
  }while(*i<=*j);}
void ordena(int Esq,int Dir, Pessoas *A){
    int i,j;
    particao(Esq,Dir,&i,&j,A);
    if(Esq<j) ordena(Esq,j,A);
    if(i<Dir) ordena(i,Dir,A);}
void quicksort(Pessoas *A, contador n){ordena(1,n,A);}
///Metodo HeapSort
void Insere (TipoItem *x , TipoItem *A, TipoIndice *n){
  (*n)++; A[*n]=*x; A[*n].Chave=INT_MIN;
  AumentaChave(*n,x->Chave,A);}
void AumentaChave(TipoIndice i, TipoChave ChaveNova, TipoItem *A){
  TipoItem x;
  if(ChaveNova < A[i].Chave){printf("ChaveNova menor que atual \n"); return;}
  A[i].Chave=ChaveNova;
  while(i > 1 && (A[i/2].Chave<A[i].Chave)){x=A[i/2];A[i/2]=A[i];A[i]=x; i=i/2; } }
TipoItem RetiraMax(TipoItem *A, TipoIndice *n){
  TipoItem Maximo;
  if (*n < 1) printf("Erro: heap vazio \n" );
  else{Maximo = A[1];A[1] = A[*n];(*n)--;RefazMax(1, *n, A);}
  return Maximo;}
void ConstroiMax(TipoItem *A, TipoIndice n){
  TipoIndice Esq = n/2 + 1;
  while (Esq > 1){
    Esq--;
    RefazMax(Esq, n, A);}}
void RefazMax(TipoIndice Esq, TipoIndice Dir, TipoItem *A){
  TipoIndice i = Esq; TipoItem x; int j = i*2;
  x = A[i];
  while (j<=Dir){
    if (j<Dir)
      if (A[j].Chave<A[j+1].Chave)///inverte no Heap minimo
          j++;
    if (x.Chave>=A[j].Chave)///Inverte no Heap Minimo
        break;
    A[i]=A[j]; i=j; j=i*2;}
    A[i]=x;}
/// Metodo MergeSort
void intercala(int * v, int left, int mid, int right){
    int aux[right-left+1];
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right){
        if(v[i] <= v[j]) aux[k++] = v[i++];
        else aux[k++] = v[j++];}
    while(i <= mid) aux[k++] = v[i++];
    while(j <= right) aux[k++] = v[j++];
    for(i = left, k = 0; i <= right; i++, k++) v[i] = aux[k];
    return;}
void mergeaux(int *v, int left, int right){
    if(left >= right)return;
    int mid = floor((right + left) / 2);
    mergeaux(v, left, mid);
    mergeaux(v, mid+1, right);
    intercala(v, left, mid, right);
    return;}
void mergesort(int *v, int n, int *p){mergeaux(v, 0, n-1);return;}

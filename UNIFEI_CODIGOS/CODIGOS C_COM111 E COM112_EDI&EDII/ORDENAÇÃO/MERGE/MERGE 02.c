#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

void intercala(int * v, int left, int mid, int right){
  int aux[right-left+1];
  int i = left, j = mid + 1, k = 0;
  while(i <= mid && j <= right){
    if(v[i] <= v[j]) aux[k++] = v[i++];
    else aux[k++] = v[j++];
  }
  while(i <= mid) aux[k++] = v[i++];
  while(j <= right) aux[k++] = v[j++];
  for(i = left, k = 0; i <= right; i++, k++) v[i] = aux[k];
  return;
}


void mergeaux(int *v, int left, int right){
    if(left >= right) return;
    int mid = floor((right + left) / 2);
    mergeaux(v, left, mid);
    mergeaux(v, mid+1, right);
    intercala(v, left, mid, right);
    return;
}

void mergesort(int *v, int n){
    mergeaux(v, 0, n-1);
    return;
}

int main(int argc, char * argv[]){
  int n;

  scanf("%d\n", &n);
  
  int * v = (int *) malloc(n*sizeof(int));
  
  for(int i = 0; i < n; i++) scanf("%d", &(v[i]));
  
  mergesort(v, n);

  for(int i = 0; i < n; i++) printf("%d ", v[i]);
  printf("\n");
  
  free(v);
}

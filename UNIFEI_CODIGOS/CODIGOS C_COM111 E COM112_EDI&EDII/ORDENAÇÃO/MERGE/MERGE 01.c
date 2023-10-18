#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void intercala(int * v, int left, int mid, int right, int *p){
    int aux[right-left+1];
    *p=0;
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right){
        if(v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while(i <= mid)
         aux[k++] = v[i++];
    while(j <= right)
         aux[k++] = v[j++];
    for(i = left, k = 0; i <= right; i++, k++){
         v[i] = aux[k];
    }
    return;
}


void mergeaux(int *v, int left, int right, int *p,int n){

    if(left >= right){
        return;
    }
    int mid = floor((right + left) / 2);
    mergeaux(v, left, mid,p,n);
    mergeaux(v, mid+1, right,p,n);
    intercala(v, left, mid, right,p);

    if(left >= mid){
       return;
    }
    int midl = floor((left + mid) / 2);
    mergeaux(v, left, midl,p,n);
    mergeaux(v, midl+1, right,p,n);
    intercala(v, left, midl, right,p);

    if(right <= mid){
       return;
    }
    int midr = floor((right + mid) / 2);
    mergeaux(v, left, midr,p,n);
    mergeaux(v, midr+1, right,p,n);
    intercala(v, left, midr, right,p);

    if(*p!=0){
      for(int i=0;i<n;i++)
        printf("%d ",v[i]);
      printf("\n");
    }
    return;
}

void mergesort(int *v, int n, int *p){
    mergeaux(v, 0, n-1, p, n);
    return;
}

int main(int argc, char * argv[]){
    int n,imp;
    scanf("%d\n", &n);
    int * v = (int *) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &(v[i]));
    mergesort(v, n,&imp);
    for(int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
    free(v);
}

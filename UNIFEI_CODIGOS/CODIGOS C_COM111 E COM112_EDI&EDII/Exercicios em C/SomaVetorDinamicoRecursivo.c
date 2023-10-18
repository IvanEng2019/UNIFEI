#include<stdio.h>

int vetrec(int n, int v1[]){

    if(n==1){
      return v1[n-1];
    }
    return v1[n-1] + vetrec(n-1,v1);
}
/******FIBONACCI******************
int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
      return 1;
    return fib(n-1)+fib(n-2);
}
********************************/

int main(){

    int n, *v;
    printf("Entre com o tamanho do vetor:");
    scanf("%d",&n);

    v= (int*) malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
         scanf("%d",&v[i]);

    printf("a soma do vetor é: %d",vetrec(n,v));

    free(v);



return 0;
}

#include<stdio.h>

int abs(int n){
    if (n>=0)
        return n;
    else
        return -n;
}
int main(){
        int n, absn;
        printf("Digite um numero: ");
        scanf(" %d", &n);
        absn = abs(n);
        printf("\nO valor de n e %d e o valor de abs(n) e %d\n", n, abs(n));
}

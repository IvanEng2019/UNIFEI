#include <stdio.h>
int main(){
    int a,b,aux;
    printf("Entre com o valor de a e b:");
    scanf("%d %d",&a, &b);
    aux=a;
    a=b;
    b=aux;
    printf("Trocado a= %d e b=%d\n",a,b);

return 0;
}

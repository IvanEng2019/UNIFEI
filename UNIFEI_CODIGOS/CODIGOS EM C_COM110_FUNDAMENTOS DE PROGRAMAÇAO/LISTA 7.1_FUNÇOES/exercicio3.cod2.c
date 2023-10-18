#include<stdio.h>
#include<stdlib.h>
int param(int x){
x = x + 10;
return x;
}
int main(){
int x, y;
printf("Digite um numero: ");
scanf(" %d", &x);
y = param(x);
printf("\nO valor de y e %d \n", y);
printf("\nO valor de x e %d \n", x);
system("pause");
}

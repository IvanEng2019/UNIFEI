#include<stdio.h>

void imprimeEnderecos(int v[2]){
// Antes de cada comando da função, o comentário descreve o que será impresso
// o endereço apontado por v = o endereço armazenado em v

printf("\nO endereço apontado por v na funcaoTeste = %p", v); //5

// o endereço do primeiro elemento do vetor v

printf("\nO endereço do primeiro elemento de v na funcaoTeste = %p", &v[0]); //6
}
int main ()
{
int v[] = {10,20};
// Antes de cada comando, o comentário descreve o que será impresso
// o endereço apontado por v = o endereço armazenado em v

printf("\nO endereço apontado por v na main = %p", v); // 2
// o endereço apontado por v = o endereço armazenado em v

printf("\nO endereço do primeiro elemento de v na main = %p\n", &v[0]); //3

imprimeEnderecos(v);
system("pause");
return 0;
}

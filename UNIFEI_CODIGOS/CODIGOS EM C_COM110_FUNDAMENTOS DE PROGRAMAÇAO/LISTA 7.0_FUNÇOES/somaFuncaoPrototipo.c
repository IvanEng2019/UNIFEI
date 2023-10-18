/********************************************************************************************************************
Exemplo de função com prototipo --> função depois do principal (main)
********************************************************************************************************************/

#include <stdio.h>

int soma (int c,int d); // assinatura da funçao (Prototipo)

int main (){
    int a,b,s; // variaveis globais
    printf("Entre com dois numeros:");
    scanf("%d %d",&a,&b);
    s = soma(a,b); //chamada da função em c por favor atribui a copia do valor a para c e da vaivel b para d
    printf("\nA soma é igual a %d.",s);
return 0;
}

int soma (int c,int d){
 return c+d; // c e d variaveis locais, reconhecidas apenas por soma ( da propria função)
}

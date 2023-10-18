/********************************************************************************************************************
Exemplo de função --> função antes da principal (main)
********************************************************************************************************************/

#include <stdio.h>

int soma (int c,int d){
 return c+d; // c e d variaveis locais, reconhecidas apenas por soma ( da propria função)
}

void escrevafrase1(){
    printf("\nEntre com dois numeros:");
    return;
}
void escrevafraseR(){
    printf("\nA soma é igual a.");
    return;
}

int main (){
    int a,b; // variaveis globais
    escrevafrase1();
    scanf("%d %d",&a,&b);
    escrevafraseR();
    printf("%d.",soma(a,b));//chamada da função em c por favor atribui a copia do valor a para c e da vaivel b para d
return 0;
}


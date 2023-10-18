/********************************************************************************************************************
Questão 3. Faça uma função que receba 2 valores inteiros e imprima-os de forma ordenada.
Utilize a função no programa principal.
********************************************************************************************************************/

#include <stdio.h> //incluindo bibliteca

void ordemC(int a,int b){ // funçao que imprime em ordem 2 numeros inteiros (crescente)
    if(a<b)
       printf("%d,%d",a,b);
    else
       printf("%d,%d",b,a);
}

int main (){ //função principal
    int a,b; // variaveis locais de main()
    printf("Entre com dois numeros:");
    scanf("%d %d",&a,&b);
    ordemC(a,b);//chamada da função soma atribuindo uma copia do valor de a e b respetivamente para as variaveis a e b da função soma
return 0;
}

// o mínimo múltiplo comum (MMC) de dois inteiros a e b é o menor inteiro positivo que é múltiplo simultaneamente de a e de b.
#include <stdio.h>

//maximo divisor comum
int mdc(int a, int b){
    if (a != b) {
        if (b > a) {
            int aux = b;
            b = a;
            a = aux;
        }
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
    }
    return a;
}

//minimo divisor comum
int mmc(int a, int b) {
   return  (a * b)/mdc(a, b);
}

int main(void){
    int n1, n2;
    char sair = 's';    
   
    printf("\n O minimo multiplo comum (MMC) de dois numeros.\n"); 
  
   while(sair == 's'){
        printf("\n Entre com o primeiro Numero: ");
        scanf(" %d", &n1);
        printf(" Entre com o segundo Numero: ");
        scanf(" %d", &n2);

        printf(" O MMC (%d , %d ) = %d.\n", n1, n2, mmc(n1, n2));
        printf(" Se deseja continuar tecle s ou para sair qualquer tecla: ");
        scanf(" %c", &sair);
   }
   return 0;
}
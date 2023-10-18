//O máximo divisor comum (MDC) corresponde ao produto dos divisores comuns entre dois ou mais números inteiros.
#include <stdio.h>

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

int main(void){
    int n1, n2;
    char sair = 's';
    printf("\n O Maximo Divisor Comum (MDC) de dois numeros.\n"); 

    while(sair == 's'){
        printf("\n Entre com o primeiro Numero: ");
        scanf(" %d", &n1);
        printf(" Entre com o segundo Numero: ");
        scanf(" %d", &n2);
        printf(" O MDC ( %d , %d) = %d.\n",n1, n2, mdc(n1, n2));
        printf(" Se deseja continuar tecle s ou para sair qualquer tecla: ");
        scanf(" %c", &sair);
   }
   return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <sys/wait.h>

#define MAX 10000
//COM220 - Sistemas Operacionais
//Exercício Prático 01 - 26/08/2019
//PROBLEMA 2
//Nome: Rafael Greca Vieira     Matrícula: 2018000434
//Nome: Ivan Leoni Vilas Boas   Matrícula: 2018009073

double fatorial(double n){
    double resultado=n;
    if(n==0)
        return 1;
    while(n>1){
        resultado = resultado*(n-1);
        n--;
    }
    return resultado;
}

double exponencial(double base, int expoente){
    double resultado = 1;
    if(expoente == 0)
        return 1;
    else{
        for(int cont =1;cont <= expoente; cont++)
            resultado = resultado * base;
    }
    return resultado;
}

///cos x= 1 − x2/2! + ..
double serie_cos(double x){
    double resultado= 1.0;
    double sinal = 1.0;
    for(int cont= 0; cont<MAX; cont++){
        resultado = resultado + ( sinal * exponencial(x, 2*cont))/fatorial((double)2*cont);
        sinal = -sinal;
    }
    return resultado;
}

///sen x= x − x3/3! +...
double serie_seno(double x){
    double resultado = x;
    double sinal = 1.0;
    for(int cont= 0; cont<MAX; cont++){
        resultado = resultado + (sinal * exponencial(x, 2*cont+1))/fatorial((double)2*cont+1);
        sinal = -sinal;
    }
    return resultado;
}

//comeco da funcao
int main(int argc, const char * argv[]) {
    int fd[2]; /* File descriptors pro Pipe*/
    int fd2[2];
    pid_t filhoA; /* Variável para armazenar o pid*/
    int status1;
    int status2;
    double x;
    scanf("%lf", &x);

    printf("Fatorial de x  = %d\n",fatorial(x));
    printf("\n......sen e coseno pela biblioteca math.h..........\n\n");
    printf("Sen calculado = %lf\n", sin (x));
    printf("Cos calculado  = %lf\n", cos(x));
    printf("Tangente de X eh: %lf\n", tan(x));
    printf(".....................................\n\n");

    /* Criando nosso Pipe */
    if(pipe(fd) < 0) {
        perror("pipe") ;
        return -1 ;
    }
     if(pipe(fd2) < 0) {
        perror("pipe") ;
        return -1 ;
    }
    /* Criando o processo filho*/
    if ((filhoA = fork()) < 0){
        perror("fork");
        exit(1);
    }
    if (filhoA == 0){//filho a
        double resultado_cos, valor_x;
        close(fd[1]);//Fecha a escrita do pipe 1
        read(fd[0], &valor_x, sizeof(valor_x));
        resultado_cos = serie_cos(valor_x);
        printf("Cos calculado pelo Filho a = %lf\n", resultado_cos);
        close(fd[0]);//Fecha leitura
        write(fd[1], &resultado_cos, sizeof(resultado_cos));
        exit(0);
    }
    else{ //pai
        pid_t filhoB;
        double cos_x, sen_x;
       ///0 = leitura, 1 = escrita
        close(fd[0]); //Fecha a leitura do pipe 1
        write(fd[1], &x, sizeof(x));
        sleep(10);
        close(fd[1]);//Fecha escrita
        read(fd[0], &cos_x, sizeof(cos_x));

        if ((filhoB = fork()) < 0){
            perror("fork");
            exit(1);
        }
        if (filhoB == 0){ //filho b
            double resultado_sen, valor_x2;
            close(fd2[1]);//Fecha a escrita
            read(fd2[0], &valor_x2, sizeof(valor_x2));
            resultado_sen = serie_seno(valor_x2);
            printf("Sen calculado pelo Filho b= %lf\n",resultado_sen);
            close(fd2[0]);//Fecha leitra
            write(fd2[1], &resultado_sen, sizeof(resultado_sen));
            exit(0);

        }
        else{ //pai
            close(fd2[0]);//Fecha a leitura do pipe 2
            write(fd2[1], &x, sizeof(x));
            sleep(10);
            close(fd2[1]);//Fecha escrita
            read(fd2[0], &sen_x, sizeof(sen_x));
            printf("\nTangente de X eh: %lf\n\n", (sen_x/cos_x));
        }
    }
    return 0;
}

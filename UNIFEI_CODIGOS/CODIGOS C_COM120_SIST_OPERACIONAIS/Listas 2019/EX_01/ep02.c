#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

//COM220 - Sistemas Operacionais
//Exercício Prático 01 - 26/08/2019
//PROBLEMA 2
//Nome: Rafael Greca Vieira     Matrícula: 2018000434
//Nome: Ivan Leoni Vilas Boas   Matrícula: 2018009073

int fatorial(int termos){
    int aux;
    aux = termos;
    while(termos > 1){
        aux = aux * (termos - 1);
        termos--;
    }
    return (aux);
}

double serie_cos(double x){
    int i;
    double resultado = 1;
    for(i = 0; i < 100; i++){
        resultado += (double)(pow(-1, i) * pow(x, 2*i)) / (double)fatorial(2*i);
    }
    return (resultado);
}

//Se a diferenca do atual para o anterior for menor ou igual a precisao para, senao, faz de novo

double serie_seno(double x){
    int i;
    double resultado = x;
    for(i = 0; i < 100;i++){
        resultado += (double)(pow(-1, i) *pow(x, 2*i + 1))/ (double)fatorial(2*i + 1);
    }
    return (resultado);
}

//comeco da funcao
int main(int argc, const char * argv[]) {
    int fd[2]; /* File descriptors pro Pipe*/
    int fd2[2];
    pid_t pid; /* Variável para armazenar o pid*/
    pid_t pidb;

    /* Criando nosso Pipe */
    if(pipe(fd) < 0) {
        perror("pipe") ;
        return -1 ;
    }
    /* Criando nosso Pipe */
    if(pipe(fd2) < 0) {
        perror("pipe") ;
        return -1 ;
    }
    /* Criando o processo filho*/
    if ((pid = fork()) < 0){
        perror("fork");
        exit(1);
    }
    if ((pidb = fork()) < 0){
            perror("fork");
            exit(1);
        }
    /* Processo Pai*/
    if (pid > 0){
        //PAI CALCULA A TAN
        double tangente, x, cos_x, sen_x;
        scanf("%lf", &x);

        ///0 = leitura, 1 = escrita
        close(fd[0]); //Fecha a leitura do pipe 1
        write(fd[1], &x, sizeof(x));
        close(fd[1]);//Fecha escrita
        read(fd[0], &cos_x, sizeof(cos_x));

        close(fd2[0]);//Fecha a leitura do pipe 2
        write(fd2[1], &x, sizeof(x));
        close(fd2[1]);//Fecha escrita
        read(fd2[0], &sen_x, sizeof(sen_x));
        printf("Tangente de X eh: %lf\n", sen_x/cos_x);

    }
    else{
        //FILHO A CALCULA O COS
        double resultado_cos, valor_x;
        close(fd[1]);//Fecha a escrita do pipe 1
        read(fd[0], &valor_x, sizeof(valor_x));
        resultado_cos = serie_cos(valor_x);
        printf("Cos calculado pelo Filho = %lf\n", resultado_cos);
        close(fd[0]);//Fecha leitura
        write(fd[1], &resultado_cos, sizeof(resultado_cos) +1);

        //FILHO B CALCULA O SEN

        if (pidb == 0){
            double resultado_sen, valor_x2;
            close(fd2[1]);//Fecha a escrita
            read(fd2[0], &valor_x2, sizeof(valor_x2));
            resultado_sen = serie_seno(valor_x2);
            printf("Sen calculado pelo Filho = %lf\n",resultado_sen);
            close(fd2[0]);//Fecha leitra
            write(fd2[1], &resultado_sen, sizeof(resultado_sen) +1);
        }
    }
    return 0;
}

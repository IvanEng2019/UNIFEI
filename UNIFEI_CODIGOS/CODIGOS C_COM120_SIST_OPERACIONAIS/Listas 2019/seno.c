//  EP02 - calcula seno

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

//função para calcular o fatorial
double fatorial(int termos)
{
    double aux;
    aux = termos;
    while(termos > 1)
    {
        aux = aux * (termos - 1);
        termos--;
    }
    return (aux);
}

//Se a diferenca do atual para o anterior for menor ou igual a precisao para, senao, faz de novo

//funcões para calcular o seno
//função 01
double serie_seno_01(double x, int termos)
{
    int i;
    double resultado;
    resultado = 0;

    for(i = 0; i < termos;i++){

        resultado += pow(-1, i) * pow(x, 2*i + 1) / fatorial(2*i + 1);
    }

    return (resultado);
}

//função 02
double serie_seno_02(double x)
{
    int i=0;
    double resultado, anterior;
    double precisao = 0.000000000000010;
    resultado = 0;
    
    resultado += pow(-1, i) * pow(x, 2*i + 1) / fatorial(2*i + 1);
    anterior = resultado;

    i++;;
    resultado += pow(-1, i) * pow(x, 2*i + 1) / fatorial(2*i + 1);

    i++;;
    
    while (fabs(anterior-resultado) > precisao) {
        anterior = resultado;
        resultado += pow(-1, i) * pow(x, 2*i + 1) / fatorial(2*i + 1);
        
        i++;
    }
    
    return (resultado);
}

//double serie_cos(double x){
//    return (cos(x));
//}


//funcao main
int main(int argc, const char * argv[]) {
    
    double x;//leitura do numero que queremos
    //printf("Digite um numero para calcular a Tangente: ");
    printf("Digite um numero para calcular o seno: ");
    scanf("%lf",&x);
    
    int fd[2]; //declarando vetorzinho do pipe
    pid_t pid; //para armazenar o pid
    
    //criando o pipe com retorno de erro, se ele retornar -1
    if(pipe(fd)<0) {
        perror("pipe") ;
        return -1 ;
    }
    
    //criando o processo filho
    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

   //Processo pai
    if (pid > 0)
    {
        //fechando leitura do pipe
        close(fd[0]);
        //int termos e x = valor
        
        double seno;
        seno = serie_seno_01(x);
        
        //escrevendo o sen
        
        write(fd[1], &seno, sizeof(seno) +1);
   
        exit(0);
    }

    //processo filho

    else
    {
        double seno;
        //double calculado, tangente;
        
        //calculado = serie_cos(x);
        //printf("Cos calculado pelo Filho = %f\n",calculado);
        
        //Fechando escrita do pipe
        close(fd[1]);
        
        //Lendo pelo pipe

        read(fd[0], &seno, sizeof(seno));

        printf("Sen calculado pelo Pai = %f\n",seno);
       
        //Calculo tangente
        // tangente = seno/calculado;
        //printf("--------------------\n");
        //printf("\nTangente = %f\n",tangente);
        
        //Porque acaba depois
        exit(0);
    }
    return 0;
}

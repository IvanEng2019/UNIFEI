// Calcula pi, a qtde de pontos no círculo e o total de cada thread

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int qthread = 0;// Quantidade de threads lida pelo usuario
int qpontos = 0;// Quantidade de pontos

int num_ptos [40]; // Pontos totais de cada
int num_ptos_cir[40]; // Pontos que cairam no circulo

double pi = 0;  // contem o valor de pi

// Funcao que gera pontos aleatorios e conta os que cairam dentro do circulo
void *monte_pi (void *param) {
    // param recebe o identificador da thread
        int i;// Variavel para laco
    
    // Transforma o param para um ponteiro para int e passa o valor dele para o id, para usar nos indices dos vetores
    int idthread = *((int *)param);
    // Para poder usar como indice dos vetores e afins
    
    double x,y,verifica;
    
    // Laco para fazer cada thread sortear
    for (i = 0; i <= qpontos; i++){
        
        // Funcao que c
        x = drand48(); // sorteia um número de 0 a 1
        y = drand48(); // sorteia um número de 0 a 1
        
        // Recebe conta para verificar se caiu dentro ou nao do circulo
        verifica = ((x*x) + (y*y));
        
        // Para conferir se caiu dentro do circulo
        
        // Se a soma dos quadrados for menor que R = 1
        // então caiu no círculo
        if (verifica <= 1){
            num_ptos_cir[idthread] ++; // conta pontos no círculo
        }
        
        // Pontos totais
        num_ptos[idthread] ++; 
    } 
    pthread_exit(0);
}

int main(int argc, const char * argv[]) {
    
    // int j;
    int i;
    int totalp = 0; // total de pontos
    int totalc = 0; // pontos no circulo
   
    // Leitura da quantidade de threads que o usuario quer
    printf("Digite a quantidade de threads (Entre 4 e 40): ");
    scanf("%i",&qthread);
    qthread ++;
    if (qthread < 4) {
        qthread = 5;
        printf("Quantidade de threads definida para 4!\n\n");
    }else if (qthread >40){
        qthread = 41;
        printf("Quantidade de threads definida para 40!\n\n");
    }
    
    // Leitura da quantidade de pontos que o usuario quer
    printf("\nDigite a quantidade de pontos (Entre 10 e 1000000): ");
    scanf("%i",&qpontos);
    if (qpontos < 10) {
        qpontos = 4;
        printf("Quantidade de pontos definido para 10!\n\n");
    }else if (qpontos > 1000000){
        qpontos = 1000000;
        printf("Quantidade de pontos definido para 1000000!\n\n");
    }
    
    pthread_t tid[qthread];  // Vetor com as threads
    
    // Cria as threads
    for (i = 1; i< qthread ; i++)
        pthread_create (&tid[i], NULL, monte_pi, &i);
    
    // Espera as threads terminarem para prosseguir
    for (i = 0; i< qthread ; i++)
        pthread_join (tid[i], NULL);
    
    
    // Soma todos os indices de pontos totais e os que cairam no circulo
    for (i = 0; i< qthread ; i++){
        totalp += num_ptos[i];  // Total de pontos
        totalc += num_ptos_cir[i]; // Somente os que cairam no circulo
    }
    
    // Calcula pi (usando cast para double)
    pi = 4.0*(((double)totalc)/((double)totalp));
    
    // Mostra Valor de pi
    printf("\n••••••••••••••••••••\n");
    printf("Pi = %f\n",pi);
    
    return 0;
}






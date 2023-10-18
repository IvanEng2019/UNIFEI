// complete o codigo para Calcular pi, a qtde de pontos no círculo e o total de cada thread

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include<unistd.h>

double pi = 0;  // contem o valor de pi, castado como variável global
int numeroPontos[10]; // Total de pontos da thread
int pontosCirculo[10]; // Pontos dentro de círculo

void *randomizer (void *itera); // sorteia e verifica os pontos pela thread

int main(int argc, const char * argv[]) {
    
    int aux1;
    pthread_t threads[11];//Vetor de threads
    
    int totalPontos = 0; // total de pontos
    int totalCirculo = 0; // pontos no circulo
    // ID das threads
    
    // Para todas as threads
    for (int aux2 = 0; aux2< 10 ; aux2++){
        //Cria dez threads para fazer o cálculo dos valores aleatórios com rand
        pthread_create (&threads[aux2], NULL, randomizer, &aux2);
        sleep(1);
    }
    
    // Para cada thread
    for (int aux3 = 0; aux3<= 9 ; aux3++){
        // espera que as threads terminem
        pthread_join (threads[aux3], NULL);
    }
    
    for (int aux4 = 0; aux4<= 9 ; aux4++){
        totalPontos += numeroPontos[aux4];
        totalCirculo += pontosCirculo[aux4];
    }
    
    printf("\nTotal de pontos: %d", totalPontos);
    printf("\nTotal de pontos no círculo: %d\n", totalCirculo);
    
    
    // Calcula o valor de pi e imprime na tela
    pi = 4.0*(((double)totalPontos)/((double)totalCirculo));//usa cast para transformar variável em double
    
    printf("\n\nValor de pi: %lf ", pi);
    
    return 0;
}



void *randomizer (void *itera) {
    
    int thrnum = *((int *)itera); // O número da thread ()
    double x,y,z;
    
    numeroPontos[thrnum] = 0;
    pontosCirculo[thrnum] = 0;
    
    printf("\nthread: %i \n",thrnum);
    for ( int i = 0; i<100000; i++){
        x = drand48(); // sorteia um número de 0 a 1
        y = drand48(); // sorteia um número de 0 a 1
        z = ((x*x) + (y*y));
        printf("\nz: %.2lf", z);
        // Se a soma dos quadrados for menor que R = 1
        // então caiu no círculo
        if (z <= 1.0){
            pontosCirculo[thrnum]++; // conta pontos no círculo
        }
        
        numeroPontos[thrnum]++; // incrementa os pontos totais da thread N (0 a 9)
        
        // A cada 10 mil iterações imprime na tela
        
    }
    
    // Imprime na tela a qtde de pontos no círculo
    // e no total de cada thread
    printf ("\nNumero de pontos dentro do circulo na Thread %i :%d\n",thrnum, pontosCirculo[thrnum]);
    printf ("Total de pontos na Thread %i :%d\n",thrnum, numeroPontos[thrnum]);
    pthread_exit(0);
}

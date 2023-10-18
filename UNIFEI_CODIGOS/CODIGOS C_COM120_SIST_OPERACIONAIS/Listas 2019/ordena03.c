// ordena 03
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QTD_Thread 8//Quantidade de threads a ser usada

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        
        /* Move elements of arr[0..i-1], that are  greater than key, to one position ahead
         of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void *funcao(void *thread_id){
    int *ident;
    ident = thread_id;
    printf("• Thread %i\n", *ident);//alerta inicio
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    insertionSort(arr, n);
    printArray(arr, n);
    printf("o Thread %i\n", *ident);//alerta fim
    
    return NULL;//Para evitar bug no XCODE
}

int main(int argc, const char * argv[]) {
    pthread_t threads[QTD_Thread];//criamos um vetor de thread usando o TAD phtread_t
    int i, qtd[QTD_Thread];
    
    for (i = 0; i < QTD_Thread; i++) {
        qtd[i] = i + 1;
        pthread_create(&threads[i], NULL, funcao, (void *)&qtd[i]);//funcao para criacao das threads
        //Endereco de memoria da thread/ parametro nulo/ funcao que ela vai executar/ e o argumento da funcao
    }
    
    //laco para esperar as threads retornarem para depois seguir em frente
    for (i = 0; i < QTD_Thread; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("\n");
    return 0;
}

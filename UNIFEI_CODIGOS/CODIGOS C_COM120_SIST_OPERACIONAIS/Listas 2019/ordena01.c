// Ordenação 01

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QTD_Thread 2//Quantidade de threads a ser usada
int arr[] = {77, 12, 11, 13, 5, 6, 12, 23, 45, 8};

// Ordenacao select
void selection_sort (int vetor[], int ante, int max) {
    int i, j, min, aux;
    int lim_inf = ante;
    //comeca do 499 ate o 1000
    for (i = lim_inf; i < (max - 1); i++) {
        /* O minimo é o primeiro número não ordenado ainda */
        min = i;
        for (j = i+1; j < max; j++) {
            /* Caso tenha algum numero menor ele faz a troca do minimo*/
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }
        /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
        if (i != min) {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }

}

// Ordenacao insertion sort
void insertionSort(int arr[], int ante, int n){
    int i, key, j;
    for (i = ante+1; i < n; i++)
    {
        key = arr[i];
        j = i-1;

        /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
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
void printArray(int arr[], int w, int n)
{
    int i;
    for (i=w; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void *funcao(void *thread_id){
    int *ident;
    ident = thread_id;
    //printf("• Thread %i\n", *ident);//alerta inicio

    if (*ident == 2) {
        //selection comeca no 0 - 4, insert 5 - 10
        insertionSort(arr, 5, 10);

    }else{
        //selection comeca no 0 - 4, insert 5 - 10
        selection_sort (arr, 0, 5);
    }

     //printf("o Thread %i\n", *ident);//alerta fim
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

    printf("Insert\n");
    printArray(arr, 0, 5);
    //receber um de 500 valores aqui, outro de 500, juntar e aplicar algum metodo
    printf("Select\n");
    printArray(arr, 5, 10);

    //Mostrar o array todo

    printArray(arr, 0, 10);
    //ordenar de novo pela main unsando insert
    insertionSort(arr, 0, 10);

    return 0;
}

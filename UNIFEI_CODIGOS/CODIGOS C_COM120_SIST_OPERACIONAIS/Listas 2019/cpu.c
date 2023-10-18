// Total time taken by CPU

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

struct thread_data
{
    int count;
    unsigned int *arr;
};

struct thread_data thread_data_array[2];

void insertionSort(unsigned int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void *sortAndMergeArrays(void *threadarg)
{
    int count;
    unsigned int *arr;
    struct thread_data *my_data;

    my_data = (struct thread_data *) threadarg;
    count = my_data->count;
    arr =  my_data->arr;

    insertionSort(arr, count);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int count, i, rc;
    clock_t start, end, total_t;
    pthread_t threads[2];

    //get the loop count. If loop count is not provided take 10000 as default loop count.
    if(argc == 2){
        count = atoi(argv[1]);
    }
    else{
        count = 10000;
    }

    unsigned int arr1[count], arr2[count], copyArr1[count], copyArr2[count];

    srand(time(0));

    for(i = 0; i<count; i++){
        arr1[i] = rand();
        arr2[i] = rand();

        copyArr1[i] = arr1[i];
        copyArr2[i] = arr2[i];
    }

    start = clock();
    for(int t=0; t<2; t++) {
        thread_data_array[t].count = count;
        if(t==0)
            thread_data_array[t].arr = arr1;
        else
            thread_data_array[t].arr = arr2;

        rc = pthread_create(&threads[t], NULL, sortAndMergeArrays, (void *) &thread_data_array[t]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    end = clock();

    total_t = (double)(end - start);
    printf("Total time taken by CPU to sort using threads: %d\n", total_t);


    start = clock();
    insertionSort(copyArr1, count);
    insertionSort(copyArr2, count);
    end = clock();

    total_t = (double)(end - start);
    printf("Total time taken by CPU to sort sequentially: %d\n", total_t);

    pthread_exit(NULL);
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//COM220 - Sistemas Operacionais
//Exercício Prático 01 - 26/08/2019
//PROBLEMA 1
//Nome: Rafael Greca Vieira     Matrícula: 2018000434
//Nome: Ivan Leoni Vilas Boas   Matrícula: 2018009073

int main()
{
    int pid=0;
    pid = fork();

    //pai
    if(pid != 0){

        for(int i=0; i<1000; i++){
            printf("%d\n", i);
        }

    }else{
        //filho

        int pida = 0;
        int pidb = 0;
        pida = fork();
        pidb = fork();

        //A
        if(pida != 0){

            for(int i=1000; i<2000; i++){
                printf("%d\n", i);
            }


        }else{
            //filho a

            int pidc, pidd = 0;
            pidc = fork();

            //C
            for(int i=3000; i<4000; i++){
                printf("%d\n", i);
            }

            pidd = fork();

            //D
            for(int i=4000; i<5000; i++){
                printf("%d\n", i);
            }

        }

        //B
        for(int i=2000; i<3000; i++){
            printf("%d\n", i);
        }

    }
}

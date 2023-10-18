//  EP01

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, const char * argv[]) 
{
    int pid = 0;
    pid = fork();//criacao do processo filho A
    int i;
    
    if (pid != 0 )
    {//processo pai
        
        //sendo o processo pai, deve criar outro processo, o filho B
        int pfb = 0;//criando processo C
        pfb = fork();
        
        if (pfb != 0) {//faz coisas do processo pai
            
            for (i = 0; i<=999; i++) {
                printf("%d\n",i);
            }
            
        }else{//faz coisas que o processo filho B deve fazer
            //printf("\nfaz coisas que o processo filho B deve fazer\n");
            for (i = 2000 ; i<= 2999; i++) {
                printf("%d\n",i);
            }
            
        }
        
    }
    else{//processo filho A
        int pfa = 0;//criando processo C
        pfa = fork();
        
        if (pfa != 0) {//faz coisas do processo filho A
            //sendo ele o processo A ele cria o proocesso D
            
            int pfd = 0;//criando processo D
            pfd = fork();
            
            if (pfd != 0) {//faz coisas do processo pai
                //printf("\nfaz coisas do processo filho A deve fazer\n");
                for (i = 1000; i<=1999; i++) {
                    printf("%d\n",i);
                }
                
            }else{//faz coisas que o processo filho B deve fazer
                //printf("\nfaz coisas que o processo filho D deve fazer\n");
                for (i = 4000 ; i<= 4999; i++) {
                    printf("%d\n",i);
                }
            }
            
        }
        else{//faz coisas que o processo filho C deve fazer
            //printf("\nfaz coisas que o processo filho C deve fazer\n");
            for (i = 3000 ; i<= 3999; i++) {
                printf("%d\n",i);
            }
        }  
        
    }
    return 0;
}

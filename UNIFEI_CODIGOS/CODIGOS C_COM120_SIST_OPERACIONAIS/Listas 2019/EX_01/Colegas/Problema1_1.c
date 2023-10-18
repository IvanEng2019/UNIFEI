#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  int pi_d;
  int pid;
  int p_id;
  int pid_d;
  int i;
  pi_d = fork();
  int cont = 0;

  if(pi_d == 0){
    printf("Child Process B:\npid :%d\nppid:%d\n",getpid(),getppid());

    for (int i = 2000; i < 2999; i++){
      cont++;
    }
    printf("Valor-Filho B Final: %d\n", cont);
  }
  
  if(pi_d > 0){
    pid = fork();
    if(pid > 0){
      printf("\nParent Process:\npid:%d\nppid:%d\n",getpid(),getppid());

      for (i = 0; i < 999;i++){
        cont++;
      }
      printf("Valor-Pai Final: %d\n", cont);
    }
    else if(pid == 0){
        p_id = fork();

        if(p_id > 0){
          printf("Child Process A:\npid :%d\nppid:%d\n",getpid(),getppid());

          for(i = 1000; i < 1999; i++){
            cont++;
          }

          printf("Valor-Filho-A Final: %d\n", cont);
        }

        if (p_id == 0){
          printf("Child Process C:\npid: %d\nppid:%d\n", getpid(), getppid());
          for(i = 3000; i < 3999; i++){
            cont++;
          }
          printf("Valor-Filho C Final: %d\n", cont);
        } else {
          pid_d = fork();

          if (pid_d == 0){
            printf("Child Process D:\npid: %d\nppid:%d\n", getpid(), getppid());
            for (i = 4000; i < 4999; i++){
              cont++;
            }
            printf("Valor-Filho D Final = %d\n",cont);
          }
        }

      }
  }
  sleep(10);
  return 0;
}

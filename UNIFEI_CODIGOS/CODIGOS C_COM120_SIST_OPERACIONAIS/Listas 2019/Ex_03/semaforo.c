/*
Programa semaforo.c -  exemplo de uso de semaforos e Regiao Critica
Secao 2.6.4 da apostila de S.O. (pag. 41)
Hist'oria: Criado por Eleri, Mauricio, Ivan
           Modificado por Marco Aurelio
           Modificado por Roberto Lotufo 6nov96

Este programa controla o acesso ao terminal para impressao de um texto
(região crítica) através de semáforos.

Compilacao: gcc semaforo.c -o semaforo
----------
Uso: execute dois processos simultaneos em background:
---  semaforo&; semaforo&

e observe o resultado

OBS: para matar os processos:
---  kill <n. do processo>

     o n'umero do processo aparece no in'icio da mensagem impressa.

SUGESTAO de modificacoes:
--------
1. Comente as linhas dos sem'aforos e observe o resultado deste novo programa
2. Modifique o programa de modo a que o primeiro crie o segundo processo
   utilizando o fork().  */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <semaphore.h>
extern errno;

/* acessa um semaforo ja criado */
int GetSem( key_t key)
{
  int semid;
  semid = semget(key, 1, 0777 | IPC_CREAT);
  return(semid);
}


/* define operacao DOWN */
void DOWN( int semid)
{
  struct sembuf psem[2];

  psem[0].sem_num = 0;
  psem[0].sem_op = -1;
  psem[0].sem_flg = SEM_UNDO;

  semop(semid, psem, 1);
}

/* define operacao UP */
void UP( int semid)
{
  struct sembuf vsem[2];

  vsem[0].sem_num = 0;
  vsem[0].sem_op = 1;
  vsem[0].sem_flg = SEM_UNDO;

  semop(semid, vsem, 1);
}

main(int argc, char *argv[])
{
  char *poema[8];
  int i;
  int semid;
  int pid, pid_father, pid_son;
  int com_semaforo;

  com_semaforo = 0;
  if (argc == 1) com_semaforo = 1;

  printf("\nExecucao %s semaforo\n", (com_semaforo)? "com" : "sem");

  pid_father = getpid(); /* busca o n'umero do processo */
  semid = GetSem(13);

  if(semid < 0)
    {
      printf("\nSemaforo nao criado por GetSem !\n");
      exit(0);
    }

  poema[0] = "As armas e os baroes assinalados";
  poema[1] = "Que da ocidental praia Lusitana";
  poema[2] = "Por mares nunca dantes navegados";
  poema[3] = "Passaram ainda alem de Tapobrana";
  poema[4] = "E, em perigos e guerras esforcados";
  poema[5] = "Mais do que prometia a forca humana";
  poema[6] = "Por gente remota edificaram";
  poema[7] = "Novo reino, que tanto sublimaram";

  pid_son = fork();
  pid = (pid_son)? pid_son : pid_father;

  printf("Inicio de execucao do processo %d, semaforo %d\n", pid, semid);

  while(1)
  {
    if (com_semaforo)
      DOWN(semid); /*   entrada na Regiao Critica */
    for(i = 0; i < 8; i++)
    {
      printf("\n%d: %s", pid, poema[i]);
      sleep(0.5);
    }
    printf("\n\n");
    if (com_semaforo)
      UP(semid); /*  saida da Regiao Critica */
    sleep(2);
  }
}

//      fork1.c
//      
//      Copyright 2012 Carlos Minoru Tamaki <professorcco@gmail.com>
//      
//		Este e um software livre; voce pode redistribuir e/ou modificar
//		nos termos do GNU General Public License como publicado pelo
//      Free Software Foundation; como na vesao 2 da Licenca ou (na sua
//      opcao) qualquer versao posterior.
//      
//      Exemplo de criação de processos a partir de um processo em
//      execução.
//      

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>


int main(int argc, char *argv[])
{
 	time_t inicio, fim;
	double tempo;

	int pid;
	long int i;
	time( &inicio );
	pid=fork();
	
	if (pid != 0)
	{
		printf( "Sou processo pai!!!\n" );
		printf( "Sou processo pai, iniciando a contagem!!!\n" );
		for( i = 0; i < 4000000000; i++ );
		printf( "Processo pai encerrando !!!\n" );
	}			 
	else
	{
		printf("Sou processo filho!!!\n");
		printf("Sou processo filho, iniciando a contagem!!!\n");
		for( i = 0; i < 4000000000; i++ );
		printf( "Processo filho encerrando !!!\n" );
	}
	
	time( &fim );
	tempo = difftime( fim, inicio );
	printf( "Tempo decorrido de cpu = %.2lf segundos\n", tempo );
		 
	return 0;
}

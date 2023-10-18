//      fork0.c
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

int main(int argc, char *argv[])
{
 
	int pid;
	int i, j; 

	pid=fork();
	
	if (pid != 0)
	{
		printf( "Sou processo pai!!!\n" );
		for( i = 0; i < 10; i++ )
		{
			for( j = 0; j < 300000000; j++ );
			printf( "Processo pai executando i = %d\n", i );
		}
		printf( "Eu, pai já terminei!!! \n" );
	}			 
	else
	{
		printf("Sou processo filho!!!\n");
		for( i = 0; i < 10; i++ )
		{
			for( j = 0; j < 300000000; j++ );
			printf( "Processo filho executando i = %d\n", i );
		}
		printf( "Eu, filho já terminei!!! \n" );
	}
	printf( "Programa encerrado!!!" );

	return 0;
}

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
 
	int pid=0;

	pid=fork();
	
	if (pid != 0)
	{
		printf( "Sou processo pai!!!\n" );
	}			 
	else
	{
		printf("Sou processo filho!!!\n");
	}
	return 0;
}

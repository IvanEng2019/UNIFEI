//      cpu_bound0.c
//      
//      Copyright 2012 Carlos Minoru Tamaki <professorcco@gmail.com>
//      
//		Este e um software livre; voce pode redistribuir e/ou modificar
//		nos termos do GNU General Public License como publicado pelo
//      Free Software Foundation; como na vesao 2 da Licenca ou (na sua
//      opcao) qualquer versao posterior.
//      
//      Exemplo simples de processo CPU-Bound
//      
//      


#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv)
{
	time_t inicio, fim;
	double tempo;
	 unsigned int i;
	
	time( &inicio );
	printf( "Tamanho da variável x = %ld bytes\n", sizeof( i ) );
	printf( "Primeira contagem\n" );
	for ( i = 0; i < 4000000000; i++ );
	printf( "Segunda contagem\n" );
	for ( i = 0; i < 4000000000; i++ );

	time( &fim );
	tempo = difftime( fim, inicio );
	printf( "Tempo decorrido de cpu = %.2lf segundos\n", tempo );
	return 0;
}


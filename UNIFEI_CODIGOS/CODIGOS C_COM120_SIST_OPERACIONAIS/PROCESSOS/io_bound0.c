//      io_bound0.c
//      
//      Copyright 2012 Carlos Minoru Tamaki <professorcco@gmail.com>
//      
//		Este e um software livre; voce pode redistribuir e/ou modificar
//		nos termos do GNU General Public License como publicado pelo
//      Free Software Foundation; como na vesao 2 da Licenca ou (na sua
//      opcao) qualquer versao posterior.
//      
//      Exemplo simples de processo I/O-Bound
//      
//      


#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
	time_t inicio, inicio1, inicio2, inicio3, fim;
	double tempo;
	int i;
	int mat;
	char nome[10];
	
	time( &inicio );
	printf( "Primeira contagem\n" );
	for ( i = 0; i < 2100000000; i++ );
	
	time( &inicio1 );
	printf( "Digite o número de matrícula: " );
	scanf( "%d", &mat );
	printf( "Digite o nome: " );
	scanf( " %s", nome );
	
	time( &inicio2 );
	printf( "Segunda contagem\n" );
	for ( i = 0; i < 2100000000; i++ );
	
	time( &inicio3 );
	printf( "Número: %d\n", mat );
	printf( "Nome: %s\n\n", nome );
	
	time( &fim );
	tempo = difftime( inicio1, inicio ) + difftime( inicio3, inicio2 );
	printf( "Tempo de cpu = %.2lf segundos\n", tempo );
	
	tempo = difftime( inicio2, inicio1 ) + difftime( fim, inicio3 );
	printf( "Tempo de i/o = %.2lf segundos\n", tempo );
	
	tempo = difftime( fim, inicio );
	printf( "Tempo total de execução = %.2lf segundos\n", tempo );

	return 0;
}


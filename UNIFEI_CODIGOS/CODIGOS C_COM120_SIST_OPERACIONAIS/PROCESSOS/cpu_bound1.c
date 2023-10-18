//      cpu_bound1.c
//      
//      Copyright 2012 Carlos Minoru Tamaki <professorcco@gmail.com>
//      
//		Este e um software livre; voce pode redistribuir e/ou modificar
//		nos termos do GNU General Public License como publicado pelo
//      Free Software Foundation; como na vesao 2 da Licenca ou (na sua
//      opcao) qualquer versao posterior.
//      
//      Exemplo de processo CPU-Bound
//      Produto de matrizes utilizando alocação dinâmica
//      


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defina aqui adimensão máxima das matrizes
#define MAX 1000

int main(int argc, char **argv)
{
	time_t inicio, inicio1, fim;
	double tempo;
	double **a, **b, **c;
	int i, j, k;

	srand( time( NULL ) );	//inicialização do gerador randômico

	time( &inicio );		//tempo de início do cálculo

// Alocação das matrizes
	printf( "Alocando as 3 matrizes [%d]x[%d]\n", MAX, MAX );
	a = (double **) calloc( MAX, sizeof( double * ) );
	b = (double **) calloc( MAX, sizeof( double * ) );
	c = (double **) calloc( MAX, sizeof( double * ) );
	for( j = 0; j < MAX; j++ )
	{
		a[j] = (double *) calloc( MAX, sizeof( double ) );
		b[j] = (double *) calloc( MAX, sizeof( double ) );
		c[j] = (double *) calloc( MAX, sizeof( double ) );
	}

// Atribuição de valores para os elementos das matrizes, randomicamente	
	printf( "Atribuindo valores para A e B\n" );
	for( i = 0; i < MAX; i++ )
		for( j = 0; j < MAX; j++ )
		{
			a[i][j] = (double)rand()/(double)rand();
			b[i][j] = (double)rand()/(double)rand();
		}

// Cálculo do produto
	printf( "Calculando o produto C\n" );
	time( &inicio1 );		//tempo de início do cálculo

	for( i = 0; i < MAX; i++ )
		for( j = 0; j < MAX; j++ )
		{
			c[i][j] = 0.0;
			for( k = 0; k < MAX; k++ )
			c[i][j] = c[i][j] + a[i][k]*b[k][j];
		}

	time( &fim );
	tempo = difftime( fim, inicio1 );
	printf( "Tempo de cálculo do produto = %.2lf segundos\n", tempo );
		
	printf( "Liberando as 3 matrizes\n" );
	for( j = 0; j < MAX; j++ )
	{
		free( a[j] );
		free( b[j] );
		free( c[j] );
	}
	free( a );
	free( b );
	free( c );

	tempo = difftime( fim, inicio );
	printf( "Tempo total decorrido de cpu = %.2lf segundos\n", tempo );

	return 0;
}


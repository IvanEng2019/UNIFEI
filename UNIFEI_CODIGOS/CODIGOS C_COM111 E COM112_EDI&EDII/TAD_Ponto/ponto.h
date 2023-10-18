/*******************/
/* TAD para ponto  */
/*******************/
#ifndef ER_PONTO_H
#define ER_PONTO_H

// constantes
#define DEBUG 1


// tipo de dado
typedef struct ponto Ponto;


// protótipos das funções
Ponto *pto_cria(float x, float y);

void pto_libera(Ponto *p);

void pto_obtem(Ponto *p, float *x, float *y);

void pto_atribui(Ponto *p, float x, float y);

float pto_distancia(Ponto *p1, Ponto *p2);



#endif
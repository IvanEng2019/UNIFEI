//bibliotecas do sistema
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// bibliotecas do projeto
#include "ponto.h"

// definicao do tipo de dado Ponto
struct ponto{
  float x;
  float y;
};

// aloca e retorna um ponteiro do tipo Ponto com
// coordenadas "x" e "y" 
Ponto *pto_cria(float x, float y)
{
  Ponto *p = (Ponto*) malloc(sizeof(Ponto));

  if(p != NULL){
    pto_atribui(p, x, y);

  }else{
    printf("Memória insuficiente!");
    return NULL;
  }

  return p;
}

// desaloca memória
void pto_libera(Ponto *p)
{
  if(p != NULL){
    free(p);
  }
}

// recupera, por referência, o valor do ponto
void pto_obtem(Ponto *p, float *x, float *y)
{
  *x = p->x;
  *y = p->y;
}

// atribui um valor para o ponto
void pto_atribui(Ponto *p, float x, float y)
{
  p->x = x;
  p->y = y;
}

// calcula a distância entre dois pontos
float pto_distancia(Ponto *p1, Ponto *p2)
{
  float dx = p1->x - p2->x;
  float dy = p1->y - p2->y;

  return sqrt(dx*dx + dy*dy);
}

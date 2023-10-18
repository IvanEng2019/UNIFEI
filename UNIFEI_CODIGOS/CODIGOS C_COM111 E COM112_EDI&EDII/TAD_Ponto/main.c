
// bibliotecas do sistema
#include <stdio.h>

// bibliotecas do projeto
#include "ponto.h"

// funcao principal
int main(void) {

  Ponto *p, *q;
  float x, y, dist;
  
  // criando dois pontos, p e q
  p = pto_cria(10, 20);
  q = pto_cria(30, 10);

  // imprimindo coordenadas do ponto p
  pto_obtem(p, &x, &y);
  printf("\n(%.2f, %.2f)", x, y);

  // imprimindo coordenadas do ponto q
  pto_obtem(q, &x, &y);
  printf("\n(%.2f, %.2f)", x, y);

  // calculando a distancia entre p e q
  dist = pto_distancia(p, q);
  printf("\nDistância: %.2f", dist);

  // liberando memória
  pto_libera(p);
  pto_libera(q);

  return 0;
}
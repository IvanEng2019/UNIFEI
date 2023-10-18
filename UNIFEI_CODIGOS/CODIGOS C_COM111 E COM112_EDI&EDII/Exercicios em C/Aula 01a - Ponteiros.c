#include "stdio.h"

int subtracao(int n1, int n2){
  return n1 - n2;
}

void soma(int *ps, int n1, int n2){
  *ps = n1 + n2;
}

int main(void) {

  // declara��o das vari�veis (sub) e (s)
  int sub; // vari�vel do tipo inteiro que armazena total da subtra��o
  int s; // vari�vel do tipo inteiro que armazena total da soma


  /***********************************************************************************************/
  /** passagem de par�metro por valor (fun��o subtracao() retorna o resultado da subtra��o)     **/
  /***********************************************************************************************/

  subtracao(10, 6); // chama fun��o que calcula a subtra��o 10 - 6 = 4
  printf("Subtra��o = %d\n", sub);


  /***********************************************************************************************/
  /** passagem de par�metro por refer�ncia (fun��o soma() recebe o endere�o da vari�vel s)      **/
  /***********************************************************************************************/

  // usando o endere�o da vari�vel (&s)
  soma(&s, 3, 5);
  printf("Soma com s = %d\n", s);

  /***********************************************************************************************/
  /** passagem de par�metro por refer�ncia (fun��o soma() recebe um ponteiro para a vari�vel s) **/
  /***********************************************************************************************/

  // declara��o dos ponteiros (ps) e (ps2)
  int *ps = &s; // ponteiro para a posi��o de mem�ria que armazena o total da soma
  int **ps2 = &ps; // ponteiro para o ponteiro anterior

  // usando o ponteiro (ps) que cont�m o endere�o da vari�vel (s)
  soma(ps, 3, 5);
  printf("Soma com ps = %d\n", s);

  // usando o valor do ponteiro para ponteiro (ps2) que cont�m o endere�o do ponteiro (ps)
  soma(*ps2, 3, 5);
  printf("Soma com *ps2 = %d\n", s);

  return 0;
}

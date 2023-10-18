/********************************************************************************************
Programa: PortaLogicaNao.c
Desenvolvedores:Ivan && Kamilla && Tiago
Objetivo: Representar a porta lógica NÃO na linguagem C
Explicação:A liguagem C utiliza o caracter ! para representar a porta NÃO;
A porta lógica NÃO inverte o valor da entrada. Ela apresenta apenas um valor de entrada
verdadeiro ou falso (0 ou 1).Caso a entrada da porta seja 1 (verdade)a saída sera 0 (falso),
caso a entrada da porta seja 0 (falso) a saída será 1 (verdade).
*********************************************************************************************/

#include <stdio.h>
int main ()
 {
    printf ("\nPorta logica NAO:\n\nENTRADA   SAIDA NAO\n");
    printf ("  0  %10d\n",!0);
    printf ("  1  %10d\n",!1);

    printf ("\nPorta logica NAO com porta E, OU e XOU para 2 entradas:\n\n A B  !(A&&B) !(A||B) !(A^B)\n");
    printf (" 0 0  %4d %7d %7d\n",!(0&&0),!(0||0),!(0^0));
    printf (" 1 0  %4d %7d %7d\n",!(1&&0),!(1||0),!(1^0));
    printf (" 0 1  %4d %7d %7d\n",!(0&&1),!(0||1),!(0^1));
    printf (" 1 1  %4d %7d %7d\n",!(1&&1),!(1||1),!(1^1));

    printf ("\nPorta logica NAO com porta E, OU e XOU para 3 entradas:\n\n A B C  !(A&&B&&C) !(A||B||C) !(A^B^C)\n");
    printf (" 0 0 0 %6d %10d %9d\n",!(0&&0&&0),!(0||0||0),!(0^0^0));
    printf (" 1 0 0 %6d %10d %9d\n",!(1&&0&&0),!(1||0||0),!(1^0^0));
    printf (" 0 1 0 %6d %10d %9d\n",!(0&&1&&0),!(0||1||0),!(0^1^0));
    printf (" 1 1 0 %6d %10d %9d\n",!(1&&1&&0),!(1||1||0),!(1^1^0));
    printf (" 0 0 1 %6d %10d %9d\n",!(0&&0&&1),!(0||0||1),!(0^0^1));
    printf (" 1 0 1 %6d %10d %9d\n",!(1&&0&&1),!(1||0||1),!(1^0^1));
    printf (" 0 1 1 %6d %10d %9d\n",!(0&&1&&1),!(0||1||1),!(0^1^1));
    printf (" 1 1 1 %6d %10d %9d\n",!(1&&1&&1),!(1||1||1),!(1^1^1));

    return 0;
  }

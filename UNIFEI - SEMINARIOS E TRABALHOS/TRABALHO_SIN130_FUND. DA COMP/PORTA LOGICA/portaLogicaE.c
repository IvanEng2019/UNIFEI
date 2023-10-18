/***************************************************************************************
Programa: PortaLogicaE.c
Desenvolvedores:Ivan && Kamilla && Tiago
Objetivo: Representar a porta lógica E na linguagem C
Explicação:A liguagem C utiliza o caracter && para representar a porta E;
Na porta lógica E a saida será 1 (verdade) quando todas as entradas forem 1(verdade).
e sera 0 (falso) quando exitir apenas uma entrada 0 (falso).
****************************************************************************************/
#include <stdio.h>
int main ()
 {
    printf ("\nPorta logica E com 2 entradas:\n\n A  B  SAIDA E\n");
    printf (" 0  0 %4d\n",0&&0);
    printf (" 0  1 %4d\n",0&&1);
    printf (" 1  0 %4d\n",1&&0);
    printf (" 1  1 %4d\n",1&&1);

    printf ("\nPorta logica E com 3 entradas:\n\n A  B  C SAIDA E\n");
    printf (" 0  0  0 %4d\n",0&&0&&0);
    printf (" 0  1  0 %4d\n",0&&1&&0);
    printf (" 1  0  0 %4d\n",1&&0&&0);
    printf (" 1  1  0 %4d\n",1&&1&&0);
    printf (" 0  0  1 %4d\n",0&&0&&1);
    printf (" 0  1  1 %4d\n",0&&1&&1);
    printf (" 1  0  1 %4d\n",1&&0&&1);
    printf (" 1  1  1 %4d\n",1&&1&&1);

    return 0;
 }

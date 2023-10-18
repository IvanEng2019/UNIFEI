/***************************************************************************************
Programa: PortaLogicaOU.c
Desenvolvedores:Ivan && Kamilla && Tiago
Objetivo: Representar a porta lógica OU na linguagem C
Explicação:A liguagem C utiliza o caracter || para representar a porta OU;
Na porta lógica OU a saida será 1 (verdade) quando existir apenas uma entrada 1 (verdade)
e sera 0 (falso) quando todas as entradas forem 0 (falso).
****************************************************************************************/
#include <stdio.h>
int main ()
 {
    printf ("\nPorta logica OU com 2 entradas:\n\n A  B  SAIDA OU\n");
    printf (" 0  0 %4d\n",0||0);
    printf (" 0  1 %4d\n",0||1);
    printf (" 1  0 %4d\n",1||0);
    printf (" 1  1 %4d\n",1||1);

    printf ("\nPorta logica OU com 3 entradas:\n\n A  B  C  SAIDA OU\n");
    printf (" 0  0  0 %4d\n",0||0||0);
    printf (" 0  1  0 %4d\n",0||1||0);
    printf (" 1  0  0 %4d\n",1||0||0);
    printf (" 1  1  0 %4d\n",1||1||0);
    printf (" 0  0  1 %4d\n",0||0||1);
    printf (" 0  1  1 %4d\n",0||1||1);
    printf (" 1  0  1 %4d\n",1||0||1);
    printf (" 1  1  1 %4d\n",1||1||1);

    return 0;
 }

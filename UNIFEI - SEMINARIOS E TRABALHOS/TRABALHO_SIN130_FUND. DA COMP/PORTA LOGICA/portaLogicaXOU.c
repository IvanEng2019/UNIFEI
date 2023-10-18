/*****************************************************************************************
Programa: PortaLogicaXOU.c
Desenvolvedores:Ivan && Kamilla && Tiago
Objetivo: Representar a porta lógica XOR (EOU/XOU) na linguagem C
Explicação:A liguagem c utiliza o caracter ^ para representar a porta XOR;
Na porta logica XOR a saida sera 1 (verdade) quando a somatoria do numero de verdades (1)
das entradas for impar e será 0 (falso) quando o somatorio das entradas verdades (1)
for par.
******************************************************************************************/

#include <stdio.h>
int main ()
 {
    printf ("\nPorta logica XOR (EOU/XOU) com 2 entradas:\n\n A  B  SAIDA XOR\n");
    printf (" 0  0 %4d\n",0^0);
    printf (" 0  1 %4d\n",0^1);
    printf (" 1  0 %4d\n",1^0);
    printf (" 1  1 %4d\n",1^1);

    printf ("\nPorta logica XOR (EOU/XOU) com 3 entradas:\n\n A  B  C  SAIDA XOR\n");
    printf (" 0  0  0 %4d\n",0^0^0);
    printf (" 0  1  0 %4d\n",0^1^0);
    printf (" 1  0  0 %4d\n",1^0^0);
    printf (" 1  1  0 %4d\n",1^1^0);
    printf (" 0  0  1 %4d\n",0^0^1);
    printf (" 0  1  1 %4d\n",0^1^1);
    printf (" 1  0  1 %4d\n",1^0^1);
    printf (" 1  1  1 %4d\n",1^1^1);

    return 0;
 }

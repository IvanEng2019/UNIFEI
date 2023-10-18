#include <stdio.h>
int main ()
 {

    printf ("Porta logica E:\n A  B  SAIDA\n");//sera 1 (v) quando toDas entradas forem verdade
    printf (" 0  0 %4d\n",0&&0);
    printf (" 0  1 %4d\n",0&&1);
    printf (" 1  0 %4d\n",1&&0);
    printf (" 1  1 %4d\n",1&&1);

    printf ("\nPorta logica ou:\n A  B  SAIDA\n");//sera 1 (v) quando apenas uma entrada ou mais for verdade (1)
    printf (" 0  0 %4d\n",0||0);
    printf (" 0  1 %4d\n",0||1);
    printf (" 1  0 %4d\n",1||0);
    printf (" 1  1 %4d\n",1||1);

    printf ("\nPorta logica xor (EOU/xou):\n A  B  SAIDA\n"); //saida sera 1(v) quando o nº de entradas 1 forem impares
    printf (" 0  0 %4d\n",0^0);
    printf (" 0  1 %4d\n",0^1);
    printf (" 1  0 %4d\n",1^0);
    printf (" 1  1 %4d\n",1^1);

    printf ("Porta logica NÃO:\n A  SAIDA\n");
    printf (" 0 %4d\n",!0);
    printf (" 1 %4d\n",!1);

    printf ("Porta logica NÃO:\n A  B  !A  !B !(A&&B) !(A||B) !(A^B)\n");
    printf (" 0 0 %4d %3d %4d %7d %7d\n",!0,!0,!(0&&0),!(0||0),!(0^0));
    printf (" 1 0 %4d %3d %4d %7d %7d\n",!1,!0,!(1&&0),!(1||0),!(1^0));
    printf (" 0 1 %4d %3d %4d %7d %7d\n",!0,!1,!(0&&1),!(0||1),!(0^1));
    printf (" 1 1 %4d %3d %4d %7d %7d\n",!1,!1,!(1&&1),!(1||1),!(1^1));


  return 0;
 }

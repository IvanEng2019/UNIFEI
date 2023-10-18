#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "avrbin.h"
#include "avrbin.c"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    arvBin* raiz = cria_arvore();

    system("pause");
    return 0;
}
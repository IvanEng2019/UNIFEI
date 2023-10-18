/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aluno
 *
 * Created on 15 de Maio de 2018, 08:20
 */

#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

/*
 * 
 */
int main() 
{
    abp *A = criaArvore();
    noArvore *noAtual;
    insereNo(A, 50);
    insereNo(A, 30);
    insereNo(A, 55);
    insereNo(A, 10);
    insereNo(A, 15);
    insereNo(A, 20);
    insereNo(A, 80);
    insereNo(A, 90);
    insereNo(A, 68);
    noAtual = retornaSentinelaRaiz(A);
    percorreEmOrdem(noAtual);
    printf("\n");
    removeNo(A, 50);
    removeNo(A, 90);
    percorreEmOrdem(retornaSentinelaRaiz(A));
    printf("\n");
    return(0);
        
}
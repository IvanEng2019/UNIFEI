/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aluno
 *
 * Created on 16 de Abril de 2018, 14:28
 */

#include <stdio.h>
#include <stdlib.h>
#include 
/*
 * 
 */
int main() 
{
    abp *A = criaArvore();
    noArvore *noAtual;
    insereNo(A, 300);
    insereNo(A, 200);
    insereNo(A, 450);
    insereNo(A, 430);
    insereNo(A, 470);
    insereNo(A, 410);
    noAtual = retornaSentinelaRaiz(A);
    percorreEmOrdem(noAtual);
    return(0);
        
}


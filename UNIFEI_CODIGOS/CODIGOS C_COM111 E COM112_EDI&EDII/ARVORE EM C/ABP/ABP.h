/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ABP.h
 * Author: aluno
 *
 * Created on 16 de Abril de 2018, 14:22
 */

#ifndef ABP_H
#define ABP_H

typedef struct noArvore noArvore;
typedef struct abp abp;


//instancia um TAD arvore e retorna a referencia para essa estrutura
abp* criaArvore();

//a funcao insere um no na arvore, dado o valor da chave a ser inserida
//a funcao retorna 1 se o valor foi inserido com sucesso
//e -1 se nao foi possivel inserir
int insereNo(abp *A, int valor);

//funçao que remove um no da arvore, dado o valor da chave
//a funcao retorna 1 para o no removido com sucesso 
//e -1 para o no nao existente na arvore
int removeNo(abp *A, int valor);

//imprime os elementos da arvore em ordem crescente
void percorreEmOrdem(noArvore *noAtual);      

noArvore* retornaSentinelaRaiz(abp *A);

//funçao que atualiza o Fator de Balanceamento da arvore AVL
void atualizaFB(noArvore *novoNo);

//funcao que verifica as funçoes de balanceamento do no desbalanceado
void balanceamento(noArvore *noDesbalanceado);

//rotacao a esquerda
void rotacaoEsq(noArvore *noDesbalanceado);

//rotacao a direita
void rotacaoDir(noArvore *noDesbalanceado);

#endif /* ABP_H */


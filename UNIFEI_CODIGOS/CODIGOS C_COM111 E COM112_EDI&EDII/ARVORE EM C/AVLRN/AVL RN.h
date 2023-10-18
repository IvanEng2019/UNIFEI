/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVL.h
 * Author: aluno
 *
 * Created on 15 de Maio de 2018, 08:20
 */

#ifndef AVL_H
#define AVL_H

typedef struct noArvore noArvore;
typedef struct avp avp;


//instancia um TAD arvore e retorna a referencia para essa estrutura
avp* criaArvore();

//a funcao insere um no na arvore, dado o valor da chave a ser inserida
//a funcao retorna 1 se o valor foi inserido com sucesso
//e -1 se nao foi possivel inserir
int insereNo(avp *A, int valor);

//funçao que remove um no da arvore, dado o valor da chave
//a funcao retorna 1 para o no removido com sucesso 
//e -1 para o no nao existente na arvore
int removeNo(avp *A, int valor);

//imprime os elementos da arvore em ordem crescente
void percorreEmOrdem(noArvore *noAtual);      

//retorna o no raiz (direita da sentinela)
noArvore* retornaSentinelaRaiz(avp *A);


//funcao que verifica as funçoes de balanceamento do no desbalanceado
//chama as rotacoes adequadas e realiza o ajuste do FB posteriormente
void balanceamento_insercao(avp *A, noArvore *novoNo);

//rotacao a esquerda
void rotacaoEsq(noArvore *noDesbalanceado);

//rotacao a direita
void rotacaoDir(noArvore *noDesbalanceado);


//funcao que verifica as funçoes de balanceamento do no desbalanceado
//chama as rotacoes adequadas e realiza o ajuste do FB posteriormente
void balanceamento_remocao(avp *A, noArvore *noPai, noArvore *noFilho);

#endif /* AVL_H */


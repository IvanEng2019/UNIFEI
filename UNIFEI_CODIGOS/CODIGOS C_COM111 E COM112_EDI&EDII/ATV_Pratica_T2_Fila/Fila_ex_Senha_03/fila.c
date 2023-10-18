#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fila.h"

Fila* criaFila(){
 Fila *novaFila = (Fila*) malloc(sizeof(Fila));
 novaFila->primeiro = NULL;
 novaFila->ultimo = NULL;
 return(novaFila);
}

void insereSenha(Fila *filaa,int preferencial){
    Senha *novaSenha;
    novaSenha =  (Senha*) malloc(sizeof(Senha));
    if(preferencial==1){
        novaSenha->pref=1;
    }else{
        novaSenha->pref=0;
    }
    novaSenha->prox = NULL;
    if(filaa->primeiro==NULL){
        novaSenha->codigo= 1;
        filaa->primeiro = novaSenha;
        filaa->ultimo = filaa->primeiro;
    }else{
        novaSenha->codigo = (filaa->ultimo->codigo) +1;
        filaa->ultimo->prox = novaSenha;
        filaa->ultimo = novaSenha;
    }
}

int chamaSenha(Fila * filaa, Fila * filaaDestino, int apagar){
    Senha *senhaChamada;
    int codigoChamado;
    senhaChamada = filaa->primeiro;
    codigoChamado = senhaChamada->codigo;
    filaa->primeiro = filaa->primeiro->prox;
    if(apagar==0){
        insereEstaSenha(senhaChamada, filaaDestino);
        return codigoChamado;
    }else{
        free(senhaChamada);
        return codigoChamado;
    }

}

void insereEstaSenha(Senha * senhaInserida, Fila * filaaDestino){
    senhaInserida->prox=NULL;
    if(filaaDestino->primeiro==NULL){
        filaaDestino->primeiro = senhaInserida;
        filaaDestino->ultimo = filaaDestino->primeiro;
    }else{
        filaaDestino->ultimo->prox = senhaInserida;
        filaaDestino->ultimo = senhaInserida;
    }
}

void liberaFila( Fila * filaa){
    while(filaa->primeiro !=NULL){
        chamaSenha(filaa, filaa, 1);
    }
    free(filaa);
}

void imprimeFila(char * prefixo, Fila * filaa){
    printf("FILA:\n");
    Senha * aux;
    aux = filaa->primeiro;
    if(aux == NULL){
        printf("FILA VAZIA!");
        return;
    }
    do{
        if(aux->pref==1){
            printf("%sP%d\n",prefixo,aux->codigo);
        }else{
            printf("%sC%d\n",prefixo,aux->codigo);
        }

        aux = aux->prox;
    }while( aux !=NULL );

}
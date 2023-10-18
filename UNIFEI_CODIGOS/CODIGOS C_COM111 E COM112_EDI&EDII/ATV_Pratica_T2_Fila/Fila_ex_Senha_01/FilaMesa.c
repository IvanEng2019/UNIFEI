#include <stdio.h>
#include <stdlib.h>
#include "filaMesa.h"

FilaM* criaFilaMesa(){
 FilaM *FM = (FilaM*) malloc(sizeof(FilaM));
 if(FM!=NULL){
    FM->primeiro = NULL;
    FM->ult = NULL;
 }
 return FM;
}

void insereSenhaMesa(FilaM *filaMesa,int pref){
    Sen *senhaMesa= (Sen*) malloc(sizeof(Sen));
    if(senhaMesa!=NULL){
    if(pref==1)
        senhaMesa->pref=1;
    else
        senhaMesa->pref=0;
    senhaMesa->prox = NULL;
    if(filaMesa->primeiro==NULL){
        senhaMesa->cod= 1;
        filaMesa->primeiro = senhaMesa;
        filaMesa->ult = filaMesa->primeiro;
    }
    else{
        senhaMesa->cod = (filaMesa->ult->cod) +1;
        filaMesa->ult->prox = senhaMesa;
        filaMesa->ult = senhaMesa;
    }
  }
}

int chamaSenhaMesa(FilaM* filaMesa, FilaM *destino, int del){
    if(filaMesa!=NULL){
     Sen *senhaSol = filaMesa->primeiro;
     int cod = senhaSol->cod;
     filaMesa->primeiro = filaMesa->primeiro->prox;
     if(del==0)
        inserirSenha(senhaSol, destino);
     else
        free(senhaSol);
    return cod;
    }
    return -1;
}

void inserirSenha(Sen *sInserir, FilaM *mesaDest){
    if(mesaDest !=NULL){
     sInserir->prox=NULL;
     if(mesaDest->primeiro==NULL){
         mesaDest->primeiro = sInserir;
         mesaDest->ult= mesaDest->primeiro;
     }
     else{
        mesaDest->ult->prox = sInserir;
        mesaDest->ult = sInserir;
     }
    }
}

void imprimeFilaMesa(char *desc, FilaM* filaMesa){
    if(filaMesa!=NULL){
        printf("FILA:\n");
        Sen *aux = filaMesa->primeiro;
        if(aux == NULL){
            printf("FILA ESTA VAZIA!");
        return;
        }
        do{
            if(aux->pref==1)
               printf("%sP%d\n",desc,aux->cod);
            else
              printf("%sC%d\n",desc,aux->cod);
        aux = aux->prox;
        }while( aux!=NULL );
    }
}

void liberaFilaMesa(FilaM *filaMesa){
    Sen *del, *aux = filaMesa->primeiro;
    if(filaMesa!=NULL){
        while(aux!=NULL){
            del=aux;
            aux=aux->prox;
            free(del);
        }
        free(filaMesa);
    }
}






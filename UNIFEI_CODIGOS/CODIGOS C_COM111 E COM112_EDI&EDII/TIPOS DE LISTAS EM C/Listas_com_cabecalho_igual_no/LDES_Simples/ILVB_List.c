#include<stdlib.h>
#include<stdio.h>
#include "ILVB_List.h"

///Imprime na tela as opções do usuario
int menu(){
    int op;
    printf("Operações com Lista simples:\n");
    printf("\nEscolha a opcao desejada:\nTecle:\n");
	printf("     0 para Sair\n");
	printf("     1 para Deletar toda lista.\n");
	printf("     2 para Exibir lista\n");
	printf("     3 para Adicionar no inicio\n");
	printf("     4 para Adicionar no final\n");
	printf("     5 para Escolher onde inserir: na posição desejada da lista\n");
	printf("     6 para Escolher onde inserir: Depois de um elemento especifico\n");
	printf("     7 para Escolher onde inserir: Antes de um elemento especifico\n");
	printf("     8 para inserir o dado ordenadamente\n");
	printf("     9 para Retirar do inicio\n");
	printf("     10 para Retirar do fim\n");
	printf("     11 para Escolher de onde tirar: Conforme posição da lista\n");
	printf("     12 para Escolher qual elemento retirar (busca e deleta)\nOpção: ");
	scanf("%d",&op);
	system("cls");
	return op;
}
///Função imprime opções
void opcao(int opc,celula* list){
	switch(opc){
		case 0:
			deletaLista(list);
			break;
		case 1:
			deletaLista(list);
			iniciaNoCabecalho(list);
			break;
		case 2:
			imprimeLista(list);
			break;
		case 3:
			insereInicioLista(list);
			break;
		case 4:
			insereFimLista(list);
			break;
		case 5:
			insereNaPosicaoDadaLista(list);
			break;
		case 6:
            insereListaDepoisConteudo(list);
			break;
        case 7:
            insereListaAntesConteudo(list);
			break;
        case 8:
            insereDadoOrdenado(list);
			break;
		case 9:
			removeCelulaInicio(list);
			break;
		case 10:
			removeCelulaFim(list);
			break;
		case 11:
			removePosicaoLista(list);
			break;
	    case 12:
			removeConteudoEspecifico(list);
			break;
		default:
			printf("Comando invalido\n\n");
	}
}
///Função aloca memoria uma nova celulula (ponteiro+conteudo)
celula *alocaMemoriaCelula(){
	celula *novoNo=(celula*)malloc(sizeof(celula));
	if(novoNo==NULL){
      printf("Sem memoria disponivel!\n");
      exit(1);
	}
	else
      return novoNo;
}
///Inicio da lista onde primeira celula será um cabeçalho
void iniciaNoCabecalho(celula *cabeca){
      cabeca->prox=NULL; //1ª celula aponta para nulo e nao tem conteudo
}
///Funcão que insere elemento/conteudo na lista
void insereConteudoLista(celula *novoElemento){
		printf("Novo elemento da lista: ");
		scanf("%d",&novoElemento->conteudo);
}
///verifica tamanhd da lista-retorna 0 caso esteja vazia e 1 caso tenha elemento
int listaVazia(celula *list){
	if(list->prox==NULL)
		return 0;
	else
		return 1;
}
///retorna tamanho da lista
int tamanhoLista(celula *list){
  int cont=0;
  if(listaVazia(list)){
    for(celula* noTemp=list->prox;noTemp!=NULL;noTemp=noTemp->prox)
        cont++;
  }
  return cont;
}
///imprime a lista
void imprimeLista(celula *list){
     if(!listaVazia(list))
        printf("Lista vazia.\n");
     else{
       printf("Lista:");
       for(celula* noTemp=list->prox;noTemp!=NULL;noTemp=noTemp->prox)
           printf ("%5d",noTemp->conteudo);
       printf("\n        ");
       int i,t=tamanhoLista(list);
	   for(i=0;i<t;i++)
          printf("  ^  ");
       printf("\nOrdem:");
       for(i=1;i<=t;i++)
          printf("%5d",i);
       printf("\n\n");
      }
}
///Função que deleta todos elementos da lista
void deletaLista(celula *list){
	if(listaVazia(list)){
      celula* noDel;
      celula* noTemp=list->prox;
      printf("Deletando todos elementoos da lista:\n\n");
      while(noTemp!=NULL){
           int i=0;
           noDel=noTemp;
           noTemp=noTemp->prox;
           printf("Deletado o %d elemento: %d\n",++i,noDel->conteudo);
           free(noDel);
      }/*
      celula* noTemp,* noDel;
      for(noTemp=list->prox;noTemp!=NULL;noTemp=noTemp->prox){
           noDel=noTemp;
           printf("Deletado:%d.\n",noDel->conteudo);
           free(noDel);
      }*/
      free(noTemp);
      printf("\nFoi Liberado o cabeçalho: A Lista toda.\n");
    }
    else
        printf("Lista Vazia.\n");
}
///Funcão que insere no começo da lista
void insereInicioLista(celula *list){
	celula* nova=alocaMemoriaCelula();
	insereConteudoLista(nova);
	celula* auxVelha=list->prox; //definido cabeçalho que list->prox==NULL
	list->prox=nova;
	nova->prox=auxVelha;
}
///Função que insere no fim da lista
void insereFimLista(celula *list){
	celula *nova=alocaMemoriaCelula();
	insereConteudoLista(nova);
	nova->prox=NULL;
	if(listaVazia(list)==0)
		list->prox=nova;
	else{
        celula* noTemp;
	    for(noTemp=list->prox;noTemp->prox!=NULL;noTemp=noTemp->prox);
        noTemp->prox=nova;
	}
}
///Função que insere confome a posiçao dada
void insereNaPosicaoDadaLista(celula *list){
    if(listaVazia(list)){
        int pos,t=tamanhoLista(list);
        printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ",t);
        scanf("%d",&pos);
        if(pos>=1 && pos<=t){
            if(pos==1)
                insereInicioLista(list);
            else{
                if(pos==t)
                    insereFimLista(list);
                else{
                    celula *nova=alocaMemoriaCelula();
                    insereConteudoLista(nova);
                    celula *noAux=list->prox;
                    celula *noAnt;
                    for(int i=1;i<pos;i++){
                        noAnt=noAux;
                        noAux=noAux->prox;
                    }
                    noAnt->prox=nova;
                    nova->prox=noAux;
                }
            }
        }
        else
            printf("Posição Invalida.\n");
    }
	else
		printf("Lista Vazia\n");
}
///Função que insere confome a posiçao dada
void insereDadoOrdenado(celula *list){
    if(!listaVazia(list))
       insereInicioLista(list);
    else{
        int x;
        printf("Entre com o novo dado:");
        scanf("%d",&x);
        celula *noAnt,*auxTemp;
        for(auxTemp=list->prox; auxTemp->prox!=NULL && auxTemp->conteudo<x;auxTemp=auxTemp->prox)
            noAnt=auxTemp;
        if(auxTemp==list->prox)
           insereInicioLista(list);
        else{
           celula *nova=alocaMemoriaCelula();
           printf("Confirme o dado. ");
           insereConteudoLista(nova);
           nova->prox = auxTemp;
           noAnt->prox = nova;
        }
    }
}
///busca a posição de um elemento especifico
celula *buscaUltimaPosicaoConteudo(celula *list,int x){
   celula *noTemp;
   for (noTemp=list->prox;noTemp->prox!=NULL && noTemp->conteudo!=x;noTemp=noTemp->prox);
   return noTemp;
}
///busca a posição anterior de um elemento especifico
celula *buscaPenultimaPosicaoConteudo(celula *list,int x){
   celula *penultimo;
   for(celula *ultimo=list->prox;ultimo->prox!=NULL && ultimo->conteudo!=x;ultimo=ultimo->prox)
       penultimo=ultimo;
   return penultimo;
}
///busca a utima posição da lista
celula *buscaPenultimaPosicaoLista(celula *list){
    celula *penultimo;
    for(celula *ultimo=list->prox;ultimo->prox!=NULL;ultimo=ultimo->prox)
        penultimo=ultimo;
    return penultimo;
}
///busca a penultima posição da lista
celula *buscaUltimaPosicaoLista(celula *list){
   celula *noTemp;
   for (noTemp=list->prox;noTemp->prox!=NULL;noTemp=noTemp->prox);
   return noTemp;
}
/// insere depois de um elemento especifico
void insereListaDepoisConteudo(celula *list){
   int x;
   celula *nova=alocaMemoriaCelula();
   insereConteudoLista(nova);
   printf("Quer inserir depois de qual elemento:");
   scanf("%d",&x);
   celula *posicaox=buscaUltimaPosicaoConteudo(list,x);
   nova->prox=posicaox->prox;
   posicaox->prox=nova;
}
/// insere antes de um elemento especifico
void insereListaAntesConteudo(celula *list){
   int x;
   celula *nova=alocaMemoriaCelula();
   insereConteudoLista(nova);
   printf("Quer inserir antes de qual elemento:");
   scanf("%d",&x);
   celula *anterior=buscaPenultimaPosicaoConteudo(list,x);
   celula *auxTemp=anterior->prox;
   anterior->prox=nova;
   nova->prox=auxTemp;

}
///Deleta um celula no inicio da lista
void removeCelulaInicio(celula *list){
	if(!listaVazia(list))
		printf("Lista Vazia.\n");
	else{
		celula *noDel=list->prox;
		list->prox=noDel->prox;
		printf("DELETADO: %3d\n\n", noDel->conteudo);
		free(noDel);
	}
}
///Função deleta o ultimo elemento
void removeCelulaFim(celula*list){
	if(!listaVazia(list))
		printf("Lista Vazia.\n");
	else{
	    celula *penultimo=buscaPenultimaPosicaoLista(list);
	    celula *ultimo=penultimo->prox;
		penultimo->prox=NULL;
        printf("DELETADO: %3d\n\n",ultimo->conteudo);
        free(ultimo);
	}
}
///Função que deleta o no da lista conforme posiçao dada
void removePosicaoLista(celula* list){
    if(!listaVazia(list))
		printf("Lista Vazia.\n");
	else{
        int pos,t=tamanhoLista(list);
        printf("Que posicao, [de 1 ate %d] voce deseja retirar: ",t);
        scanf("%d",&pos);
        if(pos>0 && pos<=t){
            if(pos==1)
                removeCelulaInicio(list);
            else{
                if(pos==t)
                    removeCelulaFim(list);
                else{
                    celula *anterior;
                    celula *atual=list->prox;
                    for(int i=1;i<pos;i++){
                        anterior=atual;
                        atual=atual->prox;
                    }
                    anterior->prox=atual->prox;
                    printf("DELETADO: %3d\n\n",atual->conteudo);
                    free(atual);
                }
            }
        }
        else
            printf("Posição invalida\n\n");
	}
}
/// Função que deleta o no da lista conforme conteudo dado
void removeConteudoEspecifico(celula *list){
   int x;
   printf("Quer deletar qual elemento da lista:");
   scanf("%d",&x);
   celula *penultimo=buscaPenultimaPosicaoConteudo(list,x);
   celula *posicaox=penultimo->prox;
   penultimo->prox=posicaox->prox;
   printf("DELETADO: %3d\n\n",posicaox->conteudo);
   free(posicaox);
}

/*imprime a lista inteira de forma recursiva:
void imprimeLista (celula *list) {
   if (list->prox != NULL) {
      printf ("%d\n", list>conteudo);
      imprimeLista (list->prox); }
}
busca a posição de um elemento especifico de forma recursiva
celula *buscaLista (int x, celula *list){
   if (list->prox == NULL)  return NULL;
   if (list->conteudo == x)  return list;
   return buscaList (x, list->prox); }*/

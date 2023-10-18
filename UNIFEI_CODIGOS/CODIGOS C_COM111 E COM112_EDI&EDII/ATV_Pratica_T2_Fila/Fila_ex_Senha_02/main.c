#include <stdio.h>
#include <stdlib.h>
#include "FILAENCS.h"

int main(void)
{
  Fila *SE=NULL;
  Fila *XP=NULL;
  Fila *XC=NULL;
  Fila *NP=NULL;
  Fila *NC=NULL;
  int opcao,n, cf=0;
  char cp,ta;
  do{
    printf("\n\nMenu de opçoes");
    printf("\n1 - Criar fila SE.");
    printf("\n2 - Criar N senhas - numeros para senha");
    printf("\n3 - Criar 4 filas.");
    printf("\n4 - Impime senha-Remover no inicio de cada fila-");
    printf("\n6 - Sair");
    printf("\nOpçao: ");
    scanf("%d", &opcao);

    switch(opcao)
    {
      case 1:
        SE = criar_fila();
        if(SE != NULL)
          printf("Lista criada com sucesso!");
        else
          printf("Lista nao criada!");
        break;
      case 2:
        printf("Entre com o numero de atendimetos diarios.\n");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            if(enfileirar(SE,i) == 0)
                printf("Inser��o n�o realizada.");
        }
        break;
      case 3:
        if(SE!=NULL){
            printf("Entre com o tipo de atendimento (X) para Caixa e (N) para Negocial.");
            scanf(" %c",&ta);
            printf("Entre com o perfil do cliente (P) para Preferencial e (C) para Convencional.");
            scanf(" %c",&cp);
            if(ta =='X'&& cp =='P')
            {
                if(XP==NULL)
                {
                    XP=criar_fila();
                    if(XP==NULL){
                        printf("Lista n�o criada!");
                        break;
                    }
                }
                if(preenche_senha(XP,SE,ta,cp)==1)
                {
                  if(imprime_fila(XP) == 0)
                    printf("N�o existe fila XP.\n");
                }
                else
                    printf("Fila XP n�o pode gerar senha.\n");
            }
            if(ta=='X'&& cp=='C')
            {
                if(XC==NULL)
                {
                    XC=criar_fila();
                    if(XC == NULL)
                    {
                        printf("Lista n�o criada!");
                      break;
                    }
                }
                if(preenche_senha(XC,SE,ta,cp)==1)
                {
                  if(imprime_fila(XC) == 0)
                    printf("N�o existe fila XC.\n");
                }
                else
                    printf("Fila XC n�o pode gerar senha.\n");
            }
            if(ta=='N'&& cp=='P')
            {
                if(NP==NULL)
                {
                    NP=criar_fila();
                    if(NP == NULL)
                    {
                        printf("Lista n�o criada!");
                        break;
                    }
                }
                if(preenche_senha(NP,SE,ta,cp)==1)
                {
                  if(imprime_fila(NP) == 0)
                    printf("N�o existe fila NP.\n");
                }
                else
                    printf("Fila NP n�o pode gerar senha.\n");
            }
             if(ta=='N'&& cp=='C')
             {
                if(NC==NULL)
                {
                    NC=criar_fila();
                    if(NC == NULL)
                    {
                        printf("Lista n�o criada!");
                        break;
                    }
                }
                if(preenche_senha(NC,SE,ta,cp)==1)
                {
                  if(imprime_fila(NC) == 0)
                    printf("N�o existe fila NC.\n");
                }
                else
                    printf("Fila NC n�o pode gerar senha.\n");
            }
           cf=1;
         }
         else
            printf("Defina o numero de atendimentos diarios primeiro.");
         break;
      case 4: //(XP) Caixa Preferencial, (XC) Caixa Convencional, (NP) Negocial Preferencial, (NC) Negocial Convencional
          if(cf==1)
          {
            if(rand()%2==1)
            {//(Negocial ou Caixa
                  if(NP!=NULL)
                  {
                      if(imprime_senha(NP)) 
                      {
                          if(desinfileirar(NP) == 1)
                          printf("Remo��o se senha NP realizada com sucesso!");
                      }
                  }
                  else
                      printf("Fila NP esta fazia.\n");
            }
          }
          else
            printf("Filas ianda nao foram criadas");
        break;
      case 5:
        liberar_fila(SE);
        liberar_fila(NC);
        liberar_fila(NP);
        liberar_fila(XP);
        liberar_fila(XC);
        printf("\nFinalizando...");
        break;
      default:
        printf("\nOp��o inv�lida!");
        break;
    }
  }while(opcao!=6);
  return 0;
}

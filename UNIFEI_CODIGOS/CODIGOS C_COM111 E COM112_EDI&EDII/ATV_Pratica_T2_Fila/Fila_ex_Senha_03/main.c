#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fila.h"

Fila * XC;
Fila * XP;
Fila * NC;
Fila * NP;
Fila * MESAN;
Fila * MESAC;
int sequenciaPref=0;
int limiteDiario, opcao;
int atendimentosXC =0;
int atendimentosXP =0;
int atendimentosNC =0;
int atendimentosNP=0;
int totalAtendimentos=0;
int totalSenhasTiradas=0;

int main(){
    srand(time(NULL));

    XC = criaFila();
    XP = criaFila();
    NC = criaFila();
    NP = criaFila();
    MESAN = criaFila();
    MESAC= criaFila();
    printf("Digite o limite diario de Atendimentos:");
    scanf("%d",&limiteDiario);
    printf("Limite de [%d] Atendimentos estabelecido",limiteDiario );
    do {

        printf("\n \n Selecione uma opcao:");


        if(totalSenhasTiradas==limiteDiario){
           printf("\n [INDISPONIVEL] - Retirar Senha");
        }else{
            printf("\n [1] - Retirar senha");
        }
        if(totalSenhasTiradas>0){
          printf("\n [2] - Chamar senha");
        }else{
            printf("\n [INDISPONIVEL] - Chamar senha");
        }


        printf("\n OPCAO:");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                if(totalSenhasTiradas==limiteDiario){
                    system("cls");
                    printf("MAXIMO DE SENHAS ATINGITO");
                 }else{
                    menuRetira();
                    totalSenhasTiradas++;
                }
                break;
            case 2:
                if(totalSenhasTiradas>0){
                    menuChama();
                }else{
                    system("cls");
                    printf("NENHUMA SEHA FOI RETIRADA AINDA");
                }



                break;
            default:
                system("cls");
                printf("\nOPCAO INVALIDA");
                break;
        }
    }while(totalAtendimentos!=limiteDiario);

    printf("\n FIM DO ATENDIEMNTO \n");
    printf("TOTAL DE ATENDIMENTOS CAIXA: %d \n",atendimentosXC+atendimentosXP);
    printf("TOTAL DE ATENDIMENTOS NEGOCIAL: %d \n",atendimentosNC+atendimentosNP);
    liberaFila(XC);
    liberaFila(XP);
    liberaFila(NC);
    liberaFila(NP);
    printf("SENHAS CHAMADAS MESA CAIXA:  \n");
    imprimeFila("X",MESAC);
    printf("SENHAS CHAMADAS MESA NEGOCIAL:  \n");
    imprimeFila("N",MESAN);
    liberaFila(MESAC);
    liberaFila(MESAN);
    return 0;
}

void menuRetira(){
    int tipoAtendimento, tipoPerfil;
    system("cls");
    printf("Selecione o tipo de atendimento:");
    printf("\n[1]-CAIXA");
    printf("\n[2]-NEGOCIAL");
    printf("\nOPCAO:");
    scanf("%d",&tipoAtendimento);
    printf("\nSelecione o tipo do perfil:");
    printf("\n[1]-CONVENCIONAL");
    printf("\n[2]-PREFERENCIAL");
    printf("\nOPCAO:");
    scanf("%d",&tipoPerfil);
    system("cls");
    if(tipoAtendimento==1){
        if(tipoPerfil==1){
            insereSenha(XC,0);
            imprimeFila("X",XC);
        }else{
            insereSenha(XP,1);
            imprimeFila("X",XP);
        }
    }else{
        if(tipoPerfil==1){
            insereSenha(NC,0);
            imprimeFila("N",NC);
        }else{
            insereSenha(NP,1);
            imprimeFila("N",NP);
        }
    }
}

menuChama(){
    system("cls");

    if((sequenciaPref<2 && (XP->primeiro !=NULL || NP->primeiro !=NULL)) || (XC->primeiro ==NULL && NC->primeiro==NULL)){
        sequenciaPref++;
        if(((rand() % 100) >=50 && XP->primeiro != NULL)){
            printf("SENHA CHAMADA: XP%d",chamaSenha(XP,MESAC,0));
            atendimentosXP++;
        }else{
            printf("SENHA CHAMADA: NP%d",chamaSenha(NP, MESAN,0));
            atendimentosNP++;
        }

    }else{
        sequenciaPref=0;
        if(((rand() % 100) >=50 && XC->primeiro != NULL) || NC->primeiro==NULL){
            printf("SENHA CHAMADA: XC%d",chamaSenha(XC, MESAC,0));
            atendimentosXC++;
        }else{
            printf("SENHA CHAMADA: NC%d",chamaSenha(NC, MESAN,0));
            atendimentosNC++;
        }
    }
    totalAtendimentos++;
}
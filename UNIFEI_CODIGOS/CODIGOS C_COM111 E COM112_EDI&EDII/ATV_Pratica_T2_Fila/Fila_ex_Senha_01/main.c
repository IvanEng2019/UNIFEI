#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "filaMesa.h"

int main()
{
    int contPref=0,contXC=0,contXP=0,contNC=0,contNP=0, totalAtend=0, falta=0;
    int opcao,numAtendDiarios;

    FilaM *XC=criaFilaMesa();
    FilaM *XP=criaFilaMesa();
    FilaM *NC=criaFilaMesa();
    FilaM *NP=criaFilaMesa();
    FilaM *MESA1=criaFilaMesa();
    FilaM *MESA2=criaFilaMesa();
    do
    {
        printf("Quantos atendimentos diarios(Numero de Atendimentos maior que 0):");
        scanf("%d",&numAtendDiarios);
    }
    while(numAtendDiarios<1);
    printf("Serão atendidos %d\n",numAtendDiarios);
    do
    {
        printf("\n\nSelecione uma opcao:");


        if(falta==numAtendDiarios)
        {
            printf("\nIndisponivel - Retirar Senha");
        }
        else
        {
            printf("\n [1] - Retirar senha");
        }
        if(falta>0)
        {
            printf("\n [2] - Chamar senha");
        }
        else
        {
            printf("\n [Indisponivel] - Chamar senha");
        }
        printf("\n Opcao:");
        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            if(falta==numAtendDiarios)
            {
                printf("Senha acabou.");
            }
            else
            {
                int tipoAt, tipoPer;
                printf("Selecione o tipo de atendimento:");
                printf("\n[1]-CAIXA");
                printf("\n[2]-NEGOCIAL");
                printf("\nOPCAO:");
                scanf("%d",&tipoAt);
                printf("\nSelecione o tipo do perfil:");
                printf("\n[1]-CONVENCIONAL");
                printf("\n[2]-PREFERENCIAL");
                printf("\nOPCAO:");
                scanf("%d",&tipoPer);
                if(tipoAt==1)
                {
                    if(tipoPer==1)
                    {
                        insereSenhaMesa(XC,0);
                        imprimeFilaMesa("X",XC);
                    }
                    else
                    {
                        insereSenhaMesa(XP,1);
                        imprimeFilaMesa("X",XP);
                    }
                }
                else
                {
                    if(tipoPer==1)
                    {
                        insereSenhaMesa(NC,0);
                        imprimeFilaMesa("N",NC);
                    }
                    else
                    {
                        insereSenhaMesa(NP,1);
                        imprimeFilaMesa("N",NP);
                    }
                }
                falta++;
            }
            break;
        case 2:
            if(falta>0)
            {

                if((contPref<2 && (XP->primeiro !=NULL || NP->primeiro !=NULL)) || (XC->primeiro ==NULL && NC->primeiro==NULL))
                {
                    contPref++;
                    if(((rand() % 2)==1 && XP->primeiro != NULL))
                    {
                        printf("Chamando Sennha: XP%d",chamaSenhaMesa(XP,MESA2,0));
                        contXP++;
                    }
                    else
                    {
                        printf("chamando senha: NP%d",chamaSenhaMesa(NP, MESA1,0));
                        contNP++;
                    }
                }
                else
                {
                    contPref=0;
                    if(((rand() % 2)==1 && XC->primeiro != NULL) || NC->primeiro==NULL)
                    {
                        printf("chamando senha: XC%d",chamaSenhaMesa(XC, MESA2,0));
                        contXC++;
                    }
                    else
                    {
                        printf("SENHA CHAMADA: NC%d",chamaSenhaMesa(NC, MESA1,0));
                        contNC++;
                    }
                }
            totalAtend++;
        }
        else
        {
            printf("Nenhuma senha foi tirada");
        }
        break;
    default:
        printf("\nOpcao invalida");
        break;
    }
}
while(falta!=numAtendDiarios);
printf("\n Atendimentos Finalizados \n");
printf("Total atendidos na mesa caixa %d \n",contXC+contXP);
printf("Total atendidos na mesa Negocial: %d \n",contNC+contNP);
liberaFilaMesa(XC);
liberaFilaMesa(XP);
liberaFilaMesa(NC);
liberaFilaMesa(NP);

printf("Senhas atendidas na mesa caixa: \n");
imprimeFilaMesa("X",MESA2);
printf("Senhas atendidas na mesa negocial: \n");
imprimeFilaMesa("N",MESA1);
liberaFilaMesa(MESA1);
liberaFilaMesa(MESA2);
return 0;
}


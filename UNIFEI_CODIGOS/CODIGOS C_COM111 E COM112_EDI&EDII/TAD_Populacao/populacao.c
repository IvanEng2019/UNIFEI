#include <stdio.h>
#include "populacao.h"

void cadastro (int n, pessoa *pes ){
    for (int i=0; i<n; i++)    {
        printf ("Entre com com dos olhos, sexo, cabelo e idade respectivamente:");
        scanf(" %c %c %c %d",&pes[i].olhos, &pes[i].sex, &pes[i].cab, &pes[i].id);
    }
}
float mediab(int n, pessoa *pes){
    int soma=0,cont=0;
    for (int i=0; i<n; i++){
        if( pes[i].olhos=='C' && pes[i].cab=='P'){
            soma+=pes[i].id;
            cont++;
        }
    }
    return (float)soma/cont;
}
int mid(int n, pessoa * pes){
    int maior=pes[0].id;
    for(int i=1; i<n; i++)
        if(maior<pes[i].id)
            maior=pes[i].id;
    return maior;
}
int qtdfem (int n, pessoa *pes){
    int qtd=0;
    for(int i=0;i<n;i++)
        if (pes[i].sex=='F'&& pes[i].olhos=='A' && pes[i].cab=='L' && pes[i].id>=18 && pes[i].id<=35)
            qtd++;
    return qtd;
}
void mat(int n, pessoa *pes, int **m){
     for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
            if(i==j)
               m[i][j]= pes[i].id;
            else
               m[i][j]=0;
      for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            printf("m[%d][%d]=%d\n",i,j,m[i][j]);
}

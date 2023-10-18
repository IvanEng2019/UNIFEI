/***************************************************************
Faça um programa que multiplique os valores de um vetor A pelos
valores da mesma posição do vetor B de no maximo 20 elementos.
O tamanho de cada vetor e os valores deverão ser fornecido pelo
usuario e caso um vetor seja maior, o restante do vetor resultante
deverá ser preenchido pelo valor do vetor maior.
****************************************************************/
#include<stdio.h>

int main(){
    int i, tamA, tamB,tamMaior,tamMenor, A[20], B[20], C[20];
    printf("Entre com a quantidade do tamanho do vetor A:");
    scanf("%d",&tamA);
    for(i=0;i<tamA;i++)
    {
     printf("Entre com a o valor do vetor A[%d]:",i);
     scanf("%d",&A[i]);
    }
    printf("Entre com a quantidade do tamanho do vetor B:");
    scanf("%d",&tamB);

    for(i=0;i<tamB;i++)
    {
     printf("Entre com a o valor do vetor B[%d]:",i);
     scanf("%d",&B[i]);
    }
    if(tamA>tamB)
    {
      tamMaior=tamA;
      tamMenor=tamB;
    }
    else
    {
      tamMaior=tamB;
      tamMenor=tamA;
    }
    for(i=0;i<tamMenor;i++)
        C[i]=A[i]*B[i];

    if(tamA!=tamB)
    {
        for(i=tamMenor;i<tamMaior;i++)
        {
            if(tamMaior==tamA)
                C[i]=A[i];
            else
                C[i]=B[i];
        }
    }
    printf("Os valores resultante do vetor C:\n");
    for(i=0;i<tamMaior;i++)
        printf("C[%d]=%d.\n",i,C[i]);

return 0;
}

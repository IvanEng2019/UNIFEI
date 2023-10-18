#include<stdio.h>
int main()
{
    int n, x,i,vet[20],cont=0;
    printf("\nEntre com a quantidade de numeros a serem lidos:");
    scanf("%d",&n);
    for(i=0;i<3;i++)
    {
         printf("\nEntre com o valor:");
         scanf("%d",&vet[i]);
    }
    printf("\nQual numero deseja saber qnatas vezes repete:");
    scanf("%d",&x);
    for(i=0;i<3;i++)
    {
         if(x==vet[i])
            cont++;
    }
     printf("\nO %d repete %d vezes.\n", x,cont);
     return 0;
}

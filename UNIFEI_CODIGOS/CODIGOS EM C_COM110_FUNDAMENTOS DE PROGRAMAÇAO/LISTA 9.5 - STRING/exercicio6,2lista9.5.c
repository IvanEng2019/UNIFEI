/****************************************************************************************************
6.	Elabore uma fun��o que receba uma matriz de nomes e um nome e retorne -1 se o nome n�o est� na
matriz. Caso o nome seja encontrado, retorne o �ndice da linha. Use esta fun��o e a fun��o do
 exerc�cio 3 para preencher uma matriz de nomes digitados pelo usu�rio e verificar se o nome
  �Jo�o Francisco da Silva� foi digitado. A quantidade de nomes que dever�o ser preenchidos dever�
  ser fornecida pelo usu�rio.
*****************************************************************************************************/

#include <stdio.h>
#include <string.h>

int igual(char nomes[50][101],char nom[],int qtd)
{
    int r;
    for(int i=0;i<qtd;i++)
    {
        if(strcmp(nomes[i],nom)==0)
        {
           r=i;
           i=qtd;
        }
        else
           r= -1;
    }
    return r;

}
void preencha(char cad[50][101], int tam)
{
    for(int i=0;i<tam;i++)
    {
        printf("Entre com o nome:");
        scanf(" %[^\n]",cad[i]);
    }
    return;
}
int main(){
    int n,ret;
    char cadeia [50][101], nome[101];
    printf("Entre com o numero de nomes(1-50):");
    scanf("%d",&n);
    preencha(cadeia,n);
    strcpy(nome,"pedro");// Jo�o Francisco da Silva");
    ret=igual(cadeia,nome,n);
    if(ret==-1)
        printf("O nome %s n�o esta na lista.\n",nome);
    else
        printf("O nome %s esta na lista na linha %d.\n",nome,ret+1);

    printf("\nMatriz completa:\n");
    for(int i=0;i<n;i++)
        printf("Nome: %s\n",cadeia [i]);

return 0;
}

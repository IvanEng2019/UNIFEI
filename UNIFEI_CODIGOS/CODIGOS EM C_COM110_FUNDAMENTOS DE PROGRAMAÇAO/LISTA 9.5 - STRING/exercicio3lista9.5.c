/****************************************************************************************************
3.	Elabore uma função que receba n nomes do usuário (n<=50) e armazene esses nomes em uma matriz
passada como parâmetro. Na matriz de nomes, cada linha deve corresponder a um nome digitado.
O tamanho máximo de um nome é 100 (caracteres).
*****************************************************************************************************/

#include <stdio.h>
#include <string.h> // funçoes de strings:
//strcpy(cadeia1,cadeia 2) -> copia da 2 para  1. ex strcpy(palavra,"maria)
//strlen - fornece o tamanho da cadeia
//strcmp - compara se são iguais retornado 0 se forem iguais.se o numero retornado for maior q 0 significa q a 1 é maior que a segunda em ordem alfabetica

void preencha(char cad[3][101], int tam)
{
    for(int i=0;i<tam;i++)
    {
        printf("Entre com o nome:");
        scanf(" %[^\n]",cad[i]);
    }
    return;
}
int main(){
    int n;
    char cadeia [3][101];
    printf("Entre com o numero de nomes(1-50):");
    scanf("%d",&n);
    preencha(cadeia,n);
    for(int i=0;i<n;i++)
        printf("Nome: %s\n",cadeia [i]);

return 0;
}

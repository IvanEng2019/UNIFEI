/***************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 09/08/2018

Exercício:
1. Foi realizada uma pesquisa sobre algumas características físicas de n habitantes de uma região.
Foram coletados os seguintes dados de cada habitante:
(a)
 sexo: M - masculino, ou F - feminino;
(b)
 cor dos olhos: A - azuis, ou C - castanhos;
(c)
 cor dos cabelos: L - louros, P - pretos, ou C - castanhos;
(d)
 idade.
Faça um programa em linguagem C que leia a quantidade n de habitantes da região e imprima
os valores calculados pelas funções a seguir:
(a) Que leia esses dados, armazenando-os em vetores (um vetor para cada característica).
(b) Que determine e devolva ao programa principal a média de idade das pessoas com olhos
castanhos e cabelos pretos.
(c) Que determine e devolva ao programa principal a maior idade entre os habitantes.
(d) Que determine e devolva ao programa principal a quantidade de indivíduos do sexo femi-
nino com idade entre 18 e 35 anos (inclusive) e que tenham olhos azuis e cabelos louros.
(e) Que preencha a diagonal principal de uma matriz M de tamanho nxn com a idade dos
habitantes, o restante das posições devem ter valor zero.

Observação:
 os vetores, a matriz e a variável n devem ser declarados dentro do programa
principal e passados para as funções usando passagem de parâmetros, conforme a necessidade.

****************************************************************************************/
#include <stdio.h>
#define MAX 5

void cadastro (int n, char olhos[], char sex[], char cab[], int id[] );//nao precisa colocar o tamanho do vetor
float mediab(int n, char olhos[], char cab[], int id[]);
int mid(int n, int id[]);
int qtdfem (int n, char olhos[], char sex[], char cab[], int id[] );
void mat(int n, int id[], int m[][MAX]);//na matriz tem a necessidade de colocar o nº/tamanho das colunas

int main(){
    printf("Program em C q le a quantidade n de habitantes da região e imprime alguns os valores.\n");
    int n, id[MAX], M[MAX][MAX];
    char olhos[MAX],sex[MAX], cab[MAX];
    printf("Entre com a aquantidade de habitantes:");
    scanf("%d",&n);
    cadastro(n,olhos,sex,cab,id);
    printf ("Média de idade das pessoas com olhos castanhos e cabelos pretos:%.2f\n",mediab(n,olhos,cab,id));
    printf("A maior idade entre os habitantes: %d\n", mid(n,id));
    printf("A qtd de mulheres com idade entre 18 e 35 anos (inclusive) e deolhos azuis e cabelos louros: %d\n",qtdfem(n,olhos,sex,cab,id));
    printf("\nA diagonal principal da matriz M de tamanho nxn apresenta a idade dos habitantes e o restante das posições tem valor zero.\n");
    mat(n,id,M);
return 0;
}

void cadastro (int n, char olhos[], char sex[], char cab[], int id[] ){
    for (int i=0; i<n; i++)
    {
        printf ("Entre com com dos olhos, sexo, cabelo e idade respectivam,ente:");
        scanf(" %c %c %c %d",&olhos[i], &sex[i], &cab[i], &id[i]);
    }
}

float mediab(int n, char olhos[], char cabelos[], int id[]){
    float med;
    int soma=0,cont=0;
    for (int i=0; i<n; i++)
    {
        if( olhos[i]== 'C'&& cabelos[i] =='P')
            soma+=id[i];
            cont++;
    }
    med=(float)soma/cont;
    return med;
}

int mid(int n, int id[])
{
    int maior=id[0];
    for(int i=1; i<n; i++)
    {
        if(maior<id[i])
            maior=id[i];
    }
    return maior;
}

int qtdfem (int n, char olhos[], char sex[], char cab[], int id[] ){
    int qtd=0;
    for(int i=0;i<n;i++)
    {
        if (sex[i]=='F'&& olhos[i]=='A' && cab[i]=='L' && id[i]>=18 && id[i]<=35)
            qtd++;
    }
    return qtd;
}

void mat(int n, int id[], int m[][n]){
     for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
            if(i==j)
               m[i][j]= id[i];
            else
               m[i][j]=0;
      for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            printf("m[%d][%d]=%d\n",i,j,m[i][j]);
}

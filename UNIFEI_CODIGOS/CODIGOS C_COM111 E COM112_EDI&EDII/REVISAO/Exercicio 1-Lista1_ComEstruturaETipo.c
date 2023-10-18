/***************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 26/08/2018

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
#include <stdlib.h>

typedef struct {
    int id;
    char olhos,sex,cab;
}pessoa;

void cadastro (int n, pessoa *pes);
float mediab(int n, pessoa *pes);
int mid(int n, pessoa *pes);
int qtdfem (int n, pessoa *pes );
void mat(int n, pessoa *pes, int **m);

int main(){
    printf("Program em C q le a quantidade n de habitantes da região e imprime alguns os valores.\n");
    int n;
    printf("Entre com a aquantidade de habitantes:");
    scanf("%d",&n);
    pessoa *p1=(pessoa*)malloc(n*sizeof(pessoa));
    cadastro(n,p1);
    printf ("Média de idade das pessoas com olhos castanhos e cabelos pretos:%.2f\n",mediab(n,p1));
    printf("A maior idade entre os habitantes: %d\n", mid(n,p1));
    printf("A qtd de mulheres com idade entre 18 e 35 anos (inclusive) e deolhos azuis e cabelos louros: %d\n",qtdfem(n,p1));
    int **M=(int*)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        M[i]=(int*)malloc(n*sizeof(int));
    printf("\nA diagonal principal da matriz M de tamanho nxn apresenta a idade dos habitantes e o restante das posições tem valor zero.\n");
    mat(n,p1,M);
    free (p1);
    for(int i=0;i<n;i++)
        free (M[i]);
    free (M);
return 0;
}
void cadastro (int n, pessoa *pes ){
    for (int i=0; i<n; i++)    {
        printf ("Entre com com dos olhos, sexo, cabelo e idade respectivam,ente:");
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

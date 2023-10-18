/* EP 10 - 04/11/2019
Ivan leoni vilas boas ra 2018009073
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned short dia;
    unsigned short mes;
    unsigned short ano;
    unsigned short hora;
    unsigned short min;
    unsigned short seg;
} data;

typedef struct
{
    char nome[8];
    char extensao[3];
    unsigned short sistema;
    unsigned short hidden;
    unsigned short archieved;
    data criacao;
    data acesso;
    unsigned long int tamanho;
    unsigned long int cluster;
} arquivo;

typedef struct
{
    char dados[512];
    unsigned long int prox;
} cluster;
int clusters[500];
int main(int argc, char *argv[])
{
    arquivo arq;
    FILE *file;
    int clusNum = 0;
    cluster c;
    file = fopen("Disco.dat", "r+b");
    fseek(file, 0, SEEK_SET);
    while (!feof(file))
    {
        fread(&arq, sizeof(arquivo), 1, file);
        if (!strcmp("EXT4", arq.nome)){
            printf("\nArquivo %s encontrado!\n", arq.nome);
            break;
        }
    }
    unsigned long int totalTamanho = arq.tamanho;
    unsigned long int tamanhoArquivo = arq.tamanho;
    unsigned long int atual = arq.cluster;
    while (!feof(file)){
        fseek(file, sizeof (cluster) * atual, SEEK_SET);
        fread(&c, sizeof (cluster), 1, file);
        clusters[clusNum] = atual;
        if (c.prox){
            printf("\n%s", c.dados);
            atual = c.prox;
            tamanhoArquivo -= 512;
            clusNum++;
        }
        else{
            for (int i = 0;i < tamanhoArquivo; i++)
                printf("%c",c.dados[i]);
             clusNum++;
            break;
        }
    }
    printf("Clusters: %d\n", clusNum);
    fclose(file);
}


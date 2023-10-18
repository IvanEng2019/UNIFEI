//// Lendo structs do arquivo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CaminhoArquivo "/Users/Ivan/Documents/Leitura/Diretorio.dat"

typedef struct {
    unsigned short dia;
    unsigned short mes;
    unsigned short ano;
    unsigned short hora;
    unsigned short min;
    unsigned short seg;
}data;

typedef struct{
    char nome[10]; //nome do arquivo iniciado com o hexadecimal 0ebh são arquivos deletados
    char extensao[3];
    // Proteção
    unsigned short sistema; //arquivo do sistema
    unsigned short hidden; //arquivo oculto unsigned short archieved; //arquivo arquivado // Data e hora da criação
    data criacao;
    data acesso;    // Data do último acesso
    unsigned long int tamanho;   // Tamanho
    unsigned long int cluster;// Cluster inicial
}arquivo;

int main( int argc, char *argv[ ] ){
    printf("Argumento = %s\n",argv[1]);
    FILE *file;
    arquivo leitura;
    file = fopen(CaminhoArquivo,"r");
    int contalinha = 1;

    if(argc == 1) { // Sem argumentos
        while( !feof(file) ) {
            //fflush(stdin);
            fread(&leitura, sizeof(arquivo), 1, file);

            if (contalinha < 6) {
                printf("%s.%s ", leitura.nome, leitura.extensao);
                contalinha++;
            }else{
                contalinha = 0;
                printf("\n");
                printf("%s.%s ", leitura.nome, leitura.extensao);
                contalinha++;
            }
        }
    }
    printf("Data = %d\n",leitura.criacao.hora);

    fclose(file);
    return 0;
}
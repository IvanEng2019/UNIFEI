/***************************************************************
*  Código em C de descriptografia                              *
*  No terminal do Windows:                                     *
*  Vá ate o diretório que contem o arquivo Descriptografia.c   *
*  Para compilar: gcc Descriptografia.c -o descifragem         *
*  Para executar: descifragem                                  *
***************************************************************/

///bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Definição de constantes
#define TAM 100 //Tamanho da mensagem
#define TK 8 //tamanho da chave
#define TH 10 //tamanho do resumo + 1
#define TN 30 //tamanho dos nomes dos arquivos

typedef unsigned char byte;
int flag = 0;

///Função que ira realizar a decodificação
void Decifra(byte *bloco,char *chave, int itens){

    //printf("\nDecriptografando...\n");
    for( int i=0; i<itens; i++){
        // se o bit for par
        if (i%2 == 0){
            bloco[i] = (bloco[i]) - (chave[i] << 1);
            bloco[i] = (bloco[i]) << 1;
            //Correca BUG perda de bits ao fim do byte
            if (flag >2 && flag <= 10 && flag!=6)
                 bloco[i] += 1;
            if (flag >= 22 && flag <= 34)
                bloco[i] += 1;
            if (flag >= 46 && flag <= 58)
                bloco[i] += 1;
        }
        else{
            bloco[i] = (bloco[i]) - (chave[i] >> 1);
            bloco[i] = (bloco[i]) >> 1;
        }
        flag += 1;
        //printf("[%d] = %3d = %c\n", i, bloco[i], bloco[i]);
    }
    //printf("\nfim descriptografia!\n\n");
}

///Função que ira retornar um resumo do tipo inteiro dada a mensagem e seu tamanho
unsigned int hash(const char* str, unsigned int itens){

   unsigned int seed = 131;
   unsigned int hash = 0;

   for (int i = 0; i < itens; ++str, ++i)
      hash = (hash * seed) + (*str);
   return hash;
}


int main(int argc, const char * argv[]) {

    ///Declaração de variáveis
    char dados[TAM], msg[TAM],ChaveCifragem[TK],resumoCrip[TH],strResumoMsg[TH];
    char NomeArquivoEntrada[TN], NomeArquivoSaida[TN];
    FILE *ArquivoEntrada,*ArquivoSaida;
    unsigned int resumoMsg;
    int  Itens,j=0, qtd=0;

    ///Limpeza de buffer
    memset(dados, 0, TAM);
    memset(ChaveCifragem, 0, TK);
    memset(msg, 0, TAM);
    memset(resumoCrip, 0, TH);
    memset(strResumoMsg, 0, TH);

    ///Introdução
    for(int i=0; i<78; i++)
        printf ("*");
    printf("\n\nDescriptografia com chave simetrica de 8 digitos e hash de tamanho fixo 9:");
    printf("\nRealiza separacao da MSG e do resumo depois faz um novo resumo da MSG\nseparada e descriptografa o resumo recebido,");
    printf(" em seguida compara os resumos:\no resumo da MSG e o resumo descriptografado:");
    printf("Se iguais forem verifica a\ngarantia de autenticidade pela hash e confidencialidade pela chave e,\n");
    printf("por fim se cria um novo arquivo .txt somente com a MSG original.\n\n");
    for(int i=0; i<78; i++)
        printf ("*");

    ///Entrada de dados do usuário
    printf("\n\nEntre com o Nome do Arquivo Cifrado = ");
    scanf("%s",NomeArquivoEntrada);
    printf("Entre com o Nome do Arquivo para Destino = ");
    scanf("%s",NomeArquivoSaida);
    printf("Entre com a senha de 8 digitos = ");
    scanf("%s",ChaveCifragem);
    printf ("\n");
    for(int i=0; i<78; i++)
        printf ("*");

    ///Abertura de arquivo para leitura
    ArquivoEntrada  = fopen(NomeArquivoEntrada,"rb");
    Itens = fread(dados,1,TAM,ArquivoEntrada);
    printf ("\n\nMSG Completa recebida do arquivo %s (Msg+resumo criptografado):\n\n%s\n", NomeArquivoEntrada, dados);
    printf ("\nTamanho MSG do arquivo %s: %d\n\n", NomeArquivoEntrada, Itens);
    for(int i=0; i<78; i++)
        printf ("*");

    ///separação da mensagem e do resumo
    for(int i=0; i<Itens; i++){
        if(qtd <=(Itens - TH)){
            msg[i]= dados[i];
        }
        else{
            resumoCrip[j]= dados[i];
            j++;
        }
        qtd++;
    }
    printf("\n\nSeparacao da MSG e Resumo criptografado do arquivo %s.\n",NomeArquivoEntrada);
    printf("\nMSG recebida do arquivo %s:\n\n%s\n",NomeArquivoEntrada,msg);
    printf("Tamanho total somente da Msg do arquivo %s: %d\n\n",NomeArquivoEntrada,strlen(msg));
    printf("Resumo criptografado de Tam.: %d recebido do %s: %s\n\n",strlen(resumoCrip),NomeArquivoEntrada,resumoCrip);
    for(int i=0; i<78; i++)
        printf ("*");

    resumoMsg = hash(msg,(Itens - TH + 1 )); ///transforma os dados em um resumo string(hash)
    itoa(resumoMsg,strResumoMsg,TH);///transforma o resumo de inteiro em tipo vetor de char(string)
    //sprintf(strResumoMsg, "%d", resumoMsg);
    printf("\n\nResumo gerado pela  MSG do arquivo %s: %s\n",NomeArquivoEntrada,strResumoMsg);
    //for(int i=0;i<TH-1;i++)
       //printf("[%d] = %3d = %c\n", i, strResumoMsg[i], strResumoMsg[i]);

    Decifra(resumoCrip,ChaveCifragem,TH-1);///Realiza a descriptografia
    printf("Resumo descriptografado do arquivo %s: %s\n\n", NomeArquivoEntrada,resumoCrip);
    //for(int i=0;i<TH-1;i++)
      //  printf("[%d] = %3d = %c\n", i, resumoCrip[i], resumoCrip[i]);
    for(int i=0; i<78; i++)
            printf ("*");

    if(strcmp(strResumoMsg,resumoCrip)==0){ ///Compara os resumos
        ArquivoSaida = fopen(NomeArquivoSaida,"wb"); /// Criação do arquivo de saida para gravação
        fwrite(msg,sizeof(msg),1,ArquivoSaida); ///Grava no arquivo de saida
        printf("\n\nFoi garantida a autenticacao e confidencialidade do arquivo %s.\n\n",NomeArquivoEntrada);
        for(int i=0; i<78; i++)
           printf ("*");
        printf("\n\nA seguinte MSG original foi gravada com sucesso em %s:\n\n%s",NomeArquivoSaida,msg);
        printf ("\nTamanho MSG gravada no arquivo %s: %d\n\n", NomeArquivoSaida, strlen(msg));
        fclose(ArquivoSaida); ///Fecha o arquivos de saída
    }
    else{
       printf("\n\nNão foi garantida a autenticidade e nem a confidencialidade do arquivo %s.\n",NomeArquivoEntrada);
       printf("O arquivo %s portanto não foi criado!\n\n",NomeArquivoSaida);
    }
    for(int i=0; i<78; i++)
            printf ("*");

    fclose(ArquivoEntrada);///Fecha o arquivo de entrada

    printf("\n");
    return 0;
}

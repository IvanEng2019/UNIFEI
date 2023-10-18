/***********************************************************
*  Código em C de criptografia                             *
*  No terminal do Windows:                                 *
*  Vá ate o diretório que contem o arquivo Criptografia.c  *
*  Para compilar: gcc Criptografia.c -o cifragem           *
*  Para executar: cifragem                                 *
***********************************************************/

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

///Função que ira realizar a codificação
void Cifra(byte *bloco,char *chave, int itens){

  //printf("\n\n");
  for( int i=0; i<itens; i++){
    if (i%2 == 0)
       bloco[i] = (bloco[i] >> 1) + (chave[i] << 1);
    else
        bloco[i] = (bloco[i] << 1) + (chave[i] >> 1);
    //printf("[%d] = %d = %c\n", i, bloco[i], bloco[i]);
  }
  //printf("\n");
}

///Função que ira retornar um resumo do tipo inteiro dada a mensagem e seu tamanho
unsigned int hash(const char* str, unsigned int itens){

   unsigned int seed = 131;
   unsigned int hash = 0;

   for (int i = 0; i < itens; ++str, ++i)
      hash = (hash * seed) + (*str);
   return hash;
}

int main(){

  ///declaração de variáveis
  char BlocoDados[TAM], ChaveCifragem[TK],strResumoMsg[TH];
  char NomeArquivoEntrada[TN], NomeArquivoSaida[TN];
  FILE *ArquivoEntrada,*ArquivoSaida;
  unsigned int resumoMsg;
  int  Itens;

  ///limpeza de buffer
  memset(BlocoDados, 0, TAM);
  memset(ChaveCifragem, 0, TK);
  memset(strResumoMsg, 0, TH);

  ///Introdução
  for(int i=0; i<70; i++)
    printf ("*");
  printf("\n\nCriptografia com chave simetrica de 8 digitos e hash de tamanho fixo 9:");
  printf("\nRealiza o resumo de uma MSG, em seguida o criptografa e por fim\n");
  printf("o adiciona juntamente com a MSG original em um novo arquivo .txt.\n\n");
  for(int i=0; i<70; i++)
    printf ("*");

  ///Entrada de dados do usuário
  printf("\n\nEntre com o Nome do Arquivo Original = ");
  scanf("%s",NomeArquivoEntrada);
  printf("Entre com o Nome do Arquivo para Cifragem = ");
  scanf("%s",NomeArquivoSaida);
  printf("Entre com uma senha de 8 digitos = ");
  scanf("%s",ChaveCifragem);
  for(int i=0; i<70; i++)
    printf ("*");

  ///Abertura de arquivo para leitura e gravação
  ArquivoEntrada  = fopen(NomeArquivoEntrada,"rb");
  ArquivoSaida = fopen(NomeArquivoSaida,"wb");

  do{
    Itens = fread(BlocoDados,1,TAM,ArquivoEntrada);
    printf("\n\nMsg Original do arquivo %s:\n\n%s \n",NomeArquivoEntrada,BlocoDados);
    printf("Tamanho Msg Original do arquivo %s: %d\n",NomeArquivoEntrada,Itens);

    if(Itens!=0){

      fwrite(BlocoDados,Itens,1,ArquivoSaida); ///Realiza gravação da mesagem
      resumoMsg = hash(BlocoDados,Itens); ///Realiza o resumo da mensagem
      printf("Resumo Tipo inteiro: %d\n",resumoMsg);

      itoa(resumoMsg,strResumoMsg,TH); ///Transforma o resumo do tipo inteiro em string
      //sprintf(strResumoMsg, "%d", resumoMsg);
      printf("Resumo Tipo  string: %s - Tam.:%d\n\n",strResumoMsg,strlen(strResumoMsg) );

      for(int i=0; i<70; i++)
            printf ("*");
      Cifra(strResumoMsg,ChaveCifragem,TH-1); ///Realiza a criptografia
      printf("\n\nCifra do Resumo: %s - Tam.:%d\n\n",strResumoMsg,strlen(strResumoMsg));

      for(int i=0; i<75; i++)
            printf ("*");
      if(fwrite(strResumoMsg,TH-1,1,ArquivoSaida)){///Grava o resumo criptografado no arquivo de saída
        printf("\n\nA hash foi criptografada para envio e o Arquivo %s criado com sucesso!\n\n",NomeArquivoSaida);
        for(int i=0; i<75; i++)
            printf ("*");
        fclose(ArquivoSaida); ///Fecha o arquivo de saída
      }
      else
        printf("\n\nArquivo %s não pode ser criptografado!\n",NomeArquivoSaida);
    }
  }while(!feof(ArquivoEntrada));

   memset(BlocoDados, 0, TAM);//limpeza de buffer
   ArquivoSaida  = fopen(NomeArquivoSaida,"rb");
   if(fread(BlocoDados,1,TAM,ArquivoSaida)){
       printf("\n\nMensagem final gravada no arquivo %s:\n\n%s\n", NomeArquivoSaida,BlocoDados);
       printf ("\nTamanho MSG do arquivo %s: %d\n\n",NomeArquivoSaida, strlen(BlocoDados));
   }
   else
        printf("\n\nA mensagem não foi gravada no arquivo %s!\n\n",NomeArquivoSaida);
   for(int i=0; i<70; i++)
       printf ("*");
  //Fecha os arquivos de entrada e saída
  fclose(ArquivoSaida);
  fclose(ArquivoEntrada);

  printf("\n\n");
  system ("pause");
  return 0;
}


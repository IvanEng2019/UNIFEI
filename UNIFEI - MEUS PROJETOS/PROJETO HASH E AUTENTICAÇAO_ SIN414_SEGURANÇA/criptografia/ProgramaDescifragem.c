/********************************************************
*  Para compilar gcc ProgramaBaseDescifragem.c -o descifragem *
*  Para executar ./descifragem                             *
********************************************************/


#include <stdio.h>
#include <stdlib.h>

#define TAM 9
#define SYMBOLS 256

typedef unsigned char byte;

int flag = 0;

void Decifra(byte *bloco,char *chave, int itens)
{
    int i;
    for(i=0; i<itens; i++)
    {
        
        // se o bit for par
        if (i%2 == 0){
            bloco[i] = (bloco[i]) - (chave[i] << 1);
            bloco[i] = (bloco[i]) << 1;
            //Correca BUG perda de bits ao fim do byte
            if (flag >= 0 && flag <= 10)
                bloco[i] += 1;
            if (flag >= 22 && flag <= 34)
                bloco[i] += 1;
            if (flag >= 46 && flag <= 58)
                bloco[i] += 1;
            //Correca BUG perda de bits ao fim do byte
        }else{
            bloco[i] = (bloco[i]) - (chave[i] >> 1);
            bloco[i] = (bloco[i]) >> 1;
        }
        flag += 1;
    }
}

   
int main(int argc, const char * argv[]) {
    
    char BlocoDados[TAM], ChaveCifragem[TAM];
    FILE *ArquivoEntrada,*ArquivoSaida;
    char NomeArquivoEntrada[30], NomeArquivoSaida[30];
    int  Itens;
    
    printf("Entre com o Nome do Arquivo Cifrado = ");
    scanf("%s",NomeArquivoEntrada);
    printf("Entre com o Nome do Arquivo para Destino = ");
    scanf("%s",NomeArquivoSaida);
    printf("Entre com a senha de 8 digitos = ");
    scanf("%s",ChaveCifragem);
    
    ArquivoEntrada  = fopen(NomeArquivoEntrada,"rb");
    ArquivoSaida = fopen(NomeArquivoSaida,"wb");
    do
    {
        Itens = fread(BlocoDados,1,TAM,ArquivoEntrada);
        
        if(Itens!=0)
        {
            Decifra(BlocoDados,ChaveCifragem, Itens);
            fwrite(BlocoDados,Itens,1,ArquivoSaida);
        }
    } while(!feof(ArquivoEntrada));
    
    fclose(ArquivoSaida);
    fclose(ArquivoEntrada);

    return 0;
}

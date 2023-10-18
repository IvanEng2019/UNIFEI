// As funções para manipulação de arquivo estão na biblioteca stdlib
#include<stdio.h>
#include<stdlib.h>
int main () {
int mat, i;
float nota1, nota2;
FILE *arq; //cria um ponteiro para um arquivo
/* abre o arquivo exercicioArquivo no modo leitura e gravação e atribui o endereço do arquivo ao ponteiro arq. O modo w+ abre o arquivo no inicio substituindo o conteúdo do arquivo.*/
arq = fopen("exercicioArquivo.txt","w+");
if (arq == NULL) { //se não foi possível abrir o arquivo, arq será NULL
printf("\nArquivo inválido");
exit(1); // interrompe o programa
}
else { //Caso contrário, os dados serão solicitados ao usuário
printf("\nDigite a mat:");
scanf("%d", &mat);
while (mat!=0){
printf("\nDigite a N1:");
scanf("%f", &nota1);
printf("\nDigite a N2:");
scanf("%f", &nota2);
fprintf(arq, "%d %.2f %.2f\n", mat, nota1, nota2); // grava os valores das variáveis nota1 e nota2 no arquivo apontado por arq
//o formato %.2f no fprintf salva somente duas casas decimais no arquivo
printf("\nDigite a mat:");
scanf("%d", &mat);
}
i= 1;
rewind(arq); // volta para o início do arquivo
fscanf(arq, "%d %f %f", &mat, &nota1, &nota2); //lê a primeira linha do arquivo
while (!feof(arq)) { //a função feof retorna verdadeiro se estiver no fim do arquivo
//o formato %.2f no printf imprime somente duas casas decimais
printf("\nMatricula do aluno %d: %d - Nota1: %.2f/Nota2: %.2f", i++, mat, nota1, nota2);
fscanf(arq, "%d %f %f", &mat, &nota1, &nota2); // le as demais informações do arquivo
}
}
printf("\n");
fclose(arq); //fecha o arquivo
system("pause");}

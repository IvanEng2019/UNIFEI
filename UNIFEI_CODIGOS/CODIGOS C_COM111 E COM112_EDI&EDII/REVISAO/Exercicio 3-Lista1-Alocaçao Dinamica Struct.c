/***************************************************************************************
Programador: Ivan Leoni vilas Boas Matricula: 2018009073
Professora: Elisa
Disciplina:Algoritimos e extrutura de Dados I
UNIFEI- Itajuba
Data: 12/08/2018

Exercício 3:
Crie um registro (struct) ALUNO que contenha os seguintes campos:
(a) int matricula;
(b) char nome[50];
(c) int dia_nasc;
(d) int mes_nasc;
(e) int ano_nasc;
(f) oat nota;
Escreva um programa que leia o número n de alunos a serem cadastrados. Em seguida, um
vetor V com n posições deve ser alocado dinamicamente usando uma função que retorna um
ponteiro do tipo ALUNO. O programa deve preencher o vetor V e imprimir o registro dos
alunos aprovados, isto é, com nota maior ou igual a 6,0. Para executar tais tarefas devem ser
criadas funções para:
(a) Alocar memória dinamicamente para um vetor do tipo ALUNO.
(b) Preencher o vetor de alunos.
(c) Imprimir o vetor de alunos.
(d) Preencher o registro de um aluno.
(e) Imprimir o registro de um aluno.

****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula,dia_nasc,mes_nasc,ano_nasc;
    char nome[50];
    float nota;
} aluno;

aluno *alocarVetorAlunosV(int t);
void preencherVetorAlunosV(int n, aluno *vet);
void imprimirVetorAlunosV(int n, aluno *vet);
void imprimirVetorAprovadosV(int n, aluno *vet);

int main(){
    aluno *v;
    int total;
    do{
        printf("Entre com a quantidade de alunos:");
        scanf("%d",&total);
        //Alocação Dinamica de vetor
        v = alocarVetorAlunosV(total); // chama função que aloca memória para o vetor com tamanho l*c
    }while (v == NULL);
    printf("\nCadastro de %d alunos (com vetor dinamico de %d posições):",total,total);
    preencherVetorAlunosV(total, v);// chamada de função para preencher vetor
    imprimirVetorAlunosV(total, v);// chamada de função para imprimir vetor
    imprimirVetorAprovadosV(total, v);
    free(v);
return 0;
}
aluno *alocarVetorAlunosV(int t){
  aluno *v;// declara um ponteiro de ponteiro
  v = (aluno*) malloc(t * sizeof(aluno));// aloca memória para um vetor de ponteiro com t posições do tipo (int)
  if(v == NULL){//Se v==NULL nao conseguiu alocar memoria para o vetor
    printf("Memória insuficiente! Tente Alocar memoria menor!\n");
  }
  return v;
}
void preencherVetorAlunosV(int n, aluno *vet){
  for(int i=0; i<n; i++){
     printf("\nEntre com a matricula, dia_nasc, mes_nasc, ano_nasc, a nota e o nome respectivamente:");
     setbuf(stdin, NULL);
     scanf("%d %d %d %d %f %[^\n]s",&vet[i].matricula,&vet[i].dia_nasc,&vet[i].mes_nasc,&vet[i].ano_nasc,&vet[i].nota,&vet[i].nome);
     //fflush(stdin);
    }
}
void imprimirVetorAlunosV(int n, aluno *vet){
    printf("\nDados de todos os aluno aprovados e reprovados:");
    for(int i=0; i<n; i++)
        printf("\nMatricula=%d\nDia_nas=%d-Mes_nasc=%d-Ano_nasc=%d\nNota=%.2f\nNome: %s",vet[i].matricula,vet[i].dia_nasc,vet[i].mes_nasc,vet[i].ano_nasc,vet[i].nota, vet[i].nome);
}
void imprimirVetorAprovadosV(int n, aluno *vet){
    printf("\n\nDados somente dos alunos Aprovados:");
    for(int i=0; i<n; i++)
        if(vet[i].nota>=6)
            printf("\nMatricula=%d\nDia_nas=%d-Mes_nasc=%d-Ano_nasc=%d\nNota=%.2f\nNome:%s",vet[i].matricula,vet[i].dia_nasc,vet[i].mes_nasc,vet[i].ano_nasc,vet[i].nota, vet[i].nome );
}

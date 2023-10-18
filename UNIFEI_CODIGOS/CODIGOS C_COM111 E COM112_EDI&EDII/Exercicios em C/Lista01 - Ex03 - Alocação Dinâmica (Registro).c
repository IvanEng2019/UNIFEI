#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// definindo registro aluno com os campos matricula, nome, dia, m�s e ano de nascimento e nota
typedef struct ALUNO{
  int matricula;
  char nome[MAX];
  int dia_nasc;
  int mes_nasc;
  int ano_nasc;
  float nota;
}ALUNO;

/***********************************************************************/
/** Prot�tipos de fun��es                                              */
/***********************************************************************/
ALUNO *alocarVetorInt(int n);

void preencherVetor(int n, ALUNO *v);
void imprimirVetor(int n, ALUNO *v);

void cadastrarAluno(ALUNO *aluno);
void imprimirAluno(ALUNO aluno);


/***********************************************************************/
/** Fun��o principal                                                   */
/***********************************************************************/
int main(void)
{
  int n;
  ALUNO *vetor;

  printf("\nDigite n�mero de alunos a ser cadastrado:");
  scanf("%d", &n);

  // aloca mem�ria para o vetor com tamanho n
  vetor = alocarVetorInt(n);

  printf("\n>> Cadastre %d alunos: \n", n);

  // chamada de fun��o para preencher vetor
  preencherVetor(n, vetor);

  printf("\n>> Alunos matriculados: \n", n);

  // chamada de fun��o para imprimir vetor
  imprimirVetor(n, vetor);

  printf("\n>> Alunos aprovados: \n", n);

  // imprime o registro dos alunos aprovados
  for(int i=0; i<n; i++)
  {
    printf("\n ---------------------------- ");

    if(vetor[i].nota >= 6.0){
      imprimirAluno(vetor[i]);
    }
    printf("\n ---------------------------- \n");
  }

  // desaloca mem�ria
  free(vetor);

  return 0;
}


/********************************************************************/
/** Fun��o para alocar mem�ria para vetor com n elementos           */
/********************************************************************/
ALUNO *alocarVetorInt(int n)
{
  // declara um ponteiro de ponteiro
  ALUNO *v;

  // aloca mem�ria para um vetor de ponteiro com n posi��es do tipo (int)
  v = (ALUNO*) malloc(n * sizeof(ALUNO));

  if(v == NULL){
    printf("Mem�ria insuficiente!");
  }

  return v;
}

/********************************************************************/
/** Fun��o para preencher vetor com valores digitados pelo usu�rio */
/********************************************************************/
void preencherVetor(int n, ALUNO *v)
{
  // cadastra n registros do tipo ALUNO
  for(int i=0; i<n; i++)
  {
    printf("\n ---------------------------- \n");
    cadastrarAluno(&v[i]);
    printf(" ---------------------------- \n");
  }
}

/******************************************************************/
/** Fun��o para imprimir vetor                                   */
/******************************************************************/
void imprimirVetor(int n, ALUNO *v)
{
  // imprime n registros do tipo ALUNO
  for(int i=0; i<n; i++)
  {
    printf("\n ---------------------------- ");
    imprimirAluno(v[i]);
    printf("\n ---------------------------- \n");
  }
}

/******************************************************************/
/** Fun��o para cadastrar um registro do tipo ALUNO                                   */
/******************************************************************/
void cadastrarAluno(ALUNO *aluno)
{
    do{
      printf(" Matr�cula: ");
      scanf("%d", &aluno->matricula);
    }while(aluno->matricula < 1);

    printf(" Nome: ");
    scanf("%s%*c", &aluno->nome);

    do{
      printf(" Data de nascimento (Ex: 10 2 1990): ");
      scanf("%d%d%d", &aluno->dia_nasc, &aluno->mes_nasc, &aluno->ano_nasc);
    }while( (aluno->dia_nasc < 1 || aluno->dia_nasc > 31) ||
            (aluno->mes_nasc < 1 || aluno->mes_nasc > 12) ||
            (aluno->ano_nasc < 1900 || aluno->ano_nasc > 2018) );

    do{
      printf(" Nota: ");
      scanf("%f", &aluno->nota);
    }while(aluno->nota < 0 || aluno->nota > 10);

}


/******************************************************************/
/** Fun��o para imprimir um registro do tipo ALUNO                                  */
/******************************************************************/
void imprimirAluno(ALUNO aluno)
{
    printf("\n Matr�cula: %d ", aluno.matricula);
    printf("\n Nome: %s", aluno.nome);
    printf("\n Data de nascimento: %d/%d/%d ", aluno.dia_nasc, aluno.mes_nasc, aluno.ano_nasc);
    printf("\n Nota: %.2f", aluno.nota);
}


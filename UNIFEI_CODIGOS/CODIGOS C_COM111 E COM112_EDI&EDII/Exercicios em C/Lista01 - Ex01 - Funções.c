#include <stdio.h>

// protótipos
void lerDados(int n, char sexo[], char olhos[], char cabelos[], int idade[]);
float calcularMediaIdade(int n, int idade[], char olhos[], char cabelos[]);
int calcularMaiorIdade(int n, int idade[]);
int calcularQuantidade(int n, int idade[], char sexo[], char olhos[], char cabelos[]);
void preencherMatriz(int n, int matriz[][n], int idade[]);

// função principal
int main(void) {

  int n;

  scanf("%d", &n);

  char sexo[n], olhos[n], cabelos[n];
  int idade[n], matriz[n][n];

  lerDados(n, sexo, olhos, cabelos, idade);

  printf("\nMédia: %.2f", calcularMediaIdade(n, idade, olhos, cabelos));
  printf("\nMaior: %d", calcularMaiorIdade(n, idade));
  printf("\nQtd: %d \n\n", calcularQuantidade(n, idade, sexo, olhos, cabelos));

  preencherMatriz(n, matriz, idade);

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf(" %d ", matriz[i][j]);
    }
    printf("\n");
  }



  return 0;
}

// funções
void lerDados(int n, char sexo[], char olhos[], char cabelos[], int idade[])
{
  for(int i=0; i<n; i++){

    printf("\n\n%dº habitante\n\n", i+1);

    printf(" Sexo (F ou M): ");
    scanf(" %c", &sexo[i]);

    printf(" Cor dos olhos (A ou C): ");
    scanf(" %c", &olhos[i]);

    printf(" Cor dos cabelos (L, P ou C): ");
    scanf(" %c", &cabelos[i]);

    printf(" Idade: ");
    scanf(" %d", &idade[i]);
  }
}


float calcularMediaIdade(int n, int idade[], char olhos[], char cabelos[])
{
  float soma = 0;
  int cont = 0;

  for(int i=0; i<n; i++){
    if(olhos[i] == 'C' && cabelos[i] == 'P'){
      soma = soma + idade[i];
      cont++;
    }
  }

  if(cont == 0){
    return 0;
  }

  return (float) (soma / cont);
}


int calcularMaiorIdade(int n, int idade[])
{
  int maior = idade[0];

  for(int i=1; i<n; i++){
    if(idade[i] > maior){
      maior = idade[i];
    }
  }

  return maior;
}


int calcularQuantidade(int n, int idade[], char sexo[], char olhos[], char cabelos[])
{
  int cont = 0;

  for(int i=0; i<n; i++){
    if(olhos[i] == 'A' && cabelos[i] == 'L' && sexo[i] == 'F'){
      if(idade[i] >= 18 && idade[i] <= 35){
        cont++;
      }
    }
  }

  return cont;
}


void preencherMatriz(int n, int matriz[][n], int idade[])
{
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i == j){
        matriz[i][j] = idade[i];
      }else{
        matriz[i][j] = 0;
      }
    }
  }
}

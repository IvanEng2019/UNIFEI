#include <stdio.h>

struct pessoa{
  char sexo;
  char olhos;
  char cabelos;
  int idade;
};

// protótipos
void lerDados(int n, struct pessoa p[]);
float calcularMediaIdade(int n, struct pessoa p[]);
int calcularMaiorIdade(int n, struct pessoa p[]);
int calcularQuantidade(int n, struct pessoa p[]);
void preencherMatriz(int n, int matriz[][n], struct pessoa p[]);

// função principal
int main(void) {

  int n;

  scanf("%d", &n);

  //char sexo[n], olhos[n], cabelos[n];
  //int idade[n];
  struct pessoa p[n];
  int matriz[n][n];

  lerDados(n, p);

  printf("\nMédia: %.2f", calcularMediaIdade(n, p));
  printf("\nMaior: %d", calcularMaiorIdade(n, p));
  printf("\nQtd: %d \n\n", calcularQuantidade(n, p));

  preencherMatriz(n, matriz, p);

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf(" %d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}

// funções
void lerDados(int n, struct pessoa p[])
{
  for(int i=0; i<n; i++){

    printf("\n\n%dº habitante\n\n", i+1);

    printf(" Sexo (F ou M): ");
    scanf(" %c", &p[i].sexo);

    printf(" Cor dos olhos (A ou C): ");
    scanf(" %c", &p[i].olhos);

    printf(" Cor dos cabelos (L, P ou C): ");
    scanf(" %c", &p[i].cabelos);

    printf(" Idade: ");
    scanf(" %d", &p[i].idade);
  }
}


float calcularMediaIdade(int n, struct pessoa p[])
{
  float soma = 0;
  int cont = 0;

  for(int i=0; i<n; i++){
    if(p[i].olhos == 'C' && p[i].cabelos == 'P'){
      soma = soma + p[i].idade;
      cont++;
    }
  }

  if(cont == 0){
    return 0;
  }

  return (float) (soma / cont);
}


int calcularMaiorIdade(int n, struct pessoa p[])
{
  int maior = p[0].idade;

  for(int i=1; i<n; i++){
    if(p[i].idade > maior){
      maior = p[i].idade;
    }
  }

  return maior;
}


int calcularQuantidade(int n, struct pessoa p[])
{
  int cont = 0;

  for(int i=0; i<n; i++){
    if(p[i].olhos == 'A' && p[i].cabelos == 'L' && p[i].sexo == 'F'){
      if(p[i].idade >= 18 && p[i].idade <= 35){
        cont++;
      }
    }
  }

  return cont;
}


void preencherMatriz(int n, int matriz[][n], struct pessoa p[])
{
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i == j){
        matriz[i][j] = p[i].idade;
      }else{
        matriz[i][j] = 0;
      }
    }
  }
}

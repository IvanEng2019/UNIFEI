Algoritmo "somaZero"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   :le sequ�ncia de n�meros digitados pelo usu�rio
//              at� que o n�mero 0 seja digitado e retorne a soma dos
//              n�meros digitados.

// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 24/03/2018
Var
// Se��o de Declara��es das vari�veis
    cont: inteiro
    num,soma: real
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
   soma<-0
   escreva("Entre com o numero:")
   leia(num)
   enquanto num<>0 faca
           soma<-soma+num
           escreva("Entre com um numero:")
           leia(num)
   fimenquanto
   escreval("A soma do numero �:",soma)
Fimalgoritmo
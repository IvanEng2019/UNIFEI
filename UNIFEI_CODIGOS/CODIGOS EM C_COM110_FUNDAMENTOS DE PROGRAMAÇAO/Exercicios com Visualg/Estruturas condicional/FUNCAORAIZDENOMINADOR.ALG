Algoritmo "funcaoRaizdenominador"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   :Criar um algoritmo que receba o valor de x, calcule e
//imprima o valor de f(x). Voce pode usar as fun��es matem�ticas da
//linguagem utilizada. f(x)<-(5X+3)/raizquadrada(x*x-16)

// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 19/03/2018
Var
// Se��o de Declara��es das vari�veis 
   x,y: real
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreva("Entre com o valor de x: ")
   leia(x)
   se (x>=5) entao
   y<- ((5*x)+3)/(raizQ((x*x)-16))
   fimse
   escreval("O valor da fun��o �:",y)
Fimalgoritmo
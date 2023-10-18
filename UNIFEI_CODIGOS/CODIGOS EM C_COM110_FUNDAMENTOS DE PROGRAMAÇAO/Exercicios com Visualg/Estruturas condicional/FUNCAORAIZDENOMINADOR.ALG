Algoritmo "funcaoRaizdenominador"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   :Criar um algoritmo que receba o valor de x, calcule e
//imprima o valor de f(x). Voce pode usar as funções matemáticas da
//linguagem utilizada. f(x)<-(5X+3)/raizquadrada(x*x-16)

// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 19/03/2018
Var
// Seção de Declarações das variáveis 
   x,y: real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreva("Entre com o valor de x: ")
   leia(x)
   se (x>=5) entao
   y<- ((5*x)+3)/(raizQ((x*x)-16))
   fimse
   escreval("O valor da função é:",y)
Fimalgoritmo
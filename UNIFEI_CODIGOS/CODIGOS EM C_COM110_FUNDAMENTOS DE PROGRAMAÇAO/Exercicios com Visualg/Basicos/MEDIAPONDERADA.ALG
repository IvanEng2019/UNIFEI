Algoritmo "mediaPonderada"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : calcular e exibir a m�dia ponderada de
//               2 notas dadas. (nota 1 tem peso 6 e nota 2 tem peso 4)
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 16/03/2018
Var
// Se��o de Declara��es das vari�veis 
   n1,n2,mp: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreva("Entre com a n nota 1 de peso 6:")
   leia(n1)
   escreva("Entre com a n nota 2 de peso 4:")
   leia(n2)
   mp <- ((n1*6)+(n2*4))/10
   escreva("A media ponderada �:",mp)
Fimalgoritmo
Algoritmo "custo"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : N canetas foram pagas com uma nota de Z reais,
//               obtendo-se y reais de troco. O algoritmo
//               retorno o custou unitario de cada caneta.
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 15/03/2018
Var
// Se��o de Declara��es das vari�veis 
  qtdTotal,valorNota:inteiro
  troco, custoUnitario: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreva( "Entre com a quantidade totas de canetas pagas: ")
   leia (qtdTotal)
   escreva( "Entre com o valor da nota: ")
   leia (valorNota)
   escreva ( "Entre com o valor do troco: ")
   leia (troco)
   custoUnitario <-(valorNota-troco)/qtdTotal
   escreval( "O valor unitario �: ",custoUnitario )
Fimalgoritmo
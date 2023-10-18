Algoritmo "custo"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : N canetas foram pagas com uma nota de Z reais,
//               obtendo-se y reais de troco. O algoritmo
//               retorno o custou unitario de cada caneta.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 15/03/2018
Var
// Seção de Declarações das variáveis 
  qtdTotal,valorNota:inteiro
  troco, custoUnitario: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreva( "Entre com a quantidade totas de canetas pagas: ")
   leia (qtdTotal)
   escreva( "Entre com o valor da nota: ")
   leia (valorNota)
   escreva ( "Entre com o valor do troco: ")
   leia (troco)
   custoUnitario <-(valorNota-troco)/qtdTotal
   escreval( "O valor unitario é: ",custoUnitario )
Fimalgoritmo
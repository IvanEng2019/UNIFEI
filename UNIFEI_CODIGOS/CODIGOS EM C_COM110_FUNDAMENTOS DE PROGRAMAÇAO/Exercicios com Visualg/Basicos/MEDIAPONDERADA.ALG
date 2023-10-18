Algoritmo "mediaPonderada"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : calcular e exibir a média ponderada de
//               2 notas dadas. (nota 1 tem peso 6 e nota 2 tem peso 4)
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 16/03/2018
Var
// Seção de Declarações das variáveis 
   n1,n2,mp: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreva("Entre com a n nota 1 de peso 6:")
   leia(n1)
   escreva("Entre com a n nota 2 de peso 4:")
   leia(n2)
   mp <- ((n1*6)+(n2*4))/10
   escreva("A media ponderada é:",mp)
Fimalgoritmo
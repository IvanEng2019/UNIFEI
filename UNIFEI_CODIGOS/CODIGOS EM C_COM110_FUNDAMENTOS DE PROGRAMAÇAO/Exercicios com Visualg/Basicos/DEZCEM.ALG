Algoritmo "dezcem"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Considere um número de 3 dígitos, usando os operadores
//               \ (divisão inteira) e % (resto da divisão)
//               imprimir o algarismo correspondente à centena
//               e o algarismo correspondente à dezena.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 15/03/2018
Var
// Seção de Declarações das variáveis 
   num,cem,dez: inteiro
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreva ( "Entre com um numero de tres algarismos: ")
   leia (num)
   cem <- num\100
   dez <- (num%100)\10
   escreva( "O algarismo da centana é: ",cem, " o da dezena é: ", dez)

Fimalgoritmo
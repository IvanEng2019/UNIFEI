Algoritmo "dezcem"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Considere um n�mero de 3 d�gitos, usando os operadores
//               \ (divis�o inteira) e % (resto da divis�o)
//               imprimir o algarismo correspondente � centena
//               e o algarismo correspondente � dezena.
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 15/03/2018
Var
// Se��o de Declara��es das vari�veis 
   num,cem,dez: inteiro
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreva ( "Entre com um numero de tres algarismos: ")
   leia (num)
   cem <- num\100
   dez <- (num%100)\10
   escreva( "O algarismo da centana �: ",cem, " o da dezena �: ", dez)

Fimalgoritmo
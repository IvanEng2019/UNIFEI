Algoritmo "div5e3"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : le um n�mero inteiro e verifique se � divis�vel por 5
//               e divis�vel por 3 exiba uma mensagem com esta informa��o.
//               Caso n�o seja, � necess�rio exibir uma mensagem. .
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 18/03/2018
Var
// Se��o de Declara��es das vari�veis
   num: inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
    escreva("Entre com o numero: ")
    leia(num)
    se (num%5 = 0)e (num%3 = 0) entao
       escreval("O numero digitado � divisivel por 3 e 5.")
    senao
       escreval("N�o � divisivel por 3 e 5")
    fimse
Fimalgoritmo
Algoritmo "div5e3atualizado"
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
//Se��o de Comandos, procedimento, fun��es, operadores, etc...
    escreva("Entre com o numero: ")
    leia(num)
//O reto da divisao igual a zero indica que � divisivel
//O resto da divis�o igual a 1 ou diferente de zero indica que n�o � divisivel
    se (num%5=0) e (num%3=1) entao //se o numero for divisel por 5 e nao for por 3
        escreval("O Numero digitado � divisivel apenas por 5!")
    senao
       se (num%3=0) e (num%5<>0)entao//se o numero for divisel por 3 e nao for por 5
          escreval("O Numero digitado � divisivel apenas por 3!")
       senao
          se(num%5 = 0)e(num%3 = 0) entao //se o numero for divisel por 5 e for por 3
             escreval("O numero digitado � divisivel por 3 e 5!")
          senao //se o numero nor for divisel por 5 e nao for por 3
             escreval("N�o � divisivel por 3 e nem 5!")
          fimse
      fimse
    fimse
Fimalgoritmo
Algoritmo "5� Exerc�cio - Opera��es"
// Disciplina  :  [Fundamentos de Programa��o]
// Professor   : Melise Maria Veiga de Paula
// Descri��o   : Ap�s receber 2 valores voc� seleciona o que fazer
// Autor(a)    : Adriel Douglas Nogueira Carlos e Ivan Leoni Vilas Boas
// Data atual  : 22/03/2018
Var
// Se��o de Declara��es das vari�veis 
num1,num2:real
opcao:inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreval("Entre primeiro valor e pressione enter:")
   leia(num1)
   escreval("Entre segundo valor e pressione enter:")
   leia(num2)
   escreval("Escolha uma das op��es abaixo digitando o n�mero correspondente e pressione enter")
   escreval("1 - M�dia entre os n�meros digitados.")
   escreval("2 - Diferen�a do maior pelo menor n�mero digitado.")
   escreval("3 - Produto entre os n�meros digitados.")
   escreval("4 - Divis�o do primeiro pelo segundo n�mero digitado.")
   leia(opcao)
   se (opcao<1) ou (opcao>4) entao
      escreva("Op��o n�o valida.")
   fimse
   se opcao=1 entao
      escreval("A m�dia �:",(num1+num2)/2)
   fimse
   se opcao=2 entao
      se num1>num2 entao
         escreva("A diferen�a �:",num1-num2)
      senao
           escreva("A diferen�a �:",num2-num1)
      fimse
   fimse
   se opcao=3 entao
      escreva("O produto �:",num1*num2)
   fimse
   se opcao=4 entao
      se num2=0 entao
         escreva("Opera��o imposs�vel.")
      senao
           escreva("A raz�o �:",num1/num2)
      fimse
   fimse
Fimalgoritmo
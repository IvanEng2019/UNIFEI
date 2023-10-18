Algoritmo "5º Exercício - Operações"
// Disciplina  :  [Fundamentos de Programação]
// Professor   : Melise Maria Veiga de Paula
// Descrição   : Após receber 2 valores você seleciona o que fazer
// Autor(a)    : Adriel Douglas Nogueira Carlos e Ivan Leoni Vilas Boas
// Data atual  : 22/03/2018
Var
// Seção de Declarações das variáveis 
num1,num2:real
opcao:inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreval("Entre primeiro valor e pressione enter:")
   leia(num1)
   escreval("Entre segundo valor e pressione enter:")
   leia(num2)
   escreval("Escolha uma das opções abaixo digitando o número correspondente e pressione enter")
   escreval("1 - Média entre os números digitados.")
   escreval("2 - Diferença do maior pelo menor número digitado.")
   escreval("3 - Produto entre os números digitados.")
   escreval("4 - Divisão do primeiro pelo segundo número digitado.")
   leia(opcao)
   se (opcao<1) ou (opcao>4) entao
      escreva("Opção não valida.")
   fimse
   se opcao=1 entao
      escreval("A média é:",(num1+num2)/2)
   fimse
   se opcao=2 entao
      se num1>num2 entao
         escreva("A diferença é:",num1-num2)
      senao
           escreva("A diferença é:",num2-num1)
      fimse
   fimse
   se opcao=3 entao
      escreva("O produto é:",num1*num2)
   fimse
   se opcao=4 entao
      se num2=0 entao
         escreva("Operação impossível.")
      senao
           escreva("A razão é:",num1/num2)
      fimse
   fimse
Fimalgoritmo
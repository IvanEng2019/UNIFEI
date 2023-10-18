Algoritmo "maiorDeDois"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Receba dois valores e retorne o maior deles.
//               retorno o custou unitario de cada caneta.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 18/03/2018
Var
// Seção de Declarações das variáveis 
   num1,num2, aux : real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreval ("Entre com dois numeros quaisquer:")
   leia(num1,num2)
   se (num1>num2) entao
      escreval("O maior é o primeiro digitado:",num1)
   senao
      escreval("O maior é o segundo digitado:",num2)
   fimse
Fimalgoritmo
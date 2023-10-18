Algoritmo "somaZero"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   :le sequência de números digitados pelo usuário
//              até que o número 0 seja digitado e retorne a soma dos
//              números digitados.

// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 24/03/2018
Var
// Seção de Declarações das variáveis
    cont: inteiro
    num,soma: real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...
   soma<-0
   escreva("Entre com o numero:")
   leia(num)
   enquanto num<>0 faca
           soma<-soma+num
           escreva("Entre com um numero:")
           leia(num)
   fimenquanto
   escreval("A soma do numero é:",soma)
Fimalgoritmo
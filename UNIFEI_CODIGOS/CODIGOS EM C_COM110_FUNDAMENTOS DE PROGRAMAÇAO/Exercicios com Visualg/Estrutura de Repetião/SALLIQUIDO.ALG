Algoritmo "salLiquido"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   :le o nome do funcionário, o salário bruto, o valor do desconto
//              e a gratificação do funcionário e escreva na tela o nome e
//              o valor do salário líquido. Os nomes devem ser lidos até
//              que a sequência XXXX seja digitada.

// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 24/03/2018
Var
// Seção de Declarações das variáveis
    nome:caracter
    salB,desc,grat,salL: real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...
   escreva("Entre com o nome:")
   leia(nome)
   enquanto nome<>"XXXX" faca
           escreva("Entre com o salário bruto:")
           leia(salB)
           escreva("Entre com a gratificação:")
           leia(grat)
           escreva("Entre com o valor do desconto:")
           leia(desc)
           salL<- SalB+grat-desc
           escreval("O Funcionario ",nome," recebe se salario liquido =" , salL)
           escreva("Entre com o nome:")
           leia(nome)
   fimenquanto
Fimalgoritmo
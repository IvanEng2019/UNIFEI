Algoritmo "salLiquido"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   :le o nome do funcion�rio, o sal�rio bruto, o valor do desconto
//              e a gratifica��o do funcion�rio e escreva na tela o nome e
//              o valor do sal�rio l�quido. Os nomes devem ser lidos at�
//              que a sequ�ncia XXXX seja digitada.

// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 24/03/2018
Var
// Se��o de Declara��es das vari�veis
    nome:caracter
    salB,desc,grat,salL: real
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
   escreva("Entre com o nome:")
   leia(nome)
   enquanto nome<>"XXXX" faca
           escreva("Entre com o sal�rio bruto:")
           leia(salB)
           escreva("Entre com a gratifica��o:")
           leia(grat)
           escreva("Entre com o valor do desconto:")
           leia(desc)
           salL<- SalB+grat-desc
           escreval("O Funcionario ",nome," recebe se salario liquido =" , salL)
           escreva("Entre com o nome:")
           leia(nome)
   fimenquanto
Fimalgoritmo
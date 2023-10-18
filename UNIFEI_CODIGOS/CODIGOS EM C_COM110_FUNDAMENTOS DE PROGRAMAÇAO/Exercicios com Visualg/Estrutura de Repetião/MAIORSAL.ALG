Algoritmo "maiorSal"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   : le o salário e o nome de 20 funcionários e retorne
//               o nome e o salário do funcionário que ganha mais.
//               Todos os salários são diferentes.

// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 22/03/2018
Var
// Seção de Declarações das variáveis
   i: inteiro
   sal1,maior:real
   nome,funcMaior: caracter
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...
    para i de 1 ate 20 passo 1 faca
         Escreval("Entre com o nome e o salario do funcionario respectivamente:")
         leia(nome,sal1)
         se(maior<sal1)entao
            maior<-sal1
            funcMaior<-nome
         fimse
    fimpara
    escreval("O maior salario é do ", func, " de",maior, " reais" )
Fimalgoritmo
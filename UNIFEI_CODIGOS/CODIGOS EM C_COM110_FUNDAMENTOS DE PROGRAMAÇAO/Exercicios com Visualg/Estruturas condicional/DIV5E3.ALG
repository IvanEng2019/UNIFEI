Algoritmo "div5e3"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : le um número inteiro e verifique se é divisível por 5
//               e divisível por 3 exiba uma mensagem com esta informação.
//               Caso não seja, é necessário exibir uma mensagem. .
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 18/03/2018
Var
// Seção de Declarações das variáveis
   num: inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...
    escreva("Entre com o numero: ")
    leia(num)
    se (num%5 = 0)e (num%3 = 0) entao
       escreval("O numero digitado é divisivel por 3 e 5.")
    senao
       escreval("Não é divisivel por 3 e 5")
    fimse
Fimalgoritmo
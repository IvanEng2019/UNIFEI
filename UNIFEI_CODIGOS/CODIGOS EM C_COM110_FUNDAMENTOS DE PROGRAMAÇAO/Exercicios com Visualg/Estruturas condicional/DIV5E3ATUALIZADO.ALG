Algoritmo "div5e3atualizado"
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
//Seção de Comandos, procedimento, funções, operadores, etc...
    escreva("Entre com o numero: ")
    leia(num)
//O reto da divisao igual a zero indica que é divisivel
//O resto da divisão igual a 1 ou diferente de zero indica que não é divisivel
    se (num%5=0) e (num%3=1) entao //se o numero for divisel por 5 e nao for por 3
        escreval("O Numero digitado é divisivel apenas por 5!")
    senao
       se (num%3=0) e (num%5<>0)entao//se o numero for divisel por 3 e nao for por 5
          escreval("O Numero digitado é divisivel apenas por 3!")
       senao
          se(num%5 = 0)e(num%3 = 0) entao //se o numero for divisel por 5 e for por 3
             escreval("O numero digitado é divisivel por 3 e 5!")
          senao //se o numero nor for divisel por 5 e nao for por 3
             escreval("Não é divisivel por 3 e nem 5!")
          fimse
      fimse
    fimse
Fimalgoritmo
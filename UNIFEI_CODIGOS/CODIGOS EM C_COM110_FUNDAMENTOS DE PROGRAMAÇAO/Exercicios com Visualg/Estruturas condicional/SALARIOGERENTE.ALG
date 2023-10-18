Algoritmo "salarioGerente"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : le o nome da função de um funcionário e o valor do seu salário.
//               Se a função for “Gerente”, verifique a regra abaixo.
//               Se salario < 5000, escreva “Reajuste de Salário”,
//               caso contrário, escreva “Salário Compatível”
//               Se a função não for gerente, escreva “Não é gerente”
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 18/03/2018
Var
// Seção de Declarações das variáveis
   cargo: caracter
   salario : real
Inicio
//Seção de Comandos, procedimento, funções, operadores, etc...
    escreva("Entre com a função do colaborador:")
    leia(cargo)
    escreva("Entre com o salario do colaborador:")
    leia(salario)
    se(cargo="Gerente") entao
          se (salario <5000)entao
             escreval("Reajuste de Salário")
          senao
             escreval("salario compativel.")
          fimse
    senao
      escreval("Não é gerente")
    fimse
Fimalgoritmo
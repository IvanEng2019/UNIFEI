Algoritmo "salarioGerente"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : le o nome da fun��o de um funcion�rio e o valor do seu sal�rio.
//               Se a fun��o for �Gerente�, verifique a regra abaixo.
//               Se salario < 5000, escreva �Reajuste de Sal�rio�,
//               caso contr�rio, escreva �Sal�rio Compat�vel�
//               Se a fun��o n�o for gerente, escreva �N�o � gerente�
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 18/03/2018
Var
// Se��o de Declara��es das vari�veis
   cargo: caracter
   salario : real
Inicio
//Se��o de Comandos, procedimento, fun��es, operadores, etc...
    escreva("Entre com a fun��o do colaborador:")
    leia(cargo)
    escreva("Entre com o salario do colaborador:")
    leia(salario)
    se(cargo="Gerente") entao
          se (salario <5000)entao
             escreval("Reajuste de Sal�rio")
          senao
             escreval("salario compativel.")
          fimse
    senao
      escreval("N�o � gerente")
    fimse
Fimalgoritmo
Algoritmo "maiorSal"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   : le o sal�rio e o nome de 20 funcion�rios e retorne
//               o nome e o sal�rio do funcion�rio que ganha mais.
//               Todos os sal�rios s�o diferentes.

// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 22/03/2018
Var
// Se��o de Declara��es das vari�veis
   i: inteiro
   sal1,maior:real
   nome,funcMaior: caracter
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
    para i de 1 ate 20 passo 1 faca
         Escreval("Entre com o nome e o salario do funcionario respectivamente:")
         leia(nome,sal1)
         se(maior<sal1)entao
            maior<-sal1
            funcMaior<-nome
         fimse
    fimpara
    escreval("O maior salario � do ", func, " de",maior, " reais" )
Fimalgoritmo
Algoritmo "mediaQuinze"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   :Le 15 n�meros e imprima a m�dia dos n�meros digitados

// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 22/03/2018
Var
// Se��o de Declara��es das vari�veis
   i: inteiro
   num, soma : real
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
    soma<-0
    para i de 1 ate 15 passo 1 faca
         escreva ("Entre com o ", i, "� numero:")
         leia (num)
         soma<-soma+num
    fimpara
    escreval("A media dos numero digitados �:",soma/15)
Fimalgoritmo
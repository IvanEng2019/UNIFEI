Algoritmo "somadez"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   : le 10 n�meros e imprima a soma dos n�meros digitados

// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 22/03/2018
Var
// Se��o de Declara��es das vari�veis
   i : inteiro
   num, soma : real
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
    soma<-0
    para i de 1 ate 3 passo 1 faca
         escreva ("Entre com o ", i, "� numero:")
         leia (num)
         soma<-soma+num
    fimpara
    escreval("A soma dos numero disgitados �:",soma)
Fimalgoritmo
Algoritmo "mediaQuinze"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   :Le 15 números e imprima a média dos números digitados

// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 22/03/2018
Var
// Seção de Declarações das variáveis
   i: inteiro
   num, soma : real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...
    soma<-0
    para i de 1 ate 15 passo 1 faca
         escreva ("Entre com o ", i, "º numero:")
         leia (num)
         soma<-soma+num
    fimpara
    escreval("A media dos numero digitados é:",soma/15)
Fimalgoritmo
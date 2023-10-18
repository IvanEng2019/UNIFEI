Algoritmo "somadez"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   : le 10 números e imprima a soma dos números digitados

// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 22/03/2018
Var
// Seção de Declarações das variáveis
   i : inteiro
   num, soma : real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
    soma<-0
    para i de 1 ate 3 passo 1 faca
         escreva ("Entre com o ", i, "º numero:")
         leia (num)
         soma<-soma+num
    fimpara
    escreval("A soma dos numero disgitados é:",soma)
Fimalgoritmo
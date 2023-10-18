Algoritmo "intervalo"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   : le uma quantidade desconhecida de números inteiros e
//conte quantos deles estão nos seguintes intervalos: [0-25], [26-50],
//[51-75] e [76-100].
//A entrada de dados deve terminar quando for lido um número negativo.

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
// Data atual  : 03/04/2018

Var
// Seção de Declarações das variáveis 
    n, cont1,cont2,cont3,cont4: inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   Escreva ("Entre com o numero de 0 a 100:")
   leia(n)
   enquanto n>=0 faca
            se (n>=0) e (n<=25) entao
               cont1<-Cont1+1
            senao
                 se (n>=26) e (n<= 50) entao
                     cont2<-Cont2+1
                 senao
                     se (n>=51) e (n<=75) entao
                         cont3<-Cont3+1
                     senao
                         se (n>=76) e (n<=100) entao
                            cont4<-Cont4+1
                         senao
                             escreval("Este numero não corresponde nenhum intervalo.")
                         fimse
                     fimse
                 fimse
            fimse
            Escreva ("Entre com o numero de 0 a 100:")
            leia(n)
   fimenquanto
   escreva("O nºde elementos do 1º[0-25],2º[26-50],3º[51-75] e 4º[76-100] intervalos são:",cont1,cont2,cont3,cont4)
Fimalgoritmo
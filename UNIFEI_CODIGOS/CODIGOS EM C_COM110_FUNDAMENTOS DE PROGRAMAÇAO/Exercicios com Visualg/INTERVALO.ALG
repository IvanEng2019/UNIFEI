Algoritmo "intervalo"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   : le uma quantidade desconhecida de n�meros inteiros e
//conte quantos deles est�o nos seguintes intervalos: [0-25], [26-50],
//[51-75] e [76-100].
//A entrada de dados deve terminar quando for lido um n�mero negativo.

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
// Data atual  : 03/04/2018

Var
// Se��o de Declara��es das vari�veis 
    n, cont1,cont2,cont3,cont4: inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
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
                             escreval("Este numero n�o corresponde nenhum intervalo.")
                         fimse
                     fimse
                 fimse
            fimse
            Escreva ("Entre com o numero de 0 a 100:")
            leia(n)
   fimenquanto
   escreva("O n�de elementos do 1�[0-25],2�[26-50],3�[51-75] e 4�[76-100] intervalos s�o:",cont1,cont2,cont3,cont4)
Fimalgoritmo
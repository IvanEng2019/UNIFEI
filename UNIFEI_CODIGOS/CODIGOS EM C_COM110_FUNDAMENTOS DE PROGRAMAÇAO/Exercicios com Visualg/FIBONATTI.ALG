Algoritmo "fibonaci"
// Disciplina  :  [Linguagem e L�gica de Programa��o] 
// Descri��o   : Faz a serie de Fibonaci:Soma sempre os dois ultimos elementos
// Autor(a)    : Ivan
// Data atual  : 03/04/2018
Var
// Se��o de Declara��es das vari�veis 
   lim,cont,fib,ant, atual: inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
     escreva("Entre com o limite:")
     leia(lim)
     cont <-1
     atual<-1
     ant<-0
     escreva("1,")
     enquanto cont<lim faca
               fib<-Ant + atual   //1,1,2,3,5,8,13
               ant<-atual
               atual<-fib
               cont<-cont+1
               Escreva (fib,",")
     fimenquanto
Fimalgoritmo
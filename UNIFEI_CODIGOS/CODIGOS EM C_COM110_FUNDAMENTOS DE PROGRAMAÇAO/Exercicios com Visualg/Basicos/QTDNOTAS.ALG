Algoritmo "qtdNotas"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : calcula quantas notas de 50, 10 e 1 s�o necess�rias para
//               se pagar uma conta cujo valor � fornecido
//               (numero minimo de notas possiveis)
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 15/03/2018
Var
// Se��o de Declara��es das vari�veis 
   valor,cin,dez,um: inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
     escreva("Entre com o valor da conta:")
     leia (valor)
     cin<-valor\50
     dez<-(valor%50)\10
     um<-(valor%50)%10
     escreval( " Ser�o necessarias: ", cin," notas de cinquenta reais.")
     escreval( " Ser�o necessarias: ", dez," notas de dez reais.")
     escreval( " Ser�o necessarias: ", um," notas de um real.")
Fimalgoritmo
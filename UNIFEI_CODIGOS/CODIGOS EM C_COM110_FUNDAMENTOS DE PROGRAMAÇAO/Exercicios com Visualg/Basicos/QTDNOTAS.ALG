Algoritmo "qtdNotas"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : calcula quantas notas de 50, 10 e 1 são necessárias para
//               se pagar uma conta cujo valor é fornecido
//               (numero minimo de notas possiveis)
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 15/03/2018
Var
// Seção de Declarações das variáveis 
   valor,cin,dez,um: inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
     escreva("Entre com o valor da conta:")
     leia (valor)
     cin<-valor\50
     dez<-(valor%50)\10
     um<-(valor%50)%10
     escreval( " Serão necessarias: ", cin," notas de cinquenta reais.")
     escreval( " Serão necessarias: ", dez," notas de dez reais.")
     escreval( " Serão necessarias: ", um," notas de um real.")
Fimalgoritmo
Algoritmo "divisoes"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Algoritmo retorna o valor inteiro da divis�o
//               de dois n�meros e o resto da divis�o entre
//               esses dois n�meros.
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 15/03/2018
Var
// Se��o de Declara��es das vari�veis 
   num,den : inteiro
   inter,resto : inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
     escreva ("Entre com o numerador e o denominador respectivamente: ")
     leia (num,den)
     inter <- num\den
     resto <- num%den
     escreval ( "O inteiro da divis�o de ",num," e ",den, " �: ",inter)
     escreval ( "O resto da divis�o de ",num," e ",den, " �: ",resto)
Fimalgoritmo
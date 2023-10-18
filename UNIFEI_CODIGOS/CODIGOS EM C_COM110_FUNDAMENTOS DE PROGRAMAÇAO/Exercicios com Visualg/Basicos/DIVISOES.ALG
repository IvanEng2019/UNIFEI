Algoritmo "divisoes"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Algoritmo retorna o valor inteiro da divisão
//               de dois números e o resto da divisão entre
//               esses dois números.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 15/03/2018
Var
// Seção de Declarações das variáveis 
   num,den : inteiro
   inter,resto : inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
     escreva ("Entre com o numerador e o denominador respectivamente: ")
     leia (num,den)
     inter <- num\den
     resto <- num%den
     escreval ( "O inteiro da divisão de ",num," e ",den, " é: ",inter)
     escreval ( "O resto da divisão de ",num," e ",den, " é: ",resto)
Fimalgoritmo
Algoritmo "trocaux"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Algoritmo que recebe dois valores
//               e troca os seus valores entre si.
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 16/03/2018
Var
// Se��o de Declara��es das vari�veis 
   valor1,valor2,aux: real

Inicio
// para troca sera necess�rio uma variavel auxiliar
    escreval("Entre respectivamente com o 1� e 2� volor real: ")
    leia (valor1,valor2)
    escreval("O 1� valor digitado �:",valor1," e O 2� volor e:",valor2)
     aux<- valor1
     valor1 <-valor2
     valor2 <- aux
    escreval("Trocando o 1� valor agora �:",valor1," e O 2� volor e:",valor2)
Fimalgoritmo
Algoritmo "trocaux"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Algoritmo que recebe dois valores
//               e troca os seus valores entre si.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 16/03/2018
Var
// Seção de Declarações das variáveis 
   valor1,valor2,aux: real

Inicio
// para troca sera necessário uma variavel auxiliar
    escreval("Entre respectivamente com o 1º e 2º volor real: ")
    leia (valor1,valor2)
    escreval("O 1º valor digitado é:",valor1," e O 2º volor e:",valor2)
     aux<- valor1
     valor1 <-valor2
     valor2 <- aux
    escreval("Trocando o 1º valor agora é:",valor1," e O 2º volor e:",valor2)
Fimalgoritmo
Algoritmo "trocaNome"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Algoritmo que receba dois nomes, nome1 e nome2,
//               e realize a troca destes nomes.
//               Mostrar o novo valor do nome1 e do nome2 depois de trocados.
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 15/03/2018
Var
// Se��o de Declara��es das vari�veis 
      nome1,nome2,aux: caracter
Inicio
// para troca sera necess�rio uma variavel auxiliar
    escreval("Entre respectivamente com o 1� e 2� nome: ")
    leia (nome1,nome2)
    escreval("O 1� nome fornecido �:",nome1," e O 2� nome �:",nome2)
     aux<- nome1
     nome1 <-nome2
     nome2 <- aux
    escreval("Trocando o 1� nome agora �:",nome1," e O 2� nome �:",nome2)
Fimalgoritmo
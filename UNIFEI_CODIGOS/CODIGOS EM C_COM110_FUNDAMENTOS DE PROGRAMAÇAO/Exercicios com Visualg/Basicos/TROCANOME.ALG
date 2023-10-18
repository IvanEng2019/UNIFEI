Algoritmo "trocaNome"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Algoritmo que receba dois nomes, nome1 e nome2,
//               e realize a troca destes nomes.
//               Mostrar o novo valor do nome1 e do nome2 depois de trocados.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 15/03/2018
Var
// Seção de Declarações das variáveis 
      nome1,nome2,aux: caracter
Inicio
// para troca sera necessário uma variavel auxiliar
    escreval("Entre respectivamente com o 1º e 2º nome: ")
    leia (nome1,nome2)
    escreval("O 1º nome fornecido é:",nome1," e O 2º nome é:",nome2)
     aux<- nome1
     nome1 <-nome2
     nome2 <- aux
    escreval("Trocando o 1º nome agora é:",nome1," e O 2º nome é:",nome2)
Fimalgoritmo
Algoritmo "mediaAprovacao"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : A partir de valores digitados pelo usuário da média de um
//               aluno, informar se ele foi aprovado (media >= 6),
//               reprovado (0 < media < 3), ou se ficou de exame (3<=media<6).
//               Se ficou de exame, solicitar a nota do exame e informar se o
//               aluno foi aprovado (nota do exame >= 6) ou reprovado.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 18/03/2018
Var
// Seção de Declarações das variáveis
      media, exame : real
Inicio
//Seção de Comandos, procedimento, funções, operadores, etc...
    escreva("Entre com o valor da media:")
    leia(media)
    se(media >0) e (media<3) entao
       escreva("Reprovado!")
    senao
       se(media>=3)e (media<6) entao
          escreval("Ficou de exame!")
          escreva("Entre com o valor da nota do exame:")
          leia(exame)
          se (exame>=6) entao
              escreval("Aprovado!")
          senao
              escreval("Reprovado!")
          fimse
       senao
          escreval("Aprovado!")
       fimse
    fimse

Fimalgoritmo
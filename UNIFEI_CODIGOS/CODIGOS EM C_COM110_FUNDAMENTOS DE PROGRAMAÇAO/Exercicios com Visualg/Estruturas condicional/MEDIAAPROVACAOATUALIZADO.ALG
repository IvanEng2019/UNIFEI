Algoritmo "mediaAprovacaoAtualizado"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : A partir de valores digitados pelo usu�rio da m�dia de um
//               aluno, informar se ele foi aprovado (media >= 6),
//               reprovado (0 < media < 3), ou se ficou de exame (3<=media<6).
//               Se ficou de exame, solicitar a nota do exame e informar se o
//               aluno foi aprovado (nota do exame >= 6) ou reprovado.
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 18/03/2018
Var
// Se��o de Declara��es das vari�veis
      media, exame : real
Inicio
//Se��o de Comandos, procedimento, fun��es, operadores, etc...
    escreva("Entre com o valor da media:")
    leia(media)
    se (media <0) entao
       escreval("Nota invalida!")
    senao
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
                 se (exame<0) entao
                     escreva ("Nota invalida!")
                 senao
                     escreval("Reprovado!")
                 fimse
             fimse
          senao
             escreval("Aprovado!")
             
          fimse
        fimse
    fimse

Fimalgoritmo
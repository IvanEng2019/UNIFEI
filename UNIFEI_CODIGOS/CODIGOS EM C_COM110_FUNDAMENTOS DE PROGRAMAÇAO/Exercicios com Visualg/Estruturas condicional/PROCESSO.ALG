Algoritmo "processo"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Se o processo � do tipo �A� e possui valor maior
//               que R$12000,00, ent�o deve ser escrito �Processo em
//               andamento com custo alto�. Se o processo tem prazo maior
//               que 12 meses (o prazo � sempre dado em quantidade de meses)
//               ou o cliente � do tipo �Especial�, deve ser escrito
//               �Processo cr�tico�
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 18/03/2018
Var
// Se��o de Declara��es das vari�veis 
   tip : caracter
   prazo : inteiro
   valor: real
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreval ("Qual o valor do processo:")
   leia(valor)
   escreval("Qual o tipo de processo:")
   leia(tip)
   escreval("Qual o valor o prazo do processo:")
   leia(prazo)
   se (tip = "A") e (valor > 12000) entao
      escreval("Processo em andamento com custo alto ")
   Senao
      se (prazo>12) e (tip= "Especial") entao
          escreval("Processo cr�tico")
      fimse
  fimse
Fimalgoritmo
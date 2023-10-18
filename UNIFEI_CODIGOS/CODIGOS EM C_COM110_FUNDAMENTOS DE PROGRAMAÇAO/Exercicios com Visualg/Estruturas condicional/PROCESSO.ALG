Algoritmo "processo"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Se o processo é do tipo “A” e possui valor maior
//               que R$12000,00, então deve ser escrito “Processo em
//               andamento com custo alto”. Se o processo tem prazo maior
//               que 12 meses (o prazo é sempre dado em quantidade de meses)
//               ou o cliente é do tipo “Especial”, deve ser escrito
//               “Processo crítico”
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 18/03/2018
Var
// Seção de Declarações das variáveis 
   tip : caracter
   prazo : inteiro
   valor: real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
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
          escreval("Processo crítico")
      fimse
  fimse
Fimalgoritmo
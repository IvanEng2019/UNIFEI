Algoritmo "peso"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : algoritmo que receba o peso de uma pessoa, calcule e mostre:
//               a. O novo peso quando a pessoa engorda 15% do peso digitado
//               b. O novo peso quando a pessoa engorda 20% do peso digitado
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 16/03/2018
Var
// Seção de Declarações das variáveis 
   p1,p2,peso: real
   
inicio

  escreva("Digite o peso:")
  leia (peso)
  p1 <-peso * 15/100
  p1 <-p1 + peso
  escreval("Se engordar 15% o Seu peso é:",p1)
  p2 <-peso * 20/100;
  p2 <-p2 + peso
  escreva("Se engordar 20% o Seu peso é:",p2)

Fimalgoritmo
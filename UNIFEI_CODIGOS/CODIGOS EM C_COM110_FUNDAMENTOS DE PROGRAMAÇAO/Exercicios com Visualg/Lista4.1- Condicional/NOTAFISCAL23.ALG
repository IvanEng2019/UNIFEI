Algoritmo "notaFiscal23"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Recebe a quantidade comprada, o codigo de um produto
//               e calcula e mostra o preço unitário, o preço total da nota,
//               valor do desconto aplicado ao total, preço final da nota.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 18/03/2018
Var
// Seção de Declarações das variáveis 
   qtd,cod: inteiro
   pUnitario,pTotal,vFinal: real
   sinalizador: logico //variavel usada para controle correto da entrada codigo
                       //Inicialmente no visulg já atribui falso
                       //Quando for atribuido verdade ao sinalizador
                       //significará que o codigo de entrada inserido é invalido
                       //e atravez ds estrutura de condição se
                       // não sera executado o restante do codigo
Inicio
// Solicitação de dados de entrada e atribuiçoes desses dados:
   escreva("Ente com o codigo do produto:")
   leia(cod)
//estratura se relaciona o codigo de entrada e fornece o valor unitario do produto
   se (cod >=1) e (cod<=10) entao
       pUnitario <- 10
       escreval("O preço unitário do produto é:",pUnitario)
   senao
      se (cod>=11) e (cod<=20) entao
          pUnitario <- 15
          escreval("O preço unitário do produto é:",pUnitario)
      senao
         se (cod>=21) e (cod<=30) entao
             pUnitario <- 20
             escreval("O preço unitário do produto é:",pUnitario)
         senao
            se (cod>=31) e (cod<=40) entao
                pUnitario <- 30
                escreval("O preço unitário do produto é:",pUnitario)
            senao
                sinalizador <- VERDADEIRO//Atribui verdade a variavel logica sinalizador
            fimse
         fimse
      fimse
   fimse
//caso sinalizador continuar falso as demais intruções são executadas
//caso sinalizador for verdadeiro, significa q o cogido digitado nao
//é exitente, entao mostra mensagem de codigo errado e encerra o programa
   se (sinalizador <> VERDADEIRO ) entao
      //Deteminando Preço total do produto
      escreva("Ente com o quantidade total adquirida do produto:")
      leia(qtd)
      pTotal<-punitario*qtd  //Calcula valor do preço total do produto
      escreval("O Preço total do produtos é: ", pTotal) //Fornece o valor do preço total do produto
      // Determinado qual será o Desconto e o preço final da nota
      se(pTotal<250) entao
        escreval("Atribuido desconto de 5%")
        vFinal<-pTotal*0.95
        escreval("O preço final da nota com desconto é:",vFinal)
      senao
          se(pTotal>250)e (pTotal<500)entao
            escreval("Atribuido desconto de 10%")
            vFinal<-pTotal*0.90
            escreval("O preço final da nota com desconto é:",vFinal)
          senao //se(pTotal>=500) entao
            escreval("Atribuido desconto de 15%")
            vFinal<-pTotal*0.85
            escreval("O preço final da nota com desconto é:",vFinal)
          fimse
      fimse
   senao
      escreval("Codigo não existente!")
   fimse
Fimalgoritmo
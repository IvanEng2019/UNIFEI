Algoritmo "notaFiscal23"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Recebe a quantidade comprada, o codigo de um produto
//               e calcula e mostra o pre�o unit�rio, o pre�o total da nota,
//               valor do desconto aplicado ao total, pre�o final da nota.
// Autor(a)    : Adriel Douglas Nogueira Carlos e Ivan Leoni Vilas Boas
// Data atual  : 22/03/2018
Var
// Se��o de Declara��es das vari�veis 
   qtd,cod: inteiro
   pUnitario,pTotal,vFinal: real
   sinalizador: logico //variavel usada para controle correto da entrada codigo
                       //Inicialmente no visulg j� atribui falso
                       //Quando for atribuido verdade ao sinalizador
                       //significar� que o codigo de entrada inserido � invalido
                       //e atravez ds estrutura de condi��o se
                       // n�o sera executado o restante do codigo
Inicio
// Solicita��o de dados de entrada e atribui�oes desses dados:
   escreva("Ente com o codigo do produto:")
   leia(cod)
//estratura se relaciona o codigo de entrada e fornece o valor unitario do produto
   se (cod >=1) e (cod<=10) entao
       pUnitario <- 10
       escreval("O pre�o unit�rio do produto �:",pUnitario)
   senao
      se (cod>=11) e (cod<=20) entao
          pUnitario <- 15
          escreval("O pre�o unit�rio do produto �:",pUnitario)
      senao
         se (cod>=21) e (cod<=30) entao
             pUnitario <- 20
             escreval("O pre�o unit�rio do produto �:",pUnitario)
         senao
            se (cod>=31) e (cod<=40) entao
                pUnitario <- 30
                escreval("O pre�o unit�rio do produto �:",pUnitario)
            senao
                sinalizador <- VERDADEIRO//Atribui verdade a variavel logica sinalizador
            fimse
         fimse
      fimse
   fimse
//caso sinalizador continuar falso as demais intru��es s�o executadas
//caso sinalizador for verdadeiro, significa q o cogido digitado nao
//� exitente, entao mostra mensagem de codigo errado e encerra o programa
   se (sinalizador <> VERDADEIRO ) entao
      //Deteminando Pre�o total do produto
      escreva("Ente com o quantidade total adquirida do produto:")
      leia(qtd)
      pTotal<-punitario*qtd  //Calcula valor do pre�o total do produto
      escreval("O Pre�o total do produtos �: ", pTotal) //Fornece o valor do pre�o total do produto
      // Determinado qual ser� o Desconto e o pre�o final da nota
      se(pTotal<250) entao
        escreval("Atribuido desconto de 5%")
        vFinal<-pTotal*0.95
        escreval("O pre�o final da nota com desconto �:",vFinal)
      senao
          se(pTotal>250)e (pTotal<500)entao
            escreval("Atribuido desconto de 10%")
            vFinal<-pTotal*0.90
            escreval("O pre�o final da nota com desconto �:",vFinal)
          senao //se(pTotal>=500) entao
            escreval("Atribuido desconto de 15%")
            vFinal<-pTotal*0.85
            escreval("O pre�o final da nota com desconto �:",vFinal)
          fimse
      fimse
   senao
      escreval("Codigo n�o existente!")
   fimse
Fimalgoritmo
Algoritmo "13� Exerc�cio - Pre�os"
// Disciplina  :  [Fundamentos de Programa��o]
// Professor   : Melise Maria Veiga de Paula
// Descri��o   : Ap�s receber o pre�o calcular novo pre�o declarar se barato, normal, caro ou muito caro.
// Autor(a)    : Adriel Douglas Nogueira Carlos e Ivan Leoni Vilas Boas
// Data atual  : 22/03/2018
Var
// Se��o de Declara��es das vari�veis 
valorProduto:real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreval("Entre com o valor do produto e pressione enter:")
   leia(valorProduto)
   se valorProduto<50 entao
      valorProduto<-valorProduto*1.05
      se valorProduto<80 entao
         escreva("Novo Valor �:",valorProduto,".Barato.")
      fimse
      se (valorProduto>=80) e (valorProduto<=120) entao
         escreva("Novo Valor �:",valorProduto,".Normal.")
      fimse
      se (valorProduto>120) e (valorProduto<=200) entao
         escreva("Novo Valor �:",valorProduto,".Caro.")
      fimse
      se valorProduto>200 entao
         escreva("Novo Valor �:",valorProduto,".Muito Caro.")
      fimse
   fimse
   se (valorProduto>=50) e (valorProduto<=100) entao
         valorProduto<-valorProduto*1.10
         se valorProduto<80 entao
            escreva("Novo Valor �:",valorProduto,".Barato.")
         fimse
         se (valorProduto>=80) e (valorProduto<=120) entao
            escreva("Novo Valor �:",valorProduto,".Normal.")
         fimse
         se (valorProduto>120) e (valorProduto<=200) entao
            escreva("Novo Valor �:",valorProduto,".Caro.")
         fimse
         se valorProduto>200 entao
            escreva("Novo Valor �:",valorProduto,".Muito Caro.")
         fimse
   fimse
   se valorProduto>100 entao
      valorProduto<-valorProduto*1.15
      se valorProduto<80 entao
         escreva("Novo Valor �:",valorProduto,".Barato.")
      fimse
      se (valorProduto>=80) e (valorProduto<=120) entao
         escreva("Novo Valor �:",valorProduto,".Normal.")
      fimse
      se (valorProduto>120) e (valorProduto<=200) entao
         escreva("Novo Valor �:",valorProduto,".Caro.")
      fimse
      se valorProduto>200 entao
         escreva("Novo Valor �:",valorProduto,".Muito Caro.")
      fimse
   fimse
Fimalgoritmo
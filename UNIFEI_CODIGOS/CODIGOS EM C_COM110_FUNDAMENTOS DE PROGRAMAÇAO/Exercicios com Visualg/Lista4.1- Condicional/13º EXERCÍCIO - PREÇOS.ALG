Algoritmo "13º Exercício - Preços"
// Disciplina  :  [Fundamentos de Programação]
// Professor   : Melise Maria Veiga de Paula
// Descrição   : Após receber o preço calcular novo preço declarar se barato, normal, caro ou muito caro.
// Autor(a)    : Adriel Douglas Nogueira Carlos e Ivan Leoni Vilas Boas
// Data atual  : 22/03/2018
Var
// Seção de Declarações das variáveis 
valorProduto:real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreval("Entre com o valor do produto e pressione enter:")
   leia(valorProduto)
   se valorProduto<50 entao
      valorProduto<-valorProduto*1.05
      se valorProduto<80 entao
         escreva("Novo Valor é:",valorProduto,".Barato.")
      fimse
      se (valorProduto>=80) e (valorProduto<=120) entao
         escreva("Novo Valor é:",valorProduto,".Normal.")
      fimse
      se (valorProduto>120) e (valorProduto<=200) entao
         escreva("Novo Valor é:",valorProduto,".Caro.")
      fimse
      se valorProduto>200 entao
         escreva("Novo Valor é:",valorProduto,".Muito Caro.")
      fimse
   fimse
   se (valorProduto>=50) e (valorProduto<=100) entao
         valorProduto<-valorProduto*1.10
         se valorProduto<80 entao
            escreva("Novo Valor é:",valorProduto,".Barato.")
         fimse
         se (valorProduto>=80) e (valorProduto<=120) entao
            escreva("Novo Valor é:",valorProduto,".Normal.")
         fimse
         se (valorProduto>120) e (valorProduto<=200) entao
            escreva("Novo Valor é:",valorProduto,".Caro.")
         fimse
         se valorProduto>200 entao
            escreva("Novo Valor é:",valorProduto,".Muito Caro.")
         fimse
   fimse
   se valorProduto>100 entao
      valorProduto<-valorProduto*1.15
      se valorProduto<80 entao
         escreva("Novo Valor é:",valorProduto,".Barato.")
      fimse
      se (valorProduto>=80) e (valorProduto<=120) entao
         escreva("Novo Valor é:",valorProduto,".Normal.")
      fimse
      se (valorProduto>120) e (valorProduto<=200) entao
         escreva("Novo Valor é:",valorProduto,".Caro.")
      fimse
      se valorProduto>200 entao
         escreva("Novo Valor é:",valorProduto,".Muito Caro.")
      fimse
   fimse
Fimalgoritmo
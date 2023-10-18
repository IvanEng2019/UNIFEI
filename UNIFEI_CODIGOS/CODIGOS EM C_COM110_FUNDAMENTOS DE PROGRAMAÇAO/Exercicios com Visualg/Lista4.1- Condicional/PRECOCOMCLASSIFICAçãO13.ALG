Algoritmo "precoComClassificação13"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Recebe o preco atual do produto, calcula e mostra
//               o novo preço e a classificação conforme especificações
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 17/03/2018
Var
// Seção de Declarações das variáveis 
   pAtual,pNovo : real
   classificacao : caracter
Inicio
//Solicitação, entrada e atribuições de dados
  escreva("Entre com o valor do preço atual:")
  leia(pAtual)
//As estrutas se Definirão o novo preço conforme preço valor do preço atual
  se(pAtual>0) e (pAtual < 50) entao
     pNovo <- pAtual*1.05 //Executa de preço for menor que 50
  senao
    se(pAtual>=50) e (pAtual<100) entao
        pNovo <- pAtual*1.1 //Executa se o preço for entre 50 (igual) e 100
    senao
      se(pAtual >= 100) entao
        pNovo <- (pAtual*1.15)//Executa se o preço for maior ou igual a 100
      senao
        escreval("Preço atual impossivel!")
      fimse
    fimse
  fimse
//As estruturas se definirão a classificação de acordo com o valor do novo preço
  Se(pNovo<80) entao
     classificacao <- "BARATA" // Executa de preço for menor que 80
  Senao
     se(pNovo>=80) e (pnovo<120) entao
        classificacao <- "NORMAL"//Executa de preço for entre 80 (igual) e 120
     senao
        se(pNovo>=120) e (pnovo<200) entao
           classificacao <- "CARO" //Executa de preço for entre 120 (igual) e 200
        Senao // se (pNovo>200)
           classificacao <- "MUITO CARO" //Executa se o preço for maior ou igual a 200
        fimse
     fimse
  fimse
   se(pAtual>0) entao //Executa somente se o preço atual for valido
     escreval("O novo preço é",pNovo, " sua Classificação: ",classificacao)
   fimse
Fimalgoritmo
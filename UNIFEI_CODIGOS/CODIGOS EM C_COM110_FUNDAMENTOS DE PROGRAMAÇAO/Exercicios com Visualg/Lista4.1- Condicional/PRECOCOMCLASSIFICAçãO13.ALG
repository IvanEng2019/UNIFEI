Algoritmo "precoComClassifica��o13"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Recebe o preco atual do produto, calcula e mostra
//               o novo pre�o e a classifica��o conforme especifica��es
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 17/03/2018
Var
// Se��o de Declara��es das vari�veis 
   pAtual,pNovo : real
   classificacao : caracter
Inicio
//Solicita��o, entrada e atribui��es de dados
  escreva("Entre com o valor do pre�o atual:")
  leia(pAtual)
//As estrutas se Definir�o o novo pre�o conforme pre�o valor do pre�o atual
  se(pAtual>0) e (pAtual < 50) entao
     pNovo <- pAtual*1.05 //Executa de pre�o for menor que 50
  senao
    se(pAtual>=50) e (pAtual<100) entao
        pNovo <- pAtual*1.1 //Executa se o pre�o for entre 50 (igual) e 100
    senao
      se(pAtual >= 100) entao
        pNovo <- (pAtual*1.15)//Executa se o pre�o for maior ou igual a 100
      senao
        escreval("Pre�o atual impossivel!")
      fimse
    fimse
  fimse
//As estruturas se definir�o a classifica��o de acordo com o valor do novo pre�o
  Se(pNovo<80) entao
     classificacao <- "BARATA" // Executa de pre�o for menor que 80
  Senao
     se(pNovo>=80) e (pnovo<120) entao
        classificacao <- "NORMAL"//Executa de pre�o for entre 80 (igual) e 120
     senao
        se(pNovo>=120) e (pnovo<200) entao
           classificacao <- "CARO" //Executa de pre�o for entre 120 (igual) e 200
        Senao // se (pNovo>200)
           classificacao <- "MUITO CARO" //Executa se o pre�o for maior ou igual a 200
        fimse
     fimse
  fimse
   se(pAtual>0) entao //Executa somente se o pre�o atual for valido
     escreval("O novo pre�o �",pNovo, " sua Classifica��o: ",classificacao)
   fimse
Fimalgoritmo
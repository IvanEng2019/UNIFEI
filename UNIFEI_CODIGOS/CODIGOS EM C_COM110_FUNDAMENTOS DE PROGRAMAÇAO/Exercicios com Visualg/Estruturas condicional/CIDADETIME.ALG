Algoritmo "cidadeTime"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : recebe o nome de um time de futebol e retorne o estado
//               de origem do time. Os nomes v�lidos s�o: S�o Paulo,
//               Palmeiras, Flamengo, Vasco, Atl�tico Mineiro, Cruzeiro,
//               Bahia, Gr�mio e Internacional.Exibir uma mensagem caso
//               o nome seja diferente de uma dessas op��es.
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 18/03/2018
Var
// Se��o de Declara��es das vari�veis 
   time: caracter

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreval("Entre com o time:")
   leia(time)
   escolha time
   caso "S�o Paulo","Palmeiras"
         escreval("Pertence originalmente ao estado de s�o Paulo.")
   caso "flamengo", "vasco"
         escreval("Pertence originalmente ao estado do Rio de Janeiro.")
   caso "Atl�tico mineiro","Cruzeiro"
        escreval("Pertence originalmente ao estado de Minas Gerais.")
   caso "bahia"
        escreval("Pertence originalmente ao estado da Bahia.")
   caso "Gr�mio","intenacional"
       escreval("Pertence originalmente ao estado do Rio Grande do Sul.")
   outrocaso
       escreval("A Cidade de Origem deste Time n�o esta cadastrada no sistema.")
   fimescolha
Fimalgoritmo
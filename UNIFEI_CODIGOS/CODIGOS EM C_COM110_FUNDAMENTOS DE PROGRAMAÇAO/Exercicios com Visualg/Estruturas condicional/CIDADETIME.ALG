Algoritmo "cidadeTime"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : recebe o nome de um time de futebol e retorne o estado
//               de origem do time. Os nomes válidos são: São Paulo,
//               Palmeiras, Flamengo, Vasco, Atlético Mineiro, Cruzeiro,
//               Bahia, Grêmio e Internacional.Exibir uma mensagem caso
//               o nome seja diferente de uma dessas opções.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 18/03/2018
Var
// Seção de Declarações das variáveis 
   time: caracter

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreval("Entre com o time:")
   leia(time)
   escolha time
   caso "São Paulo","Palmeiras"
         escreval("Pertence originalmente ao estado de são Paulo.")
   caso "flamengo", "vasco"
         escreval("Pertence originalmente ao estado do Rio de Janeiro.")
   caso "Atlético mineiro","Cruzeiro"
        escreval("Pertence originalmente ao estado de Minas Gerais.")
   caso "bahia"
        escreval("Pertence originalmente ao estado da Bahia.")
   caso "Grêmio","intenacional"
       escreval("Pertence originalmente ao estado do Rio Grande do Sul.")
   outrocaso
       escreval("A Cidade de Origem deste Time não esta cadastrada no sistema.")
   fimescolha
Fimalgoritmo
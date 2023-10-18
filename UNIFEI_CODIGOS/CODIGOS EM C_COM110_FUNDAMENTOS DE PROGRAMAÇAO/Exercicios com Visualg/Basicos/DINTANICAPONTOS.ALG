Algoritmo "dintanicaPontos"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : com dados de entrada dois pontos quaisquer do plano,
//                P(x1,y1) e Q(x2, y2),imprime a distância entre eles.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 16/03/2018
Var
// Seção de Declarações das variáveis 
   x1,x2,y1,y2,d : real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
     escreval("Entre com x1 e y1:")
     leia(x1,y1)
     escreval("Entre com x2 e y2:")
     leia(x2,y2)
     d<- RaizQ( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
        escreval("A distancia dos pontos é: ",d)
Fimalgoritmo
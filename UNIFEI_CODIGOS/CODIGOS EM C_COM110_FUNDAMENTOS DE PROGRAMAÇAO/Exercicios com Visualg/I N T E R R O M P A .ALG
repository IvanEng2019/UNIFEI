Algoritmo " i n t e r r o m p a "
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   : Le uma lista de 10 números inteiros positivos e imprima
// quais números são divisíveis por 2. Caso seja digitado um número negativo,
// o algoritmo deve ser interrompido. Use o comando interrompa

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
// Data atual  : 03/04/2018
Var
// Seção de Declarações das variáveis 
   i, num: inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreva ("Entre com um numero:")
   leia (num)
   i<-0
   enquanto i<10 faca
            se num<0 entao
               interrompa
            senao
                se num%2=0 entao
                   escreval("Este numero é divisivel por 2:",num)
                fimse
            fimse
            i<-i+1
            escreva ("Entre com um numero:")
            leia (num)
   Fimenquanto
Fimalgoritmo
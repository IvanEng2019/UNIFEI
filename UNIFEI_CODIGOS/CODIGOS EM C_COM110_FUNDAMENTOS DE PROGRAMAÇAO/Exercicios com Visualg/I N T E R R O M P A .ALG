Algoritmo " i n t e r r o m p a "
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   : Le uma lista de 10 n�meros inteiros positivos e imprima
// quais n�meros s�o divis�veis por 2. Caso seja digitado um n�mero negativo,
// o algoritmo deve ser interrompido. Use o comando interrompa

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
// Data atual  : 03/04/2018
Var
// Se��o de Declara��es das vari�veis 
   i, num: inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreva ("Entre com um numero:")
   leia (num)
   i<-0
   enquanto i<10 faca
            se num<0 entao
               interrompa
            senao
                se num%2=0 entao
                   escreval("Este numero � divisivel por 2:",num)
                fimse
            fimse
            i<-i+1
            escreva ("Entre com um numero:")
            leia (num)
   Fimenquanto
Fimalgoritmo
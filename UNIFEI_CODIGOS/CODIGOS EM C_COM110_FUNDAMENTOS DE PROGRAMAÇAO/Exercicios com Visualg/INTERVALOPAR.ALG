Algoritmo "ParIntervalo"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : le os limites inferior e superior de um intervalo
// e imprima todos os n�meros inteiros pares no intervalo aberto e o
// somat�rio desses n�meros. Suponha que os n�meros digitados sejam crescentes,
// ou seja, o primeiro valor � menor que o segundo.

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
// Data atual  : 03/04/2018
Var
// Se��o de Declara��es das vari�veis 
    num1, num2 ,soma : inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
        escreva( "Entre com os numeros:")
        leia (num1,num2)  // num1< num2
        soma<-0
        escreva("O intervalo aberto ]")
        enquanto num1<=num2 faca
            se num1%2=0 entao
               escreva(num1,",")
               soma<-soma+num1
            fimse
            num1<-num1+1
        fimenquanto
        escreval("[")
        escreval(" A soma dos intervalos pares �:",soma)
Fimalgoritmo
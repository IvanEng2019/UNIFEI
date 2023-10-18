Algoritmo "ParIntervalo"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : le os limites inferior e superior de um intervalo
// e imprima todos os números inteiros pares no intervalo aberto e o
// somatório desses números. Suponha que os números digitados sejam crescentes,
// ou seja, o primeiro valor é menor que o segundo.

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
// Data atual  : 03/04/2018
Var
// Seção de Declarações das variáveis 
    num1, num2 ,soma : inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
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
        escreval(" A soma dos intervalos pares é:",soma)
Fimalgoritmo
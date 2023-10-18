Algoritmo "intervalo"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   :São dados um número n e quatro outros, a, b, c e d
//correspondentes, respectivamente, às extremidades dos intervalos
//[a,b] e [c,d], sendo a<b, c<d e a<c. Determinar se n pertence somente
//ao intervalo [a,b] ou, se pertence a ambos ou não pertence a nenhum dos
// intervalos. Em cada um dos casos, exibir uma mensagem ao usuário.

// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 19/03/2018
Var
// Seção de Declarações das variáveis 
    N,a,b,c,d: real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...
    escreva("Entre com o valor de um numero.")
    leia(N)
    escreva ("Entre com o valor do primerio membro do primeiro intervalo:")
    leia (a)
    escreva ("Entre com o valor do segundo membro do primeiro intervalo:")
    leia (b)
    escreva ("Entre com o valor do primerio membro do segundo intervalo:")
    leia (c)
    escreva ("Entre com o valor do segundo membro do segundo intervalo:")
    leia (d)
    se (a < b ) e (c < d) e (a < c) entao
        se(N < a) ou (N > d) ou ((N > b) e (N < c)) entao
           escreval( "O ",N," esta fora dos intervalos [", a, ",", b,"] e [",c,",",d,"]")
        senao
           se(N >= a) e (N <= b) e (N >= c) e (N <= d) entao
             escreval("O ",N," pertence a ambos os intervalos [", a, ",", b,"] e [",c,",",d,"]")
           senao
              se(N >= a) e (N <= b) e (N<c) entao
                escreval("O ",N," pertence ao intervalo [", a, ",", b,"]")
              senao  // (N >= c) e (N <= d) e N>b
                 escreva("O ",N," pertence ao intervalo [", c, ",", d,"]")
              fimse
           fimse
        fimse
    senao
       escreva( "Intervalos fornecidos fogem a regra a<b, c<d e a<c")
    fimse
Fimalgoritmo
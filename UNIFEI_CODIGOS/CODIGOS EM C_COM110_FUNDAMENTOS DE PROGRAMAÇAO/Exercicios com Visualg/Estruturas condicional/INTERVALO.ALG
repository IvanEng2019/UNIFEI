Algoritmo "intervalo"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   :S�o dados um n�mero n e quatro outros, a, b, c e d
//correspondentes, respectivamente, �s extremidades dos intervalos
//[a,b] e [c,d], sendo a<b, c<d e a<c. Determinar se n pertence somente
//ao intervalo [a,b] ou, se pertence a ambos ou n�o pertence a nenhum dos
// intervalos. Em cada um dos casos, exibir uma mensagem ao usu�rio.

// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 19/03/2018
Var
// Se��o de Declara��es das vari�veis 
    N,a,b,c,d: real
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
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
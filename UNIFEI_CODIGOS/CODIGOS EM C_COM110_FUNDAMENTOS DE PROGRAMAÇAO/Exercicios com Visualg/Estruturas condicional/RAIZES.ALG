Algoritmo "raizes"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Algoritmo para calcular as ra�zes de uma equa��o do 2� grau
//              (Ax2 + Bx + C). Considere que o valor de A <> 0 e
//              (B2 � 4AC) > 0. Escreva os valores na tela.
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 15/03/2018
Var
// Se��o de Declara��es das vari�veis 
   a,b,c: inteiro
   r1,r2,delta: real
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
    escreva("Entre respectivamente com valor de A, B e C:")
    leia(a,b,c)
    delta<-(b*b)-(4*a*c))
    se (delta>=0) entao
        r1<-(-b+(RaizQ(delta)))/(2*a)
        r2<-(-b-(RaizQ(delta)))/(2*a)
        escreval("As raizes da equa��o s�o: R1=",r1, " e R2=",r2)
    senao
       escreva("Raizes n�o reais")
    fimse
Fimalgoritmo
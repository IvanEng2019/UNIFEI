Algoritmo "raizes"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Algoritmo para calcular as raízes de uma equação do 2º grau
//              (Ax2 + Bx + C). Considere que o valor de A <> 0 e
//              (B2 – 4AC) > 0. Escreva os valores na tela.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 15/03/2018
Var
// Seção de Declarações das variáveis 
   a,b,c: inteiro
   r1,r2,delta: real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
    escreva("Entre respectivamente com valor de A, B e C:")
    leia(a,b,c)
    delta<-(b*b)-(4*a*c))
    se (delta>=0) entao
        r1<-(-b+(RaizQ(delta)))/(2*a)
        r2<-(-b-(RaizQ(delta)))/(2*a)
        escreval("As raizes da equação são: R1=",r1, " e R2=",r2)
    senao
       escreva("Raizes não reais")
    fimse
Fimalgoritmo
Algoritmo "pesoIdeal"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Recebe a altura (H) e o sexo de uma pessoa,
//               calcule e imprima o seu peso ideal,
//               utilizando as seguintes f�rmulas:
//               Para homens: (72.7 * H) � 58
//               Para mulheres: (62.1 * H) � 44.7
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 18/03/2018
Var
// Se��o de Declara��es das vari�veis 
    h,p : real
    sexo : caracter
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
    escreva("Entre com o sexo:")
    leia (sexo)
    escreva("Entre com a altura:")
    leia (h)
    se (sexo = "homem") entao
        p<-(72.7 * h) � 58
    senao
        p<-(62.1 * h) � 44.7
    fimse
    escreval("O peso ideal �:",p)

Fimalgoritmo
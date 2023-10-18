Algoritmo "pesoIdeal"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Recebe a altura (H) e o sexo de uma pessoa,
//               calcule e imprima o seu peso ideal,
//               utilizando as seguintes fórmulas:
//               Para homens: (72.7 * H) – 58
//               Para mulheres: (62.1 * H) – 44.7
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 18/03/2018
Var
// Seção de Declarações das variáveis 
    h,p : real
    sexo : caracter
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
    escreva("Entre com o sexo:")
    leia (sexo)
    escreva("Entre com a altura:")
    leia (h)
    se (sexo = "homem") entao
        p<-(72.7 * h) – 58
    senao
        p<-(62.1 * h) – 44.7
    fimse
    escreval("O peso ideal é:",p)

Fimalgoritmo
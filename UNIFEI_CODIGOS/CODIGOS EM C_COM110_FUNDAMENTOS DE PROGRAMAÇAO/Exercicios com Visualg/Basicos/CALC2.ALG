Algoritmo "calc2"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : ler dois valores inteiros, efetuar e mostrar o resultado das
//               opera��es de adi��o, subtra��o e multiplica��o.
//               Considere que todos os n�meros s�o diferentes de 0.
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 15/03/2018
Var
// Se��o de Declara��es das vari�veis 
   valor1,valor2,conta: inteiro
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
    escreva("Entre respectivamente com o 1� e 2� volor inteiro: ")
    leia (valor1,valor2)
    escreval("O 1� valor digitado �:",valor1," e O 2� volor e:",valor2)
    conta <- valor1+valor2
    escreval ("A adi�ao �:",conta)
    conta <- valor1-valor2
    escreval ("A subtra��oo �:",conta)
    conta <- valor1*valor2
    escreval ("A multiplica��o �:",conta)
Fimalgoritmo
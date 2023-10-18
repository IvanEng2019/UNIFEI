Algoritmo "calc2"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : ler dois valores inteiros, efetuar e mostrar o resultado das
//               operações de adição, subtração e multiplicação.
//               Considere que todos os números são diferentes de 0.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 15/03/2018
Var
// Seção de Declarações das variáveis 
   valor1,valor2,conta: inteiro
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
    escreva("Entre respectivamente com o 1º e 2º volor inteiro: ")
    leia (valor1,valor2)
    escreval("O 1º valor digitado é:",valor1," e O 2º volor e:",valor2)
    conta <- valor1+valor2
    escreval ("A adiçao é:",conta)
    conta <- valor1-valor2
    escreval ("A subtraçãoo é:",conta)
    conta <- valor1*valor2
    escreval ("A multiplicação é:",conta)
Fimalgoritmo
Algoritmo "categoriaAB"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   :Escreva um algoritmo que leia a categoria de uma lista de
//              funcion�rios e retorne o sal�rio do funcion�rio considerando
//              a regra abaixo. Al�m do sal�rio, retorne a soma do sal�rio
//              de todas as categorias digitadas.
//             � Categoria A � Sal�rio 10.000
//             � Categoria B � Sal�rio 5.000
//             A lista termina quando for digitada uma categoria = X.
//             Caso usu�rio digite uma categoria diferente, deve ser exibida
//             uma mensagem: Categoria Inv�lida

// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 24/03/2018
Var
// Se��o de Declara��es das vari�veis
    cat:caracter
    somaSalAB, sal: inteiro
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
   somaSalAB<-0
   escreva("Entre com a categoria:")
   leia(cat)
   enquanto cat<>"X" faca
           se cat = "A"  entao
              somasalAB<-somasalAB+10000
              escreval("O salario � 10.000,00 reais:")
           senao
              se cat = "B" entao
                 somasalAB<-somasalAB+5000
                 escreval("O salario � 5.000,00 reais:")
              senao
                 escreval("Categoria invalida!")
              fimse
           fimse
           escreva("Entre com a categoria:")
           leia(cat)
   fimenquanto
   se (somaSalAB<>0)entao
       escreval("O salario de todas categorias digitadas �:",somasalAB)
   senao
       escreval("Lista vazia: N�o h� funiconarios com categorias A e B nesta lista.")
   fimse
Fimalgoritmo
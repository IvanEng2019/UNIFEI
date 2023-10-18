Algoritmo "categoriaAB"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   :Escreva um algoritmo que leia a categoria de uma lista de
//              funcionários e retorne o salário do funcionário considerando
//              a regra abaixo. Além do salário, retorne a soma do salário
//              de todas as categorias digitadas.
//             • Categoria A – Salário 10.000
//             • Categoria B – Salário 5.000
//             A lista termina quando for digitada uma categoria = X.
//             Caso usuário digite uma categoria diferente, deve ser exibida
//             uma mensagem: Categoria Inválida

// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 24/03/2018
Var
// Seção de Declarações das variáveis
    cat:caracter
    somaSalAB, sal: inteiro
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...
   somaSalAB<-0
   escreva("Entre com a categoria:")
   leia(cat)
   enquanto cat<>"X" faca
           se cat = "A"  entao
              somasalAB<-somasalAB+10000
              escreval("O salario é 10.000,00 reais:")
           senao
              se cat = "B" entao
                 somasalAB<-somasalAB+5000
                 escreval("O salario é 5.000,00 reais:")
              senao
                 escreval("Categoria invalida!")
              fimse
           fimse
           escreva("Entre com a categoria:")
           leia(cat)
   fimenquanto
   se (somaSalAB<>0)entao
       escreval("O salario de todas categorias digitadas é:",somasalAB)
   senao
       escreval("Lista vazia: Não há funiconarios com categorias A e B nesta lista.")
   fimse
Fimalgoritmo
Algoritmo "tipoTriangulo"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Dado os lados de um triângulo A, B e C,
//               verificar as seguintes regras: o Se A2=B2+C2,
//               responder triângulo é retângulo,
//               o Senão se A2>B2+C2, responder triângulo é obtusângulo,
//               o Senão, responder Nenhuma das opções
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 18/03/2018
Var
// Seção de Declarações das variáveis 
    A,B,C: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
    escreval("Entre com o valor dos tres lados do triangulo.")
    leia (A,B,C)
    se (A<=B+C)e(B<=A+C)e(C<=A+B) entao
        se (A*A = B*B + C*C) entao
            escreva ("Estre triangulo é retângulo.")
        senao
            se(A*A > (B*B)+(C*C)) entao
                escreva ("Estre triangulo é obtusangulo")
            senao
               escreval("Nenhuma das opções.")
            fimse
        fimse
    senao
      escreva ("Estes valores Não forma um triangulo.")
    fimse
Fimalgoritmo
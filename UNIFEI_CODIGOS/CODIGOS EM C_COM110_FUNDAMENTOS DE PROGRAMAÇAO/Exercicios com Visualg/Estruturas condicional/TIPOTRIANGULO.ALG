Algoritmo "tipoTriangulo"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Dado os lados de um tri�ngulo A, B e C,
//               verificar as seguintes regras: o Se A2=B2+C2,
//               responder tri�ngulo � ret�ngulo,
//               o Sen�o se A2>B2+C2, responder tri�ngulo � obtus�ngulo,
//               o Sen�o, responder Nenhuma das op��es
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 18/03/2018
Var
// Se��o de Declara��es das vari�veis 
    A,B,C: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
    escreval("Entre com o valor dos tres lados do triangulo.")
    leia (A,B,C)
    se (A<=B+C)e(B<=A+C)e(C<=A+B) entao
        se (A*A = B*B + C*C) entao
            escreva ("Estre triangulo � ret�ngulo.")
        senao
            se(A*A > (B*B)+(C*C)) entao
                escreva ("Estre triangulo � obtusangulo")
            senao
               escreval("Nenhuma das op��es.")
            fimse
        fimse
    senao
      escreva ("Estes valores N�o forma um triangulo.")
    fimse
Fimalgoritmo
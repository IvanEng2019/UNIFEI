Algoritmo "somaN"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   :Le n n�meros e imprima a soma desses n�meros.
//              O valor de n deve ser informado pelo usu�rio.

// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 22/03/2018
Var
// Se��o de Declara��es das vari�veis
   i,n : inteiro
   num, soma : real
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
    soma<-0
    escreva ("Entre com quantos numero quer somar:")
    leia(n)
    para i de 1 ate n passo 1 faca
         escreva ("Entre com o ", i, "� numero:")
         leia (num)
         soma<-soma+num
    fimpara
    escreval("A soma dos numero disgitados �:",soma)
Fimalgoritmo
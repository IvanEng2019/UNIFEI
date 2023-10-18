Algoritmo "somaN"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   :Le n números e imprima a soma desses números.
//              O valor de n deve ser informado pelo usuário.

// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 22/03/2018
Var
// Seção de Declarações das variáveis
   i,n : inteiro
   num, soma : real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...
    soma<-0
    escreva ("Entre com quantos numero quer somar:")
    leia(n)
    para i de 1 ate n passo 1 faca
         escreva ("Entre com o ", i, "º numero:")
         leia (num)
         soma<-soma+num
    fimpara
    escreval("A soma dos numero disgitados é:",soma)
Fimalgoritmo
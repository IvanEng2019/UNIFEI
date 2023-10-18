Algoritmo "reajusteSal"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : calcule e imprima o salário reajustado de um funcionário
//               de acordo com a seguinte regra: Salários até 300,
//               reajuste 50%. Salários maiores que 300, reajuste 30%
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 18/03/2018
Var
// Seção de Declarações das variáveis 
   sal,nSal: real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
    escreval ("Entre com o salario:")
    leia(sal)
    se sal<=300 entao
       nSal<-sal*1.5
    senao
        se sal>300 entao
           nSal<-sal*1.3
        fimse
    fimse
    escreval("Novo salario reajustado é:",nsal)
Fimalgoritmo
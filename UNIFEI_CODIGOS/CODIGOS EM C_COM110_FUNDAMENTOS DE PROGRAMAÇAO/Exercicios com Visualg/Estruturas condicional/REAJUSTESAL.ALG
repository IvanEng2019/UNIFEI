Algoritmo "reajusteSal"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : calcule e imprima o sal�rio reajustado de um funcion�rio
//               de acordo com a seguinte regra: Sal�rios at� 300,
//               reajuste 50%. Sal�rios maiores que 300, reajuste 30%
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 18/03/2018
Var
// Se��o de Declara��es das vari�veis 
   sal,nSal: real
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
    escreval ("Entre com o salario:")
    leia(sal)
    se sal<=300 entao
       nSal<-sal*1.5
    senao
        se sal>300 entao
           nSal<-sal*1.3
        fimse
    fimse
    escreval("Novo salario reajustado �:",nsal)
Fimalgoritmo
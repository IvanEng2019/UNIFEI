Algoritmo "abonoSalarial2"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Uma empresa resolveu dar um abono salarial aos seus
//funcion�rios. O abono � definido de acordo com a seguinte regra:
//a. Se quantidade mensal de pe�as produzida pelo funcion�rio > 120
//durante os �ltimos 12 meses, o funcion�rio ganha 5% do valor l�quido
//do sal�rio. b. Se nao,se o funcion�rio n�o faltou durante os 12 �ltimos meses,
// ganha 2% do valor l�quido do sal�rio. Elabore um algoritmo que receba
//a quantidade de falta de um funcion�rio e a quantidade de pe�as produzidas
//nos �ltimos 12 meses e retorne o valor do sal�rio mais o abono.
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 19/03/2018
Var
// Se��o de Declara��es das vari�veis
   falta, peca: inteiro
   salLiquido,nSal: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
    escreva ("Entre com o numero de faltas dos ultimos 12 meses:")
    leia(falta)
    escreva ("Entre com o numero de pe�as produzidas nos ultimos 12 meses:")
    leia(peca)
    escreva ("Entre com o valor liquido do salario:")
    leia(salLiquido)
    se(peca>120) entao //Executara se o funcinario produziu 120 pe�as independente das faltas
       nSal<-salLiquido*1.05
          escreval("O valor do abono � de 5%")
    senao
       se(falta=0)e(peca<120) entao//Executa se o funcionario n�o teve alguma falta, mas produziu menos de 120 pe�as
          nSal<-salLiquido*1.02
          escreval("O valor do abono � de 2%")
       senao   //executa de produziu menos de 120 pe�as e teve alguma falta
          escreval("N�o houve algum tipo de abono.Abono=0")
          nSal<-salLiquido
       fimse
    fimse
    escreval("O valor do salario j� acrescido do abono �:",nSal)
Fimalgoritmo
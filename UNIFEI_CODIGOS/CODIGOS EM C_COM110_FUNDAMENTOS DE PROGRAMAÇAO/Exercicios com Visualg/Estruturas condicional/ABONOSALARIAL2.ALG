Algoritmo "abonoSalarial2"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Uma empresa resolveu dar um abono salarial aos seus
//funcionários. O abono é definido de acordo com a seguinte regra:
//a. Se quantidade mensal de peças produzida pelo funcionário > 120
//durante os últimos 12 meses, o funcionário ganha 5% do valor líquido
//do salário. b. Se nao,se o funcionário não faltou durante os 12 últimos meses,
// ganha 2% do valor líquido do salário. Elabore um algoritmo que receba
//a quantidade de falta de um funcionário e a quantidade de peças produzidas
//nos últimos 12 meses e retorne o valor do salário mais o abono.
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 19/03/2018
Var
// Seção de Declarações das variáveis
   falta, peca: inteiro
   salLiquido,nSal: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...
    escreva ("Entre com o numero de faltas dos ultimos 12 meses:")
    leia(falta)
    escreva ("Entre com o numero de peças produzidas nos ultimos 12 meses:")
    leia(peca)
    escreva ("Entre com o valor liquido do salario:")
    leia(salLiquido)
    se(peca>120) entao //Executara se o funcinario produziu 120 peças independente das faltas
       nSal<-salLiquido*1.05
          escreval("O valor do abono é de 5%")
    senao
       se(falta=0)e(peca<120) entao//Executa se o funcionario não teve alguma falta, mas produziu menos de 120 peças
          nSal<-salLiquido*1.02
          escreval("O valor do abono é de 2%")
       senao   //executa de produziu menos de 120 peças e teve alguma falta
          escreval("Não houve algum tipo de abono.Abono=0")
          nSal<-salLiquido
       fimse
    fimse
    escreval("O valor do salario já acrescido do abono é:",nSal)
Fimalgoritmo
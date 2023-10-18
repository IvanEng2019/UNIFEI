Algoritmo "pesquisa"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   : Foi feita uma pesquisa entre os habitantes de uma região.
// Foram coletados os dados de idade, sexo (M/F) e salário.
// Faça um algoritmo que informe: a média de salário do grupo;
// maior e menor idade do grupo e a quantidade de mulheres com salário
// até R$100,00. Encerre a entrada de dados quando for digitada uma
// idade negativa.

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
// Data atual  : 03/04/20182018
Var
// Seção de Declarações das variáveis 
   idade,idmaior,idmenor,cont,contf: inteiro
   sexo: caracter
   sal,soma : real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
     escreva("Entre com a idade :")
     leia (idade)
     soma<-0
     cont<-0
     idmaior<-idade
     enquanto idade>=0 faca
        escreva("Entre com o sexo M/F :")
        leia (sexo)
        escreva("Entre com o salario :")
        leia (sal)
        soma<-soma+Sal
        cont<-cont+1
        escreva("Entre com a idade :")
        leia (idade)
        se (idmaior>idade) entao
            idmenor<-idade
        senao
            idmaior<-idade
        fimse
        se (sal<=100) e (sexo="F")entao
            contf<-contf+1
        fimse
     fimenquanto
     se cont<>0 entao
         escreval("A media do salario do grupo é:",soma/cont)
         escreval("O numero de mulheres que ganham ate 1oo reais:",contf)
     fimse
Fimalgoritmo
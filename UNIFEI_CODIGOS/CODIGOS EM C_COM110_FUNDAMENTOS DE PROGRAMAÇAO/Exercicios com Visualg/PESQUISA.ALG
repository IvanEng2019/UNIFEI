Algoritmo "pesquisa"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   : Foi feita uma pesquisa entre os habitantes de uma regi�o.
// Foram coletados os dados de idade, sexo (M/F) e sal�rio.
// Fa�a um algoritmo que informe: a m�dia de sal�rio do grupo;
// maior e menor idade do grupo e a quantidade de mulheres com sal�rio
// at� R$100,00. Encerre a entrada de dados quando for digitada uma
// idade negativa.

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
// Data atual  : 03/04/20182018
Var
// Se��o de Declara��es das vari�veis 
   idade,idmaior,idmenor,cont,contf: inteiro
   sexo: caracter
   sal,soma : real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
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
         escreval("A media do salario do grupo �:",soma/cont)
         escreval("O numero de mulheres que ganham ate 1oo reais:",contf)
     fimse
Fimalgoritmo
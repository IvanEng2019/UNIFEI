Algoritmo "mdc"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Calcula o m�ximo divisor comum entre dois n�meros.
// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476
// Data atual  : 29/03/2018
Var
// Se��o de Declara��es das vari�veis 
    cont: inteiro //controlara o la�o de repeti��o
    num1, num2 :inteiro // Variaveis de entrada
    maior :inteiro //Maior valor da entrada ser� o clit�rio de parada do la�o
    mdc :inteiro //Variavel de saida - Resposta
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
    cont<-0 // atribui zero a cont
    escreval("Entre com dois numeros:")
    leia(num1,num2)
    se num1>num2 entao //Descobrir qual � o maior numero digitado 1� ou 2�?
       maior<-num1
    senao
       maior<-num2
    fimse
    enquanto cont<=maior faca //Repetira o la�o ate atingir o maior n� digitado
             cont<- cont+1 // Incrementa 1 ao cont
             se ((num1%cont=0) e (num2%cont=0)) entao // caso o resto da divis�o por ambos numeros seja zero
                mdc<-cont                             // o cont sera o divisor comum de ambos
             fimse
    fimenquanto //Fim da repeti��o
    escreval("O MDC de ", num1," e ",num2, " �:", mdc)
Fimalgoritmo
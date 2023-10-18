Algoritmo "mdc"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Calcula o máximo divisor comum entre dois números.
// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476
// Data atual  : 29/03/2018
Var
// Seção de Declarações das variáveis 
    cont: inteiro //controlara o laço de repetição
    num1, num2 :inteiro // Variaveis de entrada
    maior :inteiro //Maior valor da entrada será o clitério de parada do laço
    mdc :inteiro //Variavel de saida - Resposta
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
    cont<-0 // atribui zero a cont
    escreval("Entre com dois numeros:")
    leia(num1,num2)
    se num1>num2 entao //Descobrir qual é o maior numero digitado 1º ou 2º?
       maior<-num1
    senao
       maior<-num2
    fimse
    enquanto cont<=maior faca //Repetira o laço ate atingir o maior nº digitado
             cont<- cont+1 // Incrementa 1 ao cont
             se ((num1%cont=0) e (num2%cont=0)) entao // caso o resto da divisão por ambos numeros seja zero
                mdc<-cont                             // o cont sera o divisor comum de ambos
             fimse
    fimenquanto //Fim da repetição
    escreval("O MDC de ", num1," e ",num2, " é:", mdc)
Fimalgoritmo
Algoritmo "Fatorial"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   : calcula N! (fatorial de N), sendo que o valor inteiro de
//               N � fornecido pelo usu�rio. Sabe-se que:
//               N! = 1 * 2 * 3 * ... * (N-1) * N; 0! = 1, por defini��o

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476

// Data atual  : 30/03/2018
var
    // Se��o de Declara��es
    n: inteiro// N� de entrada fornecida pelo usuario
    cont: Inteiro //controla quantas vezes sera realido a multiplica��o e por qual n�
    Fat: inteiro //Resultado do fatorial

inicio
// Se��o de Comandos
     escreva("Entre com o numero que deseja calcular o fatorial:")
     leia(n)
     cont<-1  //Variavel cont � incializada com 1
     Fat<-1   //Variavel cont � incializada com 1
     enquanto cont<=n faca    //Repetira o la�o ate n intera��es seja execuada
              fat<- fat*cont  //Faz sempre a multiplica�o do resultado anterior com o numero seguinte
              cont<-cont+1   // atribui se uma unidade a cont
     fimenquanto //Fim dos comados do la�o de repeti��o
     escreval("O fatorial de",n, " �:",fat)
fimalgoritmo
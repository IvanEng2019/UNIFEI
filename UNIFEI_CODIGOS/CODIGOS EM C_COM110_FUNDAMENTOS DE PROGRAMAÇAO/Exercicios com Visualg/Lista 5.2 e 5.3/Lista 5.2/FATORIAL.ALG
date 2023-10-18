Algoritmo "Fatorial"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   : calcula N! (fatorial de N), sendo que o valor inteiro de
//               N é fornecido pelo usuário. Sabe-se que:
//               N! = 1 * 2 * 3 * ... * (N-1) * N; 0! = 1, por definição

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476

// Data atual  : 30/03/2018
var
    // Seção de Declarações
    n: inteiro// Nº de entrada fornecida pelo usuario
    cont: Inteiro //controla quantas vezes sera realido a multiplicação e por qual nº
    Fat: inteiro //Resultado do fatorial

inicio
// Seção de Comandos
     escreva("Entre com o numero que deseja calcular o fatorial:")
     leia(n)
     cont<-1  //Variavel cont é incializada com 1
     Fat<-1   //Variavel cont é incializada com 1
     enquanto cont<=n faca    //Repetira o laço ate n interações seja execuada
              fat<- fat*cont  //Faz sempre a multiplicaão do resultado anterior com o numero seguinte
              cont<-cont+1   // atribui se uma unidade a cont
     fimenquanto //Fim dos comados do laço de repetição
     escreval("O fatorial de",n, " é:",fat)
fimalgoritmo
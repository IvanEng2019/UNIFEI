Algoritmo "intervaloParSoma"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : le os limites inferior e superior de um intervalo e
//               imprima todos os n�meros inteiros pares no intervalo
//               aberto e o somat�rio desses n�meros.
// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476
// Data atual  : 30/03/2018
Var
// Se��o de Declara��es das vari�veis 
   inf,sup : inteiro  //variaveis de entrada que representa o valor inferior e superior
   somaPar: inteiro //variavel de saida que represnta a soma elementos pares do intervalo
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreva("Entre respectivamente com os valores inferior e superior do intervalo:")
   leia(inf,sup)
   Se (inf<sup) entao //Condiciona a execu��o apenas se o primeiro valor digitado for maior que o segundo
       escreva("O intervalo aberto dos pares de [",inf,",",sup," ] �: ]")
       enquanto inf<= sup faca //Repetira ate quando inferior for <=  superior
            se inf % 2=0 entao //Se o n� inferior for par escreve ele e o acrescenta a soma
               escreva(inf,",")
               somaPar<-SomaPar+inf
            fimse  //Nada precosa ser feito caso seja impar
            inf<-inf+1 //Acrescenta-se 1 ao valor inferior de modo que a repeti��o finalize quando inf<sup
      fimenquanto //fim dos comando do la�o de repeti��o
      escreva(" [ e a soma dos inteiros pares deste intervalo �:",somaPar)
   senao //Executa caso o segundo valor seja menor q o primeiro
      escreval(" O primeiro valor do intervalo dado nao � inferior ao segundo:")
   fimse
Fimalgoritmo
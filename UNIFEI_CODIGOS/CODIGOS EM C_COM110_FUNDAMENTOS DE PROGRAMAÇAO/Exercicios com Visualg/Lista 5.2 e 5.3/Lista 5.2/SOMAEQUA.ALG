Algoritmo "somaEqua"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   :calcula e escrever a soma S:
//              S = 1/1 � 2/4 + 3/9 � 4/16 + 5/25 +, ..., - 10/100
// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476
// Data atual  : 30/03/2018
Var
// Se��o de Declara��es das vari�veis 
    s: real // variavel de saida que mostrara o resuldado sa soma
    i: inteiro // variavel de controle do la�o e auxiliara na conta em cada intera��o
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   s<-0  //atribui-se 1 para soma
   para i de 1 ate 10 faca //como a formula vai de 1 ate 10 no numerador ser�o 10 intera��es
        se i%2=0 entao //caso o a parcela da opera��o tem numerador PAR sera subtraido
           s<-s - (1/i) // formula n�o simplificada: soma - (i/i*i)
        senao  //caso o a parcela da opera��o tem numerador IMPAR sera feita soma
           s<-S + (1/i) // formula n�o simplificada: soma + (i/i*i)
        fimse
  fimpara //Estabelece o limite da repeti��o
  escreva("A soma da equa��o S=(1/1)�(2/4)+(3/9)�(4/16)+(5/25)+,...,(-10/100) �:",s)
Fimalgoritmo
Algoritmo "somaEqua"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   :calcula e escrever a soma S:
//              S = 1/1 – 2/4 + 3/9 – 4/16 + 5/25 +, ..., - 10/100
// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476
// Data atual  : 30/03/2018
Var
// Seção de Declarações das variáveis 
    s: real // variavel de saida que mostrara o resuldado sa soma
    i: inteiro // variavel de controle do laço e auxiliara na conta em cada interação
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   s<-0  //atribui-se 1 para soma
   para i de 1 ate 10 faca //como a formula vai de 1 ate 10 no numerador serão 10 interações
        se i%2=0 entao //caso o a parcela da operação tem numerador PAR sera subtraido
           s<-s - (1/i) // formula não simplificada: soma - (i/i*i)
        senao  //caso o a parcela da operação tem numerador IMPAR sera feita soma
           s<-S + (1/i) // formula não simplificada: soma + (i/i*i)
        fimse
  fimpara //Estabelece o limite da repetição
  escreva("A soma da equação S=(1/1)–(2/4)+(3/9)–(4/16)+(5/25)+,...,(-10/100) é:",s)
Fimalgoritmo
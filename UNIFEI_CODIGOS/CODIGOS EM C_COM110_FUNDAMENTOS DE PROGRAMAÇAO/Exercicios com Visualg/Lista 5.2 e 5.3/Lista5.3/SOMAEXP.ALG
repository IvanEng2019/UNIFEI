Algoritmo "SomaExp"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   : Calcular o valor de S, dado por:
//               S = 1/N +2/(N-1) + 3/(N-2) + ... + (N-1)/2 + N/1,
//               sendo N fornecido pelo usu�rio.
//               Valide a entrada de dados.

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476
// Data atual  : 30/03/2018
Var
// Se��o de Declara��es das vari�veis 
    Aux: inteiro //variavel de controle de repeti��o e auxilio na opera��o
    N: inteiro //Variavel finita forncida pelo usuario q funcionar� como cliterio de parada
    NDesc: inteiro //Variavel auxiliar que sera descrescida e utilizado no denominador
    s: Real //Variavel de saida que apresentara o resuldado da opera��o final
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
    escreva("Entre com o valor de N:")
    leia(N)
    se N <> 0 entao //valida a entrada, executa apenas se o usuaria der numero diferente de 0
       s<-0  //Atribui-se 0 a soma
       aux<-1 //Atribui-se 1 a aux
       NDesc<-N // /Atribui-se o valor de N a NDesc
       enquanto (aux<=N) faca  // Repetir� o la�o ate que aux <= N
                 s<-s+aux/NDesc // enquando o numerador aumenta uma unidade o denominador cai uma
                 aux<-Aux+1    // sempre aumenta aux em + 1
                 NDesc<-NDesc -1 // sempre diminui NDesc em - 1
       fimenquanto // fim dos comando de repeti��o
       escreval("o valor de S=1/N+2/(N-1)+3/(N-2)+...+ (N-1)/2 + N/1 �:",s)
    senao // Executa apenas se usuario entrar com N=0
       Escreval("Valor de N Digitado � invalido!")
    fimse
Fimalgoritmo
Algoritmo "sequenciaDiferencial"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Imprimi os n primeiros termos da sequ�ncia definida por
//               recorr�ncia: yi+1 = yi+ i, i = 1, 2, ..., n sendo y1 = 1
// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476
// Data atual  : 29/03/2018
Var
// Se��o de Declara��es das vari�veis 
    n: inteiro  //variavel que determinaro n� de intera��es
    cont: inteiro //variavel auxiliar usado como passo e no calculo do termo seguinte
    y: inteiro //Variavel de saida: Representar� o n� sequencial em cada intera��o
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
    y<-1 // Atribui-se y1=1
    cont<-0 // Atribu-se cont=0
    escreva("Entre com o valor de n:")
    leia(n)
    escreva("A sequencia dos termos s�o:")
    enquanto cont< n faca //O la�o se repetira ate que seja atingido o n� termos dado pelo usuario
            y<-y+cont  //calculo do termo seguinte
            cont<-cont+1 //Muda o passo
            escreva(y)  //Mostra ao usuario o n� formando-se a sequ�ncia devido repeti��o
    fimenquanto //Fim do la�o
Fimalgoritmo
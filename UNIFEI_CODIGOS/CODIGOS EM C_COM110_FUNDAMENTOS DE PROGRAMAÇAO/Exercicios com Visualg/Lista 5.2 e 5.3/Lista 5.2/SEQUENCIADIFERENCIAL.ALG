Algoritmo "sequenciaDiferencial"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Imprimi os n primeiros termos da sequência definida por
//               recorrência: yi+1 = yi+ i, i = 1, 2, ..., n sendo y1 = 1
// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476
// Data atual  : 29/03/2018
Var
// Seção de Declarações das variáveis 
    n: inteiro  //variavel que determinaro nº de interações
    cont: inteiro //variavel auxiliar usado como passo e no calculo do termo seguinte
    y: inteiro //Variavel de saida: Representará o nº sequencial em cada interação
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
    y<-1 // Atribui-se y1=1
    cont<-0 // Atribu-se cont=0
    escreva("Entre com o valor de n:")
    leia(n)
    escreva("A sequencia dos termos são:")
    enquanto cont< n faca //O laço se repetira ate que seja atingido o nº termos dado pelo usuario
            y<-y+cont  //calculo do termo seguinte
            cont<-cont+1 //Muda o passo
            escreva(y)  //Mostra ao usuario o nº formando-se a sequência devido repetição
    fimenquanto //Fim do laço
Fimalgoritmo
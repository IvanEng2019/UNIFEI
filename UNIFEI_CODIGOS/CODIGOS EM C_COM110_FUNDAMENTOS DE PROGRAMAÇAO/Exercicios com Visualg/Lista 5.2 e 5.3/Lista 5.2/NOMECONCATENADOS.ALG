Algoritmo "nomeConcatenados"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   : L� uma lista de n nomes e imprima os nomes concatenados em uma
// frase separados com espa�o. O valor de n deve ser fornecido pelo usu�rio.
//Caso o nome Francisco seja digitado, a leitura dos nomes deve ser
//interrompida. Veja os exemplos abaixo:
//� n=5, nomes digitados = Maria, Joao, Paulo, Felipe e Jose.
//Sa�da: Maria Joao Paulo Felipe Jose.
//� n = 5, nomes digitados = Maria, Joao, Francisco Sa�da: Maria Joao

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476
// Data atual  : 29/03/2018
Var
// Se��o de Declara��es das vari�veis 
   n: inteiro //Vari�vel que representa o total de entradas
   cont: inteiro //Variavel auxiliar no numero de loop
   nome:caracter // Vari�vel que recebe o nome da lista
   frase: caracter //variavel que cebera todos os nomes com espa�o

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
    cont<-1 //Atribui valor 1 a variavel cont
    frase<-"" //Atribui nenhum caracter - varivel sem nenhum caracter
    escreva ("Quantos nomes ser�o dados:")
    leia(n)
    enquanto (cont<=n) faca  //Executa ate quando cont for menor ou igual ao n
            cont<-cont+1   // Acrecenta-se smepre 1 ao cont
            escreva("Entre com o nome:")
            leia(nome)
            Se(nome <> "Francisco") entao   //Executa apenas se o nome nao for igual a Francisco
               frase<-frase+nome+" "
            senao // Quando nome for igual a Francisco sair� do la�o e nao acrescenta francisco na frase
               cont<-n+1  // Para quebrar ou impedir a repti��o do la�o basta que cont seja maior que n
            fimse
    fimenquanto //fim do la�o
    Escreval(frase) //Imprime todos os caracteres da variavel frase
Fimalgoritmo
Algoritmo "nomeConcatenados"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   : Lê uma lista de n nomes e imprima os nomes concatenados em uma
// frase separados com espaço. O valor de n deve ser fornecido pelo usuário.
//Caso o nome Francisco seja digitado, a leitura dos nomes deve ser
//interrompida. Veja os exemplos abaixo:
//• n=5, nomes digitados = Maria, Joao, Paulo, Felipe e Jose.
//Saída: Maria Joao Paulo Felipe Jose.
//• n = 5, nomes digitados = Maria, Joao, Francisco Saída: Maria Joao

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476
// Data atual  : 29/03/2018
Var
// Seção de Declarações das variáveis 
   n: inteiro //Variável que representa o total de entradas
   cont: inteiro //Variavel auxiliar no numero de loop
   nome:caracter // Variável que recebe o nome da lista
   frase: caracter //variavel que cebera todos os nomes com espaço

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
    cont<-1 //Atribui valor 1 a variavel cont
    frase<-"" //Atribui nenhum caracter - varivel sem nenhum caracter
    escreva ("Quantos nomes serão dados:")
    leia(n)
    enquanto (cont<=n) faca  //Executa ate quando cont for menor ou igual ao n
            cont<-cont+1   // Acrecenta-se smepre 1 ao cont
            escreva("Entre com o nome:")
            leia(nome)
            Se(nome <> "Francisco") entao   //Executa apenas se o nome nao for igual a Francisco
               frase<-frase+nome+" "
            senao // Quando nome for igual a Francisco sairá do laço e nao acrescenta francisco na frase
               cont<-n+1  // Para quebrar ou impedir a reptição do laço basta que cont seja maior que n
            fimse
    fimenquanto //fim do laço
    Escreval(frase) //Imprime todos os caracteres da variavel frase
Fimalgoritmo
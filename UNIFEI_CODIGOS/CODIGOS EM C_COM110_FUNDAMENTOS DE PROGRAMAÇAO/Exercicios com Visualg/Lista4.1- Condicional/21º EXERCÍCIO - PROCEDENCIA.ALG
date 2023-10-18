Algoritmo "procedencia21"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Recebe o preço e o codigo de um produto e mostra sua procedência.
// Autor(a)    : Adriel Douglas Nogueira Carlos e Ivan Leoni Vilas Boas
// Data atual  : 22/03/2018
Var
// Seção de Declarações das variáveis 
   valor: real
   codigo: inteiro
   procedencia: caracter
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
     escreva("Entre com o valor do produto:")
     leia(valor)
     escreva("Entre com o codigo de origem do produto:")
     leia(codigo)
     escolha codigo //Estrutura condicional de seleção multipla
       caso 1
            procedencia <-"Sul" //Executara caso codigo for igual a 1
            escreval("O produto de codigo ",codigo," procede do ",procedencia)
       caso 2
            procedencia <-"Norte" //Executara caso codigo for igual a 2
            escreval("O produto de codigo ",codigo," procede do ",procedencia)
       caso 3
            procedencia <-"Leste" //Executara caso codigo for igual a 3
            escreval("O produto de codigo ",codigo," procede do ",procedencia)
       caso 4
            procedencia <-"Oeste" //Executara caso codigo for igual a 4
            escreval("O produto de codigo ",codigo," procede do ",procedencia)
       caso 5,6
            procedencia <-"Nordeste"//Executara caso codigo for igual a 5 ou 6
            escreval("O produto de codigo ",codigo," procede do ",procedencia)
       caso 7,8,9
            procedencia <-"Suldeste"//Executara caso codigo for igual a 8 ou 8 ou 9
            escreval("O produto de codigo ",codigo," procede do ",procedencia)
       outrocaso
            // Executara caso codigo for diferete de 1,2,3,4,5,6,7,8,9
            se (codigo>=10)e(codigo<=20)entao //Executara caso codigo estiver entre 10 e 20
                procedencia <-"Centro-Oeste"
                escreval("O produto de codigo ",codigo," procede do ",procedencia)
            senao
                se (codigo>=21)e(codigo<=30)entao //Executara caso codigo estiver entre 21 e 30
                    procedencia <-"Nordeste"
                    escreval("O produto de codigo ",codigo," procede do ",procedencia)
                senao //Executara caso codigo não estiver entre 1 a 30
                     escreval("Codigo De procedencia errado ou não encontrado/cadastrado.")
                fimse
            fimse
     fimescolha //Fim da estrura de condição de seleção multipla
   Fimalgoritmo
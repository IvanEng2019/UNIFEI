Algoritmo "prestacaoDificil"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   :Em uma loja, a forma de pagamento é uma entrada mais duas
// prestações. A entrada deve ser maior que as demais prestações.
//Por outro lado, as prestações devem ser inteiras e as maiores possíveis.
// Por exemplo, se o valor da mercadoria for R$ 270,00, a entrada e as
// duas prestações são iguais a R$ 90,00; se o valor da mercadoria for
// R$ 302,75, a entrada é de R$ 102,75 e as duas prestações são iguais a
// R$ 100,00. Escreva um algoritmo que receba o valor da mercadoria e forneça
// o valor da entrada e das duas prestações de acordo com as regras acima.

// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 19/03/2018
Var
// Seção de Declarações das variáveis 
    valor,entrada, prest, decimal1,decimal2: real
    valorInter, unidade: inteiro
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
    escreva("Entre com o valor da mercadoria:")
    leia(valor)
    decimal1<-valor-int (valor) //atribui a parte decimal do valor a variavel descimal
    valorInter<- int(valor) //Atribui a parte inteira do valor a variavel valorInt
    unidade<-(valorInter%100)%10  //Descobre quaç é Parcela da unidade e atribui a variavel unidade
    escolha unidade
    caso 0,3,6,9
    //Executa se o valor tiver unidade=0 ou 3 ou 6 ou 9
         entrada <- (valorInter)/3+decimal1
         prest<- (valorInter)/3
    caso 1,4,7
     //Executa se o valor tiver unidade =4 ou 7
         entrada <- ((valorInter-1)/3)+1+decimal1
         prest<- (valorInter-1)/3
    caso 2,5,8
    //Executa se o valor tiver unidade = 5 ou 8
         entrada <- ((valorInter-2)/3)+2+decimal1
         prest<- (valorInter-2)/3
    fimescolha //Fim do comando de multipla condição
    decimal2<-prest-int(prest) //Detemina qual o novo valor decimal da prestação depois de realizado as divisões
    se(decimal2<>0) entao  // se o novo valor decimal for diferente de zero
      entrada<-entrada + 2*decimal2 //A entrada sera acrescida de 2 vezes o valor do decimal
      prest<-prest-decimal2 //De cada prestação  sera retirado 1 vez o valor decimal
      se((entrada-prest)>=3)entao //Executará se o valor da entrada superar ou for igual a 3
         entrada<-entrada-2  //Entrada sera diminuida em 2 unidades
         prest<-prest+1   //a prestação sera aumentada um unidade cada
      fimse
    fimse
    escreva("O valor da primeira é:",entrada," e das 2 prestações são:",prest)
Fimalgoritmo

//     entrada <- (valorInter-unidade)/3+unidade+decimal1
//     prest<- (valorInter-unidade)/3
Algoritmo "MenuMatematico5"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descri��o   : Executa uma das opera��es listadas no menu com dois numeros reais
//               Mostra mensagem de erro se op��o invalida ou divis�o por zero
// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 17/03/2018
Var
// Se��o de Declara��es das vari�veis 
   num1,num2,operacao: real
   opcao:inteiro
Inicio
// Apresenta��o do menu ao usu�rio
   escreval("Tecle 1 para: Realizar m�dia entre dois numeros digitados.")
   escreval("Tecle 2 para: Realizar diferen�a entre dois numeros do maior pelo menor.")
   escreval("Tecle 3 para: Realizar o produto entre dois numeros digitados.")
   escreval("Tecle 4 para: Realizar a divis�o do primeiro numero pelo segundo digitado.")
   escreval("Qual das 4 op��o deseja realizar?")
   leia (opcao)//Usuario faz a escolha da op��o
   escolha opcao //Estrutura condicional de sele��o multipla
   caso 1
   //Realiza M�dia dos numeros digitados caso opcao = 1
         escreval("Entre com o primeiro e segundo numero respectivamente:")
         leia (num1,num2)
         operacao <- (num1+num2)/2
         escreval("A m�dia dos dois numeros �:",operacao)
   caso 2
   //Realiza a diferen�a entre dois numeros maior pelo menor caso opcao = 2
         escreval("Entre com o primeiro e segundo numero respectivamente:")
         leia (num1,num2)
         se (num1 >= num2) entao//Verificar qual � maior
            operacao <- num1-num2 // se num1 for maior executa esta
         senao
            operacao <- num2-num1 // se num2 for maior executa esta
         fimse
         escreval("A diferen�ao do maior pelo menor �:",operacao)
   caso 3
   //Realiza o produto entre os numeros digitados caso opcao = 3
         escreval("Entre com o primeiro e segundo numero respectivamente:")
         leia (num1,num2)
         operacao <- num1*num2
         escreval("O produto dos dois numeros �:",operacao)
   caso 4
   // Realiza a divis�o do primeiro pelo segundo caso opcao = 4
         escreval("Entre com o primeiro e segundo numero respectivamente:")
         leia (num1,num2)
         se num2 = 0  entao //se denominador igual a zero
            escreval("N�o existe divis�o por zero!") //Exibe esta frase
         senao
            operacao <- num1/num2 //Executa se denominador diferente de zero
            escreval("O resultado da divis�o �:",operacao)
         fimse
   outrocaso //Escolhas diferentas de 1,2,3 e 4
         escreval("Op��o ivalida!") //Caso usario digite op��o n�o valida apresenta esta frase
   fimescolha  //Fim da estrutura escolha
Fimalgoritmo
Algoritmo "MenuMatematico5"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA
// Descrição   : Executa uma das operações listadas no menu com dois numeros reais
//               Mostra mensagem de erro se opção invalida ou divisão por zero
// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 17/03/2018
Var
// Seção de Declarações das variáveis 
   num1,num2,operacao: real
   opcao:inteiro
Inicio
// Apresentação do menu ao usuário
   escreval("Tecle 1 para: Realizar média entre dois numeros digitados.")
   escreval("Tecle 2 para: Realizar diferença entre dois numeros do maior pelo menor.")
   escreval("Tecle 3 para: Realizar o produto entre dois numeros digitados.")
   escreval("Tecle 4 para: Realizar a divisão do primeiro numero pelo segundo digitado.")
   escreval("Qual das 4 opção deseja realizar?")
   leia (opcao)//Usuario faz a escolha da opção
   escolha opcao //Estrutura condicional de seleção multipla
   caso 1
   //Realiza Média dos numeros digitados caso opcao = 1
         escreval("Entre com o primeiro e segundo numero respectivamente:")
         leia (num1,num2)
         operacao <- (num1+num2)/2
         escreval("A média dos dois numeros é:",operacao)
   caso 2
   //Realiza a diferença entre dois numeros maior pelo menor caso opcao = 2
         escreval("Entre com o primeiro e segundo numero respectivamente:")
         leia (num1,num2)
         se (num1 >= num2) entao//Verificar qual é maior
            operacao <- num1-num2 // se num1 for maior executa esta
         senao
            operacao <- num2-num1 // se num2 for maior executa esta
         fimse
         escreval("A diferençao do maior pelo menor é:",operacao)
   caso 3
   //Realiza o produto entre os numeros digitados caso opcao = 3
         escreval("Entre com o primeiro e segundo numero respectivamente:")
         leia (num1,num2)
         operacao <- num1*num2
         escreval("O produto dos dois numeros é:",operacao)
   caso 4
   // Realiza a divisão do primeiro pelo segundo caso opcao = 4
         escreval("Entre com o primeiro e segundo numero respectivamente:")
         leia (num1,num2)
         se num2 = 0  entao //se denominador igual a zero
            escreval("Não existe divisão por zero!") //Exibe esta frase
         senao
            operacao <- num1/num2 //Executa se denominador diferente de zero
            escreval("O resultado da divisão é:",operacao)
         fimse
   outrocaso //Escolhas diferentas de 1,2,3 e 4
         escreval("Opção ivalida!") //Caso usario digite opção não valida apresenta esta frase
   fimescolha  //Fim da estrutura escolha
Fimalgoritmo
Algoritmo "seguros"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   :Uma companhia de seguros tem tr�s categorias de seguros
//baseados na idade e ocupa��o do segurado. Somente pessoas com mais de 18
//anos e menos de 70 podem adquirir ap�lices de seguros. Quanto �s classes
//de ocupa��es foram definidos tr�s grupos de riscos. A tabela a seguir
//fornece os c�digos de cada categoria em fun��o da faixa de idade e do
//grupo de risco.Fa�a um algoritmo que receba a idade e o grupo de risco
//de um cliente da companhia e retorne o c�digo da sua categoria.

// Autor(a)    : IVAN LEONI VILAS B�AS
// Data atual  : 19/03/2018
Var
// Se��o de Declara��es das vari�veis 
    idade, cod: inteiro
    gRisco : caracter
Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
   escreva("Entre com a idade  entre 18 e 70 anos:")
   leia(idade)
    se (idade >18) e (idade>70)entao //come�a1
        escreval("Pessoas com idade n�o permitidas a realizar o seguro.")
    senao
       escreva("Entre com qual grupo de risco pentence a pessoa:")
       leia(gRisco)
       se(gRisco = "a") ou (gRisco = "b") ou (gRisco = "c") entao  //come�a2
          se(idade >=18) e (idade <=24) entao //come�a3
            Se(gRisco="a") entao//come�a4
               cod<-7
            Senao
               se(gRisco="b")entao  //come�a5
                  cod<-8
               Senao //se(gRisco="c")
                 cod<-9
               fimse //finaliza5
           fimse //finaliza4
         senao
            se(idade >=25) e (idade <=40) entao //come�a6
               Se(gRisco="a") entao //come�a7
                 cod<-4
               Senao
                  se(gRisco="b")entao //come�a8
                     cod<-5
                  senao //se(gRisco="c")
                     cod<-6
                  fimse //finliza8
               fimse  //finliza7
            senao// se(idade >=41) e (idade <=70) entao
               se(gRisco="a") entao  //come�a9
                  cod<-1
               senao
                  se(gRisco="b")entao //come�a10
                     cod<-2
                  senao //se(gRisco="c")
                     cod<-3
                  fimse //finaliza 10
               fimse  //finaliza9
            fimse //finaliza6
          fimse //finaliza3 - se(idade >=18) e (idade <=24)
          escreval("O codigo desta pessoa �:",cod)
          senao
             escreva("O grupo de risco n�o existe.")
          fimse  //finaliza2 - se(gRisco = "a") ou (gRisco = "b") ou (gRisco = "c")
       fimse //finaliza1 - se (idade >18) e (idade>70)
Fimalgoritmo
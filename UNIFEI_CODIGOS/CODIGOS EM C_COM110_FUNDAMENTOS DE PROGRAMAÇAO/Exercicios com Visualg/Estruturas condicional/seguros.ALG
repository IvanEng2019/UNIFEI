Algoritmo "seguros"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   :Uma companhia de seguros tem três categorias de seguros
//baseados na idade e ocupação do segurado. Somente pessoas com mais de 18
//anos e menos de 70 podem adquirir apólices de seguros. Quanto às classes
//de ocupações foram definidos três grupos de riscos. A tabela a seguir
//fornece os códigos de cada categoria em função da faixa de idade e do
//grupo de risco.Faça um algoritmo que receba a idade e o grupo de risco
//de um cliente da companhia e retorne o código da sua categoria.

// Autor(a)    : IVAN LEONI VILAS BÔAS
// Data atual  : 19/03/2018
Var
// Seção de Declarações das variáveis 
    idade, cod: inteiro
    gRisco : caracter
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...
   escreva("Entre com a idade  entre 18 e 70 anos:")
   leia(idade)
    se (idade >18) e (idade>70)entao //começa1
        escreval("Pessoas com idade não permitidas a realizar o seguro.")
    senao
       escreva("Entre com qual grupo de risco pentence a pessoa:")
       leia(gRisco)
       se(gRisco = "a") ou (gRisco = "b") ou (gRisco = "c") entao  //começa2
          se(idade >=18) e (idade <=24) entao //começa3
            Se(gRisco="a") entao//começa4
               cod<-7
            Senao
               se(gRisco="b")entao  //começa5
                  cod<-8
               Senao //se(gRisco="c")
                 cod<-9
               fimse //finaliza5
           fimse //finaliza4
         senao
            se(idade >=25) e (idade <=40) entao //começa6
               Se(gRisco="a") entao //começa7
                 cod<-4
               Senao
                  se(gRisco="b")entao //começa8
                     cod<-5
                  senao //se(gRisco="c")
                     cod<-6
                  fimse //finliza8
               fimse  //finliza7
            senao// se(idade >=41) e (idade <=70) entao
               se(gRisco="a") entao  //começa9
                  cod<-1
               senao
                  se(gRisco="b")entao //começa10
                     cod<-2
                  senao //se(gRisco="c")
                     cod<-3
                  fimse //finaliza 10
               fimse  //finaliza9
            fimse //finaliza6
          fimse //finaliza3 - se(idade >=18) e (idade <=24)
          escreval("O codigo desta pessoa é:",cod)
          senao
             escreva("O grupo de risco não existe.")
          fimse  //finaliza2 - se(gRisco = "a") ou (gRisco = "b") ou (gRisco = "c")
       fimse //finaliza1 - se (idade >18) e (idade>70)
Fimalgoritmo
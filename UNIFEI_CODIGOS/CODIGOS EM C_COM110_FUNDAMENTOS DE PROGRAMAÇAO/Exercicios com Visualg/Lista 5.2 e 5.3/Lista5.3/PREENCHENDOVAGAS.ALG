Algoritmo "preenchendoVagas"
// Disciplina  : FUNDAMENTOS DE PROGRAMA��O
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descri��o   : Uma empresa decidiu fazer um levantamento em rela��o aos
//candidatos que se apresentarem para preenchimento de vagas no seu quadro
//de funcion�rios. Supondo que voc� seja o programador dessa empresa,
//fa�a um algoritmo que leia, para cada candidato, a idade, o sexo (M ou F)
//e a experi�ncia no servi�o (S ou N). Para encerrar a entrada de dados,
//digite 0 para a idade. Calcule e escreva: a. o n�mero de candidatos do
//sexo feminino e masculino; b. a idade m�dia dos homens que j� t�m
//experi�ncia no servi�o; c. o n�mero de mulheres que j� t�m experi�ncia
//no servi�o; d. o n�mero de mulheres com idade inferior a 35 anos e
//com experi�ncia no servi�o e. N�o � necess�rio validar a entrada de dados.

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476
// Data atual  : 30/03/2018
Var
// Se��o de Declara��es das vari�veis 
   idade: inteiro //variavel de entrada
   contM, contF: inteiro // variaval que recebe a quantidade homens ou mulheres entrevistados
   somaIdMExp: inteiro //Variavel que recebe a soma da sidades dos homens com experiencia
   contMExp, contFExp: inteiro// varial que recebe  a quantidade homens  ou mulheres com experiencia
   contFExpId: inteiro  // variavel que rece a quantidade de mulheres com expreiencia e menos de 35 anos
   sexo, exper: caracter  //Recebe o sexo (M/F) e se teve ou nao esperi�ncia
   mediaMExp: real //varial q recebe a media da idade dos homens com experiencia
Inicio
   // inicializa��o de vaiav�s
   contF<-0
   contM<-0
   mediaMExp<-0
   somaIdMExp<-0
   contFExp<-0
   contFExpId<-0
   contMExp<-0
   
   escreva("Entre com a idade do candidato a vaga:")
   leia(idade)
   
   enquanto idade <>0 faca  //Repetira o la�o ate que a idade digitada seja 0
            escreva("Entre com o sexo M ou F do candidato a vaga:")
            leia(sexo)
            escreva("Entre com a experiencia S ou N do candidato a vaga:")
            leia(exper)
            se sexo = "M" entao  //Executa caso seja homem
               contM<-contM+1    //Conta quantos homens tem
               se exper="S" entao  //Executa se for home e tiver experi�ncia
                  somaIdMExp<-somaIdMExp+idade  //Soma as idades dos homens com experiencia
                  contMExp<-contMExp+1    //Conta quantos homens com experi�ncia tem
               fimse
            senao   //Executa caso seja mulher
               ContF<-contF+1   //Conta quantas mulheres tem
               se (exper="S")entao  //Executa caso seja mulher e tenha experi�ncia
                  contFExp<-contFExp+1  //Conta quantas mulheres tem com experi�ncia
                  se (idade <35) entao //Executa se a mulher com expereincia tiver menos de 35
                     contFExpId<-contFExpId+1 //conta quantas mulher com experiencia tem menos de 35
                  fimse
               fimse
            fimse
            escreva("Entre com a idade do candidato a vaga:")
            leia(idade)
   fimenquanto // fim dos comandos de repiti��o
   escreval("O numero total de homens s�o:",ContM," e O numero total de mulheres s�o:",ContF)
   se contMExp <> 0 entao  //Executa caso tenha ao menos um homem com experi�ncia
       mediaMExp<-somaIdMExp/contMExp
       escreval("A idade m�dia dos homens que j� t�m experi�ncia no servi�o �:",mediaMExp)
   fimse
   escreval("O n�mero total de mulheres com experi�ncia no servi�o s�o:",ContFExp)
   escreval("O n�mero total de mulheres com idade inferior a 35 anos e com experi�ncia no servi�o s�o:",contFExpId)
Fimalgoritmo
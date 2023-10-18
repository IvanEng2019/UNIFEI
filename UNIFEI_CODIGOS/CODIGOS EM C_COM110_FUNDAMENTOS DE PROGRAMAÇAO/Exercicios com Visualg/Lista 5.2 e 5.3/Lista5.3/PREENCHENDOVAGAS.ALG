Algoritmo "preenchendoVagas"
// Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
// Professor   : MELISE MARIA VEIGA DE PAULA

// Descrição   : Uma empresa decidiu fazer um levantamento em relação aos
//candidatos que se apresentarem para preenchimento de vagas no seu quadro
//de funcionários. Supondo que você seja o programador dessa empresa,
//faça um algoritmo que leia, para cada candidato, a idade, o sexo (M ou F)
//e a experiência no serviço (S ou N). Para encerrar a entrada de dados,
//digite 0 para a idade. Calcule e escreva: a. o número de candidatos do
//sexo feminino e masculino; b. a idade média dos homens que já têm
//experiência no serviço; c. o número de mulheres que já têm experiência
//no serviço; d. o número de mulheres com idade inferior a 35 anos e
//com experiência no serviço e. Não é necessário validar a entrada de dados.

// Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
//            Fabricio Guedes da Silva - RU: 2018014476
// Data atual  : 30/03/2018
Var
// Seção de Declarações das variáveis 
   idade: inteiro //variavel de entrada
   contM, contF: inteiro // variaval que recebe a quantidade homens ou mulheres entrevistados
   somaIdMExp: inteiro //Variavel que recebe a soma da sidades dos homens com experiencia
   contMExp, contFExp: inteiro// varial que recebe  a quantidade homens  ou mulheres com experiencia
   contFExpId: inteiro  // variavel que rece a quantidade de mulheres com expreiencia e menos de 35 anos
   sexo, exper: caracter  //Recebe o sexo (M/F) e se teve ou nao esperiência
   mediaMExp: real //varial q recebe a media da idade dos homens com experiencia
Inicio
   // inicialização de vaiavés
   contF<-0
   contM<-0
   mediaMExp<-0
   somaIdMExp<-0
   contFExp<-0
   contFExpId<-0
   contMExp<-0
   
   escreva("Entre com a idade do candidato a vaga:")
   leia(idade)
   
   enquanto idade <>0 faca  //Repetira o laço ate que a idade digitada seja 0
            escreva("Entre com o sexo M ou F do candidato a vaga:")
            leia(sexo)
            escreva("Entre com a experiencia S ou N do candidato a vaga:")
            leia(exper)
            se sexo = "M" entao  //Executa caso seja homem
               contM<-contM+1    //Conta quantos homens tem
               se exper="S" entao  //Executa se for home e tiver experiência
                  somaIdMExp<-somaIdMExp+idade  //Soma as idades dos homens com experiencia
                  contMExp<-contMExp+1    //Conta quantos homens com experiência tem
               fimse
            senao   //Executa caso seja mulher
               ContF<-contF+1   //Conta quantas mulheres tem
               se (exper="S")entao  //Executa caso seja mulher e tenha experiência
                  contFExp<-contFExp+1  //Conta quantas mulheres tem com experiência
                  se (idade <35) entao //Executa se a mulher com expereincia tiver menos de 35
                     contFExpId<-contFExpId+1 //conta quantas mulher com experiencia tem menos de 35
                  fimse
               fimse
            fimse
            escreva("Entre com a idade do candidato a vaga:")
            leia(idade)
   fimenquanto // fim dos comandos de repitição
   escreval("O numero total de homens são:",ContM," e O numero total de mulheres são:",ContF)
   se contMExp <> 0 entao  //Executa caso tenha ao menos um homem com experiência
       mediaMExp<-somaIdMExp/contMExp
       escreval("A idade média dos homens que já têm experiência no serviço é:",mediaMExp)
   fimse
   escreval("O número total de mulheres com experiência no serviço são:",ContFExp)
   escreval("O número total de mulheres com idade inferior a 35 anos e com experiência no serviço são:",contFExpId)
Fimalgoritmo
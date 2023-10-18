/*******************************************************************************************************
Faça um programa para controlar o estoque de mercadorias de uma empresa. Inicialmente, o programa deverá
preencher dois vetores com dez posições cada, onde o primeiro corresponde ao código do produto e o
segundo, ao total desse produto em estoque. Logo após, o programa deverá ler um conjunto indeterminado
de dados contendo o código de um cliente e o código do produto que ele deseja comprar, juntamente com a
quantidade. Código do cliente igual a zero indica fim do programa. O programa deverá verificar:
■ se o código do produto solicitado existe. Se existir, tentar atender ao pedido; caso contrário, exibir
mensagem Código inexistente;
■ cada pedido feito por um cliente só pode ser atendido integralmente. Caso isso não seja possível,
escrever a mensagem Não temos estoque suficiente dessa mercadoria. Se puder atendê-lo, escrever
a mensagem Pedido atendido. Obrigado e volte sempre;
■ efetuar a atualização do estoque somente se o pedido for atendido integralmente;
■ no final do programa, escrever os códigos dos produtos com seus respectivoss etoques já atualizados.
********************************************************************************************************/
//inclusão da bibliotecas
 #include<stdio.h>

 #define MAX 10

 //Função que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 24/05/2018\n\n");
        printf("Programa estoque\n");
}
int main(){
    cabecalho(); //imprime os dados do aluno
     //declaração de variaveis
     int codProd[MAX],qtdEst[MAX]; // variaveis de saida sendo ambas vetores com tamanho 10 de posição 0 a 9
     int i,codCli,semafaro; //variaveis auxiliares de manipulação
     int qtdCli,codProdCli; //Variavel de entrada
     //geração de codigos do produto e a quantidade deles no estoque
     for(i=0;i<MAX;i++) //repetira ate que seja valor menos que o valor de max, no caso 10 vezes
     {
         codProd[i]=i+1; //gera codigo produto
         qtdEst[i]=100*(i+1); //gera quantidade em estoque
     }
     do{
         printf("Entre com o codido do cliente:\n");
         scanf("%d",&codCli);
         if(codCli!=0) //executa cso codigo do prodto seja diferente de 0.
         {
             printf("Entre com o codido do produto a ser comprado e a quantidade.\n");
             scanf("%d %d",&codProdCli,&qtdCli);
             semafaro=0; // variável de controle que quando zero inicará que nao existe o codigo.
             for(i=0;i<MAX;i++)
             {
                 if(codProd[i]==codProdCli)//ira comparar se o codigo digitado é igual ao codigo ja existente no vetor.
                 {   semafaro=1;// caso exista o codigo atribui 1 a variavel semafaro.
                     if((qtdEst[i]-qtdCli)>=0)//ira comparar se a quantidade existe no estoque menos a quantidade que o cliente
                     {                       //deseja é suficiente para atender ao pedido do cliente.
                         printf("Pedido atendido. Obrigado e Volte sempre.\n\n"); //se a quantidade de produtos satisfaz o pedido entao
                         qtdEst[i]=qtdEst[i]-qtdCli;               // é realizada a retirada a quantidadade daquele produto .
                     }
                     else //se a quantidade de estoque for menor que a aquantidade solicitada no pedido entao:
                     {
                         printf("Não temos estoque o suficiente desta mercadoria.\n\n");
                     }
                 }
             }
           if(semafaro==0)// se a variavel semafaro for igual a zero entao quer dizer que o codigo nao exite
                    printf("Codigo inexistente.\n\n");
         }
     }while(codCli!=0);// laço repete ate codcliente seja 0
     for(i=0;i<MAX;i++) // laço para impremi a o codigo do produto e quantidade dele.
        printf("Codigo do Produto:%d. Quantidade em Estoque:%d\n",codProd[i],qtdEst[i]);
 return 0;
}

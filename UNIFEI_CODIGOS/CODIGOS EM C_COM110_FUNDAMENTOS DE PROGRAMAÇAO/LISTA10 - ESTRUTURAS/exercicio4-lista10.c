/*******************************************************************************************************************************
4. Crie uma estrutura para armazenar dados de um produto (código – inteiro/preço-float). Crie um programa para receber dados
de 100 produtos. Armazene estas informações em um vetor. Depois de preenchido o vetor, crie funções para os seguintes casos:
    a. Verificar se o produto de código X (X>0 e deve ser fornecido pelo usuário) foi armazenado. Caso seja encontrado, retorne
       o preço do produto.
    b. Ajustar o preço de todos os produtos. O valor do ajuste em porcentagem deverá ser fornecido pelo usuário.
    c. Imprimir os dados dos produtos;
*********************************************************************************************************************************/
#include <stdio.h> // inclusão de bibliotecas com funçoes predefinidas
#define TAM 100 // define uma contante que indicara sempre o valor do tamnho maximo da minha lista, no caso 100 produtos diferentes
//Criando estrutura que tera duas variaveis cod e preço
struct produto{
    int cod; // variavel codigo do produto do tipo inteiro
    float preco;// varial preço do produto do tipo real-> float
};
//função que imprime na tela todos os dados dos produtos
void imprimir(struct produto p[])
{
    printf("\nLista com dados de todos os produtos em estoque:\n");
    for(int i=0;i<TAM;i++)// for para mudar a posição do item da minha lista. ou seja, percorre todos os itens da lista
        printf("\nProduto:%d\nCodigo:%d\nPreco:%.2f\n",i+1,p[i].cod,p[i].preco); // imprime todos os dados dos produtos na ondem de cadastro
}
//função vai alterar os preços de todos os produtos da lista
void alteracao(struct produto p[],int altera)
{
    for(int i=0;i<TAM;i++)// for para mudar a posição do item da minha lista. ou seja, percorre todos os preços da lista
       p[i].preco*=1+((float)altera/100);//formula para almentar o valor do prço de cada produto
}
//função que retorna o preço do produto caso o codigo do produto esteja na lista
float buscaCod( struct produto p[], int x)
{
    int i; //variavel que indicara a posição da varialvel da estrura na lista
    float aux=0;// varialvel de controle que auxiliará caso não exiat o codigo na lista
    for(i=0;i<TAM;i++)
    {
        if(p[i].cod==x)//compara se o codigo digitado pelo usaurio é igual a algum codigo da lista
        {
            aux=1;//quando o codigo é encontrado atribui 1 a Aux
            break;//sai do laço de repetição qando o codigo é encontrado
        }
    }
    if (aux==1)//caso tenha encontrado o codigo na lista
        return p[i].preco;
    else//caso nao tenha encontrado o codigo na lista
        return aux;
}
int main(){
    struct produto prod[TAM];// criando vetor de estrura com tamanho maximo de TAM
    int X,altera; // variaveil e entrada do usuario
    float resp; // variavel que recebera o retorno da função busca
    printf("Cadastrando produto no estoque.\n");
    for(int i=0;i<TAM;i++)//laço para cadastrar os produtos no estoque
    {
        do{
            printf("Entre com o codigo (maior que zero) e o valor do produto:");//pede ao usuario
            scanf("%d %f",&prod[i].cod,&prod[i].preco);// salva os valores respectivamente na variavel cod e preco conforme a posição de i
         }while(prod[i].cod<=0);//executa o laço enquanto x nao for maior que zero
    }
    printf("Fim do cadastro de produto no estoque.\n");
    do{
        printf("\nEntre com o codigo(X) do produto e caso o codigo exista no estoque é impresso o valor do produto.X>0:\n");//pede ao usuario
        scanf("%d",&X);// o codigo de inteiro dado pelo usuario e salvo na variavel x
    }while(X<=0);//executa o laço enquanto x nao for maior que zero
    resp=buscaCod(prod,X);//chama a função busca passando prod por referencia e x por valor
    if(resp!=0)//caso o codigo exista na lista resp sera diferente de zero e o printf sera executado
        printf("O produto custa %.2f.\n",resp);
    printf("\nDeseja ajustar o preco de todos os produtos do estoque para quantos %:");//pede ou usario
    scanf("%d",&altera);//salva na memoria o valor digitado pelo usuario na variavel altera
    alteracao(prod,altera);//chama a função alera passando prod por referencia e altera por valor
    imprimir(prod);//chama a função imprimir para mostar a lista com todos os dados passando prod por referencia
return 0;
}

#include<stdio.h>

#define QTD 5
#define AVISAR 100

typedef struct {
        int codProduto;
        int qtdEstoque;
        char nomeProduto[100];
        char nomeFornecedor[100];
        float precoUnit;
}produto;

void menu(){
     printf("\nMENU PRINCIPAL\n");
     printf("1- Cadastro de produto novo\n");
     printf("2- Incluir quantidade de produto no estoque.\n");
     printf("3- Retirar quantidade de produto no estoque.\n");
     printf("4- Visualizar quantidade no estoque\n");
     printf("5- Sair\n"); // falta alterar, deletar
     return;
}

void cadastroProdutoNovo(int *ultimo,int *max, produto *item ){
    char continuar;
    if(*max>0)
    {
    do{
        printf ("\nNovo cadastro:\nEntre com o nome do Novo Produto:");
        scanf (" %s", &item[*ultimo].nomeProduto);
        printf ("Entre com o codigo do Novo Produto:");
        scanf ("%d", &item[*ultimo].codProduto);
        printf ("Entre com a quantidade inicial do Novo Produto:");
        scanf ("%d", &item[*ultimo].qtdEstoque);
        printf ("Entre com o nome do fornecedor Produto:");
        scanf ("%s", &item[*ultimo].nomeFornecedor);
        printf ("Entre com o nome o valor unitario Produto:");
        scanf ("%f", &item[*ultimo].precoUnit);
        (*ultimo)++;
        (*max)--;
        do{
            printf("Deseja fazer novo cadastro (S/N)?");
            scanf(" %c",&continuar);
        }while (continuar!= 'S' && continuar!= 'N' && continuar!= 's' && continuar!= 'n');
     } while((continuar == 'S' || continuar == 's' )&& (*max>0));
    }
    else
        printf ("Memoria cheia.\n");
     return;
}

 void adicionarQtdEstoque(int pos, produto item[]){
      int i, add, cod;
      char continuar;
      do{
        printf("Entre com o codigo do produto a ser adicionado:");
        scanf("%d",&cod);
        printf("Entre com a quantidade a ser adicionada:");
        scanf("%d",&add);
        if(add>0)
          for (i=0;i<pos;i++)
              if (cod==item[i].codProduto)
                item[i].qtdEstoque= item[i].qtdEstoque+add;
        else
            printf ("Valor invalido.\n");
        do{
            printf("Deseja adicionar novamente (S/N)?");
            scanf(" %c",&continuar);
        }while (continuar!= 'S' && continuar!= 'N' && continuar!= 's' && continuar!= 'n');
     }while(continuar == 'S' || continuar == 's' );
     return;
 }

 void retirarQtdEstoque(int pos, produto item[]){
      int i,ret,cod;
      char continuar;
      do{
        printf("Entre com o codigo do produto a ser retirado:");
        scanf("%d",&cod);
        printf("Entre com a quantidade a ser retirada:");
        scanf("%d",&ret);
        if(ret<=0)
            printf ("Valor invalido.\n");
        else
        {
          for (i=0;i<pos;i++)
            if (cod == item[i].codProduto)
            {
                if (item[i].qtdEstoque - ret >=0)
                    item[i].qtdEstoque = item[i].qtdEstoque-ret;
                else
                   printf ("Impossivel tirar esta quantidade no estoque so tem % d.\n",item[i].qtdEstoque);
                if(item[i].qtdEstoque <= AVISAR && item[i].qtdEstoque !=0)
                    printf ("A quantidade do produto %s já atingiu %d! Fazer pedido ao fornecedor.\n",item[i].nomeProduto,item[i].qtdEstoque);
                if(item[i].qtdEstoque == 0)
                    printf ("A quantidade do produto %s é 0 no estoque!\nverificar pedido com Fornecedor\n",item[i].nomeProduto);
            }
        }
        do{
            printf("Deseja retirar algum produto do Estoque (S/N)?");
            scanf(" %c",&continuar);
        }while (continuar!= 'S' && continuar!= 'N' && continuar!= 's' && continuar!= 'n');
     }while(continuar == 'S' || continuar == 's');
     return;
 }

 void mostrarQtdEstoque (int pos,produto item[]) {
     int i,cod;
     printf("Entre com o codigo do produto que deseja ver a quantidade em estoque:");
     scanf("%d",&cod);
     for(i=0;i<pos;i++)
        if(cod == item[i].codProduto)
           printf ("A quantidade do produto %s em estoque é de %d unidades.\n",item[i].nomeProduto, item[i].qtdEstoque);
     return;
 }

int main(){
    int opcao,posicao=0,max= QTD;
    char continuar ='n';
    produto item [QTD];
    do{
       do{
            menu();
            printf("\nSelecione a opcao desejada:");
            scanf(" %d",&opcao);
        }while (opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5);
        switch(opcao)
        {
            case 1:
            cadastroProdutoNovo(&posicao,&max,item);
            break;
            case 2:
            adicionarQtdEstoque(posicao,item);
            break;
            case 3:
            retirarQtdEstoque(posicao,item);
            break;
            case 4:
            mostrarQtdEstoque(posicao,item);
            break;
        }
        if(opcao!=5)
        {
          do{
             printf("\nDeseja voltar ao menu principal(S/N)?");
             scanf(" %c",&continuar);
          }while (continuar!= 'S' && continuar!= 'N' && continuar!= 's' && continuar!= 'n');
        }
        if (continuar=='n')
            printf ("Fechando programa do Estoque.\n");
    } while(continuar == 'S' || continuar == 's' );

}


#include<stdio.h>
#include<stdlib.h>


#define QTD 3

typedef struct material
{
        int cod_produto[QTD];
        int qtd_estoque[QTD];
        char nome_produto [100];
        char nome_fornecedor [100];
        float preco_unit;
}produto;

void menu(){
     printf("MENU principal\n");
     printf("1- Incluir produto no estoque.\n");
     printf("2- Retirar produto no estoque.\n");
     printf("3- Visualizar quantidade no estoque\n");
     printf("4- Cadastro de produto novo\n");
     printf("5- Sair\n"); // falta alterar, deletar
}
 void adicionar_estoque(int pos){
      int add;
      produto item[QTD];
      do{
        printf("Entre com o codigo do produto a ser adicionado:");
        scanf("%d",&item.cod_produto[0]);
        printf("Entre com a quantidade a ser adicionada:");
        scanf("%d",&add);
        if(add>0)
        {
          for (int i=1; i<pos; i++)
            if (produto.cod_produto[0]== produto.cod_produto[i])
                qtd_estoque[i]= qdtd_estoque[i]+add;
        }
        else
            printf ("Valor invalido.\n");
      } while(add<1);
      return;
 }

 void retirar_estoque(int pos){
      int ret;
      do{
        printf("Entre com o codigo do produto a ser retirado:");
        scanf("%d",&produto.cod_produto[0]);
        printf("Entre com a quantidade a ser retirada:");
        scanf("%d",&add);
        if(add>0)
        {
          for (int i=1;i<pos;i++)
            if (produto.cod_produto[0]== produto.cod_produto[i])
                qtd_estoque[i]= qdtd_estoque[i]-ret;
        }
        else
            printf ("Valor invalido.\n");
      } while(add<1);
      return;
 }

 void mostrar estoque (int pos)
 {
     printf("Entre com o codigo do produto a ser retirado:");
     scanf("%d",&produto.cod_produto[0]);
     for (int i=1;i<pos;i++)
            if (produto.cod_produto[0]== produto.cod_produto[i])
                printf ("A quantidade do produto %s em estoque é de %d unidades.\n".produto.nome_produto, produto.qtd_estoque);
     return 0;

 }

void cadastro_produto(int *ultimo)
{
    do{
        printf ("\nEntre com o nome do Novo Produto:");
        scanf ("%s", &produto.nome_produto[*ultimo+1]);
        printf ("\nEntre com o codigo do Novo Produto:");
        scanf ("%d", &produto.cod_produto[*ultimo+1]);
        printf ("\nEntre com a quantidade inicial do Novo Produto:");
        scanf ("%d", &produto.qtd_produto[*ultimo+1]);
        printf ("\nEntre com o nome do fornecedor Produto:");
        scanf ("%s", &produto.nome_fornecedor[*ultimo+1]);
        printf ("\nEntre com o nome o valor unitario Produto:");
        scanf ("\n%f", &produto.preco_unit[*ultimo+1]);
        *ultimo= *ultimo+1;
        do{
                printf("Deseja fazer novo cadastro (S/N)?");
                scanf(" %c,&continuar);
            }while (continuar!= 'S' || continuar!= 'N' || continuar!= 's' || continuar!= 'n');
     } while(continuar== "S" || continuar== "s" );
}


int main()
{
    int menu;
    char continuar='n';
    int posicao=0;
    do{
        do{
            menu();
            printf("Selecione a opcao desejada ->");
            scanf(" %d,&menu");
        }while (menu!=1 || menu!=2 || menu!=3 || menu!=4 || menu!=5);
        switch(menu)
        {
            case 1:
            adicionar_estoque(posicao);
            break;
            case 2:
            retirar_estoque(posicao);
            break;
            case 3:
            mostrar estoque(posicao);
            break;
            case 4:
            cadastro_produto(&posicao);
            break;
            case 5:
            break;
        }
        if(menu!=4)
        {
            do{
                printf("Deseja rever novamentes as opções (S/N)?");
                scanf(" %c,&continuar);
            }while (continuar!= 'S' || continuar!= 'N' || continuar!= 's' || continuar!= 'n');
        }
    } while(continuar== "S" || continuar== "s" );
}


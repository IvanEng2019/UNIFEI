#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

#define QTD 5000
#define AVISAR 1000

typedef struct {
        int codProduto;
        int qtdEstoque;
        char nomeProduto[100];
        char nomeFornecedor[100];
        float precoUnit;
}produto;

void equipe(){
    system("cls");
    printf("Disciplina: INTRODUÇÃO A SISTEMAS DE INFORMAÇÃO\nProfessor: Alexandre Carlos Brandão Ramos");
    printf("\n\nAutores:\n Ivan Leoni Vilas Boas - RU: 2018009073\n Leonardo Rodrigo De Souza - RU: 2018015965");
    printf("\n Thiago Marcelo Passos - RU: 2018002850\n Ygor De Carvalho Andrade - RU: 2018012838");
    printf("\nData: 22/05/2018\n\n");
}

void menu(){
     system("cls");
     printf("EMPRESA LITY Ltda\n\nMENU PRINCIPAL.\n");
     printf("1- Cadastro de produto novo\n");
     printf("2- Incluir quantidade de produto no estoque.\n");
     printf("3- Retirar quantidade de produto no estoque.\n");
     printf("4- Visualizar quantidade no estoque de um produto \n");
     printf("5- Imprimir todos produtos no estoque.\n");
     printf("6- Equipe.\n");
     printf("7- Sair\n");
     return;
}

void cadastroProdutoNovo(int *ultimo,int *max, produto *item ){
    system("cls");
    char continuar,correto;
    int i,existe;
    if(*max>0)
    {
    do{
        (*ultimo)++;
        do{
            printf ("Fazendo novo cadastro de produto no estoque\n\n");
            do{
                printf ("Entre com o codigo do Novo Produto:");
                scanf ("%d", &item[*ultimo].codProduto);
                existe=0;
                if((*ultimo)>0)
                {
                  for(i=0;i<=(*ultimo-1);i++)
                  {
                    if(item[*ultimo].codProduto==item[i].codProduto)
                       existe=1;
                  }
                  if(existe==1)
                    printf("Codigo já existe.\n\n");
                }
            }while(existe==1);
            fflush(stdin);
            printf("Entre com o nome do Novo Produto:");
            scanf(" %s", &item[*ultimo].nomeProduto);
            do{
                printf ("Entre com o valor unitario Produto:");
                scanf (" %f", &item[*ultimo].precoUnit);
                if (item[*ultimo].precoUnit==0)
                    printf("Não existe preço negativo.\n");
            }while(item[*ultimo].precoUnit<0);
            do{
                printf ("Entre com a quantidade inicial do Novo Produto:");
                scanf ("%d", &item[*ultimo].qtdEstoque);
                if (item[*ultimo].qtdEstoque==0)
                    printf("Não existe quantidade negativa.\n");
            }while(item[*ultimo].qtdEstoque<0);
            printf ("Entre com o nome do fornecedor Produto:");
            scanf (" %s", &item[*ultimo].nomeFornecedor);
            printf("\nConfirmando gravação dos dados...\n\nFavor verifique os dados do novo produto:\n");
            printf("Codigo Item: %d\n",item[*ultimo].codProduto);
            printf("Nome Produto: %s\n",item[*ultimo].nomeProduto);
            printf("Preço unitario:%.2f\n",item[*ultimo].precoUnit);
            printf("Quantidade em estoque: %d\n",item[*ultimo].qtdEstoque);
            printf("Nome fornecedor: %s\n",item[*ultimo].nomeFornecedor);
            do{
                do{
                    printf("\nOs dados digitados estão corretos(s/n)?");
                    fflush(stdin);
                    scanf(" %c",&correto);
                }while (correto!='S' && correto!='N' && correto!='s' && correto!='n');
                if (correto=='s')
                {
                    printf("Produto cadastrado com sucesso!\n\n");
                    (*max)--;
                }
                else
                    printf("\nCorrigindo cadastro...\n");
            }while(correto!= 'S' && correto!= 'N' && correto!= 's' && correto!= 'n');
        }while(correto=='n');
        correto='n';
        do{
            printf("Deseja fazer cadastro de outro produto novo (S/N)?");
            scanf(" %c",&continuar);
            system("cls");
        }while (continuar!= 'S' && continuar!= 'N' && continuar!= 's' && continuar!= 'n');
     } while((continuar == 'S' || continuar == 's' )&& (*max>0));
    }
    else
        printf("Memoria cheia.\n");
     return;
}

 void adicionarQtdEstoque(int pos,produto item[]){
      system("cls");
      int i, add, cod, existe;
      char continuar;
      if(pos!=-1)
      {
        do{
           printf ("Adicionando produto no estoque\n\n");
           printf("Entre com o codigo do produto a ser adicionado:");
           scanf("%d",&cod);
           existe=0;
           for (i=0;i<=pos;i++)
           {
              if (cod==item[i].codProduto)
              {
                 do{
                    printf("Entre com a quantidade a ser adicionada:");
                    scanf("%d",&add);
                    if(add<1)
                        printf("Não tem como adicionar numeros negativos.\n\n");
                 }while(add<1);
                 item[i].qtdEstoque= item[i].qtdEstoque+add;
                 printf("Quantidade do produto adicionado com sucesso.\n\n");
                 existe=1;
             }
           }
        if(existe==0)
           printf("Não exite este codigo.\n\n");
        do{
            printf("Deseja adicionar novamente em outro código(S/N)?");
            scanf(" %c",&continuar);
            system("cls");
        }while (continuar!= 'S' && continuar!= 'N' && continuar!= 's' && continuar!= 'n');
      }while(continuar == 'S' || continuar == 's' );
      }
      else
        printf ("O estoque não apresenta produto nenhum.\n\n");
     return;
 }

 void retirarQtdEstoque(int pos,produto item[]){
      system("cls");
      int i,ret,cod,existe;
      char continuar;
      if(pos==-1)
          printf ("O estoque não apresenta produto nenhum.\n\n");
      else
      {
        do{
            printf ("Retirando produto no estoque\n\n");
            printf("Entre com o codigo do produto a ser retirado:");
            scanf("%d",&cod);
            existe=0;
            for (i=0;i<=pos;i++)
            {
              if (cod == item[i].codProduto)
              {
                existe=1;
                do{
                    printf("Entre com a quantidade a ser retirada:");
                    scanf("%d",&ret);
                    if(ret<=0)
                      printf ("Valor negativo é invalido.\n\n");
                }while(ret<=0);
                if (item[i].qtdEstoque - ret >=0)
                {
                    item[i].qtdEstoque = item[i].qtdEstoque-ret;
                    printf("Quantidade do produto retirada com sucesso.\n\n");
                    if(item[i].qtdEstoque <= AVISAR && item[i].qtdEstoque !=0)
                    {
                        printf ("Produto acabando!\n A quantidade do produto %s atingiu %d unidades.\n",item[i].nomeProduto,item[i].qtdEstoque);
                        printf("Faça novo pedido ao fornecedor ou verique se ja foi feito.\n\n");
                    }
                    if(item[i].qtdEstoque == 0)
                        printf ("Este produto acabou no estoque!\nVerificar com urgência como se enocontra pedido feito ao Fornecedor\n\n",item[i].nomeProduto);
                }
                else
                   printf ("Impossivel tirar esta quantidade no estoque.Possui %d em estoque.\n\n",item[i].qtdEstoque);
              }
            }
            if(existe==0)
                printf("Codigo Invalido.\n\n");
            do{
                printf("Deseja fazer outra retirada de algum produto do Estoque (S/N)?");
                scanf(" %c",&continuar);
                system("cls");
            }while (continuar!= 'S' && continuar!= 'N' && continuar!= 's' && continuar!= 'n');
        }while(continuar == 'S' || continuar == 's');
     }
     return;
 }

 void mostrarQtdProdEstoque(int pos,produto item[]) {
     system("cls");
     int i,cod,existe=0;
     if(pos!=-1)
     {
        printf ("visualizando apenas um produto do estoque\n\n");
        printf("Entre com o codigo do produto que deseja ver a quantidade em estoque:");
        scanf("%d",&cod);
        for(i=0;i<=pos;i++)
        {
           if(cod == item[i].codProduto)
           {
               printf ("A quantidade do produto %s em estoque é de %d.\n\n",item[i].nomeProduto, item[i].qtdEstoque);
               existe=1;
           }
        }
        if(existe==0)
            printf("Não existe produto com este código.\n\n");
     }
      else
        printf ("O estoque não tem produto nenhum.\n\n");
     return;
 }

void inventario(int pos,produto item[]){
    system("cls");
    int i;
    float valorTotal;
    if(pos==-1)
        printf ("O estoque não possui produto nenhum.\n\n");
    else
    {
        printf ("Visualizando todos os produto exisente no estoque\n\n");
        for(i=0;i<=pos;i++)
        {
            valorTotal= (item[i].precoUnit) * float(item[i].qtdEstoque) ;
            printf("Codigo Item: %d\n",item[i].codProduto);
            printf("Nome Produto: %s\n",item[i].nomeProduto);
            printf("Quantidade em estoque: %d\n",item[i].qtdEstoque);
            printf("Nome fornecedor: %s\n",item[i].nomeFornecedor);
            printf("Preço unitario:%.2f\n",item[i].precoUnit);
            printf("Preço Total:%.2f\n\n",valorTotal);
        }
    }
    return;
}

int main(){
    int opcao,posicao=-1,max=QTD;
    char continuar;
    produto item [QTD];
    setlocale(LC_ALL,"Portuguese");
    do{
       do{
            menu();
            printf("\nSelecione a opcao desejada:");
            scanf(" %d",&opcao);
        }while (opcao<1 && opcao>8);
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
            mostrarQtdProdEstoque(posicao,item);
            break;
            case 5:
            inventario(posicao,item);
            break;
            case 6:
            equipe();
            break;
            default:
            continuar='n';
        }
        if(opcao!=7)
        {
          do{
             printf("Deseja escolher outra opçao do menu principal(S/N)?");
             scanf(" %c",&continuar);
          }while (continuar!= 'S' && continuar!= 'N' && continuar!= 's' && continuar!= 'n');
        }
    } while(continuar == 'S' || continuar == 's' );
    return 0;
}

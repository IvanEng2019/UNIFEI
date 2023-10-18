//bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

//outras bibliotecas
#include "lista.h"
#include "listaEncC.h"


int menu();
int menuInserir();
//int menuRemover();
//int menuBusca();
int numeroSerInserido();
int acoes();
int escolhaLista();
int quantNumerosRemovidos();
int posicoesTroca();

int main() {

    Lista *li, *li2;

    int op, dado, simOunao, simOunao2, menuInserirLista, op3, op4, ok, acao, list1Empty, list2Empty;
    int choise, quant, posi1, posi2;
    //para op != 4
    do{
        op = menu();

        system("clear");

        //lista encadeada
        if(op == 1){
            li = criar_lista();
            li2 = criar_lista();

            if(li != NULL && li2 != NULL){
                printf("\nLista Criada com Sucesso!\n\n");

                //deseja inserir outro valor na lista 1
                do{
                    printf("Inserindo os valores na lista 1: \n");

                    menuInserirLista = menuInserir(); //chama menu de inserção
                    system("clear");

                    dado = numeroSerInserido(); //chama funçao que pega o numero digitado

                    system("clear");

                    //inserir inicio da lista
                    if(menuInserirLista == 1){
                        ok = inserirInicioLista(li, dado);

                        if(ok == 1){
                            printf("Numero %d foi inserido com sucesso:\n", dado);
                        }
                        if(ok == -1){
                            printf("\nErro! Voce nao pode inserir na lista, por que ela nao existe");
                        }
                    }else if(menuInserirLista == 2){
                        ok = inserirMeioLista(li, dado);
                        if(ok == 1){
                            printf("Numero %d foi inserido com sucesso:\n", dado);
                        }
                        if(ok == -1){
                            printf("\nErro! Voce nao pode inserir na lista, por que ela nao existe");
                        }
                    } else if(menuInserirLista == 3){
                        ok = inserirFimLista(li, dado);
                        if(ok == 1){
                            printf("Numero %d foi inserido com sucesso:\n", dado);
                        }
                        if(ok == -1){
                            printf("\nErro! Voce nao pode inserir na lista, por que ela nao existe");
                        }
                    }else{
                        printf("\nFeiura, voce sabe que essa opcao nao existe\n");
                        printf("Numero nao foi inserido a lista, ela pode estar vazia\n");
                    }

                    printf("\nDeseja Inserir Outro Numero: \n");
                    printf("1 - Sim\n");
                    printf("2 - Nao \n");
                    scanf("%d", &simOunao);

                    system("clear");
                }while (simOunao != 2);

                //inserindo na lista 2
                do{
                    printf("Vamos inserir os valores na lista 2: \n");

                    menuInserirLista = menuInserir();

                    system("clear");

                    dado = numeroSerInserido();

                    system("clear");

                    if(menuInserirLista == 1){
                        ok = inserirInicioLista(li2, dado);

                        if(ok == 1){
                            printf("Numero %d foi inserido com sucesso:\n", dado);
                        }
                        if(ok == -1){
                            printf("\nErro! Voce nao pode inserir na lista, por que ela nao existe");
                        }
                    }else if(menuInserirLista == 2){
                        ok = inserirMeioLista(li2, dado);
                        if(ok == 1){
                            printf("Numero %d foi inserido com sucesso:\n", dado);
                        }
                        if(ok == -1){
                            printf("\nErro! Voce nao pode inserir na lista, por que ela nao existe");
                        }
                    }else if(menuInserirLista == 3){
                        ok = inserirFimLista(li2, dado);
                        if(ok == 1){
                            printf("Numero %d foi inserido com sucesso:\n", dado);
                        }
                        if(ok == -1){
                            printf("\nErro! Voce nao pode inserir na lista, por que ela nao existe");
                        }
                    }else{
                        printf("\nFeiura, voce sabe que essa opcao nao existe\n");
                        printf("Numero nao foi inserido a lista, ela pode estar vazia\n");
                    }

                    printf("\nDeseja Inserir Outro Numero: \n");
                    printf("1 - Sim\n");
                    printf("2 - Nao \n");
                    scanf("%d", &simOunao);

                    system("clear");
                }while (simOunao != 2);

                //valores de lista 1 e 2 antes da concatenação
                printf("\n\nLista 1\n");
                acessarTodasPosicoesLista(li);
                printf("\n\nLista 2\n");
                acessarTodasPosicoesLista(li2);


                do{


                    //escolhendo o que fazer com a lista, nao sera aceita nenhuma opção que nao exista no menu
                    do{
                        acao = acoes();
                        system("clear");
                    }while (acao != 1 && acao != 2 && acao != 3);

                    if(acao == 1){

                        list1Empty = listaVazia(li);
                        list2Empty = listaVazia(li2);

                        if(list1Empty == 1 && list2Empty == 1){
                            printf("\nNao eh possivel concatenar pois as duas listas estao vazia\n");
                        }else if (list1Empty != 0){
                            if(list1Empty == 1){
                                printf("\nNao eh possivel concatenar pois a Lista 1 esta vazia\n");
                            }
                            if(list1Empty == -1){
                                printf("\nNao eh possivel concatenar pois a Lista 1 nao existe\n");
                            }
                        }else if(list2Empty != 0 ){
                            if(list2Empty == 1){
                                printf("\nNao eh possivel concatenar pois a Lista 2 esta vazia\n");
                                printf("ou ela ja foi concatenada uma vez\n");
                            }
                            if(list2Empty == -1){
                                printf("\nNao eh possivel concatenar pois a Lista 2 nao existe\n");
                            }
                        }else{
                            li = concatenarListas(li, li2);
                            printf("\nLista Concatenada\n");
                            acessarTodasPosicoesLista(li);
                            (*li2) = NULL;
                        }
                    }
                    if (acao == 2){
                        do{
                            //escolhendo qual lista vamos agir
                            choise = escolhaLista();
                            system("clear");
                        }while (choise != 1 && choise != 2);

                        //se formos agir na lista 1
                        if(choise == 1){
                            quant = quantNumerosRemovidos();

                            ok = removerElementoFimLista(li, quant);
                            if( ok == -1){
                                printf("\nErro! Voce nao pode remover da lista, por que ela nao existe");
                            }else if(ok == 0){
                                printf("\nLista ja esta vazia");
                            }else if(ok == 1){
                                printf("Os %d ultimos numeros foram removidos com sucesso\n", quant);
                                printf("\n\nLista 1\n");
                                acessarTodasPosicoesLista(li);
                            }else{
                                printf("\n nao eh possivel remover da tabela, nao existe posições suficientes a serem removidas\n");
                            }
                        }

                        //se formos agir na lista 2
                        if(choise == 2){
                            quant = quantNumerosRemovidos();

                            ok = removerElementoFimLista(li2, quant);

                            if( ok == -1){
                                printf("\nErro! Voce nao pode remover da lista, por que ela nao existe");
                            }else if(ok == 0){
                                printf("\nLista ja esta vazia");
                            }else if(ok == 1){
                                printf("Os %d ultimos numeros foram removidos com sucesso\n", quant);
                                printf("\n\nLista 1\n");
                                acessarTodasPosicoesLista(li2);
                            }else{
                                printf("\n nao eh possivel remover da tabela, nao existe posições suficientes a serem removidas\n");
                            }
                        }
                    }
                    if(acao == 3){
                        do{
                            //escolhendo qual lista vamos agir
                            choise = escolhaLista();
                            system("clear");
                        }while (choise != 1 && choise != 2);

                        if(choise == 1){

                            if(listaVazia(li) == -1){
                                printf("\nLista nao existe\n");
                            }else if(listaVazia(li) == 1){
                                printf("\nLista esta vazia\n");
                            }else{
                                posi1 = posicoesTroca();
                                posi2 = posicoesTroca();

                                if(posi2 > tamanhoLista(li)){
                                    printf("\nNao eh possivel trocar pois a posica %d nao existe na lista\n", posi2);
                                }else if(posi1 > tamanhoLista(li)){
                                    printf("\nNao eh possivel trocar pois a posica %d nao existe na lista\n", posi1);
                                }else{
                                    li = trocaLugar(li, posi1, posi2);

                                    acessarTodasPosicoesLista(li);
                                }
                            }


                        }

                        if(choise == 2){

                            if(listaVazia(li2) == -1){
                                printf("\nLista nao existe\n");
                            }else if(listaVazia(li2) == 1){
                                printf("\nLista esta vazia\n");
                            }else{
                                int tam;
                                tam = tamanhoLista(li2);

                                posi1 = posicoesTroca();
                                posi2 = posicoesTroca();

                                if (posi1 > tam){
                                    printf("\nNao eh possivel trocar pois a posica %d nao existe na lista\n", posi1);
                                }else if(posi2 > tam){
                                    printf("\nNao eh possivel trocar pois a posica %d nao existe na lista\n", posi2);
                                }else{
                                    li2 = trocaLugar(li2, posi1, posi2);
                                    acessarTodasPosicoesLista(li2);
                                }
                            }
                        }//fim choise 2

                    } //fim da ação 3

                    printf("\nDeseja fazer outras opções: \n");
                    printf("1 - Sim\n");
                    printf("2 - Nao \n");
                    scanf("%d", &simOunao2);
                }while(simOunao2 != 2);
            }else{
                printf("\nErro! Lista nao foi criada\n\n");
            }
        }//if se for mecher com lista encadeada

        //lista duplamente encadeada
        if(op == 2){
            li = criar_listaCirc();
            li2 = criar_lista();

             if(li != NULL && li2 != NULL){
                printf("\nLista Criada com Sucesso!\n\n");


                //deseja inserir outro valor na lista 1
                do{
                    printf("Inserindo os valores na lista 1: \n");

                    menuInserirLista = menuInserir(); //chama menu de inserção
                    system("clear");

                    dado = numeroSerInserido(); //chama funçao que pega o numero digitado

                    system("clear");

                    //inserir inicio da lista
                    if(menuInserirLista == 1){
                        ok = inserirInicioListaCir(li, dado);

                        if(ok == 1){
                            printf("Numero %d foi inserido com sucesso:\n", dado);
                        }
                        if(ok == -1){
                            printf("\nErro! Voce nao pode inserir na lista, por que ela nao existe");
                        }
                    }else if(menuInserirLista == 2){
                        ok = inserirMeioListaCir(li, dado);
                        if(ok == 1){
                            printf("Numero %d foi inserido com sucesso:\n", dado);
                        }
                        if(ok == -1){
                            printf("\nErro! Voce nao pode inserir na lista, por que ela nao existe");
                        }
                    } else if(menuInserirLista == 3){
                        ok = inserirFimListaCir(li, dado);
                        if(ok == 1){
                            printf("Numero %d foi inserido com sucesso:\n", dado);
                        }
                        if(ok == -1){
                            printf("\nErro! Voce nao pode inserir na lista, por que ela nao existe");
                        }
                    }else{
                        printf("\nFeiura, voce sabe que essa opcao nao existe\n");
                        printf("Numero nao foi inserido a lista, ela pode estar vazia\n");
                    }

                    printf("\nDeseja Inserir Outro Numero: \n");
                    printf("1 - Sim\n");
                    printf("2 - Nao \n");
                    scanf("%d", &simOunao);

                    system("clear");
                }while (simOunao != 2);


                //inserindo na lista 2
                do{
                    printf("Vamos inserir os valores na lista 2: \n");

                    menuInserirLista = menuInserir();

                    system("clear");

                    dado = numeroSerInserido();

                    system("clear");

                    if(menuInserirLista == 1){
                        ok = inserirInicioListaCir(li2, dado);

                        if(ok == 1){
                            printf("Numero %d foi inserido com sucesso:\n", dado);
                        }
                        if(ok == -1){
                            printf("\nErro! Voce nao pode inserir na lista, por que ela nao existe");
                        }
                    }else if(menuInserirLista == 2){
                        ok = inserirMeioListaCir(li2, dado);
                        if(ok == 1){
                            printf("Numero %d foi inserido com sucesso:\n", dado);
                        }
                        if(ok == -1){
                            printf("\nErro! Voce nao pode inserir na lista, por que ela nao existe");
                        }
                    }else if(menuInserirLista == 3){
                        ok = inserirFimListaCir(li2, dado);
                        if(ok == 1){
                            printf("Numero %d foi inserido com sucesso:\n", dado);
                        }
                        if(ok == -1){
                            printf("\nErro! Voce nao pode inserir na lista, por que ela nao existe");
                        }
                    }else{
                        printf("\nFeiura, voce sabe que essa opcao nao existe\n");
                        printf("Numero nao foi inserido a lista, ela pode estar vazia\n");
                    }

                    printf("\nDeseja Inserir Outro Numero: \n");
                    printf("1 - Sim\n");
                    printf("2 - Nao \n");
                    scanf("%d", &simOunao);

                    system("clear");
                }while (simOunao != 2);

                acessarTodasPosicoesListaCir(li);
                printf("\n");
                acessarTodasPosicoesListaCir(li2);

                do{

                    //escolhendo o que fazer com a lista, nao sera aceita nenhuma opção que nao exista no menu
                    do{
                        acao = acoes();
                        system("clear");
                    }while (acao != 1 && acao != 2 && acao != 3);

                    if(acao == 1){

                        list1Empty = listaVazia(li);
                        list2Empty = listaVazia(li2);

                        if(list1Empty == 1 && list2Empty == 1){
                            printf("\nNao eh possivel concatenar pois as duas listas estao vazia\n");
                        }else if (list1Empty != 0){
                            if(list1Empty == 1){
                                printf("\nNao eh possivel concatenar pois a Lista 1 esta vazia\n");
                            }
                            if(list1Empty == -1){
                                printf("\nNao eh possivel concatenar pois a Lista 1 nao existe\n");
                            }
                        }else if(list2Empty != 0 ){
                            if(list2Empty == 1){
                                printf("\nNao eh possivel concatenar pois a Lista 2 esta vazia\n");
                                printf("ou ela ja foi concatenada uma vez\n");
                            }
                            if(list2Empty == -1){
                                printf("\nNao eh possivel concatenar pois a Lista 2 nao existe\n");
                            }
                        }else{
                            printf("\nlele\n");
                            li = concatenarListasCir(li, li2);
                            printf("\nLista Concatenada\n");
                            acessarTodasPosicoesLista(li);
                            (*li2) = NULL;
                        }
                    }

                    printf("\nDeseja fazer outras opções: \n");
                    printf("1 - Sim\n");
                    printf("2 - Nao \n");
                    scanf("%d", &simOunao2);
                }while(simOunao2 != 2);

             }
        }//fim if 2


    }while (op != 4);


    //liberarLista(li);

    printf("\n\nFim do Programa :) \n\n");

    //system("pause");
    return 0;

}

int menu(){
    int op;

    printf("\n\nQual das lista abaixo voce vai usar \n");
    printf("/*-------------------------------------*/");
    printf("\n1 - Lista Encadeada");
    printf("\n2 - Lista Circular");
    printf("\n3 - Lista Duplamente Encadeada");
    printf("\n4 - Sair\n");
    printf("/*------------------------------------*/\n");
    printf("\nOpcao > ");
    scanf("%d", &op);

    return op;
}

int menuInserir(){

    int op;

    printf("\n\nMenu de opcoes\n");
    printf("/*-------------------------------------*/");
    printf("\n1 - Inserir Inicio da lista");
    printf("\n2 - Inserir meio da lista");
    printf("\n3 - Inserir fim da lista\n");
    printf("/*------------------------------------*/\n");
    printf("\nOpcao > ");
    scanf("%d", &op);

    return op;
}

/*
int menuRemover(){
    int op;
    printf("\n\nMenu de opcoes\n");
    printf("/*-------------------------------------*//*");
    printf("\n1 - Remover Inicio da lista");
    printf("\n2 - Remover meio da lista");
    printf("\n3 - Remover fim da lista\n");
    printf("/*------------------------------------*//*\n");
    printf("\nOpcao > ");
    scanf("%d", &op);
    return op;
}
*/

/*
int menuBusca(){
    int op;
    printf("\n\nMenu de opcoes\n");
    printf("/*-------------------------------------*/  /*");
   printf("\n1 - Busca por posicao");
    printf("\n2 - Busca por dado");
    printf("\n3 - Todos dados da lista \n");
    printf("/*------------------------------------*/ /*");
    printf("\nOpcao > ");
    scanf("%d", &op);
    return op;
}
*/

int numeroSerInserido(){
    int dado;

    printf("\nNumero a ser inserido: \n");
    printf(">");
    scanf(" %d", &dado);

    return dado;
}

int acoes(){

    int op;

    printf("\nEscolha uma das acoes a serem executadas;\n");
    printf("/*-------------------------------------*/");
    printf("\n1 - Receber 2 listas concatenadas");
    printf("\n2 - Remover n elementos de uma lista");
    printf("\n3 - Trocar 2 elementos de lugar\n");
    printf("/*-------------------------------------*/\n");
    printf(">");
    scanf("%d", &op);

    return op;
}

int escolhaLista(){
    int op;
    printf("\nEscolha de qual lista iremos usar;\n");
    printf("/*-------------------------------------*/");
    printf("\n1 - Lista 1");
    printf("\n2 - Lista 2\n");
    printf("/*-------------------------------------*/\n");
    printf(">");
    scanf("%d", &op);
    return op;
}

int quantNumerosRemovidos(){
    int quant;

    printf("\nEscolha quantos numeros da lista serao removidos;\n");
    printf(">");
    scanf("%d", &quant);

    return quant;

}

int posicoesTroca(){

    int posi;

    printf("\nEscolha uma posicao;\n");
    printf(">");
    scanf("%d", &posi);

    return posi;
}

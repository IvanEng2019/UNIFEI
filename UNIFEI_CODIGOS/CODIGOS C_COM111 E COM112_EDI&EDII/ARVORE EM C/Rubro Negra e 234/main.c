#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore234.h"
#include "arvoreRB.h"
#include "menu.h"
#include "io.h"
#include "convert.h"

int main() {
    int *v,op=1,menu=1,val,i,n;
    char arq[50];
    TreeRB *arvRB;
    Tree234 *arv234;
    
    printf("Digite o nome do arquivo: ");
    scanf("%s",arq);
    printf("Digite a quantidade de elementos no arquivo:");
    scanf("%d",&n);
    
    strcat(arq,".txt");
    
    v = getFileValores(arq,n);
       
    arv234 = createTree234();
    for(i=0;i<11;i++){
        val = v[i];
        insertNode234(arv234,val);
    }
    
    print234(arv234);
    
    while(op != 1000){
        if(menu == 1){
            menu123Tree();
            printf("Opcao: ");
            scanf("%d",&op);
            switch(op){
                case 1:
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d",&val);
                    insertNode234(arv234,val);
                    break;
                case 2:
                    printf("Digite o valor a ser removido: ");
                    scanf("%d",&val);
                    deleteNode234(arv234,val);
                    break;
                case 3:
                    print234(arv234);
                    break;
                case 4:
                    arvRB = convertToRBTree(arv234);
                    printRB(arvRB);
                    menu = 2;
                    break;
                case 5:
                    op = 1000;
                    break;
                default:
                    printf("Comando nao encontrado\n");
                    break;
            }
        
        }else{
            menuRBTree();
            printf("Opcao: ");
            scanf("%d",&op);
            switch(op){
                case 1:
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d",&val);
                    insertNodeRB(arvRB,val);
                    break;
                case 2:
                    printf("Digite o valor a ser removido: ");
                    scanf("%d",&val);
                    deleteNodeRB(arvRB,val);
                    break;
                case 3:
                    printRB(arvRB);
                    break; 
                case 4:
                    op = 1000;
                    break;
                default:
                    printf("Comando nao encontrado\n");
                    break;
            }
        }
    }
}


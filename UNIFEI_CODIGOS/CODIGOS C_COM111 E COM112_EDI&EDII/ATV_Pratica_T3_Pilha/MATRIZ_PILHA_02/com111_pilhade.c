//  com111_pilhade.c
//  Atividade Prática T3
//  COM111 - Algoritmo e Estrutura de Dados I


#include "com111_pilhade.h"

//Global para tamanho da fila
int quant;


//Inicializa pilha
void inicia(elemento *PILHA)
{
    PILHA->prox = NULL;
    quant=0;
}

//Funcao menu
int menu(void)
{
    int opt;
    printf("---------------------\n");
    printf(".::Escolha a opcao::.\n");
    printf("1. Empilhar matriz\n");
    printf("2. Desempilhar\n");
    printf("3. Sair\n");
    printf("4. Exibir Pilha\n");//Opcao extra
    printf("5. Esvaziar Pilha\n");//Opcao extra
    printf("Opcao: "); scanf("%d", &opt);
    printf("---------------------\n");
    return opt;
}

//Funcao para tratar opcoes
void opcao(elemento *PILHA, int op)
{
    elemento *tmp;
    switch(op){
            
        case 1:
            empilhar(PILHA);
            break;
            
        case 2:
            tmp= desempilhar(PILHA);
            break;
            
        case 3:
            libera(PILHA);
            exit (0);
            break;
            
        case 4:
            exibe(PILHA);
            break;
            
        case 5:
            libera(PILHA);
            inicia(PILHA);
            break;
            
        default:
            printf(".::Opção invalida::.\n\n");
    }
}

//Confere se esta vazia
int vazia(elemento *PILHA){
    
    //Se o primeiro elemento ja apontar para null ta vazia
    if(PILHA->prox == NULL)
        return 1;
    else
        return 0;
}

//Aloca novo no
elemento *aloca(){
    int w = 0, z = 0;
    
    elemento *novo=(elemento *) malloc(sizeof(elemento));
    if(!novo){
        printf("Memoria Insuficiente!\n");
        exit(1);
    }else{
        
        printf(".::Matriz %d::.\n",quant+1);
        for (w = 0; w < 3; w++){
            for (z = 0; z < 3; z++){
                printf("• Elemento [%d][%d] = ",w ,z);
                scanf("%lf", &novo->mat[w][z]);
            }
        }
        
        return novo;
    }
}


//Printa pilha
void exibe(elemento *PILHA){
    int w = 0, qtd = 1;
    if(vazia(PILHA)){
        printf("Pilha sem matrizes!\n\n");
        return ;
    }
    
    elemento *tmp;
    tmp = PILHA->prox;
    while( tmp != NULL){
        
        printf("\n\t\t\t.::Matriz %d::.\n",qtd);
        for (w = 0; w < 3; w++)
            printf("\t\t[%.3lf] [%.3lf] [%.3lf]\n", tmp->mat[w][0], tmp->mat[w][1], tmp->mat[w][2]);
        
        tmp = tmp->prox;
        qtd++;
    }
    
    printf("\n\n");
}


//Libera no
void libera(elemento *PILHA){
    
    if(!vazia(PILHA)){
        elemento *proxNode,
        *atual;
        
        atual = PILHA->prox;
        //Laco para dar free em todos os elementos
        while(atual != NULL){
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
    }
}

//Insere elemento
int empilhar(elemento *PILHA){
    
    //Aqui é recebido o ponteiro da nova matriz lida, ou seja, novo no alocado
    elemento *novo=aloca();
    
    //Aponta ele para nulo
    novo->prox = NULL;
    
    //Se a pilha estiver vazia
    if(vazia(PILHA))
        PILHA->prox=novo;
    else{
        elemento *tmp = PILHA->prox;
        
        while(tmp->prox != NULL)
            tmp = tmp->prox;
        
        tmp->prox = novo;
    }
    quant++;
    return 1;
}

//Retira elemento
elemento *desempilhar(elemento *PILHA){
    
    //Aqui que tem que multiplicar as matrizes
    double aux1[3][3], aux2[3][3];
    //Auxiliares para lacos
    int w = 0, x = 0;
    
    //Confere se existe algum elemento
    if(PILHA->prox == NULL){
        printf("Pilha de Matrizes Vazia!\n\n");
        return NULL;
    }else{
        
        if (quant == 1) {//Se tiver somente uma matriz
            
            elemento *tmp;
            tmp = PILHA->prox;
            
            
            printf("------------------------------RESULTADO--------------------------------------------\n");
            
            //Mostra Resultado
            for (w = 0; w < 3; w++)
                printf("\t[%.3lf] [%.3lf] [%.3lf]\n", tmp->mat[w][0], tmp->mat[w][1], tmp->mat[w][2]);
            printf("-----------------------------------------------------------------------------------\n");
            
            return NULL;
            
        }else{//Se tiver mais de uma matriz
            
            elemento *ultimo = PILHA->prox,
            *penultimo = PILHA;
            
            //Encontra ultimo elemento
            while(ultimo->prox != NULL){
                penultimo = ultimo;
                ultimo = ultimo->prox;
            }
            
            //O aux1 recebe o penultimo
            for (w = 0; w < 3; w++)
                for (x = 0; x < 3; x++)
                    aux1[w][x] = penultimo->mat[w][x];
            
            //O aux2 recebe o ultimo
            for (w = 0; w < 3; w++)
                for (x = 0; x < 3; x++)
                    aux2[w][x] = ultimo->mat[w][x];
            
            //Libera memoria do ultimo
            free(ultimo);
            
            //Penultimo recebe null
            penultimo->prox = NULL;
            
            //Ja tira um no tamanho
            quant--;
            
            //Multiplicacao das matrizes
            penultimo->mat[0][0] = ((aux1[0][0]*aux2[0][0]) + (aux1[0][1]*aux2[1][0]) + (aux1[0][2]*aux2[2][0]));//ok
            penultimo->mat[0][1] = ((aux1[0][0]*aux2[0][1]) + (aux1[0][1]*aux2[1][1]) + (aux1[0][2]*aux2[2][1]));//ok
            penultimo->mat[0][2] = ((aux1[0][0]*aux2[0][2]) + (aux1[0][1]*aux2[1][2]) + (aux1[0][2]*aux2[2][2]));//ok
            penultimo->mat[1][0] = ((aux1[1][0]*aux2[0][0]) + (aux1[1][1]*aux2[1][0]) + (aux1[1][2]*aux2[2][0]));//ok
            penultimo->mat[1][1] = ((aux1[1][0]*aux2[0][1]) + (aux1[1][1]*aux2[1][1]) + (aux1[1][2]*aux2[2][1]));//ok
            penultimo->mat[1][2] = ((aux1[1][0]*aux2[0][2]) + (aux1[1][1]*aux2[1][2]) + (aux1[1][2]*aux2[2][2]));//ok
            penultimo->mat[2][0] = ((aux1[2][0]*aux2[0][0]) + (aux1[2][1]*aux2[1][0]) + (aux1[2][2]*aux2[2][0]));//ok
            penultimo->mat[2][1] = ((aux1[2][0]*aux2[0][1]) + (aux1[2][1]*aux2[1][1]) + (aux1[2][2]*aux2[2][1]));//ok
            penultimo->mat[2][2] = ((aux1[2][0]*aux2[0][2]) + (aux1[2][1]*aux2[1][2]) + (aux1[2][2]*aux2[2][2]));//ok
            
            //Printa Multiplicacao Realizada
            printf("-----------------------------------------------------------------------------------\n");
            for (w = 0; w < 3; w++)
                printf("\t[%.3lf] [%.3lf] [%.3lf] * [%.3lf] [%.3lf] [%.3lf] = [%.3lf] [%.3lf] [%.3lf]\n", aux1[w][0], aux1[w][1], aux1[w][2], aux2[w][0], aux2[w][1], aux2[w][2], penultimo->mat[w][0], penultimo->mat[w][1], penultimo->mat[w][2] );
            printf("-----------------------------------------------------------------------------------\n");
            
            //Aqui teria que chamar de novo a mesma funcao
            desempilhar(PILHA);
            return NULL;
        }
        
        return NULL;
    }
}

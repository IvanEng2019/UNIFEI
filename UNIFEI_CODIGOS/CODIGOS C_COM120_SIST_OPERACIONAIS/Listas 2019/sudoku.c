//  sudoku

#include <stdio.h>
#include <pthread.h>

#define QTD_Thread 4//Quantidade de threads a ser usada

/*
um para linhas
Um para colunas
Um para blocos
Um para verificar se os valores estao no intervalo certo, ou seja, entre 1 e 9
*/

int checa_linhas = 0, checa_colunas = 0, checa_quad = 0, checa_intervalos = 0;

//INSERIR MATRIZ AQUI
int matriz[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}};

//funcao que verifica se existem 2 valores iguais na mesma linha
int checkHorizontal(int matriz[9][9]){
    int i, j, k, verificador = 1;

    for(i = 0; i < 9 && verificador; i++)
        for(j = 0; j < 9 && verificador; j++)
            for(k = 0; k < 9 && verificador; k++)
                if((j != k) && (matriz[i][j] == matriz[i][k]))
                    verificador = 0;
   //retorna 1 se tudo ok
    return verificador;
}

//funcao que verifica se existem 2 valores iguais na mesma coluna
int checkVertical(int matriz[9][9]){
    int i, j, k, verificador = 1;

    for(j = 0; j < 9 && verificador; j++)
        for(i = 0; i < 9 && verificador; i++)
            for(k = 0; k < 9 && verificador; k++)
                if((i != k) && (matriz[i][j] == matriz[k][j]))
                    verificador = 0;
     //retorna 1 se tudo ok
    return verificador;
}

//Funcao que verifica se existem numeros repetidos nos blocos 3x3 da matriz
int checarMenor(int mini[3][3]){
    int i, j, num, existe = 0;

    for(num = 1; num <= 9; num++){
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                if(mini[i][j] == num) existe++;
        if(existe > 1) return 0;
        existe = 0;
    }
    return 1;
}

//Funcao que separa os blocos que precisam ser lidos
/*
     * As variáveis i e j servem para iterar sobre a matriz 9x9 e identificar
     * os setores do Sudoku. Elas crescem de 3 em 3 para ter início exatamente
     * sobre o primeiro quadrado de cada setor, isso serve de referência para
     * o começo de onde o programa vai começar a pegar os valores para por na
     * matriz mini.
     * As variáveis k e l servem para iterar sobre os elementos da matriz pequena
     * 3x3; e da matriz 9x9 tomando como início os pontos i e j, para todos os
     * elementos da matriz grande serem alcançados.
     * A matriz mini 3x3, na sua vez, armazenará os valores de cada um desses
     * setores para serem depois enviados para a função checarMenor()
     */
int checarMenores(int matriz[9][9]){
    int i, j, k, l, mini[3][3];
    /*
     * Como já dito, os loops de i e j vão iterar sobre o começo de cada setor e
     * os loops de k e l sobre esses mesmos setores. Quando uma matriz 3x3 for completa,
     * ela será enviada para a função checarMenor() para verificar se é ou não válida.
     * Caso ela não seja válida, a função checarMenor() retornará falso, o que causará
     * a função atual retornar falso também, pois o Sudoku é inválido.
     * Caso todos os loops sejam completados sem problema, quer dizer que o programa
     * não achou nenhuma inconsistência, e então a função retornará verdadeiro.
     */
    for(i = 0; i < 9; i += 3)
        for(j = 0; j < 9; j += 3){
            for(k = 0; k < 3; k++)
                for(l = 0; l < 3; l++)
                    mini[k][l] = matriz[k+i][l+j];
            if(!checarMenor(mini))
                return 0;
        }
    return 1;
}
//Funcao que verifica se os numeros estao no intervalos entre 1 e 9
int verificaIntervalos(int matriz[9][9]){
    int i = 0, w = 0;
    for (i = 0; i < 9; i++) {
        for (w = 0;  w < 9; w ++) {

            if (matriz[i][w] > 9 || matriz[i][w] < 1) {
                return 0;
            }
        }
    }

    //se os numeros estao entre 1 e 9, ok, entao retorna 1
    return 1;
}

//funcao que vai determinar qual parte cada uma das 3 threads vai rodar
void *funcao(void *thread_id){
    int *ident;
    ident = thread_id;

    switch (*ident){
        case 1://linhas
            checa_linhas = checkHorizontal(matriz);
            break;

        case 2://colunas
            checa_colunas = checkVertical(matriz);
            break;

        case 3://blocos
            checa_quad = checarMenores(matriz);
            break;

        case 4://blocos
            checa_intervalos = verificaIntervalos(matriz);
            break;
    }
    return NULL;//Para evitar bug no XCODE
}

int main(){
  //verifica tambem se os valores estao entre -1 e 10

     pthread_t threads[QTD_Thread];//criamos um vetor de thread usando o TAD phtread_t
     int i, qtd[QTD_Thread];

     //chamei 27 vezes
     for (i = 0; i < QTD_Thread; i++) {

         qtd[i] = i + 1;// para variar de 1 ate 3
         pthread_create(&threads[i], NULL, funcao, (void *)&qtd[i]);//funcao para criacao das threads
         //Endereco de memoria da thread/ parametro nulo/ funcao que ela vai executar/ e o argumento da funcao

     }

     //laco para esperar as threads retornarem para depois verificar se os blocos, linhas e colunas estão ok
     for (i = 0; i < QTD_Thread; i++) {
         pthread_join(threads[i], NULL);
     }


    if(checa_linhas && checa_colunas && checa_quad && checa_intervalos){ //se todos os 4 indicadores forem 1, então é matriz
        printf("Os valores são solucao para um sudoku!\n\n");
    }else{//caso os valores nao sejam solucao
        printf("Os valores NÃO são solução do sudoku!\n\n");
    }

    return 0;
}

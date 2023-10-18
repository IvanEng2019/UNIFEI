/**********************************************************************************************************
2. Escreva uma função que receba como parâmetro 2 números inteiros e positivos e um caractere que deve
indicar a operação que deve ser realizada entre os dois números seguindo a ordem com que foram digitados.
Retorne o resultado da operação. Caso o segundo número digitado for igual a 0 e a operação escolhida for a
divisão, a função não deve ser chamada e deve ser exibida uma mensagem de erro ao usuário.
Utilize a função no programa principal.
***********************************************************************************************************/
#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // funçao que imprime cabeçalho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informação\nDisciplina:Fundamentos de Programação\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajubá.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nFaz multiplicação, divisao, soma ou subtração de inteiros positivos\n");
}

int conta (int a,int b,char op){//função que retorna resultado de operação entre 2 inteiros positivos dados
    if(op=='+')
       return a+b;
    else
        if(op=='-')
            return a-b;
        else
            if(op=='*')
              return a*b;
            else
              return a/b;
}

int main (){ //função principal
    cabecalho();
    int a,b,s; // variaveis locais de main()
    char f;
    printf("\nEntre com dois numeros:");//solicitação de valor ao usuario
    scanf("%d %d",&a,&b);//entrada de valores
    printf("\nPara multiplicar tecle *\nPara dividir tecle /\nPara subtrair tecle -\nPara somar tecle +\n");//solicitação de qual operação ao usuario
    scanf(" %c",&f);
    if (b==0 && f=='/')
        printf("\nNão existe divisão por zero\n");
    else
    {
        s=conta(a,b,f);
        printf("O resultado de %d %c %d = %d\n",a,f,b,s);//apresentado resultado ao usuario
    }

return 0;
}

/**********************************************************************************************************
2. Escreva uma fun��o que receba como par�metro 2 n�meros inteiros e positivos e um caractere que deve
indicar a opera��o que deve ser realizada entre os dois n�meros seguindo a ordem com que foram digitados.
Retorne o resultado da opera��o. Caso o segundo n�mero digitado for igual a 0 e a opera��o escolhida for a
divis�o, a fun��o n�o deve ser chamada e deve ser exibida uma mensagem de erro ao usu�rio.
Utilize a fun��o no programa principal.
***********************************************************************************************************/
#include <stdio.h> //incluindo bibliteca

void cabecalho(){ // fun�ao que imprime cabe�alho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informa��o\nDisciplina:Fundamentos de Programa��o\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajub�.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nFaz multiplica��o, divisao, soma ou subtra��o de inteiros positivos\n");
}

int conta (int a,int b,char op){//fun��o que retorna resultado de opera��o entre 2 inteiros positivos dados
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

int main (){ //fun��o principal
    cabecalho();
    int a,b,s; // variaveis locais de main()
    char f;
    printf("\nEntre com dois numeros:");//solicita��o de valor ao usuario
    scanf("%d %d",&a,&b);//entrada de valores
    printf("\nPara multiplicar tecle *\nPara dividir tecle /\nPara subtrair tecle -\nPara somar tecle +\n");//solicita��o de qual opera��o ao usuario
    scanf(" %c",&f);
    if (b==0 && f=='/')
        printf("\nN�o existe divis�o por zero\n");
    else
    {
        s=conta(a,b,f);
        printf("O resultado de %d %c %d = %d\n",a,f,b,s);//apresentado resultado ao usuario
    }

return 0;
}

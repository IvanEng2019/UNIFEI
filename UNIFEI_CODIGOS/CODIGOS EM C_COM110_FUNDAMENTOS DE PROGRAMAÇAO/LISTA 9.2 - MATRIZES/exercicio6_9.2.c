/***************************************************************************************************
6. Fa�a uma fun��o para criptografar uma frase digitada pelo usu�rio. A criptografia dever�
 substituir todas as vogais por *. Utilize a fun��o no programa principal. A frase poder� ter,
 no m�ximo, 50 caracteres.
*****************************************************************************************************/

#include<stdio.h>
#define MAX 10

void caracter(char a[])
{
    for(int i=0;i<MAX;i++)
    {
        if(a[i]=='a' || a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
            a[i]='*';

    }
    return;
}
 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 10/06/2018\n\n");//i+j=n-1;
}
int main(){
    cabecalho(); //imprime os dados do aluno
    //freopen("l.in","r",stdin); // copia os dados do arquivo txt
    char a[MAX];
    for(int i=0;i<MAX;i++)
    {
       scanf(" %c",&a[i]);
    }
    caracter(a);
    for(int i=0;i<MAX;i++)
    {
        printf("C[%d]=%c\n",i,a[i]);
    }
    return 0;
}

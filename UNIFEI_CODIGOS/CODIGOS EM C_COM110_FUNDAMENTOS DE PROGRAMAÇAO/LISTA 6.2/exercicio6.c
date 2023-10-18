/*
======================================================================================
Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
Professora  : MELISE MARIA VEIGA DE PAULA
Autores :     Ivan Leoni Vilas Boas - RU: 2018009073

Data atual  : 12/04/2018
======================================================================================
Exercício 6:
Criar um programa que verifique se uma data está correta ou não. O programa deve
ler 100 datas e contar a quantidade de datas corretas e imprimir esse valor no final.
Considere as seguintes regras:
i. Mês - entre 1 e 12
ii. Dia:
        1. 1 a 28 - mês 2 e ano não bissexto
        2. 1 a 29 - mês 2 e ano bissexto
        3. 1 a 30 - meses 4, 6, 9, 11
        4. 1 a 31 - meses restantes

======================================================================================
*/

#include <stdio.h> // inclusão de biblioteca com funçoes de entrada e saida

//inicio do programa principal
int main()
{
    int cont=0;
    int i,d,m,a;

    for(i=1;i<=10;i++)
    {
        printf("Entre respectivamente com dia/mes/ano:\n");
        scanf("%d %d %d", &d,&m,&a);
        if(a>0 && m== 2 && d>0 && d<=29 && ((a%4 == 0 || a%400==0) && (a%100!=0))){
           cont= cont+1;
           printf("certo 1º - ano é bisexto\n");}
        else
            if(a>0 && m==2 && d>0 && d<=28 ){
              cont= cont+1;
              printf("certo 2º -ano não bisexto\n");}
            else
               if (a>0 && (m==4 || m==6 || m==9 || m==11) && d>0 && d<=30){
                   cont= cont+1;
                   printf("certo 3º\n");}
               else
              //if (a>0 && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)&& d>0 && d<=31)
                  if(a>0 && (m!=2 && m!=4 && m!=6 && m!=9 && m!=11)&& (m>0 && m<13) && d>0 && d<=31){
                     cont= cont+1;
                     printf("certo 4º\n");}
    }
    printf ("A quantidade de datas certas é %d.\n", cont);
return 0;
}

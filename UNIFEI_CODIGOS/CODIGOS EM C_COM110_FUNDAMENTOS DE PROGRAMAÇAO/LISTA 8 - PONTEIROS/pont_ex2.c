
#include <stdio.h> //incluindo bibliteca
void cabecalho();

int main (){ //função principal
    cabecalho();

    int i = 5, j = 3, *p, *q;
    p = &i;
    q = &j;
    printf("%d %d \n", *p, (*p)++ + *q);

   /* i=6,j=3;
    printf("\n%d %d %d %d", q,p,i,j);
    printf("\n%d %d %d %d", *q,*p,i,j);
    i=(*q)++ + *p;
    printf("\n%d %d %d %d", *q,*p,i,j);
    printf("\n%d %d %d %d",q,p,i,j);
    i=*&*&j;
    printf("\n%d %d %d %d",i,j,&i,&j);
    *p =&j;
    printf("\n%d %d %d %d.",p,j,i,*p);
    p=&*&i;
    printf("\n%d %d %d %d.",p,j,i,*p);
    *p =i;
    printf("\n%d %d.",((*p)++),(*p)++);
    printf("\n%d %d.\n",*p++,*p++);

    printf("%d.\n",(p == &i));
    printf("%d.\n\n",(*p - *q) );
    printf("(*p)->Conteudo apontado por p = %d.\n",(*p));
    printf("(**&p)->Conteudo apontado por p %d.\n",(**&p));
    printf("(*&*p)->Conteudo apontado por p %d.\n",(*&*p));
    printf("(&i)->Endereço de i %d.\n",(&i));
    printf("(p)->Endereço de que p aponta = %d.\n",(p));
    printf("(*&p)->Endereço de que p aponta =%d.\n",(*&p));
    printf("(&p)->Endereço de p %d.\n",(&p));*/

    printf("\n");for(int i=0;i<100;i++) printf("=");
return 0;
}
void cabecalho(){ // funçao que imprime cabeçalho
   for(int i=0;i<100;i++) printf("*");
   printf("\nCurso Sistemas de Informação\nDisciplina:Fundamentos de Programação\nProfessora:Melise Maria Veiga De Paula\nUniversidade Federal de Itajubá.\n");
   for(int i=0;i<100;i++) printf("*");
   printf("\nDesenvolvedor:Ivan Leoni Vilas Boas - Matricula:2018009073\nData atual:05/05/2018\n");
   for(int i=0;i<100;i++) printf("=");
   printf("\nPrograma estudo de ponteiro.\n");
}

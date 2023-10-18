/*********************************************************************************************************
Fa�a um programa que preencha um vetor com dez n�meros inteiros e um segundo vetor com cinco n�meros
inteiros, calcule e mostre dois vetores resultantes. O primeiro vetor resultante ser� composto pela
soma de cada n�mero par do primeiro vetor somado a todos os n�meros do segundo vetor. O segundo
vetor resultante ser� composto pela quantidade de divisores que cada n�mero �mpar do primeiro vetor
tem no segundo vetor.
**********************************************************************************************************/
//inclus�o da bibliotecas
 #include<stdio.h>

 //Fun��o que mostra os dados do desenvolvedor
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMA��O\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("Aluno: Ivan Leoni Vilas Boas - RU: 2018009073\n");
        printf("Data atual: 24/05/2018\n\n");
        printf("Programa Vetores:\n\n");
}
int main(){
     cabecalho(); //imprime os dados do desenvolvedor
     //declara��o de variaveis locais
     int i,j,s=0,cont; // variaveis auxiliares de controle e manipula��o
     int vf1[10],vf2[10]; // variavel de saida
     int v1[10],v2[5]; // variavel de entrada

     for(i=0;i<10;i++)//executa 10 vezes o la�o que ira preencher a variavel v1[i]
     {
         printf("Entre com o valor do primeiro Vetor[%d]:",i);
         scanf("%d",&v1[i]);
     }
     printf("\n"); // pula cursor em 1 linha
     for(i=0;i<5;i++) //executa 5 vezes o la�o que ira preencher a variavel v2[i]
     {
         printf("Entre com o valor do segundo Vetor[%d]:",i);
         scanf("%d",&v2[i]);
         s=s+v2[i];// ja vaz a soma de todos os elementos existentes no vetor v2[i]
     }
       printf("\nResultado do primeiro vetor resultante:\n");
      for(i=0;i<10;i++)
      {
        if(v1[i]%2==0)//se o elemento do vetor for divisivel por 2, ter� resto igaul a zero, sendo ele � par
        {
           vf1[i]=v1[i]+s; // se for par fazer a soma de cada elemento par de v1[i] com o total do v2[]
           printf("%d|",vf1[i]);//imprime todo o vetor final vf1[]
        }
      }
      printf("\n\nResultado do segundo vetor resultante:\n");
      for(i=0;i<10;i++)
      {
         if(v1[i]%2!=0)//se o vetor v1[i] nao for difisivel por 2, tera resto, sendo assim impar
         {
            cont=0; //atribuido 0 a variavel cont
            for(j=0;j<5;j++)
            {
               if(v1[i]%v2[j]==0)//cado v1[i] seja divisivel por v2[j] o resto sera zero
                 cont++; // cont sera acrecido de um unidade cada vez que o elemento de v1[i] for divisivel por v2[j]
            }
            vf2[i]=cont;//o vetor final vf2[i] recebera na posi��o de i o valor referente a a varivel cont
            printf("%d|",vf2[i]);//sera impresso o valor do vetor final vf2[i]
         }
      }
       printf("\n"); // pula cursor em 1 linha
return 0;
}

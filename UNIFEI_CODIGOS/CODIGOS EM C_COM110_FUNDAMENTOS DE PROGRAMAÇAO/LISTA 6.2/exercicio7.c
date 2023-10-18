/*
==========================================================================================
Disciplina  : FUNDAMENTOS DE PROGRAMAÇÃO
Professora  : MELISE MARIA VEIGA DE PAULA
Autores :  Ivan Leoni Vilas Boas - RU: 2018009073
           Fabricio Guedes da Silva - RU: 2018014476
Data atual  :09/04/2018
===========================================================================================
Exercício 7:
O Depto de Meio Ambiente de um país mantém 2 listas de indústrias conhecidas por
serem altamente poluentes. Os resultados de várias medidas são combinados para
formar o que é chamado de índice de poluição. Isto é controlado regularmente.
Normalmente os valores ficam entre 0.05 e 0.25. Porém, se o valor atingir 0.30,
as indústrias da lista A serão chamadas a suspender as operações até que os valores
retornem ao intervalo normal. Se o índice atingir 0.40, as indústrias da lista B
serão notificadas. Se o índice exceder 0.50, indústrias das 2 listas serão avisadas.
Preparar um programa em C para ler o índice de poluição de 100 cidades e indicar
quais listas deverão ser avisadas.
============================================================================================
*/

#include <stdio.h> // incluindo biblioteca de funções de entra e saida

int main()
{
    //declaração de cariaveis
    int i; //Auxiliará o laço de repetição
    float indice; //conterá o valor de indice de poluição dado pelo usuario

    //realiza o for para  coletar o indice de poluição de 100 cidades e verifica se haverá suspenssão
    for(i=1;i<=100;i++)
    {
        //solicitação e armazenamento de entrada de dados
        printf("Entre com o valor do indice:\n");
        scanf("%f",&indice);

        if (indice >= 0.30 && indice < 0.40 )// se o indice for maior ou igual a 0,3 e menor que 0,4 apenas lista A é avisada
            printf ("Suspender as operações somente da lista A até que os valores retornem ao intervalo normal.\n");
        else
            if (indice >= 0.40 && indice <= 0.50) // se o indice for maior ou igual a 0,4 e menor é igual a 0,5 apenas lista B é avisada
                printf ("Suspender as operações somente da lista B até que os valores retornem ao intervalo normal.\n");
            else // se o indice for maior que 0,5 lista A e B serão ambas avisadas
                if (indice > 0.50) //Faz-se necessario verificar se indice >0,5 pois o indice pode estar dentro dos padrões (ser menor que 0,3) entao nenhuma lista seria avisada/suspendida
                    printf ("Suspender as operações da lista A e B até que os valores retornem ao intervalo normal.\n");
    }
return 0;
}

 //inclusão da bibliotecas
 #include<stdio.h>
 #include<stdlib.h>

 //Função que mostra os dados dos desenvolvedores
 void cabecalho(){
        printf("\nDisciplina: FUNDAMENTOS DE PROGRAMAÇÃO\nProfessora: MELISE MARIA VEIGA DE PAULA\n");
        printf("\nAutores:\nIvan Leoni Vilas Boas - RU: 2018009073\nJoão Marco Godoy da Silva - RU: 2018004317\n");
        printf("\nData atual: 03/05/2018\n\n");
        printf("\nExercício 5:Faça uma função que receba as 3 notas de um aluno por parâmetro e uma letra. Se a letra for A, calcula a média aritmética das notas do aluno, se for P, a sua média ponderada (pesos: 5, 3 e 2). Utilize esta função no programa principal para retornar a media ponderada de um aluno.\n\n");
 }

 //criação da função que calcula a media ponderada e aritimetica , esta deve retornar a media ponderada
 float medias (float n1,float n2,float n3,char op){
    if(op =='A') // caso tenha escohido letra A calcula e mostra a media aritmetica
    {
       printf ("O valor da media aritimetica é %.2f.\n", ((n1+n2+n3)/3));//apresenta media aritimetica
       return -1; //retorna -1 a main
    }
    else //caso tenha escolhido letra P calcula e retorna o valor da media ponderada
        return (n1*5+n2*3+n3*2)/10;
 }

 //função principal
 int main(){
     //declaração de variaveis
     float v1,v2,v3,med;
     char letra;

     cabecalho();//chama a função cabeçalho

     //solicitação de dados ao usuario7
     printf("Qual a media deseja calcular:\nAritmetica - Tecle A\nPonderada - Tecle P \n");
     scanf("%c",&letra);
     //fflush(stdin); //limpa o buffer do teclado
     while(letra!='A' && letra!='P') //sera pedido ao usuario ate que ele tecle A ou P
     {
          printf ("Letra incorreta\n");
          printf("Qual a media deseja calcular:\nAritmetica - Tecle A\nPonderada - Tecle P \n");
          scanf("%c",&letra);
         // fflush(stdin); ////limpa o buffer do teclado
     }

     printf("Entre com os valores das tres notas:");
     scanf("%f %f %f", &v1, &v2, &v3);

     //chama a função medias passando por parametro as variaveis solicitadas
     med=medias(v1,v2,v3,letra);// e já atribui-se o valor retornado a variavel med

     if(med!=-1) //caso tenha solicitado apenas a media aritmetica A o retorno sera -1 entao não apresenta a media ponderada
        printf("A media ponderada é %.2f:\n", med);//Apresenta a media ponderada caso o retorno seja diferente -1

     return 0;
 }

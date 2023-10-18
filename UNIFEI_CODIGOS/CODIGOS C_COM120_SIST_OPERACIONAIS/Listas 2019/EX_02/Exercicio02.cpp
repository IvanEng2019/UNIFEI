
//COM220 - Sistemas Operacionais
//Exercício Prático 02- 02/09/2019
//PROBLEMA 1
//Nome: Giovany da Silva Santos 2018007758
//Nome: Ivan Leoni Vilas Boas  Matrícula: 2018009073


//inclusão de biblioteca
#include<bits/stdc++.h>
using namespace std;

//definição de variaveis global
#define NUM_THREADS 3
double media=0.0,menor,maior=0.0;
int n;//qtd de valores randomicos

void * funcao_media(void *args)//funcao para calculo da media
{
    double *vet=(double*)args;

    int i;

    for(i=0;i<n;i++)media=media+vet[i];

    media=media/n;

}

void * funcao_menor(void *args)//funcao para calculo do menor
{
    double *vet=(double*)args;

    int i;

    menor=vet[0];

    for(i=1;i<n;i++)if(vet[i]<menor)menor=vet[i];

}

void * funcao_maior(void *args)//funcao para calculo do maior
{
    double *vet=(double*)args;

    int i;

    maior=vet[0];

    for(i=1;i<n;i++)if(vet[i]>maior)maior=vet[i];

}

int main()
{
    int thread_id[NUM_THREADS],i;//vetor de índices de threads
   //atribuindo os índices
    thread_id[0]=1;

    thread_id[1]=2;

    thread_id[2]=3;

    cout<<"Digite a quantidade de valores..."<<endl<<endl;
    cin>>n;

    double vet[n];//vetor para guargar os números randomicos

    cout<<"Gerando os valores randomicos..."<<endl<<endl;

    for(i=0;i<n;i++)//gerando num aleatorios
    {
         vet[i]=rand()%n;
         cout<<vet[i]<<" ";
    }
    cout<<endl<<endl;

    pthread_t threads[NUM_THREADS];

    //Criando as threads
    pthread_create(&threads[0],NULL,funcao_media,(void*)vet);

    pthread_create(&threads[1],NULL,funcao_maior,(void*)vet);

    pthread_create(&threads[2],NULL,funcao_menor,(void*)vet);

    //thread pai esperando o fim dos filhos para imprimir os valores
    for(i = 0; i<NUM_THREADS;i++)
    {
            pthread_join(threads[i], NULL);
    }

   //imprimindo os valores
   cout<<"Media :"<<media<<"\nMaior :"<<maior<<"\nMenor :"<<menor<<endl;;

  return 0;
}

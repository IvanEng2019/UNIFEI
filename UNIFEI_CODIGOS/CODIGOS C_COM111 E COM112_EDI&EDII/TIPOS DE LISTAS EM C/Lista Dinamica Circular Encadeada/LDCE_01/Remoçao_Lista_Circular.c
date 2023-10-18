//Na lista circular a remoção no final não muda nada com relação a lista simples
int n_ultimos_Dulpla(Lista *list, int n){
   
 if( list==NULL || (*list)== NULL ) return 0;

     int tam=0;
     Eleme *DEL, *no=(*list);
   
     if(n>tam) return 0;
     else{
           int cont=0;
           no=(*list);

           while(no->prox!=NULL){
                 no=no->prox; //ultima
                 tam++;
           }
      // se so tem um elemento e se for pedido pra retirar este unico
           if(no->prox==NULL){
               (*list)=no->prox;
               free(no);
               return 1;
           }
           else{// se tem mais de um elemento a ser retirado
              while (tam>n){// começa em (tam-n) e vai ate  o FIM (NULL)
                DEL= no;
                no=no->ant;
                no->prox=NULL;
                free(DEL);
                tam--;
               }
           return 1;
           }
     }

}

//Na lista circular a remoção no final não muda nada com relação a lista simples
int n_ultimos_Dulpla(Lista *list, int n){
   
 if( list==NULL || (*list)== NULL ) return 0;

     int tam=0;
     Eleme *DEL, *no=(*list);
     
    while(no->prox!=NULL){
            no=no->prox;
            tam++;
     }
     
     if(n>tam) return 0;
     else{
           int cont=0;
           no=(*list);
      // acha a penultima e ultima posiçao de (tam-n)
           while(cont<tam-n && no->prox!=NULL){
              no=no->prox; //ultima
              cont++;
           }
      // se so tem um elemento e se for pedido pra retirar este unico
           if(no==(*list)){// ou no->ant == NULL
               (*list)=no->prox; //NULL
               free(no);
               return 1;
           }
           else{// se tem mais de um elemento a ser retirado
              while (no->prox!=NULL){// começa em (tam-n) e vai ate  o FIM (NULL)
                DEL= no;
                no=no->prox;
                free(DEL);
               }
           (no->ant)->prox=no-> prox; //faz o penúltimo ser o ultimo apontando ele para o que o anterior apontava
           return 1;
           }
     }
}


int concatena_rec_simples( Lista *L1,Lista *L2){

    Elemento *no1=(*L1);

    if( no1==NULL && no2==NULL)
        return 0;

    if(no1==NULL)
        no1=(*L2);
        return 1;

    if(no2==NULL)
        return 1;

    if(no1->prox==NULL){
        no1->prox=(*L2);
        return 1;
    }
    return (concatena_rec_simples(&(no1->prox),(no2));
}

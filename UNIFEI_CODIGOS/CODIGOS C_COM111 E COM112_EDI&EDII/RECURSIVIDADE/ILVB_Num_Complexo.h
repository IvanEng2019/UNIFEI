/********************************************************************/
/** criação do tipo estrura im com duas variaveis float             */
/********************************************************************/
typedef struct Nunemrocomplexo{
     float n1,n2;
}im;

/*********************************************************************/
/** Função para alocar memória: Sem paramentros de entrada e retorma */
/**      um ponteiro do tipo im caso seja alocada a memoria          */
/*********************************************************************/
im *alocarIm();

/*********************************************************************/
/** Função para criar numero complexo: recebe trez paremetros,sendo: */
/**       ac e bd do tipo float e contera os dados das variaves a    */
/**             serem atribuidos e im recebe o endereço que          */
/**                    conterá resultado da atribuição               */
/**                        Não tem retorno                           */
/*********************************************************************/
void criaComplexo(float ac, float bd, im *numi);

/********************************************************************/
/** Função para imprimir numero complexo: recebe como parametro     */
/**     o endereço de um tipo im e imprime na tela os valores       */
/**                      Não retorna valores                        */
/********************************************************************/
void imprime (im *numi);

/*********************************************************************/
/** Função para somar numero complexo:recebe como parametro 3        */
/** endereços do tipo im  onde o primeiro corresponde respectivamente*/
/**   ao primeiro e segundo numero complexo,e o terceiro recebe o    */
/**           endereço que guardará o resultado da soma.             */
/**                      Não retorna valores                         */
/********************************************************************/
void somaComplexo(im *num1,im *num2,im *soma);

/*********************************************************************/
/** Função para subtrair numero complexo:recebe como parametro 3     */
/** endereços do tipo im  onde o primeiro corresponde respectivamente*/
/**   ao primeiro e segundo numero complexo,e o terceiro recebe o    */
/**           endereço que guardará o resultado da subtração.        */
/**                      Não retorna valores                         */
/********************************************************************/
void subComplexo(im *num1,im *num2,im *sub);

/*********************************************************************/
/** Função para multiplicar numero complexo: ecebe como parametro 3  */
/** endereços do tipo im  onde o primeiro corresponde respectivamente*/
/**   ao primeiro e segundo numero complexo,e o terceiro recebe o    */
/**           endereço que guardará o resultado da  multiplicação.   */
/**                      Não retorna valores                         */
/********************************************************************/
void multComplexo(im *num1,im *num2,im *mult);

/*********************************************************************/
/** Função para dividir numero complexo:ecebe como parametro 3       */
/** endereços do tipo im  onde o primeiro corresponde respectivamente*/
/**   ao primeiro e segundo numero complexo,e o terceiro recebe o    */
/**           endereço que guardará o resultado da divisão.          */
/**                      Não retorna valores                         */
/********************************************************************/
void divComplexo(im *nun1,im *nun2,im *div);

/********************************************************************/
/** Função para liberar memória: recebe um endereço para liberar a  */
/**                      memoria alocada                            */
/**                    não retorna valores                          */
/********************************************************************/
void libera (im *num);

/********************************************************************/
/** cria��o do tipo estrura im com duas variaveis float             */
/********************************************************************/
typedef struct Nunemrocomplexo{
     float n1,n2;
}im;

/*********************************************************************/
/** Fun��o para alocar mem�ria: Sem paramentros de entrada e retorma */
/**      um ponteiro do tipo im caso seja alocada a memoria          */
/*********************************************************************/
im *alocarIm();

/*********************************************************************/
/** Fun��o para criar numero complexo: recebe trez paremetros,sendo: */
/**       ac e bd do tipo float e contera os dados das variaves a    */
/**             serem atribuidos e im recebe o endere�o que          */
/**                    conter� resultado da atribui��o               */
/**                        N�o tem retorno                           */
/*********************************************************************/
void criaComplexo(float ac, float bd, im *numi);

/********************************************************************/
/** Fun��o para imprimir numero complexo: recebe como parametro     */
/**     o endere�o de um tipo im e imprime na tela os valores       */
/**                      N�o retorna valores                        */
/********************************************************************/
void imprime (im *numi);

/*********************************************************************/
/** Fun��o para somar numero complexo:recebe como parametro 3        */
/** endere�os do tipo im  onde o primeiro corresponde respectivamente*/
/**   ao primeiro e segundo numero complexo,e o terceiro recebe o    */
/**           endere�o que guardar� o resultado da soma.             */
/**                      N�o retorna valores                         */
/********************************************************************/
void somaComplexo(im *num1,im *num2,im *soma);

/*********************************************************************/
/** Fun��o para subtrair numero complexo:recebe como parametro 3     */
/** endere�os do tipo im  onde o primeiro corresponde respectivamente*/
/**   ao primeiro e segundo numero complexo,e o terceiro recebe o    */
/**           endere�o que guardar� o resultado da subtra��o.        */
/**                      N�o retorna valores                         */
/********************************************************************/
void subComplexo(im *num1,im *num2,im *sub);

/*********************************************************************/
/** Fun��o para multiplicar numero complexo: ecebe como parametro 3  */
/** endere�os do tipo im  onde o primeiro corresponde respectivamente*/
/**   ao primeiro e segundo numero complexo,e o terceiro recebe o    */
/**           endere�o que guardar� o resultado da  multiplica��o.   */
/**                      N�o retorna valores                         */
/********************************************************************/
void multComplexo(im *num1,im *num2,im *mult);

/*********************************************************************/
/** Fun��o para dividir numero complexo:ecebe como parametro 3       */
/** endere�os do tipo im  onde o primeiro corresponde respectivamente*/
/**   ao primeiro e segundo numero complexo,e o terceiro recebe o    */
/**           endere�o que guardar� o resultado da divis�o.          */
/**                      N�o retorna valores                         */
/********************************************************************/
void divComplexo(im *nun1,im *nun2,im *div);

/********************************************************************/
/** Fun��o para liberar mem�ria: recebe um endere�o para liberar a  */
/**                      memoria alocada                            */
/**                    n�o retorna valores                          */
/********************************************************************/
void libera (im *num);

#include <stdio.h>
int main() {
    int i=5, *p;
    p = &i;
    printf("&i->%d,\np-> %d\n*p+2-> %d\n**&p-> %d\n3**p-> %d\n**&p+4-> %d \n",&i, p,*p+2,**&p,3**p,**&p+4);
}

#include<stdio.h>
int x = 0;
int main(){
    int i, x = 1;
    printf("%d\n", x);
    for (i=0;i<4;i++)
    {
        int x = 2;
        printf("%d/ ", x);
        {
            int x = 3;
            printf("%d/ ", x);
        }
    }
    printf("\n%d", x);
}

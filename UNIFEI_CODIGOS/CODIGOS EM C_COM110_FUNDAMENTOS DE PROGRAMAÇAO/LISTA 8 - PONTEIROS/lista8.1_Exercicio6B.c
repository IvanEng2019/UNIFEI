#include<stdio.h>

int w = 1, x=2,y=3,z=4;

void foo(int y){
    int z = 6;
    printf("%d %d %d %d \n", w, x, y, z);
}
int main(){
    int x = 7;
    foo(5);
    foo(x);
    printf("%d %d %d %d \n", w, x, y, z);
}

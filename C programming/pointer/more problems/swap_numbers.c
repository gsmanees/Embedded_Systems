#include<stdio.h>

void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}

int main(){ 

    int a=10;
    int b=15;
    printf("values before swapping\na=%d, b=%d\n\n", a, b);
    swap(&a, &b);
    printf("values after swapping\na=%d, b=%d\n\n", a, b);
    

    return 0;
}
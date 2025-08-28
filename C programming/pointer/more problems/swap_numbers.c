
#include<stdio.h>
// function definition for swap which acccepts pointer values
// we are calling this function by their addresses in the main function
void swap(int *x, int *y){ // here x and y expecting an address 
                          // and passes their value to the function
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




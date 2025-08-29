#include<stdio.h>

// check a number even or odd by bitwise & 

void checkOddorEven(int x){
    int mask=0;
    if(x & (1<<mask))
    printf("The number is odd");
    else 
    printf("The number is even");
}

int main(){
    int n;
    printf("Input a number\n");
    scanf("%d", &n);
    checkOddorEven(n);

    return 0;
}
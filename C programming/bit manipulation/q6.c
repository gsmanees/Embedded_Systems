#include<stdio.h>
// Check if the number is a power of 2
// logic: check n & (n-1) is 0 or not, if zero, number is power of 2
int main(){
    int n;
    printf("Input a number\n");
    scanf("%d", &n);

    if(n & (n-1))
    printf("the number is not a power of 2");
    else
    printf("The number is a power of 2");


    return 0;
}

// Check whether the number is even or not

#include<stdio.h>
int main(){
    int n;
    printf("Enter the number:\n");
    scanf("%d", &n);

    if(n&1)
    printf("\nThe number id ODD");
    else
    printf("The number is EVEN");




    return 0;
}
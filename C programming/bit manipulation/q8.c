#include<stdio.h>

// this program checks whether a number is divisible by 8 or not
// used % operator 
int main(){
    int n;
    printf("Enter a number\n");
    scanf("%d", &n);

   
    if(n%8==0)
    printf("divisible by 8");
    else 
    printf("Not divisible by 8");


    return 0;

}
#include<stdio.h>

// this program checks whether a number is divisible by 16 or not
// used % operator 
int main(){
    int n;
    printf("Enter a number\n");
    scanf("%d", &n);

   
    if(n%16==0)
    printf("divisible by 16");
    else 
    printf("Not divisible by 16");


    return 0;

}
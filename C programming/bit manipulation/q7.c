#include<stdio.h>

// this program checks whether a number is divisible by 4 or not
// used % operator 
int main(){
    int n;
    printf("Enter a number\n");
    scanf("%d", &n);

   
    if(n%4==0)
    printf("divisible by 4");
    else 
    printf("Not divisible by 4");


    return 0;

}
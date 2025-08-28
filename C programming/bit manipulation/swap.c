#include<stdio.h>

int main(){
    int a,b;
    printf("Enter a=");
    scanf("%d", &a);
    printf("Enter b=");
    scanf("%d", &b);

    // bit wise XORing for swapping 
    a=a^b;
    b=a^b;
    a=a^b;

    printf("Values after swapping: \na=%d\nb=%d", a, b);

    return 0;
}
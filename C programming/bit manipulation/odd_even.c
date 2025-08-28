#include<stdio.h>
int main(){

    int number;
    int test = 1;
    printf("Input a number\n");
    scanf("%d", &number);

    while(number!=-1){

    if (number & test){
        printf("the number is odd\n\n");
    }
    else {
        printf("The number is even\n\n");
    }
    printf("Input a number\n");
    scanf("%d", &number);

     }
}
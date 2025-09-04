
// Print the binary representation of decimal number:

#include<stdio.h>

void printBin(int n){

    int i, mask = 0;
    int count=0;
    for (i=31; i>=0; i--){
        mask = 1<<i;
        if(n & mask)
        printf("1");
        else
        printf("0");
    }
}

int main(){
    int n;
    printf("Enter a number:\n");
    scanf("%d", &n);

    printf("\nThe binary number is: \n");
     printBin(n);
     
    return 0;
}
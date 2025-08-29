#include<stdio.h>

// remove last set bit
// logic n & (n-1)

void printBin(int x){
    int i;
    int mask = 0;
    for (i=31; i>=0; i--){
        mask = 1<<i;
        if(x & mask)
        printf("1");
        else
        printf("0");
    }
}

int main(){
    int n;
    printf("Input a number\n");
    scanf("%d", &n);
    printf("The binary version of your number is\n");
    printBin(n);
    n = n & (n-1);
    printf("\nThe number after removing the last set bit is\n");
    printBin(n);
    return 0;
}
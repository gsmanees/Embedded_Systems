
// Reverse the bits of a number

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

void reverseBin(int n){

    int i, mask = 0;
    int count=0;
    for (i=0; i<=31; i++){
        mask = 1<<i;
        if(n & mask)
        printf("1");
        else
        printf("0");
    }
}

int main(){

    int n;
    printf("Enter the number\n");
    scanf("%d", &n);
    
    printf("The binary version is\n");
    printBin(n);

    printf("\nThe bitwise reversed number is\n");
    reverseBin(n);


    return 0;
}
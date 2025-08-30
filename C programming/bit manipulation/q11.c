#include<stdio.h>



// function to print binary number 
void printBin(int n){

    int i; 
    int mask;
    for(i=31; i>=0; i--){
        mask = 1<<i;
        if (n & mask)
        printf("1");
        else
        printf("0");
    }
}


// function to count set bits 
void countSetbits(int n){

    int i;
    int mask=0;
    int count=0;

    for (i=31; i>=0; i--){
        mask = 1<<i;
        if(n & mask)
        count++;
    }
    printf("\nThe number of set bits in the above number = %d", count);
}

int main(){

    int n;
    printf("Enter a number\n");
    scanf("%d", &n);
    printf("The binary is\n");
    printBin(n);

    // counting and printing set bits 
    countSetbits(n);


    return 0;
}
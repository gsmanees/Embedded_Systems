#include<stdio.h>
// clear bit
// this program takes inputs number from user and prints its binary value
// then asks user which bit needs to be clear? 
// the clearing that particular bit to 0
// to clear a bit, we need to use bitwise AND operator with 0

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

void clearBit(int a, int b){

    int clr=0;
    clr=~ (1<<(b-1));
    a = a & clr;
    printf("Value after clearing %d th bit (%d th position) \n", b, b-1);
    printBin(a);

}

int main(){

    int k, n=0;
    printf("Input a number\n");
    scanf("%d", &n);
    printf("\nThe binary numnber for %d is\n", n);
    printBin(n);
    
    printf("\nInput which bit needs to be clear?\n");
    scanf("%d", &k);
    clearBit(n, k);

}
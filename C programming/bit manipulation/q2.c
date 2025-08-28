#include<stdio.h>

// this program takes inputs number from user and prints its binary value
// then asks user which bit needs to be set? 
// the setting that particular bit to 1
// to set a bit, we need to use bitwise OR operator 

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

void setBit(int a, int b){

    int set=0;
    set=1<<(b-1);
    a = a | set;
    printf("Value after setting %d th position (%d th bit) \n", b, b-1);
    printBin(a);

}

int main(){

    int k, n=0;
    printf("Input a number\n");
    scanf("%d", &n);
    printf("\nThe binary numnber for %d is\n", n);
    printBin(n);
    
    printf("\nInput which bit needs to be set?\n");
    scanf("%d", &k);
    setBit(n, k);

}
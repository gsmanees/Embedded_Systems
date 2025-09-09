
// Swap all even and odd bits

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

void swapEvenOdd(int n){ // this function used to print even and odd swapped numberd

    int even, odd, swap;
    even = n & 0xAAAAAAAA;  // n | 10101010, takes only even 
    odd = n & 0X55555555; // n| 01010101, takes only odd
    
    even = even>>1; // even shifted right 1
    odd = odd<<1; // odd shifted left to 1

    swap = even | odd; // making even and odd to another variable swap

    printf("\nNumber after swapping even and oddd bits: %d\n", swap);
    printBin(swap); // printing swap

}

int main(){

    int n;
    printf("Enter number:\n");
    scanf("%d", &n);
    printf("Binary version is\n");
    printBin(n);

    swapEvenOdd(n);


    return 0;
}
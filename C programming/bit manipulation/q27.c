
// Swap the ith and Jth bit.

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

void swapBit(int n, int i, int j){
    int bit_i, bit_j;
    bit_i=(n>>i); // ith bit moves to LSB  for equivalancy checking
    bit_j=(n>>j); // jth bit moves to LSB for equivalancy checking

    // now bit_i and bit_j different variables with only LSB (1 bit)
    // now we can compare easily by if statement, they are same or not
    // if they are same no need to swap, if different we need to swap
    if(bit_i!=bit_j){
        n = n ^ (1<<i); // XOR with 1 for swapping 
        n = n ^ (1<<j); // XOR with 1 for swapping 
    }
    printf("\nThe number after swapping bits %d and %d is: %d\n", i, j, n);
    printBin(n);
}

int main(){
    int n;
    int i, j;
    printf("\nEnter a number:\n");
    scanf("%d", &n);

    printBin(n);

    printf("\nEnter positions i and j: ");
    scanf("%d %d", &i, &j);

    swapBit(n, i, j);

    return 0;
}
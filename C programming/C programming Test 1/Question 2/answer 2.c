#include<stdio.h>

unsigned char n=15;
void printBin(int n){
 
    int i;
    int mask=0;

    for (i=7; i>=0; i--){
        mask = 1<<i;
        if(n & mask)
        printf("1");
        else 
        printf("0");
    }
    printf("\n");

}

void setBit(int n, int pos){
    int mask=0;
    mask=1<<pos;
    n=n|mask;
    printf("Value after setting bit at %d position:\n", pos);
    printBin(n);

}

void clearBit(int n, int pos){
    int mask=0;
    mask= 1<<pos;
    mask=~(mask);
    n=n&mask;
    printf("Value after clearing bit at %d position:\n", pos);
    printBin(n);
   

}

void bitToggle(int n, int pos){
    int mask=0;
    mask = 1<<(pos);
    n = n ^ mask;
    printf("Value after toggling bit at %d position:\n", pos);
    printBin(n);
    

}

int main(){
    
    // priniting the original register
    printf("\nThe original register is:\n");
    printBin(n);

    // Set the 3rd bit (bit index 2). 
    setBit(n,2);
   

    // Clear the 6th bit (bit index 5). 
    clearBit(n,5);
   

    // Toggle the 1st bit (bit index 0)
    bitToggle(n,0);
 

    // printing modified register
    printf("\nThe modified register is:\n"); 
    printBin(n);

}
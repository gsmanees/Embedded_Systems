#include<stdio.h>

void printBin(int n){
 
    int i;
    int mask=0;

    for (i=31; i>=0; i--){
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

void clearBit(int n, int clear){
    int mask=0;
    mask= 1<<clear;
    mask=~(mask);
    n=n&mask;
    printf("Value after clearing bit at %d position:\n", clear);
    printBin(n);

}

int main(){

    int a;
    int pos, clear;

    printf("Enter the number: ");
    scanf("%d", &a);
    printBin(a);

    printf("enter position to set bit: ");
    scanf("%d", &pos);
    setBit(a,pos);

    printf("Enter position to clear bit: ");
    scanf("%d", &clear);
    clearBit(a, clear);


    return 0;
}
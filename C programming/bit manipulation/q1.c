#include<stdio.h>


// here I am taking bit positions like starting from LSB - oth, 1st, 2nd leftwards
// so second bit means 2-1 = 1th position, hence I used i-1 (position) to locate ith the bit

void xthBitCheck(int x, int y){
    int mask=0;
    mask=1<<(y-1);
    if(x & mask)
    printf("SET");
    else
    printf("NOT SET");
}

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
}

int main()
{
    int i;
    int n;

    printf("Input a number\n");
    scanf("%d", &n);
    printf("The binary number for %d is \n", n);
    printBin(n);
    printf("\nInput which bit needs to be check set or not?\n");
    scanf("%d", &i);
    xthBitCheck(n, i);


}
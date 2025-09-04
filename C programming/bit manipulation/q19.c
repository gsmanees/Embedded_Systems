
// program to calculate XOR from 1 to n

#include<stdio.h>

void XORuptoN(int n){
    int i, result=0;
    for (i=1; i<=n; i++){
        result = result ^ i;

    }
    printf("Result of XOR upto %d is: %d", n, result);
}

int XORmethod2(int n){
    
    switch (n & 3) {    // n % 4 using bitwise
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
}

int main(){

    int n;
    do{
    printf("\n\nEnter n:\n");
    scanf("%d", &n);

    XORuptoN(n);
    printf("\n\nXOR upto n by second method is: %d", XORmethod2(n));
 } while(n!=1);




    return 0;
}
#include<stdio.h>

// this program toggles the ith bit of a number 

// function definition for print binary number 
void printBin(int n){

        int i;
        int mask;

        for (i=31; i>=0; i--){
            mask= 1<<i;
            if (n & mask)
            printf("1");
            else
            printf("0");


        }
}


// function definition for toggling ith bit of the number 
void bitToggle(int n, int i){
    int mask=0;
    mask = 1<<(i-1);
    n = n ^ mask;
    printf("the number after toggling the ith bit \n");
    printBin(n);

}


int main(){

    int n, i;
    printf("Enter a number\n");
    scanf("%d", &n);
    printf("the binary version of the number is\n");
    printBin(n); // converting the entered number to binary


    printf("\nEnter which bit is to be toggled\n");
    scanf("%d", &i);
    bitToggle(n, i); // toggling the ith bit 

    



    return 0;
}
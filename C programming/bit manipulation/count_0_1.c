#include<stdio.h>

// this program is written by Anees Kokadan
// It counts the number of 1s and 0s in a user input value

// counting variables declared as global
int count_1 = 0;
int count_0 = 0;



void printBin(int n){
    int i;
    int mask=0;
    for (i=31; i>=0; i--){
        mask=1<<i;
        if (n & mask){ 
        printf("1");
        count_1++; // counting number of 1s
        }
        
        else {
        printf("0");
        count_0++; // counting number of 0s
        }
        

    }
}

void count0_1(int n){ // printing the counts
    printf("Number of 1s: %d\n", count_1);
    printf("Number of 0s: %d", count_0);

}

int main(){

    int n;
    printf("input a number\n");
    scanf("%d", &n);
    printf("The binary form of your number is\n");
    printBin(n);
    printf("\nThe number of zeros and ones in yor number are\n");
    count0_1(n);

return 0;
}
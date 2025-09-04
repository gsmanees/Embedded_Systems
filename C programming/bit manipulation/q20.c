
// Find XOR of numbers from the range [L,R]


#include<stdio.h>

void XOR_LtoR(int L,int R){

    int i, result = 0;
    for (i=L; i<=R; i++){
        result = result ^ i;
    }

    printf("XOR result from %d to %d is: %d", L, R, result);
}

int main(){

        int L, R;
        printf("enter L: \n");
        scanf("%d", &L);
        printf("Enter R:\n");
        scanf("%d", &R);

        XOR_LtoR(L,R);


    return 0;
}
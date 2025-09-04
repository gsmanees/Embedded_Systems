
// Count Number of bits to be flipped to convert A to B:
#include<stdio.h>

void flipCountAtoB(int A, int B){
    int k, i, count=0;;
    k = A ^ B;
    int mask=0;
    for (i=31; i>=0; i--){
        mask = 1<<i;
        if (k & mask)
        count++;
    }
printf("\nThe number of bits to be flipped to convert A (%d) to B(%d) is %d", A, B, count);
}
int main(){
    int A, B;
    printf("Enter A: \n");
    scanf("%d", &A);
    printf("Enter B:\n");
    scanf("%d", &B);

    flipCountAtoB(A, B);


    return 0;
}
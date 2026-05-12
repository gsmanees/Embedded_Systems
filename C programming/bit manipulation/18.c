#include <stdio.h>

void printBin(int n)
{
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

int main() 
{
    int num, pos, n, result, mask;

    // Input
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Number in binary: \n");
    printBin(num);

    printf("Enter starting bit position: ");
    scanf("%d", &pos);

    printf("Enter number of bits to extract: ");
    scanf("%d", &n);

    mask = (1<<n)-1;

    // Shift number to the right and extract bits
    result = (num >> pos) & mask;

    // Output
    printf("Extracted value = %d\n", result);

    printf("The extracted value in binary:\n");
    printBin(result);

    return 0;
}
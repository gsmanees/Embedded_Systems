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
    int num, pos, n;
    int mask, result;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The number you entered in binary form is :\n" );
    printBin(num);

    printf("Enter starting position: ");
    scanf("%d", &pos);

    printf("Enter number of bits to toggle: ");
    scanf("%d", &n);

    // Create mask
    mask = ((1<<n)-1)<<pos; // subtracting 1 to make all digits as 1s

    // Toggle bits
    result = num^mask;

    // Display result
    printf("Number after toggling bits = %d\n", result);

    printf("\nThe binary form is:\n");
    printBin(result);

    return 0;
}
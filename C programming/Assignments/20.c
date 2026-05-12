#include <stdio.h>

int main() 
{
    int num1, num2, pos, n;
    int mask, bits1, bits2;

    // Input
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter starting bit position: ");
    scanf("%d", &pos);

    printf("Enter number of bits to swap: ");
    scanf("%d", &n);

    // Create mask for n bits at given position
    mask = ((1<<n)-1)<<pos;

    // Extract bits from both numbers
    bits1 = num1&mask;
    bits2 = num2&mask;

    // Clear those bits in both numbers
    num1 = num1&(~mask);
    num2 = num2&(~mask);

    // Swap and place bits
    num1 = num1|bits2;
    num2 = num2|bits1;

    // Output
    printf("\nAfter swapping bits:\n");
    printf("First number  = %d\n", num1);
    printf("Second number = %d\n", num2);

    return 0;
}
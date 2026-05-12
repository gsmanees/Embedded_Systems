#include <stdio.h>

int main()
{
    int num1, num2, pos, n;
    int mask, bits, result;

    // Input
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter starting position: ");
    scanf("%d", &pos);

    printf("Enter number of bits to replace: ");
    scanf("%d", &n);

    // Create mask for n bits
    mask = (1 << n) - 1;

    // Extract n bits from second number
    bits = num2 & mask;

    // Clear n bits in first number at given position
    num1 = num1&~(mask<<pos);

    // Place extracted bits into first number
    result = num1 | (bits << pos);

    // Output
    printf("Result after replacing bits = %d\n", result);

    return 0;
}
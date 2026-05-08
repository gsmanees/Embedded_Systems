#include <stdio.h>

// Recursive function to find GCD
int gcd(int x, int y) {
    if(y==0)
        return x;   //Base case
    else
        return gcd(x, x%y);  // Recursive call
}

int main() {
    int a, b, result;

    printf("Enter First number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);


    result = gcd(a, b); // function call

    printf("GCD of %d and %d is: %d\n", a, b, result);

    return 0;
}
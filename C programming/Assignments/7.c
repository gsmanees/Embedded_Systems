#include <stdio.h>

// Function to count digit frequency
void countDigits(int num) {
    int freq[10] = {0};  // Array to store frequency of digits 0-9

    // Handle negative numbers
    if (num<0) {
        num = -num;
    }

    // Handle 0 - direcly pushes to 0th posision in array 
    if (num==0) {
        freq[0] = 1;
    }

    // Count digits
    while (num>0) { // repeat the process while num > 0
        int digit = num % 10; // takes reminder - gets last digit 
        freq[digit]++; // pushes the last digit to its area i the frequency array 
        num = num / 10; //then number devides by 10 for getting last but one number and this loop repeats 
    }

    // Display results
    printf("\nDigit Frequencies:\n");
    for (int i=0;i<10;i++) {
        printf("Digit %d: %d\n", i, freq[i]); // prints the array
    }
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    countDigits(number);  // Function call

    return 0;
}
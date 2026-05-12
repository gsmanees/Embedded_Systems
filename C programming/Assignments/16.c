
/*
Write a C program that takes a string from the user and converts all uppercase letters 
into their corresponding lowercase letters. 
Description: The program should prompt the user to enter a sequence of characters. It 
must then check each character individually. If a character is an uppercase letter, the 
program should convert it to its lowercase equivalent. If the character is already 
lowercase or is not a letter at all, the program should leave it exactly as it is. The final 
modified string should be displayed on the screen. 
Pre-requisites: Loops, Strings, Conditional Statements, ACII
*/

#include <stdio.h>

int main()
{
    char str[100];
    int i = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    // Convert uppercase letters to lowercase
    while (str[i] != '\0')
    {
        // Check if character is uppercase
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }

        i++;
    }

    // Display result
    printf("Lowercase string: %s", str);

    return 0;
}
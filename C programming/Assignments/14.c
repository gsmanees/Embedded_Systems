#include <stdio.h>

int main() 
{
    char str[200];
    int letters[26] = {0};
    int i, count = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]", str);

    // Check each character
    for (i = 0; str[i] != '\0'; i++) {

        // Lowercase letters
        if (str[i] >= 'a' && str[i] <= 'z') 
        {
            letters[str[i] - 'a'] = 1;  
            // finds the position of every letter by subtracting its ascii value with ascii value of  small letter a
            // so we will get its exact position in english alphabe, if the position has value, letters array set to 1
        }

        // Uppercase letters
        else if (str[i] >= 'A' && str[i] <= 'Z') 
        {
            letters[str[i] - 'A'] = 1;
        }
    }

    // Count how many letters are present
    for (i = 0; i < 26; i++) 
    {
        count += letters[i];
    }

    // Check pangram
    if (count == 26)
        printf("Pangram");
    else
        printf("Not Pangram");

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() 
{
    char str[100];
    int i, length;
    int isPalindrome=1;

    printf("Enter a string: ");
    scanf("%s", str);

    length = strlen(str);   // Find length of string

    
    for(i = 0; i < length / 2; i++)     // Compare characters from beginning and end
    {
        if(str[i]!=str[length-i-1]) 
        {
            isPalindrome=0;
            break;
        }
    }

    // Display result
    if(isPalindrome) 
    {
        printf("The string is a palindrome.\n");
    } else 
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
#include <stdio.h>

int main()
{
    char str[200];
    int i = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    while (str[i]!='\0')
    {
        // Print current character
        printf("%c", str[i]);

        // If current and next characters are spaces,
        // skip all extra spaces
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            while (str[i + 1] == ' ')
            {
                i++;
            }
        }

        i++;
    }

    return 0;
}
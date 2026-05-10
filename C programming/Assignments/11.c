#include <stdio.h>

int main() 
{
    int num, temp, i=0, isNegative=0;
    char str[20];

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Handle negative number
    if (num<0) 
    {
        isNegative=1;
        num= -num;
    }

    temp=num;

    // Special case for 0
    if (temp==0) 
    {
        str[i++] ='0';
    }

    // Convert digits to characters (stored in reverse order)
    while (temp>0) 
    {
        str[i]=(temp%10)+'0'; // this will convert the last digit to string - as first letter in the string 
        temp = temp/10;     // this will remove the last digit and set last digit as the second one from the last 
        i++;                // and this process continues till fist digit 
    }

    // Add negative sign
    if (isNegative) 
    {
        str[i++] = '-';
    }

    // Null character to end string
    str[i] = '\0';

    // Reverse the string
    int start=0, end=i-1;
    char swap;

    while (start<end) 
    {
        swap = str[start];
        str[start] = str[end];
        str[end] = swap;

        start++;
        end--;
    }

    // Output string
    printf("Your integer as string: %s\n", str);

    return 0;
}
/*
Write a C program that uses functions to convert a decimal number to any base 
between 2 and 16. 
Description: The program should prompt the user to enter a decimal number and a 
target base. A separate function must be written that performs the repeated division 
method, stores each remainder, and builds the result in the correct order. For bases 
above 9, remainders 10–15 should be represented as letters A–F. The converted value 
should be displayed from the main function. 
Pre-requisites: Functions, Loops, Arrays, Character Handling.
*/

#include<stdio.h>

// function definition to convert the decimal number to given base
void changeBase(int decimal, int target_base)
{
    int i=0, j=0,reminder=0, k=0;
    char result[100], newResult[100];
    char digits[]="0123456789ABCDEF";   //We are telling compiler - these are digits, we will relate the result with this digits
    while(decimal>0)
    {
        reminder=decimal%target_base;
        result[i]=digits[reminder];
        decimal=decimal/target_base;
        i++;
    }

    // makes the results array in reverse for getting actual new base number 
    for (j=i-1; j>=0; j--)
    {
        newResult[k]=result[j];
        k++;
    }

    // printing the actual new base value 
    for (int i=0; i<k; i++)
    {
        printf("%c", newResult[i]);
    }
}

int main()
{
    int decNum, base;
    char decNum_inNewBase[100];
    // reading decimal number from user
    printf("Enter a decimal number: "); 
    scanf("%d", &decNum);

    // reading target base from user 
    printf("Enter target base between 2 - 16: ");
    scanf("%d", &base);

    // Validate base
    if (base<2||base>16) 
    {
        printf("Invalid base! Please enter a base between 2 and 16.\n");
        return 1;
    }

    // as per the question, printing the dec number in new target base 

    printf("The decimal number %d in %d base is : \n", decNum, base);
    
    // function call - to convert decimal number to target base 
   changeBase(decNum, base);
}
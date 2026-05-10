
/*
Write a C program that takes a string of digits from the user and converts it into its equivalent 
integer value. 
Description:The program should prompt the user to enter a number as a string (for example, 
"1234"). It must then process this string character by character and transform it into an actual 
integer variable that can be used for mathematical operations. The program should be able to 
handle positive numbers and display the final integer result on the screen. 
Pre-requisites: Loops, Strings, Operators. 
*/

#include<stdio.h>
int main()
{
    int result=0, i=0;
    char number[100];
    printf("Enter a number: ");
    scanf("%s", number);

    // string to number conversion
    while (number[i]!='\0')
    {
        result = result*10+(number[i]-'0'); // this will return an integer - ACCII value difference corresponding to the first element of the char number array
        // multiply with 10 for making the actual number with positional values 
        i++;
    }

    printf("The entered string in integer is: %d", result);
}

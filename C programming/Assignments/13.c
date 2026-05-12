
/*
 Write a C program that takes a string from the user and reverses its characters using 
an iterative approach. 
Description: The program should prompt the user to enter a sequence of characters. It 
must then swap or move the characters within the string using a loop until the entire 
string is reversed. The final resulting string should be displayed on the screen. 
Pre-requisites: Loops, Strings. Operators
*/

#include <stdio.h>

int main() {
    char str[100];
    int i = 0, length = 0;
    char temp;  //used for reversing 

    printf("Enter a string: ");

    while ((str[i]=getchar())!= '\n') // string reading 
    {
        i++;
    }

    str[i] = '\0'; // End the string by putting \0 at the end 

    // Find length of the string 
    while (str[length]!='\0') 
    {
        length++;
    }

    // Reverse the string
    for (i=0; i<length/2; i++) 
    {
        temp = str[i];
        str[i] = str[length -1-i];
        str[length - 1-i]=temp;
    }

    // Display reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
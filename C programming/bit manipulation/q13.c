/*
This code is written by Anees Kokadan

Program to Convert Uppercase to LowerCase and vice versa 

ASCII in Binary
'A' = 65 = 0100 0001 (binary)
'a' = 97 = 0110 0001 (binary)

'A' → 0100 0001
'a' → 0110 0001

here the difference only in 5th bit
5th bit is set in lowercase and 
5th bit is clear in uppercase 

So, 
uppercase → lowercase = set the 5th bit.
lowercase → uppercase = clear the 5th bit.

*/

#include<stdio.h>

// function to convert upperCase to LowerCase
void toLowerCase(char ch){
    int mask=0;
    mask=(1<<5);
    ch = ch | mask;
    printf("The lowerCase is is: %c", ch);
    
}

// Function to convert LowerCase to UpperCase
void toUpperCase(char ch){
    int mask=0;
    mask=(1<<5);
    ch = ch & ~(mask);
    printf("The UpperCase is: %c", ch);
}
int main(){
    char ch;
    printf("\nEnter a upper case charactor\n");
    scanf(" %c", &ch);
    toLowerCase(ch);

    char ch2;
    printf("\nEnter a lower case charactor\n");
    scanf(" %c", &ch2);
    toUpperCase(ch2);

    return 0;
}
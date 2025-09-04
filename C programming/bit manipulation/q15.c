
// program to invert an alphabets case

#include<stdio.h>

// function to convert case
void invertCase(char ch){
    if (ch>='A' && ch<='Z'){ // if charactor is uppercase
        printf("\nYou entered an Uppercase letter");
        int mask=0;
        mask = (1<<5);
        ch = ch | mask; // converted to lower case
        printf("\nThe lower case is: %c", ch);
    }

    else if(ch>='a' && ch<='z'){ // if charactor is lower case
        printf("\nYou entered a lower case letter");
        int mask=0;
        mask = (1<<5);
        mask = ~mask;
        ch = ch & mask; // converted to Upper case 
        printf("\nThe Upper case is: %c", ch);
    }

}

int main(){
    char ch;
    printf("Enter an alphabet:\n");
    scanf(" %c", &ch);
    invertCase(ch);

    return 0;
}
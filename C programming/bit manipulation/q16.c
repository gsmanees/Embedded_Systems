

// program to find letter position in alphabet
// This code is written by Anees Kokadan

#include<stdio.h>

// function to find position of a letter in alphabet
void findPos(char ch){
    int i=0, pos=0;
    int mask=0;

    // if user entered a lower case letter, it will be converted to upper case in these steps
    mask=(1<<5);
    mask = ~(mask);
    ch = ch & mask; // now the letter becomes upper case 

    for (i='A'; i<='Z'; i++){ // for loop is designed to work on upper case letters 
        pos++;
        if(ch == i)
        printf("Position of letter %c in alphabet is: %d", ch, pos);
    }
}

int main(){
    char ch;

     do{
    printf("\nEnter a letter to find its position in alphabet:\n");
    scanf(" %c", &ch);
    findPos(ch);
    } while(ch!=1);

    return 0;
}
/*
write a program which reads your name from the keyboard and outputs a list of ascii codes 
which represent your name 

This program is written by Anees Kokadan
*/

#include<stdio.h>
int main()
{
    char name[30];
    int i;
    printf("Enter your name: ");
    gets(name);
    printf("Your name: %s", name);
    
printf("The ASCII codes for your name: \n");

for (i=0; (name[i]!='\0'); i++)
{
    printf("%c: %d\n", name[i], name[i]);
}

}








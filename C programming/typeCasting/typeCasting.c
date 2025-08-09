#include<stdio.h>


//there are two types of typecasting (1) implicit (2) explicit


int main(){

// variable declarations
int x;
float y;
char c;
int ascii=0;


//--------------------------------------------------------------------
//implicit typecasting
//int to float
printf("Enter an integer for implicit typecast to float: ");
scanf("%d", &x);
y=x; // typecasting by assigning
printf("Your integer typecasted to float: %.2f",y );

// converting a charactor to corresponding ascii format by implicit typecasting 
// char to int
printf("\nEnter a charactor to convert to ASCII:");
scanf(" %c", &c);
ascii = c;
printf("ASCII code for the alphabet : %d", ascii);


//explicit typecasting --> float to int 
float f;
int k;

printf("\nEnter a floating point value to display only ineger part: ");
scanf("%f", &f);
k = (int) f; // we are forcing to convert 
printf("The number you entered without floating point value = %d", k);

// explicit typecasting --> int to char
char ch;
int ch_asc;
printf("\nEnter integer to convert to char: ");
scanf("%d", &ch_asc);
ch = (char) ch_asc; // we are forcing to convert
printf("Charactor for your number: %c", ch);



return 0;

}
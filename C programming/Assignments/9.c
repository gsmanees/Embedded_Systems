/*
Write a C program that uses functions to evaluate a simple arithmetic expression 
given two numbers and an operator. 
Description: The program should prompt the user to enter two floating-point 
numbers and an arithmetic operator (+, -, *, /). A separate function must be written for 
each operation (add, subtract, multiply, divide). A selector function should take the 
operator as a parameter and call the appropriate function, returning the result to main. 
Division by zero must be handled gracefully inside the divide function. 
Pre-requisites: Functions, Switch/Conditionals, Float Arithmetic, Error Handling
*/

#include<stdio.h>

// function definitions 
float add(float x, float y)
{
    return x+y;
}

float sub(float x, float y)
{
    return x-y;
}

float mul(float x, float y)
{
    return x*y;
}

float div(float x, float y)
{
    if (y==0)
    {
        printf("Division by zero not possiblr\n");
    }
    else
    return x/y;
}

float calc(float x, float y, char op)
{
    switch(op)
    {
        case '+': return add(x,y);
        case '-': return sub(x,y);
        case '*': return mul(x,y);
        case '/': return div(x,y);
        default: printf("Invalid operator.\n");
        return 0;
    }
}

int main()
{
    float x, y, result; // x - first number, y- second number
    char op;            // for scanning the arithmatic operator from user 

    printf("Enter First number: ");
    scanf("%f", &x);
    printf("Enter Second number: ");
    scanf("%f", &y);

    printf("Select Arithmatic Operator: (+, -, *, /): ");
    scanf(" %c", &op);

    // performing arithmatic calcultion 
    result=calc(x,y,op);

    printf("Result: %.2f", result);
}






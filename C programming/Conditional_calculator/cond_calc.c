#include <stdio.h>

// this code is written by Anees Kokadan
// Menu based calclator 

// variables declaration as global variables
int a, b;
int op;

// functions declarations
int sum(int, int);
int sub(int, int);
int mul(int, int);
float div(float, float);
void menu();

// main function
int main()
{

  // receiving inputs from user
  printf("\n\nConditional calculator\n-------------------");
  printf("\nEnter First number: ");
  scanf("%d", &a);
  printf("Enter Secod number: ");
  scanf("%d", &b);

  // Printing calculator menu
  menu();

  // function calling and return value printing
  printf("\nCalculation Result\n----------------\n");

  if (op == 1)
  {
    printf("Sum of the numbers: %d\n", sum(a, b));
  }
  else if (op == 2)
  {
    printf("Difference of the numbers: %d\n", sub(a, b));
  }
  else if (op == 3)
  {
    printf("Product of the two numbers: %d\n", mul(a, b));
  }

  else if (op == 4)
  {

    printf("Division result: %.2f\n\n\n", div(a, b));
  }

  else
  {
    printf("Please Enter a valid option: ");
  }


  return 0;
}

// functios definition section

void menu()
{
  printf("\nCONDITIONAL CALCULATOR\n------------------");
  printf("\nEnter which operation to be carried out: ?\n");
  printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit");
  printf("\n\nPlease choose your operation: ");
  scanf("%d", &op);
}

int sum(int x, int y)
{

  int sum = 0;
  sum = x + y;
  return sum;
}

int sub(int x, int y)
{

  int sub = 0;
  sub = x - y;
  return sub;
}

int mul(int x, int y)
{
  int mul = 0;
  mul = x * y;
  return mul;
}

float div(float x, float y)
{
  float div = 0;
  div = x / y;
  return div;
}

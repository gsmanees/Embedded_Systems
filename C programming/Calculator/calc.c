#include<stdio.h>

//this code is written by Anees Kokadan

//functions declarations
int sum(int, int);
int sub(int, int);
int mul(int, int);
float div(float, float);

int main()
{

  //variables declaration
    int a, b;

    //receiving inputs from user
    printf("Enter First number: ");
    scanf("%d", &a);
    printf("Enter Secod number: ");
    scanf("%d", &b);

    //function calling and return value printing
    printf("\n\nCalculation outputs\n");
    printf("Sum of the numbers: %d\n", sum(a,b));
    printf("Difference of the numbers: %d\n", sub(a,b));
    printf("Product of the two numbers: %d\n", mul(a,b));
    printf("Division result: %f\n\n\n", div(a,b));

    return 0;
}


//functios definition section

int sum(int x, int y){

  int sum=0;
  sum=x+y;
  return sum;
}

int sub(int x, int y){

  int sub=0;
  sub=x-y;
  return sub;
}

int mul(int x, int y){
  int mul=0;
  mul=x*y;
  return mul;
}

float div (float x, float y) {
  float div=0;
  div=x/y;
  return div;
}

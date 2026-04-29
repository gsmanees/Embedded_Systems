#include<stdio.h>
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Your number: %d", n);
    if (n%2==0)
    {
        printf("\nThis is an even number");
    }
    else
    {
        printf("\nThis is an odd number");
    }
}
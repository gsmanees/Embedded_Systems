#include<stdio.h>
int main()
{
    int n,i,k=1;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("\nYou entered: %d", n);

    if (n<=1)
    {
        k=0;
    }

    for (i=2; i<n; i++)
    {
        if (n%i==0)
        {
            k=0;
            break;
        }
        
    }

    if(k==1)
    {
        printf("\nThe number is a prime number");
    }

    else
    {
        printf("\nThe number is not a prime number");
    }


}
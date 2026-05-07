// perfect number
#include<stdio.h>
//global variable declarations
int isPerfect; // flag to check perfect number

// function to compute sum of divisors excluding the number
int sumOfDivisors(int n)
{
    int sum=0;
    for (int i=1; i<n; i++)
    {
        if (n%i==0)
        {
            sum+=i;
        }
    }
    if (sum==n)
        {
        isPerfect=1;
        }
    else if (sum!=n)
     {
        isPerfect=0;
     }
    return isPerfect;
}


int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    sumOfDivisors(n);  // calling function to calculate sum of divisors and set isperfect flag

    if (isPerfect==1)
    {
        printf("The number is a perfect number");
    }
    else if (isPerfect==0)
    {
        printf("The number is not a perfect number");
    }

    

}


#include<stdio.h>
int main()
{
    int n,i, f=1;

    printf("Enter the number: ");
    scanf("%d", &n);
     if (n==0)
     {
        f=1;
     }

     else
     {
        for (i=1; i<=n;i++)
        {
            f*=i;
            // 5 x 4 x 3 x 2 x 1
        }
     }

     printf("Factorial of the number %d is : %d", n, f);
}



#include<stdio.h>

/*
Output:

Enter rows:5
* 
* *
* * *
* * * *
* * * * *

*/
int main ()
{
    int i, j, n;
    printf("Enter rows:");
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        for (j=0; j<=i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
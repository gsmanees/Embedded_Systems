/*
Enter number of rows: 5
Enter number of columns: 5
* * * * * 
* * * * *
* * * * *
* * * * *


*/



#include<stdio.h>
int main()
{
    int i, j, r, c;
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);

    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
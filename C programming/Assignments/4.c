// fibonacci series
#include<stdio.h>
int main()
{
    int n, i, a=0, b=1, c;
    // a=first, b=second, c=next
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series with %d terms are as follows:", n);
    // 0, 1,  1,  2,   3,     5,     8 .....
    // 0, 1, 0+1, 1+1, 2+1    3+2

    

    
    for(i=0;i<n; i++) // for number of terms
    {
        if(i==0)
        c=0;
        else if (i==1)
        c=1;
        else
        {
            c=a+b;
            a=b;
            b=c;
        }
        printf("%d ", c);
    }
        


}
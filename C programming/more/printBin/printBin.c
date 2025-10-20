
#include<stdio.h>

void printBin(int n)  // function to convert decimal to binary
{
    int i, mask=0;
    for (i=31; i>=0; i--)
    {
        mask = 1<<i;
        if(n&mask)
        printf("1");
        else
        printf("0");
    }
}
int main ()
{
    int n;
    while(n!=-1)
    {
    printf("\nEnter a number: \n");  // scanning number from user
    scanf("%d", &n);
    printBin(n);  // printing binary representation
    }

    return 0;
}



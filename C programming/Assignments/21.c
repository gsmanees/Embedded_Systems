#include <stdio.h>

int main()
{
    int a[100], n, i, j;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i=0; i<n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
            {
                a[j] = a[n - 1];
                n--;
                j--;
            }
        }
    }

    printf("Array after removing duplicates:\n");

    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}